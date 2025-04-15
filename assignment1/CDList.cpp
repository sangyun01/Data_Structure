#include "CDList.h"

CDList::CDList() : cursor(nullptr) {}   // define constructor

CDList::~CDList() {                     // define destructor
    while (!empty()) {                  // using loop to remove the node
        remove();
    }
}

bool CDList::empty() const {            // return true if the list is empty
    return cursor == nullptr;           // check the list is empty
}

const Elem &CDList::front() const {     // return the element of the node next to the cursor
    return cursor->next->elem;
}

const Elem&CDList::back() const {       // return the element of the node at the cursor
    return cursor->elem;
}

void CDList::forward() {                // move the cursor to the next node
    if(empty()){                        // when the list is empty print the error message
        std::cout << "ERROR: Cannot move the node because of an empty list." << std::endl;
        return;
    }
    cursor = cursor->next;
}

void CDList::backward() {               // move the cursor to the previous node
    if(empty()){                        // when the list is empty print the error message
        std::cout << "ERROR: Cannot move the node because of an empty list." << std::endl;
        return;
    }
    cursor = cursor->prev;
}

void CDList::add(const Elem &e) {       // insert a new node right after the cursor
    CNode *v = new CNode;               // define the node v about new node
    v->elem = e;                        // store the element value where the node v

    if(cursor == nullptr) {             // if the list is empty
        v->next = v;                    // set the cursor process
        v->prev = v;
        cursor = v;
    }
    else {                              // already the node is exist
        v->next = cursor->next;         // bring the address at cursor pointing, the reason why locating the cursor and front node
        v->prev = cursor;               // new node prev point cursor
        cursor->next->prev = v;         // set the previous pointer of the front node (cursor->next) to point to the new node v
        cursor->next = v;               // set cursor next point is new node v
    }
}

void CDList::remove() {                 // remove the node
    if (empty()) {                      // when the list is empty print the error message
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }

    CNode* old = cursor->next;          // store the delete cursor->next point

    if (old == cursor) {                // if the list has one element
        delete old;
        cursor = nullptr;               // makes the list is null
    } else {
        cursor->next = old->next;       // cursor point like cursor->next->next node
        old->next->prev = cursor;       // cursor->next->next node prev point cursor
        delete old;                     // delete the front node
    }
}


ostream &operator<<(ostream &out, const CDList &list) {
    if(list.cursor == nullptr) {        // if the list is empty, print an error message
        out << "ERROR: Cannot print. The list is empty";
        return out;
    }
    // print process to forward direction
    CNode *first = list.cursor->next;   // define the first is front node
    CNode *last = list.cursor;          // define the last is cursor node
    CNode *current = first;             // define the current pointer is fisrt and it will be move to next node

    out << "Forward hopping:";

    do {    // already check the list is not empty so execute the print 바로..
        out << current->elem;           // print current node element 
        if (current != last) {          // if current node is not cursor node
            out << "->";                // then print "->" and current node point next current node
        }
        else {
            out << "*";                 // if current node is last, then print "*" for marking cursor node
        }
        current = current->next;
    } while (current != first);         // current node is first then is one cycle so break the loop
    out << std::endl;

    // print process to backward direction
    first = list.cursor->prev;          // define the first is previous cursor node
    last = list.cursor;                 // define the last is cursor node
    current = first;                    // define the current pointer is fisrt and it will be move to prev node

    out << "Backward hopping:";
    do {
        out << current->elem;           // print current node element 
        if (current->prev != first) {   // if prev current node is not cursor node
            out << "->";                // then print "->" and current node point prev current node
        }
        else {
            out << "*";                 // if prev current node is first, then print "*" for marking cursor node
        }
        current = current->prev;
    } while (current != first);         // current node is first then is one cycle so break the loop
    out << std::endl;

    return out;
}