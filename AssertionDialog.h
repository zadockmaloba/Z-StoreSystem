#pragma once

#include <QWidget>
#include "ui_AssertionDialog.h"

class AssertionDialog : public QWidget
{
	Q_OBJECT

public:
	AssertionDialog(QWidget *parent = Q_NULLPTR);
	~AssertionDialog();
	Ui::AssertionDialog ui;

private:
};
