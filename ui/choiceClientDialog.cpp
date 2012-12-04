
#include "choiceClientDialog.h"


ChoiceClientDialog::ChoiceClientDialog(QToolBox* toolbox,QWidget*parent):
	QDialog(parent),Ui::clientDialog()
{
	setupUi(this);
	this->toolBox = toolbox;
	this->isShowed = false;

	QObject::connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(detailsButton,SIGNAL(clicked()),this,SLOT(toDetail()));
	QObject::connect(reserveButton,SIGNAL(clicked()),this,SLOT(toReserv()));
}


ChoiceClientDialog::~ChoiceClientDialog()
{}

void ChoiceClientDialog::setFilm(Film* film)
{
	this->film = film;

	for (int i=0;i<horaireComboBox->count();i++)
	{
		horaireComboBox->removeItem(0);
	}

	vector<int> liste = film->getHorairesLibres();
	vector<int>::iterator it;
	Horaire::init();
	for (it=liste.begin();it!=liste.end();it++)
	{
		horaireComboBox->addItem(QString::fromUtf8(Horaire::getHoraire(*it).c_str()),
				QVariant(*it));
	}	
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

	details->load(this->film);
	
	if (!this->isShowed)
	{
		toolBox->addItem(details,QString::fromUtf8("Détails du film"));
	}
	toolBox->setCurrentIndex(1);
	
	this->accepted();
	this->close();

	isShowed = true;
}


void ChoiceClientDialog::toReserv()
{
	string abo = comboBox->itemText(comboBox->currentIndex()).toStdString();
	PaiementWidget* paiement = new PaiementWidget(abo,
			spinBox->value(),1,toolBox,this);
	paiement->show();
}

