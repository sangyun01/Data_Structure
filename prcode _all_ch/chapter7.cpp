#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

template <typename E>
class Position <E> {
    public:
        E &operator*();
        Position parent() const;
        PositionList children() const;
        bool isRoot() const;
        bool isExternal() const;
};

template <typename E>
class Tree<E> {
    public:
        class Position;
        class PositionList;
    public:
        int size() const;
        bool empty() const;
        Position root() const;
        PositionList positions() const;
};


int depth(const Tree&T, const Position& p) {
    if(P.isRoot()) {
        return 0;
    }
    else {
        return 1 + depth(T, p.parent()); //recursive
    }
}

int height1(const Tree &T) {
    int h = 0;
    PositionList nodes = T.positions();
    for(Iterator q= nodes.begin(); q!=nodes.end(); ++q) {
        if(q->isExternal()) {
            h = max(h, depth(T, *q));
        }
    }
    return h;
}

int height2(const Tree& T, const Position& p) {
    if (p.isExternal())
        return 0;
    int h = 0;
    PositionList ch = p.children();
    for (Iterator q = ch.begin(); q != ch.end(); ++q)
        h = max(h, height2(T, *q));
    return 1 + h;
}

void preorderPrint(const Tree &T, const Position &p) {
    cout << *p;
    PositionList ch = p.children();
    for (Iterator q = ch.begin(); q != ch.end(); ++q) {
        cout << " ";
        preorderPrint(T, *q);
    }
}

void parenPrint(const Tree& T, const Position& p) {
    cout << *p;
    if(!p.isExternal()) {
        PositionList ch = p.children();
        cout << "( ";
        for (Iterator q = ch.begin(); q != ch.end(); ++q) {
            if(q!=ch.begin())
                cout << " ";
            parenPrint(T, *q);
        }
        cout << " )";
    }
}

void postorderPrint(const Tree&T, const Position& p) {
    PositionList ch = p.children();
    for(Ite)
}

int main() {

    return EXIT_SUCCESS;
}