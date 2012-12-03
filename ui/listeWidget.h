
#ifndef __LISTWIDGET__
#define __LISTWIDGET__

#include "../utils/film.h"

#include <QToolBox>
#include <QGridLayout>
#include <iostream>

#include "qButtonImproved.h"
#include "detailWidget.h"
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
		int getMode();
	private:
		vector<QButtonImproved*> boutons;
		vector<Film> films;
		DetailWidget* detail;
		QToolBox* toolbox;
		int mode;
		bool showed;
	private slots:
		void showDetail();
};

#endif

