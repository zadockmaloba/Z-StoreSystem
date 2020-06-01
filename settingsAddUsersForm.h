#pragma once

#include <QWidget>
#include "ui_set-AddUsers.h"

class settingsAddUsersForm : public QWidget
{
	Q_OBJECT

public:
	settingsAddUsersForm(QWidget *parent = Q_NULLPTR);
	~settingsAddUsersForm();

private:
	Ui::Form ui;
};
