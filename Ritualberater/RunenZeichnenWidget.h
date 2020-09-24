#pragma once

#include "ui_RunenZeichnenWidget.h"

class RunenZeichnenWidget : public QWidget
{
	Q_OBJECT

public:
	RunenZeichnenWidget(QWidget *parent = Q_NULLPTR);
	~RunenZeichnenWidget();

private:
	void setupLayout();
	Ui::RunenZeichnenWidget ui;
};
