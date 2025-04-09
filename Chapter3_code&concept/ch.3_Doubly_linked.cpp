#include <cstdio>
#include <iostream>

using namespace std;

typedef string Elem;
class DNode {
    private:
        Elem elem;
        DNode *prev;
        DNode *next;

        friend class DLinkedList;
};

class DLinkedList {
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const Elem &front() const;
        const Elem &back() const;
        void addFront(const Elem &e);
        void addBack(const Elem &e);
        void removeFront();
        void removeBack();
    private:
        DNode *header;
        DNode *trailer;
    protected:
        void add(DNode *v, const Elem &e);
        void remove(DNode *v);
};

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;

    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!(empty())) {
        removeFront();
    }
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return header->next = trailer;
}

const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

void DLinkedList::add(DNode *v, const Elem &e) {
    DNode *u = new DNode;   // x-> u -> v 구조, u에 대해서 먼저 다 작성을 한다. 요소, 방향 등
    u->elem = e;    // u의 element value
    u->next = v;    // u's next is v
    u->prev = v->prev;  // existing of v-> prev is x, after add changing u->prev is x
    v->prev->next = v->prev = u;
    // v->prev is x when not add function. Thus changing x-> next is u
    // also change the v->prev is u before x
    // caution of order declare
}

void DLinkedList::addFront(const Elem &e) {
    add(header->next, e);
    // when the input the data front so, header next value is change
}

void DLinkedList::addBack(const Elem &e) {
    add(trailer, e);
    // already the direction is trailer input front
}

void DLinkedList::remove(DNode *v) {
    // u-> v -> w 구조
    DNode *u = v->prev;
    DNode *w = v->next;

    u->next = w;
    w->prev = u;

    delete v;
}

void DLinkedList::removeFront(DNode *v) {
    remove(header->next);
    // remove the node where locate the next the header
}

void DLinkedList::removeBack(DNode *v) {
    remove(trailer->prev);
    // remove the node where last locate about trailer
}

void listReverse(DLinkedList& L) {
    DLinkedList T;

    while (!empty()) {
        string s = L.front();
        L.removeFront();
        T.addFront(s);
    }

    while (!empty()) {
        string s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}

int main() {

    return EXIT_SUCCESS;
}