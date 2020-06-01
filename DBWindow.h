#pragma once

#include <QWidget>
#include "ui_DBWindow.h"

class DBWindow : public QWidget
{
	Q_OBJECT

public:
	DBWindow(QWidget *parent = Q_NULLPTR);
	~DBWindow();

private:
	Ui::DBWindow ui;
};
