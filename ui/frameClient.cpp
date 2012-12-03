
#include "frameClient.h"

FrameClient::FrameClient(QWidget* parent):QFrame(parent),Ui::FormClient()
{
	setupUi(this);
	toolBox->removeItem(0);
	toolBox->removeItem(0);

	liste = new ListeWidget(toolBox,MODE_CLIENT,toolBox);
	liste->setVisible(true);
	liste->setGeometry(0,0,this->frameRect().width(),
			this->frameRect().height());
	toolBox->addItem(liste,QString::fromUtf8("Catalogue de film"));
}

FrameClient::~FrameClient()
{}


void FrameClient::displayList()
{
//	detail.setVisible(false);
}

