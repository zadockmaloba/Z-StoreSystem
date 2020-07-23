#pragma once
#include <qobject.h>
#include "DataBase.h"

class stockExDb : public QObject
{
	Q_OBJECT
public:
	stockExDb();
	~stockExDb();

private:
	DataBase exchDb;

signals:

public slots:

};

inline stockExDb::stockExDb()
	: exchDb("scripts/test.db", "connectionP")
{

}
inline stockExDb::~stockExDb()
{

}

