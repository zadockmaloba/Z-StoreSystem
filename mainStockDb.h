#pragma once
#include <qobject.h>
#include "DataBase.h"

class mainStockDb : public QObject
{
	Q_OBJECT
public:
	mainStockDb();
	~mainStockDb();

private:
	DataBase mainDb;

signals:

public slots:

};

inline mainStockDb::mainStockDb()
	: mainDb("scripts/test.db", "connectionP")
{

}
inline mainStockDb::~mainStockDb()
{

}

