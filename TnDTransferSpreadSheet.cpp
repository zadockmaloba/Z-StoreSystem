#include "TnDTransferSpreadSheet.h"

TnDTransferSpreadSheet::TnDTransferSpreadSheet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TnDTransferSpreadSheet::~TnDTransferSpreadSheet()
{
}
void TnDTransferSpreadSheet::readData()
{
	trDb->connectDB();
	QSqlQuery * qry = new QSqlQuery(trDb->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	QString now = currDate.currentDate().toString();
	qry->prepare("select * from ["+now+"]");
	qry->exec();
	qmd->setQuery(*qry);
	ui.tableView->setModel(qmd);
	trDb->closeDB();
}