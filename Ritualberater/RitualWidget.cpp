#include "RitualWidget.h"

RitualWidget::RitualWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initializeLayout();
}

RitualWidget::~RitualWidget()
{
}

void RitualWidget::initializeLayout()
{
	ui.frame->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
	ui.headline->setText("Ritual");
	ui.headline->setStyleSheet("font-weight: bold");

	ui.emLabel->setText("Erfolgsmodifikator (Runenzeichnen)");
	ui.quelleLabel->setText("Ritualquelle");
	ui.resultLabel->setText("Empfohlene Zusammensetzung");
	ui.resultLabel->setStyleSheet("font-weight: bold");

	ui.strategieLabel->setText("Optimierungsstrategie");
}

