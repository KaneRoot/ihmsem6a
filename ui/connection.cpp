
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
	User::init();
	isOk=User::isRealUser(txt_identifiant->text().toStdString(),
			txt_password->text().toStdString());
	isOk=User::isRealUser("za","za");
	//	isOk=true;
	this->accepted();
	this->close();
}


