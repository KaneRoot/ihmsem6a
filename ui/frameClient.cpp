
#include "frameClient.h"

FrameClient::FrameClient(QWidget* parent):QFrame(parent),Ui::FormClient()
{
	setupUi(this);
	liste = new ListeWidget(this);
	liste->setVisible(true);
	liste->setGeometry(0,0,this->frameRect().width(),
			this->frameRect().height());
}
FrameClient::~FrameClient()
{}


void FrameClient::displayList()
{
//	detail.setVisible(false);
}

