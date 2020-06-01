#include "TransferView.h"

TransferView::TransferView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TransferView::~TransferView()
{
}
void TransferView::transferViewAppear(QWidget* par)
{
	this->setParent(par);
}
