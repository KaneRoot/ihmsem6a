
#include "qButtonImproved.h"


QButtonImproved::QButtonImproved(const QString& text,QWidget* parent, int id):
	QPushButton(text,parent)
{
	this->id = id;
}

QButtonImproved::QButtonImproved(const QIcon& icon, const QString& text,
		QWidget*parent,int id):QPushButton(icon,text,parent)
{
	this->id = id;
}	

QButtonImproved::~QButtonImproved()
{}

int QButtonImproved::getId()
{
	return this->id;
}

void QButtonImproved::setId(int id)
{
	this->id = id;
}
