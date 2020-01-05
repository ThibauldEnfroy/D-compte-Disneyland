#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDate>
#include <QSettings>
#include <QGraphicsOpacityEffect>

QSettings settings("ActonCorp", "Disney");
QString save("Enregistrer la date");
QString supp("Supprimer la date");
int largeur(570);
QDate dateAujourdhui = QDate::currentDate();
QString derniereDate;
QString agrandir ("Agrandir le calendrier"), retrecir ("Rétrécir le calendrier");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //transformation de la derniereDate en date
    derniereDate = settings.value("Date enregistrée 1").toString();
    QDate derniereDateD = QDate::fromString(derniereDate,"dd.MM.yyyy");

    //Définition des variables QDateTime
    QDateTime now = QDateTime::currentDateTime();
    QDateTime disney(QDate(derniereDateD), QTime(8, 30));

    //nombre de secondes entre les deux dates
    qint64 nombreSeconde = now.secsTo(disney);

    //Conversion des secondes en minutes, heures et jours
    qint64 nombreMinute = nombreSeconde / 60;
    qint64 nombreHeure = nombreMinute / 60;
    qint64 nombreJour = nombreHeure / 24;
    nombreSeconde = (nombreSeconde % 60);
    nombreMinute = (nombreMinute % 60);
    nombreHeure = (nombreHeure % 24);

    //Affichage de l'UI
    ui->setupUi(this);
    ui->jour->setText(QString::number(nombreJour));
    ui->heure->setText(QString::number(nombreHeure));
    ui->minute->setText(QString::number(nombreMinute));
    ui->calendarWidget->setSelectedDate(derniereDateD);
    ui->date->setText(derniereDate);
    QGraphicsOpacityEffect *_effect = new QGraphicsOpacityEffect;
    _effect->setOpacity(0.5);
    ui->widget_fond->setGraphicsEffect(_effect);
    ui->bDate1->setText(save);
    ui->bDate2->setText(save);
    ui->bDate3->setText(save);

    //Fixer la largeur de la fenêtre
    MainWindow::setFixedSize(largeur,315);

    //affichage labels en dessous calendrier
    QString dateS = ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    if (ui->bDate1->text() == save)
    {
        settings.setValue("Date enregistrée 1", dateS);
    }
    if (ui->bDate1->text() == supp)
    {
        settings.setValue("Date enregistrée 1", "");
    }
    ui->date1->setText(settings.value("Date enregistrée 1").toString());
    rafraichissement1();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    //Définition des variables QDateTime
    QDateTime now = QDateTime::currentDateTime();
    QDateTime disney(QDate(date), QTime(8, 30));

    //nombre de secondes entre les deux dates
    qint64 nombreSeconde = now.secsTo(disney);

    //Conversion des secondes en minutes, heures et jours
    qint64 nombreMinute = nombreSeconde / 60;
    qint64 nombreHeure = nombreMinute / 60;
    qint64 nombreJour = nombreHeure / 24;
    nombreSeconde = (nombreSeconde % 60);
    nombreMinute = (nombreMinute % 60);
    nombreHeure = (nombreHeure % 24);

    //Affichage du label
    ui->jour->setText(QString::number(nombreJour));
    ui->heure->setText(QString::number(nombreHeure));
    ui->minute->setText(QString::number(nombreMinute));
    ui->date->setText(date.toString("dd.MM.yyyy"));
}

void MainWindow::on_pushButton_clicked()
{
    //Si la largeur est pleine, la définir en petite
    if (largeur == 1000)
    {
        largeur = 570;
        ui->pushButton->setText(">");
    }

    //Si la largeur n'est pas pleine, la définir en pleine
    else {
        largeur = 1000;
        ui->pushButton->setText("<");
    }

    //Fixer la largeur de la fenêtre
    MainWindow::setFixedSize(largeur,315);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    QString photo;
    if (arg1 == 0)
    {
        photo = ":/ressources/Phantom_Manor.jpg";
    }
    else
    {
        photo = ":/ressources/Disney.jpg";
    }
    QPixmap pixmap(photo);
    ui->label->setPixmap(pixmap);
}

void MainWindow::rafraichissement1()
{
    ui->date1->setText(settings.value("Date enregistrée 1").toString());
    ui->date2->setText(settings.value("Date enregistrée 2").toString());
    ui->date3->setText(settings.value("Date enregistrée 3").toString());

    if (settings.value("Date enregistrée 1").toString() == "")
    {
        ui->bDate1->setText(save);
    }
    else
    {
        ui->bDate1->setText(supp);
    }
    if (settings.value("Date enregistrée 2").toString() == "")
    {
        ui->bDate2->setText(save);
    }
    else
    {
        ui->bDate2->setText(supp);
    }
    if (settings.value("Date enregistrée 3").toString() == "")
    {
        ui->bDate3->setText(save);
    }
    else
    {
        ui->bDate3->setText(supp);
    }
}

void MainWindow::on_bDate1_clicked()
{
    QString date = ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    if (ui->bDate1->text() == save)
    {
        settings.setValue("Date enregistrée 1", date);
    }
    if (ui->bDate1->text() == supp)
    {
        settings.setValue("Date enregistrée 1", "");
    }
    ui->date1->setText(settings.value("Date enregistrée 1").toString());
    rafraichissement1();
}

void MainWindow::on_bDate2_clicked()
{
    QString date = ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    if (ui->bDate2->text() == save)
    {
        settings.setValue("Date enregistrée 2", date);
    }
    if (ui->bDate2->text() == supp)
    {
        settings.setValue("Date enregistrée 2", "");
    }
    ui->date2->setText(settings.value("Date enregistrée 2").toString());
    rafraichissement1();
}

void MainWindow::on_bDate3_clicked()
{
    QString date = ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    if (ui->bDate3->text() == save)
    {
        settings.setValue("Date enregistrée 3", date);
    }
    if (ui->bDate3->text() == supp)
    {
        settings.setValue("Date enregistrée 3", "");
    }
    ui->date3->setText(settings.value("Date enregistrée 3").toString());
    rafraichissement1();
}

void MainWindow::on_date1_clicked()
{
    QString dateString = ui->date1->text();
    QDate date = QDate::fromString(dateString,"dd.MM.yyyy");

    //Définition des variables QDateTime
    QDateTime now = QDateTime::currentDateTime();
    QDateTime disney(QDate(date), QTime(8, 30));

    //nombre de secondes entre les deux dates
    qint64 nombreSeconde = now.secsTo(disney);

    //Conversion des secondes en minutes, heures et jours
    qint64 nombreMinute = nombreSeconde / 60;
    qint64 nombreHeure = nombreMinute / 60;
    qint64 nombreJour = nombreHeure / 24;
    nombreSeconde = (nombreSeconde % 60);
    nombreMinute = (nombreMinute % 60);
    nombreHeure = (nombreHeure % 24);

    //Affichage du label
    ui->jour->setText(QString::number(nombreJour));
    ui->heure->setText(QString::number(nombreHeure));
    ui->minute->setText(QString::number(nombreMinute));
    ui->date->setText(date.toString("dd.MM.yyyy"));
    ui->calendarWidget->setSelectedDate(date);
}

void MainWindow::on_date2_clicked()
{
    QString dateString = ui->date2->text();
    QDate date = QDate::fromString(dateString,"dd.MM.yyyy");

    //Définition des variables QDateTime
    QDateTime now = QDateTime::currentDateTime();
    QDateTime disney(QDate(date), QTime(8, 30));

    //nombre de secondes entre les deux dates
    qint64 nombreSeconde = now.secsTo(disney);

    //Conversion des secondes en minutes, heures et jours
    qint64 nombreMinute = nombreSeconde / 60;
    qint64 nombreHeure = nombreMinute / 60;
    qint64 nombreJour = nombreHeure / 24;
    nombreSeconde = (nombreSeconde % 60);
    nombreMinute = (nombreMinute % 60);
    nombreHeure = (nombreHeure % 24);

    //Affichage du label
    ui->jour->setText(QString::number(nombreJour));
    ui->heure->setText(QString::number(nombreHeure));
    ui->minute->setText(QString::number(nombreMinute));
    ui->date->setText(date.toString("dd.MM.yyyy"));
    ui->calendarWidget->setSelectedDate(date);
}

void MainWindow::on_date3_clicked()
{
    QString dateString = ui->date3->text();
    QDate date = QDate::fromString(dateString,"dd.MM.yyyy");

    //Définition des variables QDateTime
    QDateTime now = QDateTime::currentDateTime();
    QDateTime disney(QDate(date), QTime(8, 30));

    //nombre de secondes entre les deux dates
    qint64 nombreSeconde = now.secsTo(disney);

    //Conversion des secondes en minutes, heures et jours
    qint64 nombreMinute = nombreSeconde / 60;
    qint64 nombreHeure = nombreMinute / 60;
    qint64 nombreJour = nombreHeure / 24;
    nombreSeconde = (nombreSeconde % 60);
    nombreMinute = (nombreMinute % 60);
    nombreHeure = (nombreHeure % 24);

    //Affichage du label
    ui->jour->setText(QString::number(nombreJour));
    ui->heure->setText(QString::number(nombreHeure));
    ui->minute->setText(QString::number(nombreMinute));
    ui->date->setText(date.toString("dd.MM.yyyy"));
    ui->calendarWidget->setSelectedDate(date);
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog fenetre;
    fenetre.exec();
}
