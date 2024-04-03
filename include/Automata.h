// Copyright 2024 CSB_lab3

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include<vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
};

class Automata {
 private:
    int cash = 0;
    std::vector<std::string> menu;
    std::vector<int> price;
    STATES state = STATES::OFF;
 public:
    int google();
    void setMenu(std::vector<std::string>);
    void setPrice(std::vector<int>);
    std::string statusCheck();
    void on();
    void off();
    void coin(int);
    void getMenu();
    void getState();
    void choice(int);
    bool check(int);
    void cancel();
    void cook(int);
    void finish();
};
#endif
