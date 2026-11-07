// card.cpp
// Author: Ruohan Zhou
// Implementation of the classes defined in card.h
#include "card.h"

int toi(string a){
    if (a == "c") return 0;
    if (a == "d") return 1;
    if (a == "s") return 2;
    if (a == "h") return 3;
    if (a == "a") return 1;
    if (a == "j") return 11;
    if (a == "q") return 12;
    if (a == "k") return 13;
    return stoi(a);
}

Card::Card():suit("c"),val("a"){}
Card::Card(string s, string v): suit(s), val(v){}

string Card::gsuit() const{
  return suit;
}

string Card::gval() const{
  return val;
}

bool Card::operator<(const Card&b) const{
  int as = toi(suit);
  int bs = toi(b.suit);
  if(as != bs) return as < bs;
  else{
    return toi(val) < toi(b.val);
  }
}

bool Card::operator>(const Card&b) const{
  int as = toi(suit);
  int bs = toi(b.suit);
  if(as != bs) return as > bs;
  else{
    return toi(val) > toi(b.val);
  }
}

bool Card::operator==(const Card&b) const{
  return suit == b.suit && val == b.val;
}

ostream& operator<<(ostream& os, const Card& c) {
      os << c.gsuit() << " " << c.gval();
      return os;
}
