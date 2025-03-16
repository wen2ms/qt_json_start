#include "mainwindow.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {    
    QPushButton* write_json_btn = new QPushButton("Write Json", this);
    
    QPushButton* read_json_btn = new QPushButton("Read Json", this);
    
    write_json_btn->move(100, 200);
    
    read_json_btn->move(400, 200);
    
    connect(write_json_btn, &QPushButton::clicked, this, &MainWindow::write_json);
    
    connect(read_json_btn, &QPushButton::clicked, this, &MainWindow::read_json);
    
    resize(600, 400);
    
    QJsonDocument json_doc;
    
    if (json_doc.isEmpty()) {
        qDebug() << "Json document is empty...";
    }
    if (json_doc.isNull()) {
        qDebug() << "Json document is null...";
    }
}

MainWindow::~MainWindow() {}

void MainWindow::write_json() {
    QJsonObject obj;
    
    obj.insert("Name", "Ace");
    obj.insert("Sex", "male");
    obj.insert("Age", 20);
    
    QJsonObject sub_obj;
    
    sub_obj.insert("Father", "Gol.D.Roger");
    sub_obj.insert("Mother", "Portgas.D.Rouge");
    
    QJsonArray json_arry;
    
    json_arry.append("Sabo");
    json_arry.append("Luffy");
    
    sub_obj.insert("Brother", json_arry);
    
    obj.insert("Family", sub_obj);
    obj.insert("IsAlive", false);
    
    QJsonDocument doc(obj);
    
    QByteArray json = doc.toJson();
    
    QString filename = QFileDialog::getExistingDirectory() + "/ace.json";
    
    QFile outfile(filename);
    
    if (!outfile.open(QFile::WriteOnly)) {
        return;
    }
    outfile.write(json);
    
    outfile.close();
}

void MainWindow::read_json() {}
