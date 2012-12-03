
#include "choiceClientDialog.h"


ChoiceClientDialog::ChoiceClientDialog(QToolBox* toolbox,QWidget*parent):
	QDialog(parent),Ui::clientDialog()
{
	setupUi(this);
	this->toolBox = toolbox;
	this->isShowed = false;

	QObject::connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(detailsButton,SIGNAL(clicked()),this,SLOT(toDetail()));
}


ChoiceClientDialog::~ChoiceClientDialog()
{}

void ChoiceClientDialog::setIdFilm(int idfilm)
{
	this->idFilm = idfilm;
}

void ChoiceClientDialog::toDetail()
{	
	if (!this->isShowed)
	{
		details = new  DetailWidget(this->toolBox,this->parentWidget());
		details->setVisible(true);
		details->setGeometry(0,0,((QFrame*)this->parentWidget())->frameRect().width(),
			((QFrame*)this->parentWidget())->frameRect().height());
		details->setBrother(this);
	}

	details->load(this->idFilm);
	
	if (!this->isShowed)
	{
		toolBox->addItem(details,QString::fromUtf8("Détails du film"));
	}
	toolBox->setCurrentIndex(1);
	
	this->accepted();
	this->close();

	isShowed = true;
}


void ChoiceClientDialog::toReservation()
{
	//TODO
}

