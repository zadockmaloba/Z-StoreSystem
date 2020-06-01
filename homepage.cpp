#include "homepage.h"

homepage::homepage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->resize(1020, 600);
	ui.groupBox->setTitle("Menu");
	ui.pushButton_7->setText("DataBase Functions");
	//ui.tabWidget->addTab(nullptr, "HelloWorld");
	//Slots and actions
	openSettings();
	openviewInventory();
	openTransfersandOrders();
}

homepage::~homepage()
{
}
void homepage::openSettings()
{
	//swin.setParent(ui.tab_2);
	QObject::connect(ui.pushButton_8, SIGNAL(clicked()), &swin, SLOT(show()));
}

void homepage::openviewInventory()
{
	QObject::connect(ui.pushButton_4, SIGNAL(clicked()), &vin, SLOT(show()));
}

void homepage::openTransfersandOrders()
{
	QObject::connect(ui.pushButton_5, SIGNAL(clicked()), &trin, SLOT(show()));
}
