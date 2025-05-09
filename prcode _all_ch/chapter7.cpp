#include <cstdlib>
#include <iostream>

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
    if(R.isRoot()) {
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


int main() {

    return EXIT_SUCCESS;
}