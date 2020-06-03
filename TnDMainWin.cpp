#include "TnDMainWin.h"

TnDMainWin::TnDMainWin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//slots and activities
	ui.pushButton_4->setDisabled(true);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), &transSheet, SLOT(show()));
	QObject::connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(startDay()));
	QObject::connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(endDay()));
	QObject::connect(srt.ui.pushButton_2, SIGNAL(clicked()), &srt, SLOT(close()));
	QObject::connect(srt.ui.pushButton, SIGNAL(clicked()), &srt, SLOT(close()));
	QObject::connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(getFormInput()));
	QObject::connect(ui.pushButton_6, SIGNAL(clicked()), &transSheet, SLOT(readData()));

}

TnDMainWin::~TnDMainWin()
{
	delete(nDB);
}

int TnDMainWin::stringToInt(QString sNum)
{
	int ans = sNum.toInt();
	return ans;
}

void TnDMainWin::createTable()
{
	nDB->connectDB();
	QSqlQuery* qry = new QSqlQuery(nDB->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	QString now = currDate.currentDate().toString();
	ui.pushButton->setText(now);
	qry->prepare("create table ["+ now +"] (Item, Amount, IssuedBy, Time, TransferredTo)");
	qry->prepare("create table TEST (Item, Amount, IssuedBy, Time, TransferredTo)");
	qry->exec();
	nDB->zDB.commit();
	nDB->closeDB();
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
	//********************************************************
	//Remember to create a table for openning and closing times
	//*********************************************************
	nDB->zDB.commit();
	srt.ui.label->setText("Ending the day will lead to the databse table being locked.\nNo more changes can be made to it.");
	ui.pushButton_4->setDisabled(true);
	ui.pushButton_3->setEnabled(true);
}

void TnDMainWin::getFormInput()
{
	QString itmName = ui.comboBox_2->currentText();
	QString trnsfTO = ui.comboBox_3->currentText();
	QString issuedBy = ui.lineEdit_3->text();
	uint amnt = ui.lineEdit_4->text().toInt();
	QString now = currDate.currentDate().toString();
	QString nTime = currTime.currentTime().toString();
	nDB->connectDB();
	QSqlQuery* qry = new QSqlQuery(nDB->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	qry->prepare("insert into ["+ now +"] (Item, Amount, IssuedBy, Time, TransferredTo) values (?,?,?,?,?)");
	qry->bindValue(0, itmName);
	qry->bindValue(1, amnt);
	qry->bindValue(2, issuedBy);
	qry->bindValue(3, nTime);
	qry->bindValue(4, trnsfTO);
	qry->exec();
	nDB->zDB.commit();
	nDB->closeDB();
}

void TnDMainWin::showTransferWin()
{
	trView.setParent(ui.widget);
}
