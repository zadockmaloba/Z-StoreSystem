#pragma once

#include <QWidget>
#include "ui_TnDMainWin.h"
#include "TransferView.h"
#include "TnDTransferSpreadSheet.h"

class TnDMainWin : public QWidget
{
	Q_OBJECT

public:
	TnDMainWin(QWidget *parent = Q_NULLPTR);
	~TnDMainWin();

public slots:
	void showTransferWin();

private:
	Ui::TnDMainWin ui;
	TransferView trView;
	TnDTransferSpreadSheet transSheet;

};
