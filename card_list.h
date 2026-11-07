// card_list.h
// Author: Ruohan Zhou
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include <iostream>
#include "card.h"
using namespace std;

class CardBST {
private:
    struct Node {
        Card data;
        Node* l;
        Node* r;
        Node* p;

        Node(Card c) {
            data = c;
            l = nullptr;
            r = nullptr;
            p = nullptr;
        }
    };

    Node* root;

      void del(Node* n);
      Node* find(Node* n, Card c);

public:
    CardBST();
    ~CardBST();

    void insert(Card c);
    void remove(Card c);
    bool contains(Card c);
    void printall();
//3.i

    class Iterator {
    private:
        Node* curr;
    public:
        Iterator(Node* n) {
            curr = n;
        }

        Card& operator*();
        bool operator!=(const Iterator& other);
        bool operator==(const Iterator& other);
        Iterator& operator++();
        Iterator& operator--();
    };

    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();
};

void playGame(CardBST& alice, CardBST& bob);

#endif
