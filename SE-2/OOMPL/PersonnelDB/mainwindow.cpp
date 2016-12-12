#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "qlongvalidator.h"
#include <QInputDialog>
#include <fstream>
#include "record.h"
#include <QDebug>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    v = new QVector<Person>();
    ui->inHeight->setValidator(new QIntValidator(0, 250));
    ui->inWeight->setValidator(new QIntValidator(0, 150));
    ui->inPhNo->setValidator(new QLongValidator());
    ui->inInsPNum->setValidator(new QIntValidator());
    ui->inDriveLNum->setValidator(new QIntValidator());

    fstream inFile("data.txt", ios_base::in);
    int idx = 0;
    if(inFile.is_open()) {
        do {
            Record *r = readFile(inFile);
            if(r != NULL && r->drivingLNumber != 0) {
                Person *p = new Person();
                p->setData(*r);
                v->push_back(*p);
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                updateTable(idx++);
            }
            delete r;
            inFile.seekg(1, ios_base::cur);
        } while(inFile.peek() != EOF);
    }

    dataFile.open("data.txt", std::ios_base::in | std::ios_base::out | std::ios_base::app);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete v;
}

int foundIndex = 0;

void MainWindow::on_btnAccept_clicked()
{

    if(ui->inName->text().isEmpty() ||
            ui->inDOB->text().isEmpty() ||
            ui->inHeight->text().isEmpty() ||
            ui->inWeight->text().isEmpty() ||
            ui->inInsPNum->text().isEmpty() ||
            ui->inAddress->toPlainText().isEmpty() ||
            ui->inPhNo->text().isEmpty() ||
            ui->inDriveLNum->text().isEmpty()) {
        QMessageBox::information(this, "Error", "Please enter all data.");
        return;

    }

    if(ui->inPhNo->text().length() < 10) {
        QMessageBox::information(this, "Error", "Invalid phone number");
        return;
    }

    Person *p = new Person();

    QString bloodGrp;
    if(ui->in_rd_a->isChecked()) {
        bloodGrp = "A";
    } else if(ui->in_rd_b->isChecked()) {
        bloodGrp = "B";
    } else if(ui->in_rd_ab->isChecked()) {
        bloodGrp = "AB";
    } else if(ui->in_rd_o) {
        bloodGrp = "O";
    }

    bloodGrp.append((ui->in_rd_pve->isChecked() ? "+" : "-"));

    p->setData(ui->inName->text(),
               ui->inDOB->text(),
               bloodGrp,
               ui->inHeight->text().toInt(),
               ui->inWeight->text().toFloat(),
               ui->inInsPNum->text().toInt(),
               ui->inAddress->toPlainText(),
               ui->inPhNo->text().toLong(),
               ui->inDriveLNum->text().toFloat());

    v->push_back(*p);
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    updateTable(v->size() - 1);
    //for(int i = 0; i < 9; i++)
    //ui->tableWidget->item(foundIndex, i)->setBackground(QBrush(QColor(255, 255, 255, 255)));

    ui->inName->clear();
    ui->inDOB->setDate(QDate(2000, 1, 1));
    ui->inHeight->clear();
    ui->inWeight->clear();
    ui->inInsPNum->clear();
    Record *r = p->toRecord();
    writeFile(dataFile, *r);
}

void MainWindow::updateTable(int index) {
    ui->tableWidget->setItem(index, 0, new QTableWidgetItem(v->at(index).name));
    ui->tableWidget->setItem(index, 1, new QTableWidgetItem(v->at(index).dob));
    ui->tableWidget->setItem(index, 2, new QTableWidgetItem(v->at(index).bloodGrp));
    ui->tableWidget->setItem(index, 3, new QTableWidgetItem(QString::number(v->at(index).height)));
    ui->tableWidget->setItem(index, 4, new QTableWidgetItem(QString::number(v->at(index).weight)));
    ui->tableWidget->setItem(index, 5, new QTableWidgetItem(QString::number(v->at(index).insPNumber)));
    ui->tableWidget->setItem(index, 6, new QTableWidgetItem(v->at(index).address));
    ui->tableWidget->setItem(index, 7, new QTableWidgetItem(QString::number(v->at(index).phoneNo)));
    ui->tableWidget->setItem(index, 8, new QTableWidgetItem(QString::number(v->at(index).drivingLNumber)));
}



void MainWindow::on_btnSearch_clicked()
{

    int driveLNumber = QInputDialog::getInt(this, "Search", "Enter driving license number:");

    bool found = false;
    // int driveLNumber = ui->sDriveLNumber->text().toInt();
    for(int i = 0; i < v->size(); i++) {
        if(v->at(i).drivingLNumber == driveLNumber) {
            foundIndex = i;
            found = true;
            break;
        }
    }

    if(found) {
        QString s = "Record with Driving License No: " + QString::number(driveLNumber) + " found.";
        QMessageBox::information(this, "Record Found", s);

        for(int i = 0; i < 9; i++)
            ui->tableWidget->item(foundIndex, i)->setBackground(QBrush(QColor(255, 255, 0, 150)));
        ui->btnDelete->setEnabled(true);

    }
}

int modifyingIndex = 0;
void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    int row = item->row();
    modifyingIndex = row;
    ui->inName->setText(v->at(row).name);
    ui->inDOB->setDate(QDate::fromString(v->at(row).dob, "d MMM yyyy"));
    ui->inHeight->setText(QString::number(v->at(row).height));
    ui->inWeight->setText(QString::number(v->at(row).weight));
    ui->inInsPNum->setText(QString::number(v->at(row).insPNumber));
    ui->inAddress->setText(v->at(row).address);
    ui->inPhNo->setText(QString::number(v->at(row).phoneNo));
    ui->inDriveLNum->setText(QString::number(v->at(row).drivingLNumber));
    ui->btnModify->setEnabled(true);
    ui->btnAccept->setDisabled(true);
    if(v->at(row).bloodGrp.endsWith("+")) {
        ui->in_rd_pve->setChecked(true);
    } else {
        ui->in_rd_nve->setChecked(true);
    }
    QString bg = v->at(row).bloodGrp;
    if(bg.contains("AB")) {
        ui->in_rd_ab->setChecked(true);
    } else if(bg.contains("O")) {
        ui->in_rd_o->setChecked(true);
    } else if(bg.contains("A")) {
        ui->in_rd_a->setChecked(true);
    } else {
        ui->in_rd_b->setChecked(true);
    }

    for(int i = 0; i < 9; i++)
        ui->tableWidget->item(foundIndex, i)->setBackground(QBrush(QColor(255, 255, 255, 255)));
}

void MainWindow::on_btnModify_clicked()
{
    Person *p = v->begin() + modifyingIndex;
    QString bloodGrp;
    if(ui->in_rd_a->isChecked()) {
        bloodGrp = "A";
    } else if(ui->in_rd_b->isChecked()) {
        bloodGrp = "B";
    } else if(ui->in_rd_ab->isChecked()) {
        bloodGrp = "AB";
    } else if(ui->in_rd_o) {
        bloodGrp = "O";
    }

    bloodGrp.append((ui->in_rd_pve->isChecked() ? "+" : "-"));

    p->setData(ui->inName->text(),
               ui->inDOB->text(),
               bloodGrp,
               ui->inHeight->text().toInt(),
               ui->inWeight->text().toFloat(),
               ui->inInsPNum->text().toInt(),
               ui->inAddress->toPlainText(),
               ui->inPhNo->text().toLong(),
               ui->inDriveLNum->text().toFloat());
    updateTable(modifyingIndex);
    ui->btnModify->setDisabled(true);
    ui->btnAccept->setEnabled(true);
    updateFile();

    for(int i = 0; i < 9; i++)
        ui->tableWidget->item(foundIndex, i)->setBackground(QBrush(QColor(255, 255, 255, 255)));
}

void MainWindow::on_btnDelete_clicked()
{
    int toDel = foundIndex;

    v->remove(toDel);
    ui->tableWidget->removeRow(toDel);
    updateFile();

    ui->btnDelete->setEnabled(false);
}

Record* MainWindow::readFile(fstream &inFile) {
    Record *r = new Record();
    inFile.getline(r->name, 50);
    inFile.getline(r->dob, 15);
    inFile.getline(r->bloodGrp, 10);
    inFile >> r->height;
    inFile >> r->weight;
    inFile >> r->insPNumber;
    inFile.getline(r->address, 100);
    inFile >> r->address;
    inFile >> r->phoneNo;
    inFile >> r->drivingLNumber;

    if(r->drivingLNumber == 0) {
        return NULL;
    }

    return r;
}

void MainWindow::writeFile(fstream &outFile, Record &r) {

    outFile << r.name           << "\n";
    outFile << r.dob            << "\n";
    outFile << r.bloodGrp       << "\n";
    outFile << r.height         << "\n";
    outFile << r.weight         << "\n";
    outFile << r.insPNumber     << "\n";
    outFile << r.address        << "\n";
    outFile << r.phoneNo        << "\n";
    outFile << r.drivingLNumber << "\n";
}

void MainWindow::updateFile() {
    fstream tempFile("temp.txt", ios_base::out | ios_base::app | ios_base::in);
    for(QVector<Person>::iterator i = v->begin(); i != v->end(); i++) {
        Record *r = i->toRecord();
        qDebug() << r->name;
        writeFile(tempFile, *r);
    }

    tempFile.close();
    std::remove("data.txt");
    std::rename("temp.txt", "data.txt");
}
