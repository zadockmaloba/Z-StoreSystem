#include "DataBase.h"

DataBase::DataBase(char* path, QString conName) : zDB(QSqlDatabase::addDatabase("QSQLITE", conName))
{
	//connectDB(path);
	//zDB = QSqlDatabase::addDatabase("QSQL");
	zDB.setDatabaseName(path);
}

DataBase::~DataBase()
{
}

bool DataBase::connectDB()
{
	if (!zDB.open())
	{
		return false;
	}
	return true;
}

void DataBase::closeDB()
{
	zDB.close();
}
