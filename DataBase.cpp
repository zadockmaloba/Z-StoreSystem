#include "DataBase.h"

DataBase::DataBase(char* path, QString conName) 
	: 
	zDB(QSqlDatabase::addDatabase("QSQLITE", conName)),
	connection(conName)
{
	zDB.setDatabaseName(path);
}

DataBase::~DataBase()
{
	delete(qry);
	delete(mdl);
}

bool DataBase::connectDB()
{
	if (!zDB.open())
	{
		qDebug() << "Error openning DataBase";
		return false;
	}
	qDebug() << "DB"+connection+" connected successfully";
	return true;
}

void DataBase::closeDB()
{
	zDB.close();
}
