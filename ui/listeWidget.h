
#ifndef __LISTWIDGET__
#define __LISTWIDGET__

#include "../utils/film.h"

#include <QToolBox>
#include <QGridLayout>
#include <iostream>
#include <QRect>

#include "choiceClientDialog.h"
#include "qButtonImproved.h"

#include "ui_listeWidget.h"

#define MODE_ADMIN 12321
#define MODE_CLIENT 12421
#define ALL_MOVIES 32423
#define MOVIES ~ALL_MOVIES

class ListeWidget: public QWidget, private Ui::ListeForm
{
	Q_OBJECT
	public:
		ListeWidget(QToolBox* toolBox,int mode,QWidget* parent=0);
		ListeWidget(QToolBox* toolBox,int mode, int view,QWidget* parent=0);
		~ListeWidget();
		void load();
		void clean();
		void switchMovies();
		int getMode();
		QToolBox* getToolBox();
		vector<Film> getFilmsSelect();
		Film* getFilmSelect();
		int getViewMode();
	private:
		vector<QButtonImproved*> boutons;
		vector<Film> films;
		QToolBox* toolbox;
		QGridLayout* layout;
		ChoiceClientDialog* dialClient;
		int mode;
		int viewMode;
	private slots:
		void showDetail();
};

#endif

