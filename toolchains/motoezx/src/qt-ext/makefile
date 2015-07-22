#############################################################################
# Makefile for building libqt-ext
# Created by Wang Bin wbsecg1@gmail.com, 2011/01/28
#     Project: libqt-ext
#`moc.dep(rules to generate moc_%.cpp)->%.d->%.o
#############################################################################

HOST	= arm-linux

CC		= gcc
CXX		= g++
STRIP	= strip
AR		= ar
AS		= as
RANLIB	= ranlib

ifneq ($(HOST),)
HOSTE	:= $(addsuffix -,$(HOST))
CC		:= $(addprefix $(HOSTE),$(CC))
CXX		:= $(addprefix $(HOSTE),$(CXX))
AR		:= $(addprefix $(HOSTE),$(AR))
AS		:= $(addprefix $(HOSTE),$(AS))
STRIP	:= $(addprefix $(HOSTE),$(STRIP))
RANLIB 	:= $(addprefix $(HOSTE),$(RANLIB))
endif

AR		:= $(AR) r
INCPATH	=	-I$(QTDIR)/include/ezx -I$(QTDIR)/include/qt-2.3.8 -I$(QTDIR)/include/ezx 
#-I../templates
CFLAGS	=	-pipe -Wall -W -O2 -mcpu=iwmmxt -mtune=iwmmxt -DNO_DEBUG $(INCPATH)
CXXFLAGS=	-pipe -DQWS -fpic -fno-exceptions -fno-rtti -Wall -W -O2 -mcpu=iwmmxt -mtune=iwmmxt -DNO_DEBUG $(INCPATH)
LINK	=	$(CXX)
LFLAGS	=	-shared
LIBS	=	$(SUBLIBS) -L$(QTDIR)/lib -lezxappsdk -lezxopenwindow -lipp-miscGen -lezxappbase -lqte-mt -lezxjpeg -lezxpm

MOC		=	$(QTDIR)/bin/moc
UIC		=	$(QTDIR)/bin/uic
TAR		=	tar -cf
GZIP	=	gzip -9f
BZ		= 	bzip2 --compress --force -9

############################################ Specify headers, qobject headers, srcs and targets below ############################################
HEADERS	= global.h
#HEADERS_QOBJ	= $(foreach h,$(HEADERS),$(if $(shell grep "Q_OBJECT" $(h)),$(h))) #very slow
HEADERS_QOBJ +=	animatrix.h \
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
		qprocess_unix.h \
		qtabbar.h \
		qtabwidget.h \
		qregvalidator.h

SRCS	= 

LIB_SO	= 
LIB_A 	= ../lib/libqt-ext.a
TARGET	= ../lib/libqt-ext.so
OBJDIR	= objs
#OBJDIR	= ./
############################################ Automatic ############################################
HEADERS		+=	$(HEADERS_QOBJ)		
SRCS_QOBJ	= $(HEADERS_QOBJ:.h=.cpp)
SRCS_MOC	= $(join $(dir $(SRCS_QOBJ)),$(patsubst %,moc_%,$(notdir $(SRCS_QOBJ))))
OBJS		:= $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(SRCS)))
OBJS_QOBJ	= $(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(SRCS_QOBJ)))
OBJS_MOC	= $(patsubst ./%,$(OBJDIR)/%,$(patsubst %.cpp,%.o,$(SRCS_MOC)))
SRCS		+= $(SRCS_QOBJ) $(SRCS_MOC)
OBJS		+= $(OBJS_QOBJ) $(OBJS_MOC)
DEP 		= $(OBJS:.o=.d)

############################################ Build rules ############################################
.PHONY: all clean dist strip install

all: $(TARGET) $(LIB_SO) $(LIB_A)

$(OBJDIR):
	test -d $@ || mkdir -p $@
	
%.o: %.cpp
	@echo "making $@..."
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJDIR)/%.o: %.cpp
	@echo "Making $@..."
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
$(OBJDIR)/%.d: %.cpp
	@echo "Generating $@..."
	-@$(CXX) $(CXXFLAGS) -w -MM $< |sed -e '1s/\(.*\)/$(OBJDIR)\/\1/' >$@
	
.depend: $(SRCS) $(SRCS_QOBJ) $(SRCS_MOC)
	$(CXX) $(CXXFLAGS) -w -MM $^ > $@
	
$(TARGET): $(OBJS)
	$(LINK) $(LFLAGS) -o $(TARGET) $^ $(LIBS)

$(LIB_SO): $(OBJS)
	$(LINK) $(LFLAGS) -o $(LIB_SO) $^ $(LIBS)
		
$(LIB_A): $(OBJS)
	$(AR) $@ $^ 
	$(RANLIB) $@

moc.dep: $(HEADERS_QOBJ)
	echo "################Rules of moc srcs!#################" >$@
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
	cp -auf $(LIB_A) $(TARGET) $(QTDIR)/src/qt-ext/lib/
	cp -auf $(TARGET) ./
	cp -auf $(HEADERS_QOBJ) $(QTDIR)/include/qt-ext/
	cp -auf $(SRCS_QOBJ) makefile $(QTDIR)/src/qt-ext/
	
strip: $(TARGET)
	cp $< $<_unstripped
	-$(STRIP) $<

-include moc.dep
-include $(DEP)

