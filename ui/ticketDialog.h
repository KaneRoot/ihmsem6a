#ifndef __TICKETDIALOG__
#define __TICKETDIALOG__


#include "ui_ticket.h"
#include <QToolBox>

using namespace std;

class TicketDialog:public QDialog, private Ui::ticketDialog
{
	Q_OBJECT
	public:
		TicketDialog(string titre, string salle,
			   string horaire, string duree, string abo,
		   	   string nbPlace,QToolBox* toolbox , QWidget* parent=0);
		~TicketDialog();
	private:
		void load(string titre, string salle, string horaire,
				  string duree, string abo, string nbPlace);
		QToolBox* toolBox;
	private slots:
		void fermer();

};



#endif
