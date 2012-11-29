#ifndef __FRAMEADMIN__
#define __FRAMEADMIN__


#include <QFrame>
#include "ui_frameAdmin.h"


class FrameAdmin:public QFrame, private Ui::FormAdmin
{
	public:
		FrameAdmin(QWidget* parent=0);
		~FrameAdmin();
	private:
		//DetailEditWidget* detail;
		//ListeEditWidget* liste;
};



#endif

