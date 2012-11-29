
#ifndef __ACCUEIL_H__
#define __ACCUEIL_H__

#include <iostream>

#include "ui_accueil.h"
#include "connection.h"
#include "frameClient.h"
#include "frameAdmin.h"

class Accueil:public QMainWindow, private Ui::AccueilWindow
{
	Q_OBJECT
		public:
		Accueil(QWidget* parent=0);	
		~Accueil();
	private:
		ConnectionDial* connect;
	private slots:
		void ouvreDialConnect();
		void ouvreFrameClient();
		void ouvreFrameAdmin();
};

#endif
