#include "viewInventory.h"

viewInventory::viewInventory(QWidget *parent)
	: QWidget(parent)//, vinDB("choma.db")
{
	ui.setupUi(this);
	
	backToMainMenu();
	initDB();
	//Actions and slots
	QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(searchData()));
	QObject::connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(selectTable()));
}

viewInventory::~viewInventory()
{
	delete(vinDB);
}

void viewInventory::backToMainMenu()
{
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

void viewInventory::initDB()
{
	vinDB->connectDB();
	vinQry->prepare("select * from Employee");
	vinQry->exec();
	vinMdl->setQuery(*vinQry);
	ui.tableView->setModel(vinMdl);
	ui.tableView->setWindowTitle("Inventory");
	ui.tableView->setAlternatingRowColors(true);
	comboQ->prepare("select name from sqlite_master where type = 'table' ");
	comboQ->exec();
	cmbmdl->setQuery(*comboQ);
	ui.comboBox_2->setModel(cmbmdl);
	vinDB->closeDB();
}

void viewInventory::selectTable()
{
	vinDB->connectDB();
	QString cmbTxt = ui.comboBox_2->currentText();
	QSqlQuery* cmbSlotQ = new QSqlQuery(vinDB->zDB);
	cmbSlotQ->prepare("select * from "+ cmbTxt);
	//cmbSlotQ->bindValue(":tab",cmbTxt);
	cmbSlotQ->exec();
	QSqlQueryModel* cmbSlotMd = new QSqlQueryModel();
	cmbSlotMd->setQuery(*cmbSlotQ);
	ui.tableView->setModel(cmbSlotMd);
	vinDB->closeDB();
}

void viewInventory::searchData()
{
	QString searchQ = ui.lineEdit->text();
	QString cmbTxt = ui.comboBox_2->currentText();
	vinDB->connectDB();
	if (vinDB->zDB.isOpen()) qDebug() << ("DB is Connected");
	QSqlQuery* searchQuery = new QSqlQuery(vinDB->zDB);
	if (searchQ == "")searchQuery->prepare("select * from "+cmbTxt);
	else { searchQuery->prepare("select * from "+ cmbTxt +" where FirstName = :nm "); 
	searchQuery->bindValue(":nm", searchQ);
	}
	searchQuery->exec();
	QSqlQueryModel* schmdl = new QSqlQueryModel();
	schmdl->setQuery(*searchQuery);
	ui.tableView->setModel(schmdl);
	vinDB->closeDB();
}
