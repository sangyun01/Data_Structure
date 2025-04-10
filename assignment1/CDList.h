#ifndef CDLIST_H
#define CDLIST_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;

typedef string Elem;

class CDList;

class CNode {   // define CNode class
    private:
        Elem elem;
        CNode *next;
        CNode *prev;

        friend class CDList;
        friend ostream &operator<<(ostream &out, const CDList &list);
};

class CDList {  // define CDList
    public:
        CDList();
        ~CDList();
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