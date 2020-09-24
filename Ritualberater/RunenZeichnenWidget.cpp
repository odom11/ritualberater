#include "RunenZeichnenWidget.h"

const std::string PROBABILITY_LAYOUT_SHEET = "background-color: white";
RunenZeichnenWidget::RunenZeichnenWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setupLayout();
}

RunenZeichnenWidget::~RunenZeichnenWidget()
{
}

void RunenZeichnenWidget::setupLayout()
{
	ui.frame->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
	ui.headline->setText("Runen zeichnen");
	ui.headline->setStyleSheet("font-weight: bold");
	ui.successLabel->setText("Erfolgswahrscheinlichkeit");
	ui.betterSuccessLabel->setText("Wahrscheinlichkeit guter Erfolg");
	ui.bestSuccessLabel->setText(QString::fromUtf8("Wahrscheinlichkeit sehr guter Erfolg"));
	ui.diameterLabel->setText("Runendurchmesser [cm]");

	ui.successProb->setStyleSheet(QString::fromStdString(PROBABILITY_LAYOUT_SHEET));
	ui.betterSuccessProb->setStyleSheet(QString::fromStdString(PROBABILITY_LAYOUT_SHEET));
	ui.bestSuccessProb->setStyleSheet(QString::fromStdString(PROBABILITY_LAYOUT_SHEET));
}

