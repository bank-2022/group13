#ifndef VALIKKO_H
#define VALIKKO_H

#include <QWidget>
#include "nosto.h"
#include "saldo.h"
#include "tilitapahtumat.h"


namespace Ui {
class valikko;
}

class valikko : public QWidget
{
    Q_OBJECT

public:
    explicit valikko(QWidget *parent = 0);
    ~valikko();



    void setTiliID(const QString &value);

private slots:

    void on_btnNosto_clicked();

    void on_btnSaldo_clicked();

    void on_btnKirjauduUlos_clicked();

    void tulostainfo(QNetworkReply *reply);

    void haetyyppi(QNetworkReply *reply);


    void on_btnTilitapahtumat_clicked();

    void on_Credit_Debit_Switch_toggled(bool checked);

private:
    void info();
    void info2();
    QString tyyppi;
    Ui::valikko *ui;
    Nosto *objNosto;
    Saldo *objSaldo;
    Tilitapahtumat *objTilitapahtumat;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString TiliID;
    QString tilinumero;
    QString asiakas;
    QString Valinta;
};

#endif // VALIKKO_H
