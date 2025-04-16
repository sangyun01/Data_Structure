#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

/*
when using the headfile at queue.
but I'll type the code another method to using circular linked list.
template <typename E>
class Queue {
    public:
        int size() const;
        bool empty() const;
        const E &front() const;
        void enqueue(const E &e);
        void dequeue();
};
*/

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
        void add(const Elem &e);
        void remove();
        void advance();

    private:
        CNode *cursor;
};

CLinkedList::CLinkedList() : cursor(nullptr) {}
CLinkedList::~CLinkedList() {
    while (!empty()) {
        remove();
    }
    
}

bool CLinkedList::empty() const {
    return cursor == nullptr;
}
const Elem &CLinkedList::front() const {
    return cursor->next->elem;
}
const Elem &CLinkedList::back() const {
    return cursor->elem;
}

void CLinkedList::add(const Elem &e) {
    CNode *v = new CNode;
    v->elem = e;
    if(cursor == nullptr) {
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CLinkedList::remove() {
    CNode *old = cursor->next;
    if(old == cursor) {
        cursor = nullptr;
    }
    else {
        cursor->next = old->next;
    }
    delete old;
}

void CLinkedList::advance() {
    cursor = cursor->next;
}

class LinkedQueue {
    public:
        LinkedQueue();
        ~LinkedQueue();
        int size() const;
        bool empty() const;
        const Elem &front() const;
        void enqueue(const Elem &e);
        void dequeue();
    private:
        CLinkedList C;
        int n;
};

LinkedQueue::LinkedQueue() : C(), n(0) {}   // C, 즉 CLinkeedList에서 생성한거는 그대로 가져오고 + n=0초기화한다.
LinkedQueue::~LinkedQueue() {
    while (!empty()) {
        dequeue();
    }
}
int LinkedQueue::size() const {
    return n;
}
bool LinkedQueue::empty() const {
    return n == 0;
}
const Elem &LinkedQueue::front() const {
    return C.front();
}
void LinkedQueue::enqueue(const Elem &e) {
    C.add(e);       // add the element
    C.advance();    // move the rear index point next address
    n++;            // increase the number of element
}
void LinkedQueue::dequeue() {
    C.remove();
    n--;
}

int main() {

    return EXIT_SUCCESS;
}