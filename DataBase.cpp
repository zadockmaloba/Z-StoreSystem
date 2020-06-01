#include "DataBase.h"

DataBase::DataBase(char* path) 
{
	//connectDB(path);
	zDB = QSqlDatabase::addDatabase("QSQLITE");
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
