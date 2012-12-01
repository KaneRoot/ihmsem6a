
#ifndef __LISTWIDGET__
#define __LISTWIDGET__

#include "../utils/film.h"

#include <QGridLayout>
#include <iostream>

#include "detailWidget.h"
#include "ui_listeWidget.h"

class ListeWidget: public QWidget, private Ui::ListeForm
{
	Q_OBJECT
	public:
		ListeWidget(QWidget* parent=0);
		~ListeWidget();
		void load();
	private:
		vector<QPushButton*> boutons;
		vector<Film> films;
		DetailWidget* detail;
	private slots:
		void showDetail();
};

#endif

