#include <cstdio>
#include <iostream>

using namespace std;

typedef string Elem;

class CNode {
    private:
        Elem elem;
        CNode *next;

        friend class CLinkedList;
};

class CLinkedList {
    public:
        CLinkedList();
        ~CLinkedList();
        bool empty() const;
        const Elem &front() const;
        const Elem &back() const;
        void advance();
        void add(const Elem &e);
        void remove();

    private:
        CNode *cursor;
};

CLinkedList::CLinkedList() : cursor(NULL) {}
CLinkedList::~CLinkedList() {
    while (!empty()) {
        remove();
    }
}

bool CLinkedList::empty() const {
    return cursor == NULL;
}

const Elem &CLinkedList::front() {
    return cursor->next->elem;
    // cursor next element is front value
}

const Elem &CLinkedList::back() {
    return cursor->elem;
    // already cursor element if lastly of elment value
}

void CLinkedList::advance() {
    cursor = cursor->next;
}

void CLinkedList::add(const Elem& e) {
    CNode *v = new CNode;
    v->elem = e;

    if(cursor == NULL) { // initial node
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next; // cursor-> next => front value, change the front value
                                // always define the variable, first the store the before data
        cursor->next = v;       // also cursor direction is new value
    }
}

void CLinkedList::remove() {
    CNode *old = cursor->next;
    if(old == cursor) {
        cursor == NULL;
    }
    else {
        cursor->next = old->next;
    }
    delete old;
}

int main() {

    return EXIT_SUCCESS;
}