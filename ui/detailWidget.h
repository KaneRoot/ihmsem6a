
#ifndef __DETAILWIDGET__
#define __DETAILWIDGET__

#include "../utils/film.h"
#include "../utils/horaire.h"

#include "paiementWidget.h"
#include <iostream>
#include <QToolBox>

#include "ui_detailWidget.h"

class DetailWidget : public QWidget, private Ui::DetailForm
{
	Q_OBJECT
	public:
		DetailWidget(QToolBox* toolbox,QWidget* parent=0);
		~DetailWidget();
		void setBrother(QWidget* bro);
		void setToolBox(QToolBox* toolbox);
		QToolBox* getToolBox();
		void load(Film* f);
	private:
		void cleanCombo();
		Film *film;
		QWidget* brother;
		QToolBox* toolBox;
	private slots:
		void retour();
		void toReserve();
};

#endif


