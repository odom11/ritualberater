#pragma once

#include <QWidget>
#include "ui_CharacterWidget.h"

class CharacterWidget : public QWidget
{
	Q_OBJECT

public:
	CharacterWidget(QWidget *parent = Q_NULLPTR);
	~CharacterWidget();

private:
	void initializeLayout();
	Ui::CharacterWidget ui;
};
