#pragma once

#include <QWidget>
#include "ui_viewInventory.h"
#include "DataBase.h"

class viewInventory : public QWidget
{
	Q_OBJECT

public:
	viewInventory(QWidget *parent = Q_NULLPTR);
	~viewInventory();
	void backToMainMenu();
	void initDB();
	DataBase* vinDB = new DataBase("scripts/test.db", "connA");
	
public slots:
	void searchData();
	void selectTable();

private:
	Ui::viewInventory ui;
	QSqlQuery* vinQry = new QSqlQuery(vinDB->zDB);
	QSqlQueryModel* vinMdl = new QSqlQueryModel();
	QSqlQuery* comboQ = new QSqlQuery(vinDB->zDB);
	QSqlQueryModel* cmbmdl = new QSqlQueryModel();
};
