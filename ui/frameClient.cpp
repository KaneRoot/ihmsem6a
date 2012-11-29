
#include "frameClient.h"

FrameClient::FrameClient(QWidget* parent):QFrame(parent),Ui::FormClient()
{
	setupUi(this);
	detail = new DetailWidget(this);
	detail->setVisible(true);
	detail->setGeometry(0,0,this->frameRect().width(),this->frameRect().height());
}
FrameClient::~FrameClient()
{}

void FrameClient::displayDetail(int id)
{
//	detail->load(new Film(id));
	std::cout << id << "\n";
	detail->setVisible(true);	
}

void FrameClient::displayList()
{
//	detail.setVisible(false);
}

