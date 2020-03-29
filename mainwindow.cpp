#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>
#include<QStandardItemModel>
#include<QTableView>
#include <math.h>
#include <QPlainTextEdit>


int gLength, gLength2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    model = new QStandardItemModel(7, 1, this);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "Input");


    model1 = new QStandardItemModel(7, 1, this);
    ui->tableView_2->setModel(model1);
    model1->setHeaderData(0, Qt::Horizontal, "Output");

    model2 = new QStandardItemModel(7, 1, this);
    ui->tableView_3->setModel(model2);
    model2->setHeaderData(0, Qt::Horizontal, "Input");

    model3 = new QStandardItemModel(10, 1, this);
    ui->tableView_4->setModel(model3);
    model3->setHeaderData(0, Qt::Horizontal, " ");


}




MainWindow::~MainWindow()
{
    delete ui;
}

Set *MainSet;
Set *SecondSet;



/*
void MainWindow::on_pushButton_maxMod_clicked()
{
    int maxMod = MainSet->MaxMod();
    QString smaxMod = QString::number(maxMod);
    ui->label_maxMod->setText("The maximum number by module is: " + smaxMod);
}


void MainWindow::on_pushButton_clear_clicked()
{
    for(int i = 0; i<10; i++)
    {
        model3->setData(model3->index(i, 0), "");
    }
}




void MainWindow::on_pushButton_equal_clicked()
{
    int equal = (*MainSet == *SecondSet);
    if(equal)
        ui->label_equal->setText("YES");
    else
        ui->label_equal->setText("NO");
}

void MainWindow::on_pushButton_close_clicked()
{
    delete MainSet;
    delete SecondSet;
    this->close();
}


*/

//
//
//


void MainWindow::on_check_clicked()
{
    QString checkstr = ui->textEdit_checkEl->toPlainText().trimmed();
    int number = checkstr.toInt();
    if(MainSet->Check(number))
    {
        ui->label_yesno->setText("There is such an element");
    }
    else
    {
        ui->label_yesno->setText("There is no such an element");
    }
}

void MainWindow::on_bulean_clicked()
{
    int bulean = MainSet->Bulean();
    QString sBulean = QString::number(bulean);
    ui->label_bulean->setText("The bulean is: " + sBulean);
}



void MainWindow::on_max_clicked()
{
    int mNeg = MainSet->MaxNegative();
    QString smNeg = QString::number(mNeg);
    if(mNeg == 0)
        ui->label_maxNeg->setText("There are no negative numbers in this set");
    else
        ui->label_maxNeg->setText("The maximum negative number is: " + smNeg);
}

void MainWindow::on_min_clicked()
{
    int mPos = MainSet->MinPositive();
    QString smPos = QString::number(mPos);
    if(mPos == 10000)
        ui->label_minPos->setText("There are no positive numbers in this set");
    else
        ui->label_minPos->setText("The minimum positive number is: " + smPos);
}

void MainWindow::on_add_clicked()
{
    QString s_addNum = ui->textEdit_addEl->toPlainText().trimmed();
    int addNum = s_addNum.toInt();

    MainSet->addElement(addNum);
    *MainSet << model1;
}

void MainWindow::on_substract_clicked()
{
    QString s_subNum = ui->textEdit_subEl->toPlainText().trimmed();
    int subNum = s_subNum.toInt();

    Set *s1 = new Set(MainSet->GetLength()-1);
    s1 = MainSet->subElement(subNum);
    MainSet = s1;
    *MainSet << model1;
    MainSet->clear(model1);
}

void MainWindow::on_union_2_clicked()
{
    for(int i = 0; i<10; i++)
    {
        model3->setData(model3->index(i, 0), "");
    }
    int length = MainSet->GetLength() + SecondSet->GetLength();
    Set *unSet = new Set(length);
    *unSet = *MainSet + *SecondSet;
    *unSet<<model3;
    delete unSet;
}

void MainWindow::on_set1_clicked()
{
    QString len = ui->textEdit_length->toPlainText().trimmed();
    gLength = len.toInt();

    Set *res = new Set(gLength);
    *res >> model;
    MainSet = new Set(res->Get_Set(), gLength);
    *res << model1;
    delete res;
}

void MainWindow::on_set2_clicked()
{
    QString len = ui->textEdit_length1->toPlainText().trimmed();
    gLength2 = len.toInt();

    Set *res = new Set(gLength2);
    *res >> model2;
    SecondSet = new Set(res->Get_Set(), gLength2);
    delete res;
}

void MainWindow::on_crossing_clicked()
{
    for(int i = 0; i<10; i++)
    {
        model3->setData(model3->index(i, 0), "");
    }
    Set *inSet = new Set(MainSet->GetLength());
    *inSet = *MainSet - *SecondSet;
    *inSet<<model3;
    delete inSet;
}

void MainWindow::on_show_Memo1_clicked()
{
    (ui->plainTextEdit)<< *MainSet;
}

void MainWindow::on_pushButton_2_clicked()
{
    *SecondSet<<(ui->plainTextEdit);
}
