
#ifndef __CHOICECLIENT__
#define __CHOICECLIENT__


#include "ui_choiceClientDialog.h"

#include "detailWidget.h"
#include "paiementWidget.h"
#include <QToolBox>

class ChoiceClientDialog: public QDialog, private Ui::clientDialog
{
	Q_OBJECT
	public:
		ChoiceClientDialog(QToolBox* toolbox,QWidget* parent=0);
		~ChoiceClientDialog();
		void setIdFilm(int id);
	private:
		DetailWidget* details;
		QToolBox* toolBox;
		bool isShowed;
		int idFilm;
	private slots:
		void toDetail();
		void toReserv();
};


#endif
