
#ifndef __DETAILWIDGET__
#define __DETAILWIDGET__

#include "../utils/film.h"
//#include "../utils/horaire.h"


#include <iostream>

#include "ui_detailWidget.h"

class DetailWidget : public QWidget, private Ui::DetailForm
{
	Q_OBJECT
	public:
		DetailWidget(QWidget* parent=0);
		~DetailWidget();
		void load(int i);//(Film* f);
	private:
		Film film;
	private slots:
		void retour();
};

#endif


