
#include "detailEditWidget.h"

DetailEditWidget::DetailEditWidget(QToolBox* toolbox,QWidget* parent):
	QWidget(parent),Ui::detailEditForm()
{
	setupUi(this);
	this->mode = MODE_CREATE;
	this->film = NULL;
	this->toolBox = toolbox;
}

DetailEditWidget::DetailEditWidget(Film* f, QToolBox* toolbox, QWidget* parent):
	QWidget(parent),Ui::detailEditForm()
{
	setupUi(this);
	this->mode = MODE_EDIT;
	this->film=f;
	this->toolBox = toolbox;
}

DetailEditWidget::~DetailEditWidget()
{}

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
