#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objvalikko=new valikko;
    TiliID = "";
    Korttinumero = "";
    PINvaarin = 0;
    cleani = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
    ui=nullptr;
    delete objvalikko;
    objvalikko=nullptr;
}



void MainWindow::on_btnLogin_clicked()
{
        QJsonObject json;   //JSON objekti + data
        json.insert("Korttinumero",ui->lineEditKorttinumero->text());
        json.insert("PIN",ui->lineEditPIN->text());
        QString site_url="http://localhost:3000/kirjautuminen";
        QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        loginManager = new QNetworkAccessManager(this);

        connect(loginManager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(loginSlot(QNetworkReply*)));

        reply = loginManager->post(request, QJsonDocument(json).toJson());

}


void MainWindow::loginSlot(QNetworkReply *reply)
{

       QByteArray response_data=reply->readAll();
       QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
       QJsonArray json_array = json_doc.array();

       foreach (const QJsonValue &value, json_array)
            {
              QJsonObject json_obj = value.toObject();
              TiliID+=QString::number(json_obj["asiakas_idAsiakas"].toInt());
            }


        if(TiliID > 0){
            qDebug()<<"Tunnus oikein...Tervetuloa!";
            objvalikko->setTiliID(TiliID);
            objvalikko->show();

            //Nollataan
            cleani=0;
            PINvaarin = 0;
            ui->txtKertoja->setText("");
            TiliID = "";
            ui->lineEditPIN->setText("");
            ui->lineEditKorttinumero->setText("");
            PIN="";
            Korttinumero="";


                      }
        else          {
            ui->txtKertoja->setText("Tunnus ja/tai salasana väärin");
            PINvaarin++;
            //Nollailua
            cleani=0;
            ui->lineEditPIN->setText("");
            ui->lineEditKorttinumero->setText("");
            qDebug()<<"tunnus ja/tai salasana väärin";
            PIN="";
            Korttinumero="";

                      }

}


void MainWindow::on_btn1_clicked()
{
    Korttinumero = "1";
    contactor(Korttinumero);
}

void MainWindow::on_bt2_clicked()
{
    Korttinumero = "2";
    contactor(Korttinumero);

}

void MainWindow::on_btn3_clicked()
{
    Korttinumero = "3";
    contactor(Korttinumero);

}

void MainWindow::on_btn4_clicked()
{
    Korttinumero = "4";
    contactor(Korttinumero);

}

void MainWindow::on_btn5_clicked()
{
    Korttinumero = "5";
    contactor(Korttinumero);

}


void MainWindow::on_btn6_clicked()
{
    Korttinumero = "6";
    contactor(Korttinumero);

}

void MainWindow::on_btn7_clicked()
{
    Korttinumero = "7";
    contactor(Korttinumero);
}

void MainWindow::on_btn8_clicked()
{
    Korttinumero = "8";
    contactor(Korttinumero);

}

void MainWindow::on_btn9_clicked()
{
    Korttinumero = "9";
    contactor(Korttinumero);

}

void MainWindow::on_btn0_clicked()
{
    Korttinumero = "0";
    contactor(Korttinumero);


}

void MainWindow::contactor(const QString)
{
    Korttinumero.append(Korttinumero);
    if(cleani == 0) {
        ui->lineEditKorttinumero->setText(Korttinumero);
    } else if (cleani == 1) {
        PIN.append(Korttinumero);
        ui->lineEditPIN->setText(PIN);
    }

}

void MainWindow::on_btntyhjennys_clicked()
{
    if(cleani == 0) {
        Tommone = Korttinumero.length();
        Korttinumero.remove(Tommone-1,1);
        ui->lineEditKorttinumero->setText(Korttinumero);
    } else if (cleani == 1) {
        Tommone = PIN.length();
        PIN.remove(Tommone-1,1);
        ui->lineEditPIN->setText(PIN);
    }
}

void MainWindow::on_btnOK_clicked()
{
    cleani =cleani+1;
    if(cleani ==2) {
        cleani = 0;
        PIN = "";
        Korttinumero= "";
                  }
}
