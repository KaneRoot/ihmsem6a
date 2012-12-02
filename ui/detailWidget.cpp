
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

	
	vector<int> liste = f->getHoraires();
	vector<int>::iterator it;
	//QString& horaire_str=new QString;
	for (it=liste.begin();it!=liste.end();it++)
	{
		//std::cout << Horaire::getHoraire(1) << "\n";
		//std::cout << Horaire::getHoraire(*it) << "\n";
		//horaire_str=Horaire::getHoraire(*it).c_str();
		cbBxHoraire->addItem("",
				QVariant(*it));
	}	
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




