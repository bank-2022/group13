#include "saldo.h"
#include "ui_saldo.h"


Saldo::Saldo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Saldo)
{
    ui->setupUi(this);

}

Saldo::~Saldo()
{
    delete ui;

}


void Saldo::setTyyppi(const QString &value) // haetaan kortti
{
    Tyyppi = value;
    info();
}

void Saldo::setId(const QString &value)  // haetaan kortin id
{
    id = value;
}

void Saldo::info() //Valitaan saldo
{
    qDebug() << "Katso saldo 1  = "+Tyyppi;
    qDebug() << "tilin id = "+id;

    if(Tyyppi == "0") {
        QString site_url="http://localhost:3000/saldo/" +id;
        QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(Tulostus(QNetworkReply*)));
        reply = manager->get(request);

    }
}



void Saldo::Tulostus(QNetworkReply *reply)  // tulostetaan saldo
{


       if (Tyyppi == "0") {

           QByteArray response_data=reply->readAll();
              QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
              QJsonArray json_array = json_doc.array();
              foreach (const QJsonValue &value, json_array) {
              QJsonObject json_obj = value.toObject();
           saldo+="Saldo: "+QString::number(json_obj["Saldo"].toInt());
           qDebug() << saldo;
           ui->txtSaldo->setText(saldo);
              }

       }
}

void Saldo::on_BtnPaluuValikkoon_clicked()
{

    //nollailua ja valikkoon.
    ui->txtSaldo->setText("");
    saldo = "";
    this->close();
}
