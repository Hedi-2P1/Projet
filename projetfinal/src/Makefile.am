## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projetfinal

projetfinal_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	Ouvrier.c Ouvrier.h \
	plante.c plante.h \
	troupeau.c troupeau.h \
	capteur.c capteur.h

projetfinal_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

