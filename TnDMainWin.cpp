#include "TnDMainWin.h"

TnDMainWin::TnDMainWin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//slots and activities
	QObject::connect(ui.pushButton, SIGNAL(clicked()), &transSheet, SLOT(show()));
}

TnDMainWin::~TnDMainWin()
{
}

void TnDMainWin::showTransferWin()
{
	trView.setParent(ui.widget);
}
