#include "ticketDialog.h"

using namespace std;

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
	std::ostringstream stream;
	stream << "Film : ";
	stream << titre;
	string tmp = stream.str();
	this->lbl_nom_film->setText(QString::fromUtf8(tmp.c_str()));
	this->lbl_salle->setText(QString::fromUtf8(salle.c_str()));

	stream.str("");
	stream << "Horaire : ";
	stream << horaire;
	tmp.clear();
	tmp = stream.str();
	this->lbl_horaire->setText(QString::fromUtf8(tmp.c_str()));

	stream.str("");
	stream << "Durée : ";
	stream << duree;
	tmp.clear();
	tmp = stream.str();
	this->lbl_duree->setText(QString::fromUtf8(tmp.c_str()));

	stream.str("");
	stream << "Abonnement : ";
	stream << abo;
	tmp.clear();
	tmp = stream.str();
	this->lbl_abo->setText(QString::fromUtf8(tmp.c_str()));

	stream.str("");
	stream << "Nombre de tickets : ";
	stream << nbPlace;
	tmp.clear();
	tmp = stream.str();
	this->lbl_nb_places->setText(QString::fromUtf8(tmp.c_str()));
}

void TicketDialog::fermer()
{
	//TODO Revenir a la liste de film
	this->parentWidget()->close();
	this->close();
}


