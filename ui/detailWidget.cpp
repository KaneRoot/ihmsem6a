
#include "detailWidget.h"

DetailWidget::DetailWidget(QToolBox* toolbox, QWidget* parent):QWidget(parent),Ui::DetailForm()
{
	setupUi(this);	
	QObject::connect(btn_back,SIGNAL(clicked()),
			this,SLOT(retour()));
	QObject::connect(btnReserver,SIGNAL(clicked()),
			this,SLOT(toReserve()));
	setToolBox(toolbox);

}

DetailWidget::~DetailWidget()
{}

void DetailWidget::load(Film* f)
{
	film = f;

	cleanCombo();

	labelTitle->setText(QString::fromUtf8(film->getName().c_str()));
	textSynopsis->setText(QString::fromUtf8(film->getSynopsis().c_str()));
	string casting = "";
	vector<string> actors = film->getActors();
	vector<string>::iterator its;
	for (its=actors.begin();its!=actors.end();its++)
	{
		casting.append(*its);
		casting.push_back(';');
	}
	textEdit->setText(QString::fromUtf8(casting.c_str()));

	vector<int> liste = film->getHorairesLibres();
	vector<int>::iterator it;
	Horaire::init();
	for (it=liste.begin();it!=liste.end();it++)
	{
		comboBox->addItem(QString::fromUtf8(Horaire::getHoraire(*it).c_str()),
				QVariant(*it));
	}	

}

void DetailWidget::cleanCombo()
{
	for (int i =0;i<comboBox->count();i++)
	{
		comboBox->removeItem(0);
	}
}

void DetailWidget::setBrother(QWidget* bro)
{
	brother=bro;
}

QToolBox* DetailWidget::getToolBox()
{
	return this->toolBox;
}

void DetailWidget::setToolBox(QToolBox* toolbox)
{
	this->toolBox = toolbox; 
}

void DetailWidget::retour()
{
	toolBox->setCurrentIndex(0);
}

void DetailWidget::toReserve()
{
	string abo = comboBox->itemText(comboBox->currentIndex()).toStdString();
	PaiementWidget* paiement = new PaiementWidget(abo,
			spinBox->value(),film,toolBox,this);
	paiement->show();
}



