
#include "detailEditWidget.h"

DetailEditWidget::DetailEditWidget(QToolBox* toolbox,QWidget* parent):
	QWidget(parent),Ui::detailEditForm()
{
	setupUi(this);
	this->mode = MODE_CREATE;
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
	vector<int> horaires = Horaire::getHorairesId();  
	for (unsigned int i=0;i<horaires.size();i++)
	{
		checks.push_back(new QCheckBox(
					QString::fromUtf8(Horaire::getHoraire(horaires.at(i)).c_str()),
					this->areaContents));
		this->verticalLayout->addWidget(checks.at(checks.size()-1));
	}
	scrollArea->setWidget(areaContents);
}

void DetailEditWidget::selectAll()
{
	//if (this->checkAll->checkState()==Qt::Checked)
	for (unsigned int i=0;i<checks.size();i++)
	{
		checks.at(i)->setCheckState(this->checkAll->checkState());
	}
}

