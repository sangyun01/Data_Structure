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

int main() {

    return EXIT_SUCCESS;
}