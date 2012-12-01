TEMPLATE = app
TARGET = ausdgdfpuc
QT += core \
	  gui
HEADERS += utils/fileutils.h\
			utils/type.h\
			utils/film.h\
			ui/accueil.h\
			ui/connection.h\
			ui/frameClient.h\
			ui/frameAdmin.h\
			ui/detailWidget.h\
			ui/listeWidget.h
SOURCES += utils/fileutils.cpp\
			utils/type.cpp\
			utils/film.cpp\
			ui/accueil.cpp\
		 	ui/connection.cpp\
		 	ui/frameClient.cpp\
		 	ui/frameAdmin.cpp\
		 	ui/detailWidget.cpp\
			ui/listeWidget.cpp\
		 	main.cpp
FORMS += ui/accueil.ui\
		 ui/connectionBox.ui\
		 ui/frameClient.ui\
		 ui/frameAdmin.ui\
		 ui/listeWidget.ui\
		 ui/detailWidget.ui\
