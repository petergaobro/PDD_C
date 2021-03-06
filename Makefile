########################################################################
# COSC1076 - Advanced Programming Techniques
# Semester 2 2014 Assignment #2
# Full Name        : Peng Gao
# Student Number   : s3457558
# Course Code      : COSC1076
# Program Code     : BP162
# Start up code provided by Paul Miller
########################################################################
USER=s3457558
SOURCES=ppd_main.c ppd_menu.c ppd_options.c ppd_utility.c ppd_stock.c \
ppd_coin.c
HEADERS=ppd_main.h ppd_menu.h ppd_options.h ppd_utility.h ppd_stock.h \
ppd_coin.h
README=ppd_readme
MAKEFILE=Makefile

########################################################################

all: ppd_main.o ppd_menu.o ppd_options.o ppd_utility.o ppd_stock.o \
ppd_coin.o
	gcc -o ppd ppd_main.o ppd_menu.o ppd_options.o ppd_utility.o \
ppd_stock.o ppd_coin.o

########################################################################

ppd_main.o: ppd_main.c ppd_main.h ppd_menu.h ppd_options.h ppd_utility.h
	gcc -Wall -ansi -pedantic -c ppd_main.c
	
ppd_menu.o: ppd_menu.c ppd_menu.h
	gcc -Wall -ansi -pedantic -c ppd_menu.c
	
ppd_options.o: ppd_options.c ppd_options.h
	gcc -Wall -ansi -pedantic -c ppd_options.c
	
ppd_utility.o: ppd_utility.c ppd_utility.h
	gcc -Wall -ansi -pedantic -c ppd_utility.c

ppd_stock.o: ppd_stock.c ppd_stock.h
	gcc -Wall -ansi -pedantic -c ppd_stock.c

ppd_coin.o: ppd_coin.c ppd_coin.h
	gcc -Wall -ansi -pedantic -c ppd_coin.c

########################################################################
clean:
	@echo "cleaning ..."
	rm -f *.o ppd
########################################################################
# Move this target to the end of the Makefile to zip up your code 
# when submitting. Do not submit your .dat files, or directories. 
# We only want the files that are part of your implementation.
########################################################################
archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) $(README) $(MAKEFILE)
