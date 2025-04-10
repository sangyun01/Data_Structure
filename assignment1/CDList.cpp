#include "CDList.h"

CDList::CDList() : cursor(nullptr) {}

CDList::~CDList() {
    while (!empty()) {
        remove();
    }
}

bool CDList::empty() const {
    return cursor == nullptr;
}

const Elem &CDList::front() const {
    return cursor->next->elem;
}

const Elem&CDList::back() const {
    return cursor->prev->elem;
}

void CDList::forward() {
    if(empty()){
        std::cout << "ERROR: Cannot move the node because of an empty list." << std::endl;
        return;
    }
    cursor = cursor->next;
}

void CDList::backward() {
    if(empty()){
        std::cout << "ERROR: Cannot move the node because of an empty list." << std::endl;
        return;
    }
    cursor = cursor->prev;
}

void CDList::add(const Elem &e) {
    CNode *v = new CNode;
    v->elem = e;

    if(cursor == nullptr) {
        v->next = v;
        v->prev = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        v->prev = cursor;
        cursor->next->prev = v;
        cursor->next = v;
    }
}

void CDList::remove() {
    if (empty()) {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }

    CNode* old = cursor->next;

    if (old == cursor) {
        delete old;
        cursor = nullptr;
    } else {
        cursor->next = old->next;
        old->next->prev = cursor;
        delete old;
    }
}


ostream &operator<<(ostream &out, const CDList &list) {
    if(list.cursor == nullptr) {
        out << "ERROR: Cannot print. The list is empty";
        return out;
    }

    CNode *first = list.cursor->next;
    CNode *last = list.cursor;
    CNode *current = first;

    out << "Forward hopping:";

    do {
        out << current->elem;
        if (current != last) {
            out << "->";
        }
        else {
            out << "*";
        }
        current = current->next;
    } while (current != first);
    out << std::endl;

    first = list.cursor->prev;
    last = list.cursor;
    current = first;

    out << "Backward hopping:";
    do {
        out << current->elem;
        if (current->prev != first) {
            out << "->";
        }
        else {
            out << "*";
        }
        current = current->prev;
    } while (current != first);
    out << std::endl;

    return out;
}