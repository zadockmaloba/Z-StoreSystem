#pragma once

#include <QWidget>
#include <QtCore/qthread.h>
#include "ui_TnDMainWin.h"
#include "TransferView.h"
#include "TnDTransferSpreadSheet.h"
#include "AssertionDialog.h"
#include "DataBase.h"
#include "ViewInventory.h"

class TnDMainWin : public QWidget
{
	Q_OBJECT

public:
	TnDMainWin(QWidget *parent = Q_NULLPTR);
	~TnDMainWin();
	int stringToInt(QString sNum);
	void createTable();
	void setItemTypes();
	void setItemNames();
	void subtractStock(QString itm, QString tbl, int quantity);
	void addStock(QString itm, QString tbl, int quantity);

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
	DataBase* xnDB = new DataBase("scripts/stockmvmnt.db", "connE");
	DataBase* xvinDB = new DataBase("scripts/test.db", "connE");
	QDate currDate;
	QTime currTime;
	//viewInventory xvin;
};