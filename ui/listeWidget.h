
#ifndef __LISTWIDGET__
#define __LISTWIDGET__

#include "../utils/film.h"

#include <QToolBox>
#include <QGridLayout>
#include <iostream>

#include "choiceClientDialog.h"
#include "qButtonImproved.h"

#include "ui_listeWidget.h"

#define MODE_ADMIN 12321
#define MODE_CLIENT 12421

class ListeWidget: public QWidget, private Ui::ListeForm
{
	Q_OBJECT
	public:
		ListeWidget(QToolBox* toolBox,int mode,QWidget* parent=0);
		~ListeWidget();
		void load();
		void clean();
		int getMode();
		QToolBox* getToolBox();
		vector<Film> getFilmsSelect();
		Film* getFilmSelect();
	private:
		vector<QButtonImproved*> boutons;
		vector<Film> films;
		QToolBox* toolbox;
		QGridLayout* layout;
		ChoiceClientDialog* dialClient;
		int mode;
	private slots:
		void showDetail();
};

#endif

