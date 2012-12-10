
#ifndef __PAIEMENT__
#define __PAIEMENT__

#include "ui_paiementWidget.h"
#include "../utils/film.h"
#include "ticketDialog.h"

#include <QToolBox>

class PaiementWidget: public QDialog, private Ui::paiementForm
{
	Q_OBJECT
	public:
		PaiementWidget(string abo,int nbtickets,Film* f,
				QToolBox* toolbox,QWidget* parent=0);
		PaiementWidget(string abo,int nbtickets,int idfilm,
				QToolBox* toolbox,QWidget* parent=0);
		~PaiementWidget();
	private:
		bool checkValue();
		QToolBox* toolBox;
		Film * film;
		int nbTickets;
		string abonnement;
	private slots:
		void buy();	
};


#endif

