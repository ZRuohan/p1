// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;
  set<Card> alice;
  set<Card> bob;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    string s = line.substr(0,1);
    string v = line.substr(2);
    alice.insert(Card(s,v));
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    string s = line.substr(0,1);
    string v = line.substr(2);
    bob.insert(Card(s,v));
  }
  cardFile2.close();

  bool isA = true;
 while (true) {
   bool find = false;

   if (isA) {//a
     set<Card>::iterator it;
     for (it = alice.begin(); it != alice.end(); ++it) {

       set<Card>::iterator bit;
       for (bit = bob.begin(); bit != bob.end(); ++bit) {
         if (*it == *bit) {
           find = true;
           break;
         }
       }

       if (find) {
         Card c = *it;
         cout << "Alice picked matching card " << c << "\n";
         alice.erase(c);
         bob.erase(c);
         break;
       }
     }
   }

   else {
     set<Card>::iterator it;
     Card temp;

     for (it = bob.begin(); it != bob.end(); ++it) {

       set<Card>::iterator ait;
       for (ait = alice.begin(); ait != alice.end(); ++ait) {
         if (*it == *ait) {
           temp = *it;
           find = true;
           break;
         }
       }

 //}
 //find = true;
}

if (find) {
 cout << "Bob picked matching card " << temp << "\n";
 alice.erase(temp);
 bob.erase(temp);
 find = true;
}
}

   if (!find) {
     break;
   }
   //isA = fals
   //}
   isA = !isA;
 }

//OP

 cout << "\nAlice's cards:" << endl;
   for (set<Card>::iterator ait = alice.begin(); ait != alice.end(); ++ait) {
     Card c = *ait;
     cout << c << "\n";
   }

   cout << "\nBob's cards:" << endl;
   for (set<Card>::iterator bit2 = bob.begin(); bit2 != bob.end(); ++bit2) {
     Card c = *bit2;
     cout << c << "\n";
   }
 return 0;
}
