#include <iostream>
#include "card.h"
#include "card_list.h"
using namespace std;

int main() {
    {
        CardBST t;
        t.contains(Card("c","a"));
        t.printall();
        for (CardBST::Iterator it = t.begin(); it != t.end(); ++it) { }
        for (CardBST::Iterator it = t.rbegin(); it != t.rend(); --it) { }
        t.remove(Card("c","a"));
    }

    {
        CardBST t;
        t.contains(Card("c","a"));
        t.printall();
    }

    {
        CardBST t;
        t.insert(Card("s","5"));
        t.insert(Card("d","q"));
        for (CardBST::Iterator it = t.rbegin(); it != t.rend(); --it) { }
          t.remove(Card("s","5"));
        t.remove(Card("s","5"));
        t.printall();
    }

    {
        CardBST a, b;
        a.insert(Card("c","j"));
        a.insert(Card("s","10"));
        b.insert(Card("c","9"));
        b.insert(Card("d","2"));
        playGame(a, b);
    }

    {
        CardBST a, b;
        a.insert(Card("h","3"));
        a.insert(Card("s","10"));
        a.insert(Card("c","a"));
        a.insert(Card("c","3"));
        a.insert(Card("s","5"));
        a.insert(Card("h","10"));
        a.insert(Card("d","a"));
        b.insert(Card("c","2"));
        b.insert(Card("d","a"));
        b.insert(Card("h","10"));
        b.insert(Card("c","3"));
        b.insert(Card("d","j"));
        b.insert(Card("s","10"));
        b.insert(Card("h","a"));
        playGame(a, b);
    }

    {
        CardBST a, b;
        playGame(a, b);
    }

    return 0;
}
