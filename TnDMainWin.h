#pragma once

#include <QWidget>
#include "ui_TnDMainWin.h"
#include "TransferView.h"
#include "TnDTransferSpreadSheet.h"
#include "AssertionDialog.h"
#include "DataBase.h"

class TnDMainWin : public QWidget
{
	Q_OBJECT

public:
	TnDMainWin(QWidget *parent = Q_NULLPTR);
	~TnDMainWin();
	int stringToInt(QString sNum);
	void createTable();

public slots:
	void showTransferWin();
	void startDay();
	void endDay();
	void getFormInput();

private:
	Ui::TnDMainWin ui;
	TransferView trView;
	TnDTransferSpreadSheet transSheet;
	AssertionDialog srt;
	DataBase* nDB = new DataBase("scripts/stockmvmnt.db", "connB");
	QDate currDate;
	QTime currTime;
};
