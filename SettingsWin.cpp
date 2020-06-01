#include "SettingsWin.h"

SettingsWin::SettingsWin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	addUsers.setParent(ui.settingsDisplayWidget);
}

SettingsWin::~SettingsWin()
{
}
