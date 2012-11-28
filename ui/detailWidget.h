
#ifndef __DETAILWIDGET__
#define __DETAILWIDGET__

#include "film.h"
#include "horaire.h"


class DetailWidget:public QWidget, private Ui::detailWidget
{
	Q_OBJECT
	public:
		DetailWidget(QWidget* parent=0);
		~DetailWidget();
		void load(Film f);
	private:
		Film film;
		setDetail();
	private slots:
		void retour();
};

#endif


