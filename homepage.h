#pragma once

#include <QMainWindow>
#include "Release/uic/ui_twomain.h"
#include "SettingsWin.h"
#include "viewInventory.h"
#include "TnDMainWin.h"

class homepage : public QMainWindow
{
	Q_OBJECT

public:
	homepage(QWidget *parent = Q_NULLPTR);
	~homepage();
	void openSettings();
	void openviewInventory();
	void openTransfersandOrders();

private:
	Ui::MainWindow ui;
	//Ui::SettingsWin swin
	SettingsWin swin;
	viewInventory vin;
	TnDMainWin trin;
};
