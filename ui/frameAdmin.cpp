
#include "frameAdmin.h"


FrameAdmin::FrameAdmin(QWidget* parent):QFrame(parent),Ui::FormAdmin()
{
	setupUi(this);	
	this->toolBox->removeItem(0);
	this->toolBox->removeItem(0);
	
	liste = new ListeWidget(toolBox,MODE_ADMIN,toolBox);
	liste->setVisible(true);
	this->toolBox->addItem(liste,QString::fromUtf8("Catalogue de film"));
}

FrameAdmin::~FrameAdmin()
{}






