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
    ui->textEdit->clear();
    int a = ui->spinBox->value();
    int b = ui->spinBox_2->value();
    QString znak;

    switch (b) {
    case 1: //Январь
        if(a < 21)
        {
            znak = "Вы Козерог!";
            b = 1;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Водолей!";
            b = 2;
            ui->textEdit->append(znak);
        }
        break;
    case 2: //Февраль
        if(a < 20)
        {
            znak = "Вы Водолей!";
            b = 2;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Рыба!";
            b = 3;
            ui->textEdit->append(znak);
        }
        break;
    case 3: //Март
        if(a < 21)
        {
            znak = "Вы Рыба!";
            b = 3;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Овен!";
            b = 4;
            ui->textEdit->append(znak);
        }
        break;
    case 4: //Апрель
        if(a < 21)
        {
            znak = "Вы Овен!";
            b = 4;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Телец!";
            b = 5;
            ui->textEdit->append(znak);
        }
        break;
    case 5: //Май
        if(a < 22)
        {
            znak = "Вы Телец!";
            b = 5;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Близнецы!";
            b = 6;
            ui->textEdit->append(znak);
        }
        break;
    case 6: //Июнь
        if(a < 22)
        {
            znak = "Вы Близнецы!";
            b = 6;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Рак!";
            b = 7;
            ui->textEdit->append(znak);
        }
        break;
    case 7: //Июль
        if(a < 24)
        {
            znak = "Вы Рак!";
            b = 7;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Лев!";
            b = 8;
            ui->textEdit->append(znak);
        }
        break;
    case 8: //Август
        if(a < 24)
        {
            znak = "Вы Лев!";
            b = 8;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Дева!";
            b = 9;
            ui->textEdit->append(znak);
        }
        break;
    case 9: //Сентябрь
        if(a < 24)
        {
            znak = "Вы Дева!";
            b = 9;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Весы!";
            b = 10;
            ui->textEdit->append(znak);
        }
        break;
    case 10: //Октябрь
        if(a < 24)
        {
            znak = "Вы Весы!";
            b = 10;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Скорпион!";
            b = 11;
            ui->textEdit->append(znak);
        }
        break;
    case 11: //Ноябрь
        if(a < 24)
        {
            znak = "Вы Скорпион!";
            b = 11;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Стрелец!";
            b = 12;
            ui->textEdit->append(znak);
        }
        break;
    case 12: //Декабрь
        if(a < 22)
        {
            znak = "Вы Стрелец!";
            b = 12;
            ui->textEdit->append(znak);
        }
        else
        {
            znak = "Вы Козерог!";
            b = 1;
            ui->textEdit->append(znak);
        }
        break;
    default:
        break;
    }

    int f = 1;
    QSqlQuery query;
    bool g = query.exec("SELECT * FROM horoscope");
    QSqlRecord rec = query.record();
    QString hor = "";
    while (query.next())
    {
        if (b==f)
        {
            hor = query.value(rec.indexOf("2016")).toString();
            ui->textEdit->append(hor);
            break;
        }
        else
        {
            f++;
        }
    }
}
