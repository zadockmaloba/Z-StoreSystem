#pragma once

#include <QtSql/qtsqlglobal.h>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqlquerymodel.h>
#include <QtCore/qdebug.h>
#include <string>
#include <QtCore/qdatetime.h>

class DataBase 
{
public:
	DataBase(char* path, QString conName);
	~DataBase();
	bool connectDB();
	void closeDB();
	void createDB();
	void createTable();
public:
	QSqlDatabase zDB;
	QSqlQuery* qry = new QSqlQuery(zDB);
	QSqlQueryModel* mdl = new QSqlQueryModel();

private:
	//sqlite3* DB;
};
