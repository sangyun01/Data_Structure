#ifndef CDLIST_H
#define CDLIST_H

#include <iostream>
#include <string>

using std::string;      // string std:: omit
using std::ostream;     // osteam std:: omit

typedef string Elem;    // Elem mean string

class CDList;           // define class CDList

class CNode {   // define CNode class
    private:    // private variable elem, *next, *prev
        Elem elem;
        CNode *next;
        CNode *prev;

        friend class CDList;    // access for CDList
        friend ostream &operator<<(ostream &out, const CDList &list);   // also access for ostream function
};

class CDList {  // define CDList
    public:
        CDList();   // constructor 
        ~CDList();  // 
        bool empty() const;
        const Elem &front() const;
        const Elem &back() const;
        void forward();
        void backward();
        void add(const Elem &e);
        void remove();

        friend ostream &operator<<(ostream &out, const CDList &list);

    private:
        CNode *cursor;
};

#endif