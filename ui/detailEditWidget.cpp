
#include "detailEditWidget.h"

DetailEditWidget::DetailEditWidget(QToolBox* toolbox,QWidget* parent):
	QWidget(parent),Ui::detailEditForm()
{
	setupUi(this);
	this->mode = MODE_CREATE;
	this->labelTitle->setText(QString::fromUtf8("Ajout d'un nouveau film"));
	this->btnEditer->setText(QString::fromUtf8("Ajouter"));
	this->film = NULL;
	this->toolBox = toolbox;
	loadHoraire();
	initSignal();
}

DetailEditWidget::DetailEditWidget(Film* f, QToolBox* toolbox, QWidget* parent):
	QWidget(parent),Ui::detailEditForm()
{
	setupUi(this);
	this->mode = MODE_EDIT;
	this->labelTitle->setText(QString::fromUtf8("Édition"));
	this->film=f;
	this->toolBox = toolbox;
	this->textEdit->setText(QString::fromUtf8(f->getName().c_str()));
	this->te_synopsis->setText(QString::fromUtf8(f->getSynopsis().c_str()));
	loadHoraire();
	initSignal();
}

DetailEditWidget::~DetailEditWidget()
{}

void DetailEditWidget::initSignal()
{
	QObject::connect(this->checkAll,SIGNAL(stateChanged(int/*Qt::Unchecked*/)),
			this,SLOT(selectAll()));
	QObject::connect(this->checkAll,SIGNAL(stateChanged(int/*Qt::Checked*/)),
			this,SLOT(selectAll()));
}

int DetailEditWidget::getMode()
{
	return this->mode;
}

void DetailEditWidget::saveFilm()
{
	//Film::addFilm();
}

void DetailEditWidget::editFilm()
{
	film->save();
}

void DetailEditWidget::loadHoraire()
{
	vector<int> horaireFilm;
	
	if (this->mode == MODE_EDIT)
	{
		horaireFilm = film->getHoraires();
	}	

	vector<int> horaires = Horaire::getHorairesId();  
	bool b;
	for (unsigned int i=0;i<horaires.size();i++)
	{
		checks.push_back(new QCheckBox(
					QString::fromUtf8(Horaire::getHoraire(horaires.at(i)).c_str()),
					this->areaContents));
		if (this->mode == MODE_EDIT)
		{
			b=false;
			for (unsigned int j=0;j<horaireFilm.size() && !b;j++)
			{
				b = horaireFilm.at(j)==(int)i;
			}
			if (b)
			{
				checks.at(i)->setCheckState(Qt::Checked);
			}
		}
		this->verticalLayout->addWidget(checks.at(checks.size()-1));
	}
//	scrollArea->setWidget(areaContents);
}

void DetailEditWidget::selectAll()
{
	//if (this->checkAll->checkState()==Qt::Checked)
	for (unsigned int i=0;i<checks.size();i++)
	{
		checks.at(i)->setCheckState(this->checkAll->checkState());
	}
}

