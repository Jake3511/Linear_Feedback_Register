// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// Also editted by Jake Shick
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>
#include "FibLFSR.hpp"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

// Makes sure generate does pass if value is in ascii table form
BOOST_AUTO_TEST_CASE(testStepInstr3) {
  FibLFSR l3("1011011000110110");
  BOOST_CHECK_EQUAL(l3.generate(9), '3');
}

// Makes sure step does not work if value is inncorrect
BOOST_AUTO_TEST_CASE(testStepInstr4) {
  FibLFSR l4("1011011000110110");
  BOOST_REQUIRE_EQUAL(!l4.step(), 1);
}

// Makes sure program does not work correctly if enetered garbage characters
BOOST_AUTO_TEST_CASE(testStepInstr5) {
  FibLFSR l5("a0bc0d1000110110");
  BOOST_REQUIRE_EQUAL(!l5.generate(4), 1);
}

// Makes sure program will return correct XOR value
BOOST_AUTO_TEST_CASE(testStepInstr6) {
  FibLFSR l6("1011011000110110");
  BOOST_REQUIRE_EQUAL(l6.XOR(), 0);
}
