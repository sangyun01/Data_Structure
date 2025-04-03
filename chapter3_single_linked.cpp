//chapter 3 - single linked list
#include <cstdio>
#include <iostream>

using namespace std;

/*
class StringNode {
    private:
        string elem;
        StringNode *next;

        friend class StringLinkedList;
};

class StringLinkedList {
    public:
        StringLinkedList();
        ~StringLinkedList();
        bool empty() const;
        const string &front() const;
        void addFront(const string &e);
        void removeFront();
    private:
        StringNode *head;
};

StringLinkedList::StringLinkedList() : head(NULL) {}
StringLinkedList::~StringLinkedList() {while (!empty()) removeFront();}
bool StringLinkedList::empty() const { return head == NULL; }
const string &StringLinkedList::front() const { return head->elem; }

void StringLinkedList::addFront(const string &e) {
    StringNode *v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::removeFront() {
    StringNode *old = head;
    head = old->next;
    delete old;
}

*/ //type이 String형일 때 코드

//type is general

template <typename E>
class SNode {
    private:
        E elem;
        SNode<E> *next;

        friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
    public:
        SLinkedList();
        ~SLinkedList();
        bool empty() const;
        const E &front() const;
        void addFront(const E &e);
        void removeFront();

    private:
        SNode<E> *head;
};

template <typename E>
SLinkedList<E>::SLinkedList() : head(NULL) {}

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while(!empty())
        removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const { return head == NULL; }

template <typename E>
const E &SLinkedList<E>::front() const { return head->elem; }

template <typename E>
void SLinkedList<E>::addFront(const E &e) {
    SNode<E> *v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E> *old = head;
    head = old->next;
    delete old;
}