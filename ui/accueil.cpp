
#include "accueil.h"

Accueil::Accueil(QWidget* parent):QMainWindow(parent),
	Ui::AccueilWindow()
{
	setupUi(this);
	QObject::connect(this->but_admin,SIGNAL(clicked()),
			this,SLOT(ouvreDialConnect()));
	
}

Accueil::~Accueil()
{}

void Accueil::ouvreDialConnect()
{
	ConnectionDial* connect=new ConnectionDial(this);
	connect->setModal(true);
	connect->show();
}


