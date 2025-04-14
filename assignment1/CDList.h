#ifndef CDLIST_H
#define CDLIST_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;

typedef string Elem;

class CDList;

class CNode {               // define CNode class
    private:
        Elem elem;          // define string type elem, elem is node element value
        CNode *next;        // define node next point
        CNode *prev;        // define node prev point

        friend class CDList;    // CDList to access the private members of CNode
        friend ostream &operator<<(ostream &out, const CDList &list);   // operator<< to access private members for print
};

class CDList {  // define CDList
    public:
        CDList();                   // constructor
        ~CDList();                  // destructor
        bool empty() const;         // check the list is empty
        const Elem &front() const;  // return the element at front node
        const Elem &back() const;   // return the element at cursor node
        void forward();             // cursor move to next node
        void backward();            // cursor move to prev node
        void add(const Elem &e);    // add the node where the next to cursor
        void remove();              // delete the node at the front node

        friend ostream &operator<<(ostream &out, const CDList &list);
                                    // print the list
    private:
        CNode *cursor;              // pointer to current node
};

#endif