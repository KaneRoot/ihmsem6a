#include "ticketDialog.h"


TicketDialog::TicketDialog(string titre, string salle,
	string horaire, string duree, string abo,
	string nbPlace, QToolBox* toolbox, QWidget* parent):QDialog(parent),
	Ui::ticketDialog()
{
	setupUi(this);
	this->setVisible(true);
	this->toolBox = toolbox;
	load(titre,salle,horaire,duree,abo,nbPlace);
	QObject::connect(this->btn_ok,SIGNAL(clicked()),this,SLOT(fermer()));
}

TicketDialog::~TicketDialog()
{
}

void TicketDialog::load(string titre, string salle, string horaire,
		string duree, string abo, string nbPlace)
{
	this->lbl_nom_film->setText(QString::fromUtf8(titre.c_str()));
	this->lbl_salle->setText(QString::fromUtf8(salle.c_str()));
	this->lbl_horaire->setText(QString::fromUtf8(horaire.c_str()));
	this->lbl_duree->setText(QString::fromUtf8(duree.c_str()));
	this->lbl_abo->setText(QString::fromUtf8(abo.c_str()));
	this->lbl_nb_places->setText(QString::fromUtf8(nbPlace.c_str()));
}

void TicketDialog::fermer()
{
	//TODO Revenir a la liste de film
	this->parentWidget()->close();
	this->close();
}


