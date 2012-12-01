
#include "detailWidget.h"

DetailWidget::DetailWidget(QWidget* parent):QWidget(parent),Ui::DetailForm()
{
	setupUi(this);	

	QObject::connect(btn_back,SIGNAL(clicked()),
			this,SLOT(retour()));
}

DetailWidget::~DetailWidget()
{}

void DetailWidget::load(int i)//(Film* f)
{
	Film *f = new Film(i);
	labelTitle->setText((QString)f->getName().c_str());
	textSynopsis->setText((QString)f->getSynopsis().c_str());
	string casting = "";

	//vector<int> liste = f.getHoraires();
	//Horaire horaire;
	//for (int i=0;i<horaire.size();i++)
	//{
	//	horaire = new Horaire(liste.at(i));
	//	cbBxHoraire.addItem(horaire.getString());
	//}	
}


void DetailWidget::setBrother(QWidget* bro)
{
	brother=bro;
}

void DetailWidget::retour()
{
	brother->setVisible(true);
	this->setVisible(false);
}




