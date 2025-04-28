#include <cstdio>
#include <iostream>

using namespace std;

//목표 큐 구현 -> iterator 써서

typedef string Elem;

class CNode {
    Elem elem;
    CNode *next;

    friend class CLinkedList;
    friend class CLinkedList::Iterator;
};

class CLinkedList {
    public:
        class Iterator {
            public:
                Iterator(CNode *u);
                ~Iterator();
                Elem operator*();
                bool operator==(const Iterator &p) const;
                bool operator!=(const Iterator &p) const;
                Iterator &operator++();
            private:
                CNode *v;
        };
        CLinkedList();
        ~CLinkedList();
        bool empty() const;
        const Elem &front() const;
        const Elem &back() const;
        void addFront(Elem &e);
        void removeFront();
        void advance();

    private:
        CNode *cursor;
};

class CList_Queue {
    public:
        CList_Queue();
        ~CList_Queue();
        bool empty() const;
        int size() const;
        const Elem &front() const;
        void enqueue(const Elem &e);
        void dequeue();

    private:
        CLinkedList C;
        int n;
};

//define the Iterator function
CLinkedList::Iterator::Iterator(CNode *u) : v(u) {}
CLinkedList::Iterator::~Iterator() {}
Elem CLinkedList::Iterator::operator*() {
    return v->elem;
}
bool CLinkedList::Iterator::operator==(const Iterator &p) const {
    return v == p.v;
}
bool CLinkedList::Iterator::operator!=(const Iterator &p) const {
    return v != p.v;
}
CLinkedList::Iterator& CLinkedList::Iterator::operator++() {
    v = v->next;
    return *this;
}

//define the CLinkedList function
CLinkedList::CLinkedList() {
    cursor = nullptr;
}
CLinkedList::~CLinkedList() {
    while(!empty()) {
        removeFront();
    }
    // not nead to delete cursor, already remove while loop
}
bool CLinkedList::empty() {
    return cursor == nullptr;
}
const Elem &CLinkedList::front() const {
    return cursor->next->elem;
}
const Elem &CLinkedList::back() const {
    return cursor->elem;
}
void CLinkedList::addFront(const Elem &e) {
    CNode *v = new CNode;
    v->elem = e;
    if (cursor == nullptr) {
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CLinkedList::removeFront() {
    CNode *old = cursor->next;
    if (cursor == nullptr) {
        return;
        //원래는 throw로 예외처리
    }
    else{
        cursor->next = old->next;
    }
    delete old;
}
void CLinkedList::advance() {
    if(cursor==nullptr) {
        return;
        // 원래는 예외처리
    }
    else {
        cursor = cursor->next;
    }
}

CList_Queue::CList_Queue() : C(), n(0) {}
CList_Queue::~CList_Queue() {}
bool CList_Queue::empty() const {
    return n == 0;
}
int CList_Queue::size() const {
    return n;
}
const Elem &CList_Queue::front() const {
    return C.front();
}
void CList_Queue::enqueue(const Elem &e) {
    C.addFront(e);
    n++;
}
void CList_Queue::dequeue() {
    C.removeFront();
    n--;
}


int main() {

    return EXIT_SUCCESS;
}
