
#include "connection.h"


ConnectionDial::ConnectionDial(QWidget* parent):QDialog(parent),Ui::connectionDial()
{
	setupUi(this);
	isOk=false;
	QObject::connect(this->but_valider,SIGNAL(clicked()),
			this,SLOT(validation()));
}

ConnectionDial::~ConnectionDial()
{}


bool ConnectionDial::isConnect()
{
	return isOk;
}

void ConnectionDial::validation()
{
	isOk=true;
	this->accepted();
	this->close();
}


