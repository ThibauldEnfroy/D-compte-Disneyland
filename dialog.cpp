#include "dialog.h"
#include "ui_dialog.h"
#include <QSettings>

QSettings settings1("ActonCorp", "Disney");

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, settings1.value("Date enregistrée 1").toString());
    ui->tabWidget->setTabText(1, settings1.value("Date enregistrée 2").toString());
    ui->tabWidget->setTabText(2, settings1.value("Date enregistrée 3").toString());
    ui->plainTextEdit->setPlainText(settings1.value("Détail/Données date 1").toString());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString donnees1 = ui->plainTextEdit->toPlainText();
    settings1.setValue("Détail/Données date 1", donnees1);
}

void Dialog::on_pushButton_2_clicked()
{
    QString donnees2 = ui->plainTextEdit_2->toPlainText();
    settings1.setValue("Détail/Données date 2", donnees2);
}

void Dialog::on_pushButton_3_clicked()
{
    QString donnees3 = ui->plainTextEdit_3->toPlainText();
    settings1.setValue("Détail/Données date 3", donnees3);
}
