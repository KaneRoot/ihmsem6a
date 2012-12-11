
#include "paiementWidget.h"

PaiementWidget::PaiementWidget(string abo, int nbtickets,Film* f,
		QToolBox* toolbox,QWidget* parent):QDialog(parent),Ui::paiementForm()
{
	setupUi(this);
	
	string s = string("Nom du film :")+f->getName()+
		string("\nAbonnement :")+abo+string("\n");
	this->textEdit->setText(QString::fromUtf8(s.c_str()));
	this->toolBox = toolbox;
	this->film = f;
	this->abonnement = abo;
	this->nbTickets=nbtickets;

	QObject::connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(payerButton,SIGNAL(clicked()),this,SLOT(buy()));
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
	string s = string("Nom du film :")+film->getName()+
		string("\nAbonnement :")+abo+string("\n");
	this->textEdit->setText(QString::fromUtf8(s.c_str()));



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
		TicketDialog* td = new TicketDialog(film->getName(),
				"Salle 3","17h15","1h10","Aucun","1",toolBox,this);
		td->show();
		this->setVisible(false);
		//this->close();
		//((QDialog*)this->parentWidget())->close();
	}
}




