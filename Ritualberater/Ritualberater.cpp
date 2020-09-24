#include "Ritualberater.h"
#include <QFileSystemModel>
#include <QDebug>
#include <QStandardPaths>

#include "RuneTreeModel.h"

Ritualberater::Ritualberater(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setupRunetree();
}

void Ritualberater::setupRunetree()
{
    QString home = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QFile file(home + "/source/repos/Ritualberater/Ritualberater/Text.txt");
    file.open(QIODevice::ReadOnly);
    QString data = file.readAll();
    qDebug() << "foobar" << data;
    RuneTreeModel* model = new RuneTreeModel(data);
    file.close();
    //QFileSystemModel* filesystemModel = new QFileSystemModel();
    //filesystemModel->setRootPath("c:");
    //ui.treeView->setModel(runeTreeModel.get());
    ui.treeView->setModel(model);
    ui.treeView->show();
}

