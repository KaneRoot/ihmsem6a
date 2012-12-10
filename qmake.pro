TEMPLATE = app
TARGET = ausdgdfpuc
QT += core \
	  gui
HEADERS += utils/fileutils.h\
			utils/type.h\
			utils/film.h\
			utils/salle.h\
			utils/planning.h\
			utils/horaire.h\
			utils/user.h\
			ui/qButtonImproved.h\
			ui/accueil.h\
			ui/connection.h\
			ui/frameClient.h\
			ui/frameAdmin.h\
			ui/choiceClientDialog.h\
			ui/detailWidget.h\
			ui/listeWidget.h\
			ui/paiementWidget.h\
			ui/detailEditWidget.h\
			ui/ticketDialog.h
SOURCES += utils/fileutils.cpp\
			utils/type.cpp\
			utils/salle.cpp\
			utils/film.cpp\
			utils/planning.cpp\
			utils/horaire.cpp\
			utils/user.cpp\
			ui/qButtonImproved.cpp\
			ui/accueil.cpp\
		 	ui/connection.cpp\
		 	ui/frameClient.cpp\
		 	ui/frameAdmin.cpp\
		 	ui/detailWidget.cpp\
			ui/choiceClientDialog.cpp\
			ui/listeWidget.cpp\
			ui/paiementWidget.cpp\
			ui/detailEditWidget.cpp\
			ui/ticketDialog.cpp\
		 	main.cpp
FORMS += ui/accueil.ui\
		 ui/connectionBox.ui\
		 ui/frameClient.ui\
		 ui/frameAdmin.ui\
		 ui/listeWidget.ui\
		 ui/choiceClientDialog.ui\
		 ui/detailWidget.ui\
		 ui/detailEditWidget.ui\
		 ui/paiementWidget.ui\
		 ui/ticket.ui
