#pragma once
#include <QtCore/qobject.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qcombobox.h>
#include "DataBase.h"

class tndDataBase : public QObject
{
	Q_OBJECT
public: //public methods
	tndDataBase ();
	~tndDataBase ();
	void setItemTypes(QComboBox* widg);
	void setItemNames(QComboBox* widg ,QString currTable);
	int getRemainingStock(QString table, QString itmName);

public: //Public members
	DataBase* tnDB = new DataBase("scripts/test.db", "connG");

private:
	QSqlQueryModel clmd;

};
