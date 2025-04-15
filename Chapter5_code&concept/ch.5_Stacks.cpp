#include <cstdio>
#include <iostream>

using namespace std;

template <typename E>
class ArrayStack {
    enum {
        DEF_CAPACITY = 100
    };
    public :
        ArrayStack(int cap = DEF_CAPACITY);
        ~ArrayStack();
        int size() const;
        bool empty() const;
        const E &top();
        void push(const E &e);
        void pop();
    private:
        E *S;
        int capacity;
        int t;
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap),t(-1) {}
ArrayStack<E>::ArrayStack(int cap) {
    S = new E[cap];
    capacity = cap;
    t = -1;
}

typedef string Elem;

class SNode {
    Elem elem;
    SNode *next;

    friend class SLinkedList;
};

class SLinkedList {
    public:
        SLinkedList();
        ~SLinkedList();
        bool empty() const;
        const Elem &front() const;
        void addFront(const Elem &e);
        void removeFront();
    private:
        SNode *head;
};

SLinkedList::SLinkedList() : head(NULL) {}
SLinkedList::~SLinkedList() {
    while (!empty()) {
        removeFront();
    }
}
bool SLinkedList::empty() const {
    return head == nullptr;
}
const Elem &SLinkedList::front() const {
    return head->elem;
}
void SLinkedList::addFront(const Elem &e) {
    SNode *v = new SNode;
    v->elem = e;
    v->next = head;
    head = v;
}

void SLinkedList::removeFront() {
    SNode *old = head;
    head = head->next;
    delete old;
}

class LinkedStack {
    public:
        LinkedStack();
        ~LinkedStack();
        int size() const;
        bool empty() const;
        const Elem &top() const;
        void push(const Elem &e);
        void pop();
    private:
        SLinkedList S;
        int n;
};

LinkedStack::LinkedStack() : S(), n(0) {}   //S() is constructor of SLinkedList
LinkedStack::~LinkedStack() {}
int LinkedStack::size() const {
    return n;
}
bool LinkedStack::empty() const {
    return n == 0;  //S.empty()도 가능
}
const Elem &LinkedStack::top() const {
    return S.front();
}
void LinkedStack::push(const Elem &e) {
    n++;
    S.addFront(e);
}
void LinkedStack::pop() {
    --n;    // 값을 제거하는게 아니라서 remove함수 실행해야함 
    S.removeFront();
}

void reverse(vector<Elem> &V) {
    LinkedStack S;
    for (int i = 0; i < V.size(); i++) {
        S.push(V[i]);
    }
    for (int i = 0; i < V.size(); i++) {
        V[i] = S.top();
        S.pop();
    }
}

int main() {

    return EXIT_SUCCESS;
}