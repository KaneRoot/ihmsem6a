
#ifndef __DETAILEDIT__
#define __DETAILEDIT__

#include "ui_detailEditWidget.h"

#include <QToolBox>

#include "../utils/film.h"
#include "../utils/horaire.h"

#define MODE_CREATE 1125
#define MODE_EDIT 1124

class DetailEditWidget: public QWidget, private Ui::detailEditForm
{
	Q_OBJECT
	public:
		DetailEditWidget(QToolBox* toolbox, QWidget* parent=0);
		DetailEditWidget(Film* f,QToolBox* toolbox, QWidget* parent=0);
		~DetailEditWidget();
		int getMode();
	private:
		void initSignal();
		void loadHoraire();
		int mode;
		Film *film;
		vector<QCheckBox*> checks;
		QToolBox* toolBox;
	private slots:
		void saveFilm();
		void editFilm();
		void selectAll();
		void closeWidget();
};

#endif
