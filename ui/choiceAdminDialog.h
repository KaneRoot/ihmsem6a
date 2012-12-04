
#ifndef __CHOICEADMIN__
#define __CHOICEADMIN__

#include "ui_choiceAdminDialog.h"

#include "QToolBox"

#include "../utils/film.h"
#include "detailEditWidget.h"


class ChoiceAdminDialog:public QDialog, private Ui::choiceAdminDialog
{
	Q_OBJECT
	public:
		ChoiceAdminDialog(QToolBox* toolbox,QWidget* parent=0);
		~ChoiceAdminDialog();
		void setFilm(Film* film);
	private:
		DetailEditWidget* edit;
		QToolBox* toolBox;
		Film* film;
		bool isEditShowed;
	private slots:
		void toEdit();
		void toCreate();
		void toDelete();
};



#endif
