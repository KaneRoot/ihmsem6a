
#include "listeWidget.h"

ListeWidget::ListeWidget(QWidget* parent):QWidget(parent)
	,Ui::ListeForm()
{
	setupUi(this);
	load();
}

ListeWidget::~ListeWidget()
{}

void ListeWidget::load()
{
	this->setContentsMargins(20,20,20,20);
	films = Film::getFilms();
	vector<Film>::iterator it;
	QGridLayout * layout = new QGridLayout;
	int i=0,j=0;
	for (it=films.begin();it!=films.end();it++)
	{
		boutons.push_back(new QButtonImproved(((QString)it->getName().c_str()),
					this,i));
		boutons.at(boutons.size()-1)->setVisible(true);
		QObject::connect(boutons.at(boutons.size()-1),SIGNAL(clicked()),
				this, SLOT(showDetail()));
		boutons.at(boutons.size()-1)->resize(boutons.at(boutons.size()-1)->width(),
				50);
		layout->addWidget(boutons.at(boutons.size()-1),i%2,j%2);
		i++;
		if(i%2==0)
		{
			j++;
		}
	}
	this->setLayout(layout);
}

void ListeWidget::showDetail()
{
	films = Film::getFilms();
	detail = new  DetailWidget(this->parentWidget());
	detail->setVisible(true);
	detail->setGeometry(0,0,((QFrame*)this->parentWidget())->frameRect().width(),
		((QFrame*)this->parentWidget())->frameRect().height());
	this->setVisible(false);
	detail->setBrother(this);
	QButtonImproved* b =(QButtonImproved*)sender();
	detail->load(b->getId()); 
}
