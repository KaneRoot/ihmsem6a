
#include "accueil.h"

Accueil::Accueil(QWidget* parent):QMainWindow(parent),
	Ui::AccueilWindow()
{
	setupUi(this);
	QObject::connect(this->but_admin,SIGNAL(clicked()),
			this,SLOT(ouvreDialConnect()));
	QObject::connect(this->but_client,SIGNAL(clicked()),
			this,SLOT(ouvreFrameClient()));
	
}

Accueil::~Accueil()
{}

void Accueil::ouvreDialConnect()
{
	ConnectionDial* connect=new ConnectionDial(this);
	connect->setModal(true);
	connect->show();
}

void Accueil::ouvreFrameClient()
{
	FrameClient* frame = new FrameClient(this);
	//frame->setVisible(true);
	//this->setVisible(false);
}


