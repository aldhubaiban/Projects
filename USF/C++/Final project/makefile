blackjack:	dealer.o	player.o	blackjack.o
	g++	-std=c++14	-o	blackjack	blackjack.o	player.o	dealer.o
blackjack.o:	blackjack.cpp	player.h	dealer.h
	g++	-std=c++14	-c	-Wall	blackjack.cpp
dealer.o:	dealer.cpp	dealer.h
	g++	-std=c++14	-c	-Wall	-g	dealer.cpp
player.o:	player.cpp	player.h
	g++	-std=c++14	-c	-Wall	-g	player.cpp

	
