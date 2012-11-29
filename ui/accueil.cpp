
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
	connect=new ConnectionDial(this);
	connect->setModal(true);
	QObject::connect(connect->but_valider,SIGNAL(clicked()),
			this,SLOT(ouvreFrameAdmin()));
	connect->show();
}

void Accueil::ouvreFrameAdmin()
{
	if (connect->isConnect())
	{
		FrameAdmin* frame = new FrameAdmin(NULL);
		frame->setVisible(true);
		this->close();
	}
}

void Accueil::ouvreFrameClient()
{
	FrameClient* frame = new FrameClient(NULL);
	frame->setVisible(true);
	this->close();
	//frame->setVisible(true);
	//this->setVisible(false);
}


