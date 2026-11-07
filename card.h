// card.h
// Author: Ruohan Zhou
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card{
public:

  Card();
  Card(string s, string v);

  bool operator<(const Card& b) const;
  bool operator==(const Card& b) const;
  bool operator>(const Card& b) const;

  string gsuit() const;
  string gval() const;

private:
  string suit;
  string val;
};

ostream& operator<<(ostream& os, const Card& c);
#endif
