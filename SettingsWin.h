#pragma once

#include <QWidget>
#include "ui_SettingsWin.h"
#include "settingsAddUsersForm.h"

class SettingsWin : public QWidget
{
	Q_OBJECT

public:
	SettingsWin(QWidget *parent = Q_NULLPTR);
	~SettingsWin();

private:
	Ui::SettingsWin ui;
	settingsAddUsersForm addUsers;
};
