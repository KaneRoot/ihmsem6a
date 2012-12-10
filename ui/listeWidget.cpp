
#include "listeWidget.h"

ListeWidget::ListeWidget(QToolBox* toolBox,int mode,QWidget* parent):QWidget(parent)
	,Ui::ListeForm()
{
	setupUi(this);
	this->toolbox=toolBox;
	this->mode=mode;
	this->dialClient=NULL;
	this->viewMode=MOVIES;
	layout = new QGridLayout;
	load();
	this->setLayout(layout);
}

ListeWidget::~ListeWidget()
{}

void ListeWidget::clean()
{
	for (unsigned int i=0;i<boutons.size();i++)
	{
		layout->removeWidget(boutons.at(i));
	}
	layout->update();
	boutons.clear();
	films.clear();
}

void ListeWidget::switchMovies()
{
	viewMode = ~viewMode;
}

void ListeWidget::load()
{
	clean();

	cout << boutons.size() << " " << 
		films.size() << "\n";

	this->setContentsMargins(20,20,20,20);
	
	if (viewMode==MOVIES)
	{
		// TODO Modife vers film diffuser
		films = Film::getFilms();
	}
	else
	{
		cout << " TOUT LES FILM \n";
		films = Film::getFilms();
	}
	
	vector<Film>::iterator it;
	
	int i=0,j=0;
	for (it=films.begin();it!=films.end();it++)
	{
		boutons.push_back(new QButtonImproved(
					QString::fromUtf8(it->getName().c_str()),
					this,i));

		boutons.at(boutons.size()-1)->setCheckable(
				getMode()==MODE_ADMIN);	
		boutons.at(boutons.size()-1)->setVisible(true);
		QObject::connect(boutons.at(boutons.size()-1),SIGNAL(clicked()),
				this, SLOT(showDetail()));
		boutons.at(boutons.size()-1)->resize(boutons.at(boutons.size()-1)->width(),
				50);
		layout->addWidget(boutons.at(boutons.size()-1),j,i%2);
		i++;
		if(i%2==0)
		{
			j++;
		}
	}

//	this->setLayout(layout);
}

void ListeWidget::showDetail()
{
	if (this->mode==MODE_CLIENT)
	{
		if (dialClient==NULL)
		{
			dialClient = new ChoiceClientDialog(this->toolbox,
					this->parentWidget());
		}
		QButtonImproved* button = (QButtonImproved*)this->sender();
		dialClient->setFilm(&films.at(button->getId()));
		dialClient->show();
	}
}

QToolBox* ListeWidget::getToolBox()
{
	return this->toolbox;
}

int ListeWidget::getMode()
{
	return this->mode;
}

vector<Film> ListeWidget::getFilmsSelect()
{
	vector<Film> vectorFilms;
	return vectorFilms;
}

Film* ListeWidget::getFilmSelect()
{	
	unsigned int i=0;
	for (i=0;!boutons.at(i)->isChecked()&&
			i<boutons.size();i++);
	if (i==boutons.size())
		return (Film*)NULL;
	else
		return &(films.at(i));
}


