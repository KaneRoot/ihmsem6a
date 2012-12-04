
#include "detailEditWidget.h"

DetailEditWidget::DetailEditWidget(QToolBox* toolbox,Qwidget* parent):
	QWidget(parent),Ui::detailEditWidget()
{
	setupUi(this);
	this->mode=MODE_CREATE;
	this->film = NULL;
}

DetailEditWidget::DetailEditWidget(Film* f, QToolBox* toolbox, QWidget* parent)
{
	setupUi(this);
	this->mode = MODE_EDIT;
}

DetailEditWidget::~DetailEditWidget()
{
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
	film.save();
}
