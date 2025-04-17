#include <cstdio>
#include <iostream>

using namespace std;

typedef string Elem;

class DNode {
private:
    Elem elem;
    DNode* next;
    DNode* prev;

    friend class DLinkedList;
    friend class DLinkedList::Iterator;
};

class DLinkedList {
public:
    class Iterator {
    public:
        ~Iterator();
        Elem& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        Iterator& operator--();

        friend class DLinkedList;

    private:
        DNode* v;
        Iterator(DNode* u = nullptr);
    };

    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    int size() const;
    Iterator begin() const;
    Iterator end() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void eraseFront();
    void eraseBack();

protected:
    void insert(const Iterator& p, const Elem& e);
    void erase(const Iterator& p);

private:
    int n;
    DNode* header;
    DNode* trailer;
};

DLinkedList::Iterator::Iterator(DNode* u) {
    v = u;
}

DLinkedList::Iterator::~Iterator() {}

Elem& DLinkedList::Iterator::operator*() {
    return v->elem;
}

bool DLinkedList::Iterator::operator==(const Iterator& p) const {
    return v == p.v;
}

bool DLinkedList::Iterator::operator!=(const Iterator& p) const {
    return v != p.v;
}

DLinkedList::Iterator& DLinkedList::Iterator::operator++() {
    v = v->next;
    return *this;
}

DLinkedList::Iterator& DLinkedList::Iterator::operator--() {
    v = v->prev;
    return *this;
}

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
    header->prev = nullptr;
    trailer->next = nullptr;
    n = 0;
}

DLinkedList::~DLinkedList() {
    while (!empty()) {
        eraseFront();
    }
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return n == 0;
}

int DLinkedList::size() const {
    return n;
}

DLinkedList::Iterator DLinkedList::begin() const {
    return Iterator(header->next);
}

DLinkedList::Iterator DLinkedList::end() const {
    return Iterator(trailer);
}

void DLinkedList::insert(const DLinkedList::Iterator& p, const Elem& e) {
    DNode* w = p.v;
    DNode* u = w->prev;
    DNode* v = new DNode;
    v->elem = e;
    v->next = w;
    v->prev = u;
    u->next = v;
    w->prev = v;
    n++;
}

void DLinkedList::insertFront(const Elem& e) {
    insert(begin(), e);
}

void DLinkedList::insertBack(const Elem& e) {
    insert(end(), e);
}

void DLinkedList::erase(const DLinkedList::Iterator& p) {
    DNode* v = p.v;
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

void DLinkedList::eraseFront() {
    erase(begin());
}
void DLinkedList::removeBack() {
    remove(--end());
}

int main() {

    return 0;
}