// Copyright 2024 CSB_lab3

#include "Automata.h"

#include<iostream>
#include<vector>

void Automata::on() {
    if (state == STATES::OFF) {
        std::cout << "Activation\n";
        state = STATES::WAIT;
        }
}
void Automata::off() {
    if (state == STATES::WAIT) {
        std::cout << "Shutdown\n";
        state = STATES::OFF;
        }
}

void Automata::coin(int amount) {
     if (state == STATES::WAIT || state == STATES::ACCEPT) {
         std::cout << "Please make a deposit\n";
         cash += amount;
         std::cout << "You have deposited " <<
             amount <<"\nCurrent deposit is " << cash << "\n";
         state = STATES::ACCEPT;
         }
}

void Automata::getMenu() {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        std::cout << "Please see menu below:\n";
        for (int i = 0; i < menu.size(); i++) {
             std::cout << "\t" << "(" << i + 1 << ")" <<
                 menu[i] << " - " << price[i];
             }
    }
}

void Automata::getState() {
     switch (state) {
         case STATES::OFF:
             std::cout << "Current status - OFF";
         case STATES::WAIT:
             std::cout << "Current status - WAIT";
         case STATES::ACCEPT:
             std::cout << "Current status - ACCEPT";
         case STATES::CHECK:
             std::cout << "Current status - CHECK";
         case STATES::COOK:
             std::cout << "Current status - COOK";
             }
}

void Automata::choice(int productID) {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        if (productID<0 || productID - 1 > menu.size()) {
            std::cout << "ERROR!\n" << "Non existant product";
            return;
        } else if (!check(productID-1)) {
            state = STATES::CHECK;
            std::cout << "ERROR\n" << "Not enough money on deposit";
            return;
        } else {
            cash -= price[productID-1];
            cook(productID-1);
        }
    }
}

bool Automata::check(int productID) {
    if (price[productID] > cash) {
        return false;
        } else {
            return true;
        }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        cash = 0;
        std::cout << "Operation has been cancelled\n";
        state = STATES::WAIT;
    }
}

void Automata::cook(int productID) {
    std::cout << menu[productID] << " is being prepared\n";
    state = STATES::COOK;
    std::cout << menu[productID] << " is ready!";
}

void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
    }
}

void Automata::setMenu(std::vector<std::string> menuValue) {
    for (int i=0; i < menuValue.size(); i++) {
        menu.push_back(menuValue[i]);
    }
}

void Automata::setPrice(std::vector<int> priseValue) {
    for (int i=0; i < priseValue.size(); i++) {
        price.push_back(priseValue[i]);
    }
}

std::string Automata::statusCheck() {
    switch (state) {
        case STATES::OFF:
            return "OFF";
        case STATES::WAIT:
             return "WAIT";
        case STATES::ACCEPT:
             return "ACCEPT";
        case STATES::CHECK:
             return "CHECK";
        case STATES::COOK:
             return "COOK";
    }
}
