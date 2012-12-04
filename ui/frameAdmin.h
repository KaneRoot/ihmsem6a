#ifndef __FRAMEADMIN__
#define __FRAMEADMIN__

#include <QFrame>

#include "../utils/film.h"

#include "ui_frameAdmin.h"
#include "listeWidget.h"
#include "detailEditWidget.h"

class FrameAdmin:public QFrame, private Ui::FormAdmin
{
	Q_OBJECT
	public:
		FrameAdmin(QWidget* parent=0);
		~FrameAdmin();
	private:
		ListeWidget* liste;
		DetailEditWidget* detailEdit;
		DetailEditWidget* detailCreate;
		bool isEditShowed;
		bool isCreateShowed;
	private slots:
		void toEdit();
		void toCreate();
		void toDelete();
};



#endif

