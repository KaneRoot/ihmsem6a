
#include "choiceAdminDialog.h"

ChoiceClientDialog::ChoiceClientDialog(QToolBox* toolbox, QWidget* parent):
	QDialog(parent),Ui::choiceAdminDialog()
{
	setupUi(this);
	this->toolBox = toolbox;
	this->isEditShowed = false;
}

ChoiceClientDialog::~ChoiceClientDialog()
{}

void ChoiceClientDialog::setFim(Film *film)
{
	this->film = film;
}

void ChoiceClientDialog::toEdit()
{
	if (!this->isEditShowed)
	{
		edit=new DetailEditWidget(this->film,this->toolBox,
				this->parentWidget());
		toolBox->addItem(edit,QString::fromUtf8("Edition Film"));	
	}
	
}

void ChoiceClientDialog::toCreate()
{
}

void ChoiceClientDialog::toDelete()
{
}


