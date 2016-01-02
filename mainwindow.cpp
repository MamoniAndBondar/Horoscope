#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("mydatabase.sqlite");
    if (!sdb.open())
    {
        qDebug() << "Что-то пошло не так! БД не подключилась!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int a = ui->spinBox->value();
    int b = ui->spinBox_2->value();
    QString znak;

    switch (b) {
    case 1:
        if(a < 21)
        {
            znak = "Вы козерог!";
            b = 1;
        }
        else
        {
            znak = "Вы водолей!";
            b = 2;
        }
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    case 10:

        break;
    case 11:

        break;
    case 12:

        break;
    default:
        break;
    }

     QSqlQuery query;
     //QString str_1 = "SELECT 2016 FROM horoscope WHERE rowid=%1; ";
     QString str_1 = "SELECT * FROM horoscope; ";
     QString str = str_1.arg(b);
     bool g =  query.exec(str);
     QSqlRecord rec = query.record();
     QString vivo = query.value(rec.indexOf("2016")).toString();
     //QString vivo = query.exec(str).toString();
     qDebug() << "number is " << vivo;
     ui->lineEdit->text() = vivo;

    //QSqlQuery query("SELECT 2016 FROM horoscope WHERE rowid=%1;");
}
