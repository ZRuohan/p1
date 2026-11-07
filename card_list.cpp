// card_list.cpp
// Author: Ruohan Zhou
// Implementation of the classes defined in card_list.h
#include "card_list.h"

CardBST::CardBST() {
    root = nullptr;
}

CardBST::~CardBST() {
    del(root);
}

void CardBST::del(Node* n) {
    if (!n){
      return;
    }
    del(n->l);
    del(n->r);
    delete n;
}

bool CardBST::contains(Card c) {
    if (find(root, c)) {
        return true;
    }
    return false;
}

CardBST::Node* CardBST::find(Node* n, Card tar) {
    while (n) {
        if (n->data == tar) {
            return n;
        }
        if (tar < n->data) {
            n = n->l;
        } else {
            n = n->r;
        }
    }
    return nullptr;
}

//
void CardBST::insert(Card c) {
    if (!root) {
        root = new Node(c);
        return;
    }

    Node* n = root;
    Node* par = nullptr;

    while (n) {
        par = n;
        if (c == n->data) {
            return;
        }
        if (c < n->data) {
            n = n->l;
        } else {
            n = n->r;
        }
    }

    Node* newNode = new Node(c);
    newNode->p = par;

    if (c < par->data) {
        par->l = newNode;
    } else {
        par->r = newNode;
    }
}

void CardBST::printall() {
    if (!root) return;

      Node* n = root;
      while (n->l) {
          n = n->l;
    }

    while (n) {
        cout << n->data << "\n";

          if (n->r) {
              n = n->r;
              while (n->l) {
                n = n->l;
            }
        } else {
            Node* par = n->p;
            while (par && n == par->r) {
                n = par;
                par = par->p;
            }
            n = par;
        }
    }
}



void CardBST::remove(Card c) {
    Node* n = find(root, c);
    if (!n) return;

    Node* tar = n;
    if (n->l && n->r) {
        tar = n->r;
        while (tar->l) {
            tar = tar->l;
        }
        n->data = tar->data;
    }

    Node* ch = nullptr;
    if (tar->l) {
        ch = tar->l;
    } else if (tar->r) {
        ch = tar->r;
    }

    if (ch) {
        ch->p = tar->p;
    }

    if (!tar->p) {
        root = ch;
    } else if (tar == tar->p->l) {
        tar->p->l = ch;
    } else {
        tar->p->r = ch;
    }

    delete tar;
}


Card& CardBST::Iterator::operator*() {
    return curr->data;
}

bool CardBST::Iterator::operator!= (const Iterator& other) {
    return curr!= other.curr;}
bool CardBST::Iterator::operator== (const Iterator& other) {
    return curr== other.curr;}

CardBST::Iterator& CardBST::Iterator::operator++() {
    if (curr->r) {
        curr = curr->r;
        while (curr && curr->l) {
            curr = curr->l;
        }
    } else {
        Node* par = curr->p;
        while (par && curr == par->r) {
            curr = par;
            par = par->p;
        }
        curr = par;
    }
    return *this;
}

CardBST::Iterator& CardBST::Iterator::operator--() {
    if (curr->l) {
        curr = curr->l;
        while (curr && curr->r) {
            curr = curr->r;
        }
    } else {
        Node* par = curr->p;
        while (par && curr == par->l) {
            curr = par;
            par = par->p;
        }
        curr = par;
    }
    return *this;
}

CardBST::Iterator CardBST::begin() {
    if (!root) {
      return Iterator(nullptr);}
    Node* n = root;
    while (n->l) {
        n = n->l;
    }
    return Iterator(n);
}
CardBST::Iterator CardBST::rbegin() {
    if (!root) {
      return Iterator(nullptr);}
    Node* n = root;
    while (n->r) {
        n = n->r;
    }
    return Iterator(n);
}

CardBST::Iterator CardBST::end() {
    return Iterator(nullptr);
}
CardBST::Iterator CardBST::rend() {
    return Iterator(nullptr);
}

void playGame(CardBST& alice, CardBST& bob) {



  bool isA = true;
 while (true) {
   bool find = false;

   if (isA) {//a
     CardBST::Iterator it;
     for (it = alice.begin(); it != alice.end(); ++it) {

       if (bob.contains(*it)) {
           find = true;
       }

       if (find) {
         Card c = *it;
         cout << "Alice picked matching card " << c << "\n";
         alice.remove(c);
         bob.remove(c);
         break;
       }
     }
   }

   else {
     CardBST::Iterator it;
     Card temp;

     for (it = bob.rbegin(); it != bob.rend(); --it) {

       if (alice.contains(*it)) {
           temp = *it;
           find = true;
           break;
       }

 //}
 //find = true;
}

if (find) {
 cout << "Bob picked matching card " << temp << "\n";
 alice.remove(temp);
 bob.remove(temp);
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
   for (CardBST::Iterator ait = alice.begin(); ait != alice.end(); ++ait) {
     Card c = *ait;
     cout << c << "\n";
   }

   cout << "\nBob's cards:" << endl;
   for (CardBST::Iterator bit2 = bob.begin(); bit2 != bob.end(); ++bit2) {
     Card c = *bit2;
     cout << c << "\n";
   }}
