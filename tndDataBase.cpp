#include "tndDataBase.h"

tndDataBase::tndDataBase()
{
}

tndDataBase::~tndDataBase()
{
}

void tndDataBase::setItemTypes(QComboBox * widg)
{
	tnDB->connectDB();
	QSqlQuery* qry = new QSqlQuery(tnDB->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	qry->prepare("select name from sqlite_master where type = 'table' ");
	if (!qry->exec()) {
		QSqlError err = qry->lastError();
		qDebug() << err;
	}
	qmd->setQuery(*qry);
	widg->setModel(qmd);
	tnDB->closeDB();
}

void tndDataBase::setItemNames(QComboBox* widg ,QString currTable)
{
	tnDB->connectDB();
	QSqlQuery* qry = new QSqlQuery(tnDB->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	qry->prepare("select [Item Name] from " + currTable);
	if (!qry->exec()) {
		QSqlError err=qry->lastError();
		qDebug() << err;
	}
	qmd->setQuery(*qry);
	widg->setModel(qmd);
	tnDB->closeDB();
}

int tndDataBase::getRemainingStock(QString table, QString itmName)
{
	int n = 0;
	tnDB->connectDB();
	QSqlQuery* qry = new QSqlQuery(tnDB->zDB);
	QSqlQueryModel* qmd = new QSqlQueryModel();
	qry->prepare("select [Stock] from [ " + table + " ] where [Item Name] = ?");
	qry->addBindValue(itmName);
	if (!qry->exec()) {
		QSqlError err = qry->lastError();
		qDebug() << err;
	}
	n = qry->value(1).toInt();
	//qmd->setQuery(*qry);
	//qmd->it
	tnDB->closeDB();
	return n;
}
