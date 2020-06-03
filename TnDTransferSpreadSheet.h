#pragma once

#include <QWidget>
#include "ui_TnDTransferSpreadSheet.h"
#include "DataBase.h"

class TnDTransferSpreadSheet : public QWidget
{
	Q_OBJECT

public:
	TnDTransferSpreadSheet(QWidget *parent = Q_NULLPTR);
	~TnDTransferSpreadSheet();

public slots:
	void readData();

private:
	Ui::TnDTransferSpreadSheet ui;
	DataBase* trDb = new DataBase("scripts/stockmvmnt.db", "connC");
	QDate currDate;
};
