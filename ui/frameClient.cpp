
#include "frameClient.h"

FrameClient::FrameClient(QWidget* parent=0)
{
	setupUi(this);
	detail = new DetailWidget(this);
	detail.setVisible(true);
	detail.setGeometry(0,0,this.frameRect().width(),this.frameRect().height());
}

FrameClient::~FrameClient()
{}

void FrameClient::displayDetail(int id)
{
	detail.load(new Film(id));
	detail.setVisible(true);	
}

void FrameClient::displayListe()
{
	detail.setVisible(false);
}

