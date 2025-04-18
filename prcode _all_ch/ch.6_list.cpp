#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

/*
typedef int Elem;
class ArrayVector {
    public:
        ArrayVector();
        ~ArrayVector();
        int size() const;
        bool empty() const;
        Elem &operator[](int i);
        Elem &at(int i);
        void erase(int i);
        void insert(int i, const Elem &e);
        void reserve(int N);
    private:
        int capacity;
        int n;
        Elem *A;
};

ArrayVector::ArrayVector() : capacity(0), n(0), A(nullptr) {}
ArrayVector::~ArrayVector() {
    delete[] A;
}
int ArrayVector::size() const {
    return n;
}
bool ArrayVector::empty() const {
    return n == 0;
}
Elem &ArrayVector::operator[](int i) {
    return A[i];
}
Elem &ArrayVector::at(int i) {
    if (i < 0 || i > n) {
        return;
    }
    return A[i];
}

void ArrayVector::erase(int i) {
    for (int j = i + 1; j < n; j++){
        A[j - 1] = A[j];
    }
    n--;
}

void ArrayVector::reserve(int N) {
    if(capacity > N) {
        return;
    }
    Elem *B = new Elem[N];
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    if (A != NULL) {
        delete[] A;
    }
    A = B;
    capacity = N;
    delete B;
}

void ArrayVector::insert(int i, const Elem &e) {
    if (n >= capacity) {
        reserve(max(1, 2 * n));
    }
    for (int j = n - 1; j >= i; j--) {
        A[j + 1] = A[j];
    }
    A[i] = e;
    n++;
}
*/

typedef string Elem;

class DNode {
    private:
        Elem elem;
        DNode *prev;
        DNode *next;

        friend class DLinkedList;
        friend class DLinkedList::Iterator;
};

class DLinkedList {
    public:
        class Iterator {
            public:
                Elem &operator*();      // return the element at pointer v
                bool operator==(const Iterator &p) const;   // compare the pointer about input the pointer and current pointer
                bool operator!=(const Iterator &p) const;   // check the pointer about input the pointr is different about current pointer
                Iterator &operator++(); // move the next node about current node v
                Iterator &operator++(int);
                Iterator &operator--(); // move the prev node about current node v
                Iterator &operator--(int);

            private:
                DNode *v;
                Iterator(DNode *u);
        };
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        int size() const;
        Iterator begin();
        Iterator end();
        void InsertFront(const Elem &e);
        void InsertBack(const Elem &e);
        void eraseFront();
        void eraseBack();

    private:
        DNode *header;
        DNode *trailer;
        int n;
    protected:
        void Insert(const Iterator &p, const Elem &e);
        void erase(const Iterator &p);
};

DLinkedList::Iterator::Iterator(DNode *u) : v(u) {}
Elem &DLinkedList::Iterator::operator*() {
    return v->elem;
} 
bool DLinkedList::Iterator::operator==(const Iterator& p) const {
    return v == p.v;
}
bool DLinkedList::Iterator::operator!=(const Iterator &p) const {
    return v != p.v;
}
DLinkedList::Iterator& DLinkedList::Iterator::operator++() {
    v = v->next;
    return this;
}
DLinkedList::Iterator& DLinkedList::Iterator::operator++(int) {
    Iterator temp = *this;
    v = v->next;
    return temp;
}
DLinkedList::Iterator& DLinkedList::Iterator::operator--() {
    v = v->prev;
    return this;
}
DLinkedList::Iterator& DLinkedList::Iterator::operator--(int) {
    Iterator temp = *this;
    v = v->prev;
    return temp;
}

DLinkedList::DLinkedList();
DLinkedList::~DLinkedList();
bool DLinkedList::empty() const;
int DLinkedList::size() const;
DLinkedList::Iterator DLinkedList::begin();
DLinkedList::Iterator DLinkedList::end();
void DLinkedList::Insert(const Iterator &p, const Elem &e)
void DLinkedList::InsertFront(const Iterator &p, const Elem &e);
void DLinkedList::InsertBack(const Iterator &p, const Elem &e);
void DLinkedLsit::erase(const Iterator &p);
void DLinkedList::eraseFront(const Iterator &p);
void DLinkedList::eraseBack(const Iterator &p);


