// Copyright 2024 CSB_lab3

#include "gtest/gtest.h"
#include "Automata.h"

TEST(test, on) {
    Automata test;
    test.on();
    EXPECT_EQ("WAIT", test.statusCheck());
}

TEST(test, incorrectAction) {
    Automata test;
    test.coin(10);
    test.coin(20);
    EXPECT_EQ("OFF", test.statusCheck());
}

TEST(test, off) {
    Automata test;
    test.on();
    test.off();
    EXPECT_EQ("OFF", test.statusCheck());
}

TEST(test, coin) {
    Automata test;
    test.on();
    test.coin(10);
    EXPECT_EQ("ACCEPT", test.statusCheck());
}

TEST(test, okMoney) {
    Automata test;
    test.on();
    test.coin(100);
    test.choice(1);
    EXPECT_EQ(true, test.check(0));
}

TEST(test, cancel) {
    Automata test;
    test.on();
    test.coin(200);
    test.cancel();
    EXPECT_EQ("WAIT", test.statusCheck());
}

TEST(test, noMoney) {
    Automata test;
    test.on();
    test.coin(5);
    test.choice(1);
    EXPECT_EQ(false, test.check(0));
}

TEST(test, invalidProduct) {
    Automata test;
    test.on();
    test.coin(50);
    test.choice(8);
    EXPECT_EQ("ACCEPT", test.statusCheck());
}

TEST(test, cook) {
    Automata test;
    test.on();
    test.coin(100);
    test.choice(2);
    test.cook(1);
    EXPECT_EQ("COOK", test.statusCheck());
}

TEST(test, finish) {
    Automata test;
    test.on();
    test.coin(100);
    test.choice(2);
    test.cook(1);
    test.finish();
    EXPECT_EQ("WAIT", test.statusCheck());
}
