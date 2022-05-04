#include "valikko.h"
#include "ui_valikko.h"

valikko::valikko(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::valikko)
{
    ui->setupUi(this);
    objNosto = new Nosto;
    objSaldo = new Saldo;
    objTilitapahtumat = new Tilitapahtumat;
}

valikko::~valikko()
{
    delete ui;
    ui = nullptr;

    delete objNosto;
    objNosto = nullptr;

    delete objSaldo;
    objSaldo = nullptr;

    delete objTilitapahtumat;
    objTilitapahtumat = nullptr;


}

void valikko::on_btnNosto_clicked()                 //vie nostoon
{
    objNosto->setId(TiliID);
    objNosto->setTyyppi(tyyppi);
    objNosto->show();
}

void valikko::on_btnSaldo_clicked()           //vie saldoon
{
    objSaldo->setId(TiliID);
    objSaldo->setTyyppi(Valinta);
    objSaldo->show();
}


void valikko::on_btnTilitapahtumat_clicked()        //vie tilitapahtumat
{
    objTilitapahtumat->setId(TiliID);
    objTilitapahtumat->show();
}

void valikko::on_btnKirjauduUlos_clicked()              //kirjautuu ulos
{
    tyyppi = "";
    asiakas = "";
    tilinumero = "";
    ui->label_Saldo->setText("");
    ui->txtAsiakas->setText("");
    ui->labelinfo->setText("");
    this->close();
}

void valikko::info()    //asiakkaan haku
{
    QString site_url="http://localhost:3000/asiakas/" +TiliID;
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(tulostainfo(QNetworkReply*)));
    reply = manager->get(request);
}


void valikko::info2() //haetaan tili
{
    QString site_url="http://localhost:3000/tili/" +TiliID;
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(haetyyppi(QNetworkReply*)));
    reply = manager->get(request);
}

void valikko::tulostainfo(QNetworkReply *reply)     //tulostaa asiakkaan tiedot
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    asiakas+="Etunimi - "+json_obj["Etunimi"].toString()+"\rSukunimi - "+json_obj["Sukunimi"].toString()+"\rOsoite - "+json_obj["Osoite"].toString()+"\r";
    ui->txtAsiakas->setText(asiakas);
    }
}


void valikko::haetyyppi(QNetworkReply *reply) // saldon haku ja tilinumero
{
    Valinta = "";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    Valinta+=QString::number(json_obj["tyyppi"].toInt());
    tilinumero+=json_obj["Tilinumero"].toString();
    ui->labelinfo->setText(tilinumero);
    qDebug()<< "Kortin saldo ="+Valinta;
    }
    if(Valinta=="0") {
        ui->btnSaldo->hide();
        ui->labelkertoja->setText("");
        tyyppi = "0";
    }

}

void valikko::setTiliID(const QString &value) //haetaan tilin id mitä voidaan käyttää url
{
    TiliID = value;
    qDebug() << "tilin id = "+TiliID;
    info();
    info2();
}
