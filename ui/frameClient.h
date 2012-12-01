#ifndef __FRAMECLIENT__
#define __FRAMECLIENT__

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
		ListeWidget* liste;
		void displayList();
	private slots:
		// TODO Fonction lorsqu'on clique sur un film
		// TODO Fonction pour retourner sur la liste
};


#endif
