
#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include "ui_connectionBox.h"

class ConnectionDial:public QDialog,private Ui::connectionDial
{
	Q_OBJECT
	public:
		ConnectionDial(QWidget* parent=0);
		~ConnectionDial();
};





#endif

