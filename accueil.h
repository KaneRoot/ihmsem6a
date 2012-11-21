
#ifndef __ACCUEIL_H__
#define __ACCUEIL_H__

#include <iostream>

#include "ui_accueil.h"
#include "connection.h"

class Accueil:public QMainWindow, private Ui::AccueilWindow
{
	Q_OBJECT
	public:
		Accueil(QWidget* parent=0);	
		~Accueil();
	private slots:
		void ouvreDialConnect();
};

#endif
