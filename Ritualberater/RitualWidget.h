#pragma once

#include <QWidget>
#include "ui_RitualWidget.h"

class RitualWidget : public QWidget
{
	Q_OBJECT

public:
	RitualWidget(QWidget *parent = Q_NULLPTR);
	~RitualWidget();

private:
	void initializeLayout();
	Ui::RitualWidget ui;
};
