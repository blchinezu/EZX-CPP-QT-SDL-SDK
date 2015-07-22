#############################################################################
# Makefile for building libqt-ext
# Created by Wang Bin wbsecg1@gmail.com, 2011/01/28
#     Project: libqt-ext
#############################################################################

CC		=	arm-linux-gcc
CXX		=	arm-linux-g++
INCPATH	=	-I$(QTDIR)/include/ezx -I$(QTDIR)/include/qt-2.3.8 -I$(QTDIR)/include/ezx 
#-I../templates
CXXFLAGS	+= $(CFLAGS	=	-pipe -Wall -W -O2 -mcpu=iwmmxt -mtune=iwmmxt -DNO_DEBUG $(INCPATH)
CXXFLAGS=	-pipe -DQWS -fpic -fno-exceptions -fno-rtti -Wall -W -O2 -mcpu=iwmmxt -mtune=iwmmxt -DNO_DEBUG $(INCPATH)
LINK	=	arm-linux-g++
LFLAGS	=	-shared
LIBS	=	$(SUBLIBS) -L$(QTDIR)/lib -lezxappsdk -lezxopenwindow -lipp-miscGen -lezxappbase -lqte-mt -lezxjpeg -lezxpm

MOC		=	$(QTDIR)/bin/moc
UIC		=	$(QTDIR)/bin/uic
AR		=	arm-linux-ar r
RANLIB	=	arm-linux-ranlib
TAR		=	tar -cf
GZIP	=	gzip -9f
BZ		= 	bzip2 --compress --force -9

HEADERS_QOBJ =	animatrix.h \
		qcolordialog.h \
		qfiledialog.h \
		qfontdialog.h \
		tips.h \
		qlcdnumber.h \
		qbusybar.h \
		qlangcombo.h \
		qdial.h \
		fileview.h \
		qabstractlanglist.h \
		qlangmenu.h \
		QProgressIndicator.h \
		QColorPickerDlg.h \
		ZFileDialog.h \
		qprocess.h \
		qtabbar.h \
		qtabwidget.h
		
HEADERS		+=	$(HEADERS_QOBJ)		
SRCS_QOBJ	= $(HEADERS_QOBJ:.h=.cpp)
SRCS_MOC	= $(join $(dir $(SRCS_QOBJ)),$(patsubst %,moc_%,$(notdir $(SRCS_QOBJ))))
OBJS_QOBJ	= $(addprefix objs/,$(patsubst %.cpp,%.o,$(SRCS_QOBJ)))
OBJS_MOC	= $(patsubst ./%,objs/%,$(patsubst %.cpp,%.o,$(SRCS_MOC)))
#SRCS		+= $(SRCS_QOBJ)
SRCS		+= $(SRCS_QOBJ) $(SRCS_MOC)
OBJS		+= $(OBJS_QOBJ) $(OBJS_MOC)
TARGET		= ../lib/libqt-ext.so
TARGETA 	= ../lib/libqt-ext.a
DEP 		= $(OBJS:.o=.d)

####### Build rules
all: moc.dep $(TARGET) $(TARGETA)

%.o: %.cpp
	echo making $@...
	$(CXX) -c $(CXXFLAGS) -o $@ $<

objs/%.o: %.cpp
	@echo making $@...
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
objs/%.d: %.cpp
	-$(CXX) $(CXXFLAGS) -w -MM $^ >$@
	-sed -i '1s/\(.*\)/objs\/\1/' $@
	
.depend: $(SRCS) $(SRCS_QOBJ) $(SRCS_MOC)
	$(CXX) $(CXXFLAGS) -w -MM $^ > $@

	
$(TARGET): $(OBJS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
	
	
$(TARGETA): $(UICDECLS) $(OBJS)
	$(AR) $@  $(QTABOBJS) $^ 
	$(RANLIB) $@

moc.dep: $(HEADERS_QOBJ)
	echo "#Rules of moc srcs" >$@
	@for header in $(HEADERS_QOBJ); do \
		echo `echo ./$$header |sed 's/\(.*\)\/\(.*\).h/\1\/moc_\2.cpp/'`: $$header >>$@; \
		echo '	$$(MOC) $$< >$$@' >>$@; \
		echo >>$@; \
	done
	 
dist:
	$(TAR) $(basename $(TARGET)).tar makefile $(SRCS_QOBJ) $(HEADERS_QOBJ) $(INTERFACES)
	$(BZ) $(basename $(TARGET)).tar
	mv $(basename $(TARGET)).tar.bz2 ..

clean:
	-rm -f $(OBJS) $(OBJS_MOC) $(SRCS_MOC) $(TARGET) $(DEP)
	-rm -f `find ./ -name \*~` core

install: strip
	cp -auf $(TARGETA) $(TARGET) $(QTDIR)/src/qt-ext/lib/
	cp -auf $(TARGET) ./
	cp -auf $(HEADERS_QOBJ) $(QTDIR)/include/qt-ext/
	cp -auf $(SRCS_QOBJ) makefile $(QTDIR)/src/qt-ext/


include moc.dep
include $(DEP)
#moc_%.cpp: moc.dep
	
strip: $(TARGET)
	cp $< $<_unstripped
	-arm-linux-strip $<


#objs/%.o: %.cpp %.moc %.h .%.d
#	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<
	
#objs/moc_%.o: moc_%.cpp .%.d
#	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<
#%.moc: %.cpp
#	$(MOC) $< -o $@

#moc_%.cpp: %.h
#	$(MOC) $< -o $@

