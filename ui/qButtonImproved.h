
#ifndef __QBUTTONIMPROVED__
#define __QBUTTONIMPROVED__

#include <QPushButton>
#include <QWidget>


class QButtonImproved:public QPushButton
{
	public:
		QButtonImproved(const QString& text,QWidget* parent=0,int id=0);
		QButtonImproved(const QIcon &icon,const QString& text,QWidget* parent=0,
				int id=0);
		~QButtonImproved();
		int getId();
		void setId(int id);
	private:
		int id;
};

#endif
