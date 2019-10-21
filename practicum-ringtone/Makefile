#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

generator.exe : generator.o rtttl.o
	g++ -std=c++17 generator.o rtttl.o -o generator.exe

generator.o : generator.cpp
	g++ -std=c++17 -c generator.cpp -o generator.o

rtttl.o : rtttl_player.cpp rtttl_player.hpp note_player_pc.hpp note.hpp
	g++ -std=c++17 -c rtttl_player.cpp -o rtttl.o

melody.cpp : generator.exe
	./generator.exe

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += note.hpp
SOURCES += melody.cpp
HEADERS += melody.hpp
HEADERS += note_player.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
