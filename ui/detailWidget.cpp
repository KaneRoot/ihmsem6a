
#include "detailWidget.h"

DetailWidget::DetailWidget(QWidget* parent):QWidget(parent),Ui::DetailForm()
{
	setupUi(this);	
}

DetailWidget::~DetailWidget()
{}

void DetailWidget::load(Film* f)
{
	//labelTitle->setText(f->getName());
	//plainTextSynopsis->setText(f->getSynopsis());
	
/*	vector<int> liste = f.getHoraires();
	Horaire horaire;
	for (int i=0;i<horaire.size())
	{
		horaire = new Horaire(liste.at(i));
		cbBxHoraire.addItem(horaire.getString());
	}	
*/
}

void DetailWidget::retour()
{
	// TODO}
}




