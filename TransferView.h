#pragma once

#include <QWidget>
#include "ui_TransferView.h"

class TransferView : public QWidget
{
	Q_OBJECT

public:
	TransferView(QWidget *parent = Q_NULLPTR);
	~TransferView();

public slots:
	void transferViewAppear(QWidget* par);

private:
	Ui::TransferView ui;
};
