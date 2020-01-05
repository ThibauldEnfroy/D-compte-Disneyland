#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_bDate1_clicked();

    void on_bDate2_clicked();

    void on_bDate3_clicked();

    void rafraichissement1();

    void on_date1_clicked();

    void on_date2_clicked();

    void on_date3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
