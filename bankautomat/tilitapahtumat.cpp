#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

Tilitapahtumat::Tilitapahtumat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tilitapahtumat)
{
    ui->setupUi(this);
}

Tilitapahtumat::~Tilitapahtumat()
{
    delete ui;
}

void Tilitapahtumat::info()                 //hakee tilin tietoja
{
    QString site_url="http://localhost:3000/tilitapahtuma/" +id;
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

void Tilitapahtumat::Tulostus(QNetworkReply *reply)         //tulostaa tiedot
{
       QByteArray response_data=reply->readAll();
       QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
       QJsonArray json_array = json_doc.array();
       foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       tapahtuma+=QString::number(json_obj["maara"].toInt())+" - euroa \rTapahtuma - "+json_obj["paikka"].toString()+"\rAika - "+json_obj["aika"].toString()+"\r";
       }
       ui->txtinfo->setText(tapahtuma);
       reply->deleteLater();
       manager->deleteLater();
}

void Tilitapahtumat::setId(const QString &value)         //haetaan id, tulostaa oikean tilin asioita
{
    id = value;
    info();
}


void Tilitapahtumat::on_btnTakaisinValikkoon_clicked()          //ja vie takaisin valikkoon
{
    tapahtuma = "";
    ui->txtinfo->setText("");
    this->close();
}
