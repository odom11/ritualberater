#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_Ritualberater.h"

class Ritualberater : public QMainWindow
{
    Q_OBJECT

public:
    Ritualberater(QWidget *parent = Q_NULLPTR);

private:
	void setupRunetree();
    Ui::RitualberaterClass ui;
};
