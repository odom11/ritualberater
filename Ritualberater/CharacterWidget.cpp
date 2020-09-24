#include "CharacterWidget.h"

CharacterWidget::CharacterWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initializeLayout();
}

CharacterWidget::~CharacterWidget()
{
}

void CharacterWidget::initializeLayout()
{
	ui.frame->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
	ui.heading->setText("Charakter");
	ui.heading->setStyleSheet("font-weight: bold");

	ui.geistWissLabel->setText("Geisteswissenschaften");
	ui.weltWissLabel->setText("weltliche Wissenschaften");
	ui.ritualSpezialisierungLabel->setText("Ritualspezialisierung (toCome)");
	ui.runenZeichnenLabel->setText("Runen zeichnen");
	ui.willeLabel->setText("Willenskraft");
}

