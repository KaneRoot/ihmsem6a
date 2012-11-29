
#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include "ui_connectionBox.h"

class ConnectionDial:public QDialog,public Ui::connectionDial
{
	Q_OBJECT
	public:
		ConnectionDial(QWidget* parent=0);
		~ConnectionDial();
		bool isConnect();
	private:
		bool isOk;
	private slots:
		void validation();

};





#endif

