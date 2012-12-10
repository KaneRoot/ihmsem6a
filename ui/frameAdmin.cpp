
#include "frameAdmin.h"


FrameAdmin::FrameAdmin(QWidget* parent):QFrame(parent),Ui::FormAdmin()
{
	setupUi(this);	
	this->toolBox->removeItem(0);
	this->toolBox->removeItem(0);
	
	this->isEditShowed = false;
	this->isCreateShowed = false;

	liste = new ListeWidget(toolBox,MODE_ADMIN,toolBox);
	liste->setVisible(true);
	this->toolBox->addItem(liste,QString::fromUtf8("Catalogue de film"));
	QObject::connect(btn_ajout,SIGNAL(clicked()),this,SLOT(toCreate()));
	QObject::connect(btn_editer,SIGNAL(clicked()),this,SLOT(toEdit()));
	QObject::connect(btn_sup,SIGNAL(clicked()),this,SLOT(toDelete()));
	QObject::connect(btn_projection,SIGNAL(clicked()),this,SLOT(switchMovies()));
	QObject::connect(btn_reserver,SIGNAL(clicked()),this,SLOT(toReserv()));
}

FrameAdmin::~FrameAdmin()
{}

void FrameAdmin::toReserv()
{
	Film*f=NULL;
	f = liste->getFilmSelect();
	if (f==NULL)
	{
		cout << "Mauvais selection\n";
		return;
	}
	ChoiceClientDialog* choice = new ChoiceClientDialog(this->toolBox,
			this);
	choice->show();		
}

void FrameAdmin::switchMovies()
{
	liste->switchMovies();
	liste->load();
}

void FrameAdmin::toEdit()
{
	if (!this->isEditShowed)
	{
		Film* f = NULL;
		f = liste->getFilmSelect();
		if (f==NULL)
		{
			cout << "Mauvaise selection\n";
			return;
		}
		detailEdit = new DetailEditWidget(f,
				this->toolBox,this->toolBox);
		toolBox->addItem(detailEdit,QString::fromUtf8("Mode édition"));
	}

	this->isEditShowed=true;
}

void FrameAdmin::toCreate()
{
	if (!this->isCreateShowed)
	{
		detailCreate = new DetailEditWidget(this->toolBox,
				this->toolBox);
		toolBox->addItem(detailCreate,QString::fromUtf8("Mode création"));
	}
	if (toolBox->count()==1)
	{	
		toolBox->setCurrentIndex(1);
	}
	else
	{
		toolBox->setCurrentIndex(2);
	}
	this->isCreateShowed=true;
}

void FrameAdmin::toDelete()
{
	//TODO Supprimer film
	Film* f = NULL;
	f = liste->getFilmSelect();
	if (f==NULL)
	{
		cout << "Mauvaise sélection\n";
		return;
	}
	//cout << "film à supprimer : " << f->getName() << endl;

	Film::delFilm(f->getId());
	Film::save();
	
	liste->load();
}



