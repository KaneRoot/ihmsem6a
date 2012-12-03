
#include "detailWidget.h"

DetailWidget::DetailWidget(QToolBox* toolbox, QWidget* parent):QWidget(parent),Ui::DetailForm()
{
	setupUi(this);	
	QObject::connect(btn_back,SIGNAL(clicked()),
			this,SLOT(retour()));
	setToolBox(toolbox);
}

DetailWidget::~DetailWidget()
{}

void DetailWidget::load(int i)//(Film* f)
{
	Film *f = new Film(i);
	labelTitle->setText(QString::fromUtf8(f->getName().c_str()));
	textSynopsis->setText(QString::fromUtf8(f->getSynopsis().c_str()));
	string casting = "";
	vector<string> actors = f->getActors();
	vector<string>::iterator its;
	for (its=actors.begin();its!=actors.end();its++)
	{
		casting.append(*its);
		casting.push_back(';');
	}
	textEdit->setText(QString::fromUtf8(casting.c_str()));
		
/*	vector<int> liste = f->getHoraires();
	vector<int>::iterator it;
	Horaire::init();
	for (it=liste.begin();it!=liste.end();it++)
	{
		cbBxHoraire->addItem(QString::fromUtf8(Horaire::getHoraire(*it).c_str()),
				QVariant(*it));
	}	
*/
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




