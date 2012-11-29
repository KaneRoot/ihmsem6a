TEMPLATE = app
TARGET = ausdgdfpuc
QT += core \
	  gui
HEADERS += utils/fileutils.h\
			utils/film.h\
			ui/accueil.h\
			ui/connection.h\
			ui/frameClient.h\
			ui/frameAdmin.h\
			ui/detailWidget.h
SOURCES += utils/fileutils.cpp\
			utils/film.cpp\
			ui/accueil.cpp\
		 	ui/connection.cpp\
		 	ui/frameClient.cpp\
		 	ui/frameAdmin.cpp\
		 	ui/detailWidget.cpp\
		 	main.cpp
FORMS += ui/accueil.ui\
		 ui/connectionBox.ui\
		 ui/frameClient.ui\
		 ui/frameAdmin.ui\
		 ui/detailWidget.ui\
