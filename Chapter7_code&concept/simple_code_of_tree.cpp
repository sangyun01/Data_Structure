#include <iostream>
#include <cstlib>
#include <algorithm>
#include <list>
#include <iterator>

template <typename E>
class Position<E> {
    public:
        E &operator*();
        Position parent() const;
        PositionList children() const;
        bool isRoot() const;
        bool isExternal() const;
};

template <typename E>
class PositionList<E> {

};

template <typename E>
class tree<E> {
    public:
        class Position;
        class PositionList;
    public:
        int size() const;                   // return tree size
        bool empty() const;                 // check the tree is empty
        Position root() const;              // get the root position
        PositionList positions() const;     // get positions of all nodes
};

int depth(const Tree &T, const Position &p) {
    if(p.isRoot())
        return 0;
    else
        return 1 + depth(T, p.parent());
}

// find the depth
int height1(const Tree &T)
{
    int h = 0;
    PositionList nodes = T.positions();
    for (Iterator q = nodes.begin(); q != nodes.end(); ++q) {
        if (q->isExternal()) {
            h = max(h, depth(T, *q));
        }
    }
    return h;
}

// other method of find the depth
int height2(const Tree &T) {
    if(p.isExternal()) // when the node p is leaf than break -> return 0 -> count the depth bottom to top
        return 0;
    int h = 0;
    PositionList ch= p.children();
    for (Itertor q = ch.begin(); q != ch.end(); ++q) {
        h = max(h, depth(T, *q));
    }
    return h + 1;
}

void preorderPrint(const Tree &T, const Position &p) {
    cout << *p; // print the dereferencing the node of element
    PositionList ch = p.children(); // first print the parent and after the print children(left or right)
    for (Iterator p = ch.begin(); q != ch.end(); ++q) {
        cout << " ";
        preorderPrint(T, *q);
    }
}
// 부모 -> 자식 노드(left -> right) -> 다음 자식 노드 느낌

void parentPrint(const Tree &T, const Position &p) {
    cout << *p;
    if(!p.isExternal()) {
        PositionList ch = p.children();
        cout << "(";
        for (Iterator q = ch.begin(); q != ch.end(); ++q) {
            if (q != ch.begin())
                cout << " ";
            parenPrint(T, *q);
        }
        cout << ")"
    }
}
// 부모(자식 노드 자식노드A(자식노드A') 자식노드B) 형태

void postorderPrint(const Tree &T, const Position &p) {
    PositionList ch = p.children();
    for (Iterator q = ch.begin(); q != ch.end(); ++q) {
        postorderPrint(T, *q);
        cout << " ";
    }
    cout << *p;
}

// 자식노드 자식노드 부모노드 형태