#pragma once

#include <QWidget>
#include "ui_TnDTransferSpreadSheet.h"

class TnDTransferSpreadSheet : public QWidget
{
	Q_OBJECT

public:
	TnDTransferSpreadSheet(QWidget *parent = Q_NULLPTR);
	~TnDTransferSpreadSheet();

private:
	Ui::TnDTransferSpreadSheet ui;
};
