#include <cstdio>
#include <iostream>

using namespace std;

/*
구현 목표
1. double circular
2. template 사용해서
3. iterator 사용해서
4. 출력까지
*/

template <typename E>
class CNode {
    private:
        E elem;
        CNode *next;
        CNode *prev;

        friend class CLinkedList<E>;
        friend class CLinkedList<E>::Iterator;
        friend ostream &operator<<(ostream &os, const CLinkedList &list);
};

template <typename E>
class CLinkedList {
    public:
        class Iterator {
            public:
                ~Iterator();
                E operator*();
                bool operator==(const Iterator &p) const;
                bool operator!=(const Iterator &p) const;
                Iterator &operator++();
                Iterator &operator--();

            private:
                CNode<E> *v;
                Iterator(CNode<E> *u);
                };
        CLinkedList();
        ~CLinkedList();
        bool empty() const;
        int size() const;
        Iterator begin() const;
        Iterator end() const;
        void insertfront(E elem);
        void insertback(E elem);
        void erasefront();
        void eraseback();

        friend ostream &operator<<(ostream &os, const CLinkedList &list);

    protected:
        void insert(const Iterator &p, E elem);
        void erase(const Iterator &p);
    private:
        CNode<E> *header;
        CNode<E> *trailer;
        int n;
};

template <typename E>



template <typename E>
CLinkedList<E>::Iterator::Iterator(CNode<E> *u) : v(u) {}

template <typename E>
CLinkedList<E>::Iterator::~Iterator() {}

template <typename E>
E CLinkedList<E>::Iterator::operator*() const {
    return v->elem;
}


template <typename E>
bool CLinkedList<E>::Iterator::operator==(const Iterator& p) const {
    return v == p.v;
}

template <typename E>
bool CLinkedList<E>::Iterator::operator!=(const Iterator &p) const {
    return v != p.v;
}

template <typename E>
typename CLinkedList<E>::Iterator &CLinkedList<E>::Iterator::operator++() {
    v = v->next;
    return *this;
}

template <typename E>
typename CLinkedList<E>::Iterator &CLinkedList<E>::Iterator::operator--() {
    v = v->prev;
    return *this;
}

template <typename E>
CLinkedList<E>::CLinkedList() {
    header = new CNode<E>;
    trailer = new CNode<E>;
    header->next = trailer;
    header->prev = trailer;
    trailer->next = header;
    trailer->prev = header;

    n = 0;
}

template <typename E>
CLinkedList<E>::~CLinkedList() {
    while(!empty()) {
        erasefront();
    }
    delete header;
    delete trailer;
}

template <typename E>
bool CLinkedList<E>::empty() const {
    return n == 0;
}

template <typename E>
int CLinkedList<E>::size() const {
    return n;
}

template <typename E>
CLinkedList<E>::Iterator CLinkedList<E>::begin() const {
    return Iterator(header->next);
}

template <typename E>
CLinkedList<E>::Iterator CLinkedList<E>::end() const {
    return Iterator(trailer);
}

template <typename E>
void CLinkedList<E>::insert(const Iterator &p, E elem) {
    CNode<E> *v = new CNode<E>;
    CNode<E> *u = p.v;
    CNode<E> *w = u->next;

    v->elem = elem;
    v->next = w;
    v->prev = u;
    u->next = v;
    w->prev = v;
    n++;
}

template <typename E>
void CLinkedList<E>::insertfront(E elem) {
    insert(begin(), elem);
}

template <typename E>
void CLinkedList<E>::insertback(E elem) {
    insert(end(), elem);
}

template <typename E>
void CLinkedList<E>::erase(const Iterator& p) {
    CNode<E> *v = p.v;
    CNode<E> *u = v->prev;
    CNode<E> *w = v->next;

    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

template <typename E>
void CLinkedList<E>::erasefront() {
    erase(begin());
}

template <typename E>
void CLinkedList<E>::eraseback() {
    erase(--end());
}

template <typename E>
ostream &operator<<(ostream& os, const CLinkedList &list) {
    
}




int main() {


    return EXIT_SUCCESS;
}