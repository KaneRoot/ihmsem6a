
#include <QtGui>
#include "ui/accueil.h"

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	Accueil mainwin;
	mainwin.show();
	return app.exec();
}

