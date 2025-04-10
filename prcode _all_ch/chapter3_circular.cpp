//chapter 3 - circular linked list
#include <cstdio>
#include <iostream>

using namespace std;

typedef string Elem;
class CNode {
    private:
        Elem elem;
        CNode *next;

        friend class CircleList;
};

class CircleList {
    public:
        CircleList();
        ~CircleList();
        bool empty() const;
        const Elem &front() const;
        const Elem &back() const;
        void advance();
        void add(const Elem &e);
        void remove();
    private:
        CNode *cursor;
};

CircleList::CircleList() : cursor(NULL) {}
CircleList::~CircleList() { while (!empty())
        remove();
}

bool CircleList::empty() const { return cursor == NULL; }
const Elem &CircleList::front() const { return cursor->next->elem; }
const Elem &CircleList::back() const { return cursor->elem; }
void CircleList::advance() { cursor = cursor->next; }
void CircleList::add(const Elem &e) {
    CNode *v = new CNode;

    v->elem = e;
    if (cursor == NULL) {
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CircleList::remove() {
    CNode *old = cursor->next;
    if(old == cursor) {
        cursor = NULL;
    }
    else {
        cursor->next = old->next;
    }
    delete old;
}

int main() {
    CircleList playList;

    playList.add("Alive");
    playList.add("Freak");
    playList.add("Talkin");

    playList.advance();
    playList.advance();
    playList.remove();
    playList.add("Inferno");

    return EXIT_SUCCESS;
}