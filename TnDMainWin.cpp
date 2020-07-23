#include "TnDMainWin.h"

TnDMainWin::TnDMainWin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setItemTypes();
	setItemNames();
	//slots and activities
	ui.pushButton_4->setDisabled(true);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), &transSheet, SLOT(show()));
	QObject::connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(startDay()));
	QObject::connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(endDay()));
	QObject::connect(srt.ui.pushButton_2, SIGNAL(clicked()), &srt, SLOT(close()));
	QObject::connect(srt.ui.pushButton, SIGNAL(clicked()), &srt, SLOT(close()));
	QObject::connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(getFormInput()));
	QObject::connect(ui.pushButton_6, SIGNAL(clicked()), &transSheet, SLOT(readData()));
	QObject::connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(setItemNames()));

}

TnDMainWin::~TnDMainWin()
{
	delete(xnDB);
}

int TnDMainWin::stringToInt(QString sNum)
{
	int ans = sNum.toInt();
	return ans;
}

void TnDMainWin::createTable()
{
	xnDB->connectDB();
	QSqlQuery* qry = new QSqlQuery(xnDB->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	QString now = currDate.currentDate().toString();
	//ui.pushButton->setText(now);
	qry->prepare("create if not exists table ["+ now +"] (Item, Amount, IssuedBy, Time, TransferredTo, RemainingStock)");
	if (!qry->exec()) {
		QSqlError err(qry->lastError());
		qDebug() << err;
	}
	xnDB->zDB.commit();
	xnDB->closeDB();
}

void TnDMainWin::setItemTypes()
{
	ztnDB.setItemTypes(ui.comboBox);
}

void TnDMainWin::setItemNames()
{ 
	QString ntbl = ui.comboBox->currentText();
	ztnDB.setItemNames(ui.comboBox_2, ui.comboBox->currentText());
}

void TnDMainWin::subtractStock(QString itm, QString tbl, int quantity)
{
	//subtracting items from the test.db; the function will be placed in getFormInput()

	// Move some functions to TnDTransferSpreadsheet class such that it returns a model
}

void TnDMainWin::addStock(QString itm, QString tbl, int quantity)
{
}

void TnDMainWin::startDay()
{
	createTable();
	ui.pushButton_4->setEnabled(true);
	ui.pushButton_3->setDisabled(true);
}

void TnDMainWin::endDay()
{
	srt.show();
	//*********************************************************
	//Remember to create a table for openning and closing times
	//*********************************************************
	xnDB->connectDB();
	xnDB->zDB.commit();
	srt.ui.label->setText("Ending the day will lead to the databse table being locked.\nNo more changes can be made to it.");
	ui.pushButton_4->setDisabled(true);
	ui.pushButton_3->setEnabled(true);
	xnDB->closeDB();
}

void TnDMainWin::getFormInput()
{
	QString itmName = ui.comboBox_2->currentText();
	QString trnsfTO = ui.comboBox_3->currentText();
	QString issuedBy = ui.lineEdit_3->text();
	uint amnt = ui.lineEdit_4->text().toInt();
	QString now = currDate.currentDate().toString();
	QString nTime = currTime.currentTime().toString();
	xnDB->connectDB();
	QSqlQuery* qry = new QSqlQuery(xnDB->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	qry->prepare("insert into ["+ now +"] (Item, Amount, IssuedBy, Time, TransferredTo) values (?,?,?,?,?)");
	qry->bindValue(0, itmName);
	qry->bindValue(1, amnt);
	qry->bindValue(2, issuedBy);
	qry->bindValue(3, nTime);
	qry->bindValue(4, trnsfTO);
	qry->exec();
	xnDB->zDB.commit();
	xnDB->closeDB();
}

void TnDMainWin::showTransferWin()
{
	trView.setParent(ui.widget);
}