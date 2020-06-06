#pragma once
#include <QtCore/qobject.h>
#include "DataBase.h"

class tndDataBase : public QObject
{
	Q_OBJECT
public: //public methods
	tndDataBase ();
	~tndDataBase ();
	QSqlQueryModel setItemTypes();
	QSqlQueryModel setItemNames();

public: //Public members
	DataBase* tnDB = new DataBase("test.db", "connG");

private:

};
