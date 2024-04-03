// Copyright 2024 CSB_lab3

#include <iostream>
#include "Automata.h"

int main()
{
	Automata Bumblebee;

	Bumblebee.setMenu({ "Tea", "Espresso", "Latte", "Hot chocolate"});
	Bumblebee.setPrice({ 5, 10, 15, 8 });
	Bumblebee.getMenu();
	Bumblebee.statusCheck();
	Bumblebee.on();
	Bumblebee.coin(10);
	Bumblebee.coin(10);
	Bumblebee.choice(4);
	Bumblebee.off();
	Bumblebee.getState();
	return 0;
}
