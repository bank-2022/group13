#ifndef saldo_H
#define saldo_H


#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>


namespace Ui {
class Saldo;
}

class Saldo : public QWidget
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = 0);
    ~Saldo();

    void setId(const QString &value);

    void setTyyppi(const QString &value);

private slots:
    void on_BtnPaluuValikkoon_clicked();
    void Tulostus(QNetworkReply *reply);
    void info();
private:

    Ui::Saldo *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString saldo;
    QString id;
    QString Tyyppi;
};

#endif // Saldo_H
