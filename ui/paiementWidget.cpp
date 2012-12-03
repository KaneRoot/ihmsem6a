
#include "paiementWidget.h"

PaiementWidget::PaiementWidget(string abo, int nbtickets,Film* f,
		QToolBox* toolbox,QWidget* parent):QDialog(parent),Ui::paiementForm()
{
	setupUi(this);
	this->toolBox = toolbox;
	this->film = f;
	this->abonnement = abo;
	this->nbTickets=nbtickets;

	QObject::connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

PaiementWidget::PaiementWidget(string abo, int nbtickets,int idfilm,
		QToolBox* toolbox,QWidget* parent):QDialog(parent),Ui::paiementForm()
{
	setupUi(this);
	this->toolBox = toolbox;
	this->abonnement=abo;
	this->nbTickets=nbtickets;

	Film::init();
	film = new Film(idfilm);

	QObject::connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(payerButton,SIGNAL(clicked()),this,SLOT(buy()));
}

PaiementWidget::~PaiementWidget()
{}

bool PaiementWidget::checkValue()
{
	return true;
}

void PaiementWidget::buy()
{
	if (checkValue())
	{
		this->close();
		((QDialog*)this->parentWidget())->close();
	}
}




