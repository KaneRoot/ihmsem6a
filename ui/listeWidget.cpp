
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
	films = Film::getFilms();
	vector<Film>::iterator it;
	for (it=films.begin();it!=films.end();it++)
	{
		std::cout << it->getName() << "\n";
		boutons.push_back(new QPushButton(this));
		boutons.at(boutons.size()-1)->setVisible(true);
		QObject::connect(boutons.at(boutons.size()-1),SIGNAL(clicked()),
				this, SLOT(showDetail()));
	}	
	//QObject::connect(this,SIGNAL(clicked()),this,SLOT(showDetail(1)));
	//showDetail(1);
	// TODO Générer les boutons. Charger les films
}

void ListeWidget::showDetail()
{
	films = Film::getFilms();
	detail = new  DetailWidget(this->parentWidget());
	detail->setVisible(true);
	detail->setGeometry(0,0,((QFrame*)this->parentWidget())->frameRect().width(),
		((QFrame*)this->parentWidget())->frameRect().height());
	this->setVisible(false);
	detail->load(1);
}
