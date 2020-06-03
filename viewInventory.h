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
	
public slots:
	void searchData();
	void selectTable();

private:
	Ui::viewInventory ui;
	DataBase* vinDB = new DataBase("scripts/chin.sqlite", "connA");
	QSqlQuery* vinQry = new QSqlQuery(vinDB->zDB);
	QSqlQueryModel* vinMdl = new QSqlQueryModel();
	QSqlQuery* comboQ = new QSqlQuery(vinDB->zDB);
	QSqlQueryModel* cmbmdl = new QSqlQueryModel();
};
