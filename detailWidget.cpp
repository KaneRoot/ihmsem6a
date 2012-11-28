
#include "detailWidget.h"


DetailWidget::DetailWidget(QWidget* parent=0):QWidget(parent),Ui::detailWidget()
{
	setupUi(this);	
}

DetailWidget::~DetailWidget()
{}

DetailWidget::load(Film f)
{
	labelTitle.setText(f.getName());
	plainTextSynopsis.setText(f.getSynopsis());
	/*
	vector<int> liste = f.getHoraires();
	Horaire horaire;
	for (int i=0;i<horaire.size())
	{
		horaire = new Horaire(liste.at(i));
		cbBxHoraire.addItem(horaire.getString);
	}
	*/
}

