#ifndef __FRAMECLIENT__
#define __FRAMECLIENT__

#include "detailWidget.h"
#include "listeWidget.h"

#include <QFrame>
#include "ui_frameClient.h"

class FrameClient: public QFrame,private Ui::FormClient
{
	Q_OBJECT
	public:
		FrameClient(QWidget* parent=0);
		~FrameClient();
	private:
		DetailWidget* detail;
		//ListeWidget liste;
		void displayDetail(int id);
		void displayList();
	private slots:
		// TODO Fonction lorsqu'on clique sur un film
		// TODO Fonction pour retourner sur la liste
};


#endif
