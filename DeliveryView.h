#pragma once

#include <QWidget>
#include "ui_DeliveryView.h"

class DeliveryView : public QWidget
{
	Q_OBJECT

public:
	DeliveryView(QWidget *parent = Q_NULLPTR);
	~DeliveryView();

private:
	Ui::DeliveryView ui;
};
