#include "nosto.h"
#include "ui_nosto.h"

Nosto::Nosto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nosto)
{
    ui->setupUi(this);


}

Nosto::~Nosto()
{
    delete ui;

}

void Nosto::setId(const QString &value)  //haetaan ja piiloitetaan id
{
    id = value;
    ui->label_TiliID->setText(id);
}

void Nosto::setTyyppi(const QString &value) //credit tyyppi valinta myöhemmälle
{
    tyyppi = value;
}


void Nosto::nosta(QNetworkReply *reply)  //kertoo menikö nosto läpi vai ei
{
    QByteArray response_data=reply->readAll();
       if(response_data=="false"){
           qDebug()<<"Nosto epäonnistui";
           ui->labelsuccees->setText("Kate ei riitä");
       }
       else if(response_data=="true") {

           qDebug()<<"siirto läpi";
           ui->labelsuccees->setText("Nosto onnistui");

       }
}

void Nosto::on_btn20_clicked() //btn ja luku kertoo nostettavan summan
{

  maara = "20";
  ui->lineEditNostettavaSumma->setText(maara);

}

void Nosto::on_btn40_clicked()
{
  maara = "50";
  ui->lineEditNostettavaSumma->setText(maara);

}

void Nosto::on_btn60_clicked()
{
  maara = "60";
  ui->lineEditNostettavaSumma->setText(maara);

}

void Nosto::on_btn80_clicked()
{
  maara = "80";
  ui->lineEditNostettavaSumma->setText(maara);

}

void Nosto::on_btn100_clicked()
{
    maara = "100";
    ui->lineEditNostettavaSumma->setText(maara);
}



void Nosto::on_btnNosta_clicked()
{

      ui->lineEditNostettavaSumma->text();
      qDebug() << "Haluttu määrä "+ maara;
      qDebug() << "Tilin tyyppi: saldo= "+tyyppi;

      if(tyyppi == "0") {                   //saldon nosto

          QJsonObject json;
          json.insert("id1",ui->label_TiliID->text());
          json.insert("summa",ui->lineEditNostettavaSumma->text());
          QString site_url="http://localhost:3000/nosto/";
          QString credentials="newAdmin:newPass";
          QNetworkRequest request((site_url));
          request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
          QByteArray data = credentials.toLocal8Bit().toBase64();
          QString headerData = "Basic " + data;
          request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
          manager = new QNetworkAccessManager(this);
          connect(manager, SIGNAL(finished (QNetworkReply*)),
          this, SLOT(nosta(QNetworkReply*)));
          reply = manager->post(request, QJsonDocument(json).toJson());

                         }
}

void Nosto::on_btnTakaisin_clicked()   //bäk to valikko ja nollaus
{
    tyyppi = "";
    Summa = "";
    ui->labelsuccees->setText("");
    ui->lineEditNostettavaSumma->setText("");
    this->close();
}




void Nosto::on_btn1_clicked()
{
    Number = "1";
    contactor(Number);
}

void Nosto::on_btn2_clicked()
{
    Number = "2";
    contactor(Number);
}

void Nosto::on_btn3_clicked()
{
    Number = "3";
    contactor(Number);
}

void Nosto::on_btn4_clicked()
{
    Number = "4";
    contactor(Number);
}

void Nosto::on_btn5_clicked()
{
    Number = "5";
    contactor(Number);
}

void Nosto::on_btn6_clicked()
{
    Number = "6";
    contactor(Number);
}

void Nosto::on_btn7_clicked()
{
    Number = "7";
    contactor(Number);
}

void Nosto::on_btn8_clicked()
{
    Number = "8";
    contactor(Number);
}

void Nosto::on_btn9_clicked()
{
    Number = "9";
    contactor(Number);
}

void Nosto::on_btn0_clicked()
{
    Number = "0";
    contactor(Number);
}

void Nosto::on_btnTyhjennys_clicked()
{
    Tommone = Summa.length();
    Summa.remove(Tommone-1,1);
    ui->lineEditNostettavaSumma->setText(Summa);
}

void Nosto::contactor(const QString)
{
    Summa.append(Number);
    ui->lineEditNostettavaSumma->setText(Summa);
}
