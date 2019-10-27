#include "raschet.h"
#include "ui_raschet.h"
#include <QDebug>

Raschet::Raschet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Raschet)
{
    ui->setupUi(this);
}

Raschet::~Raschet()
{
    delete ui;
}


void Raschet::on_start_clicked()
{
    double summPerev=ui->summa_perevoda->value();
    double Vat=summPerev/1.2*0.2;
    ui->VAT->setValue(Vat);
    double summWithoutVat=summPerev-Vat;
    ui->summ_without_vat->setValue(summWithoutVat);
    double kommis=summWithoutVat/1.1*0.1;
    ui->kommis_eLama->setValue(kommis);
    double fbTransfer=summWithoutVat-kommis;
    ui->money_transfer->setValue(fbTransfer);
    double percent=0;
    if(ui->reward_percent->value())
        percent = ui->reward_percent->value()/100.0;
    else if(summPerev>=30000 && summPerev<=199999)
        percent=0.03;
    else if (summPerev>=200000 && summPerev<=999999)
        percent=0.04;
    else if (summPerev>=1000000)
        percent=0.05;
    ui->reward_percent->setValue(percent*100);
    double reward=fbTransfer*percent;
    ui->reward_summ->setValue(reward);
    double kommisActual=kommis-reward;
    ui->kommis_actual->setValue(kommisActual);
}
