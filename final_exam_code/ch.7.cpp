#include <iostream>
#include <list>

typedef std::list<Position> PositionList;
typedef int Elem;

class LinkedBinaryTree {
    protected:
        struct Node {
            Elem elt;
            Node *par;
            Node *left;
            Node *right;
            Node() : elt(), par(NULL), left(NULL), right(NULL) {}
        };
    public:
        class Position {
            private:
                Node *v;
            public:
            Position(Node *_v = NULL) : v(_v) {}
            Elem &operator*() { return v->elt; }
            Position left() const { return Position(v->left); }
            Position right() const { return Position(v->right); }
            Position parent() const { return Position(v->par); }
            bool isRoot() const { return v->par == NULL; }
            bool isExternal() const { return }
            friend class LinkedBinaryTree;
        };
    public:
        LinkedBinaryTree();
        int size() const;
        bool empty() const;
        Position root() const;
        PositionList positions() const;
        void addRoot();
        void expandExternal(const Position &p);
        Position removeAboveExternal(const Position &p);
    protected:
        void preorder(Node *v, PositionList &pl) const;
    private:
        Node *_root;
        int n;
};

LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) {}
int LinkedBinaryTree::size() const {

}
bool LinkedBinaryTree::empty() const {

}
Position LinkedBinaryTree::root() const {

}
void LinkedBinaryTree::addRoot() {

}
PositionList LinkedBinaryTree::positions() const{

}
void LinkedBinaryTree::expandExternal(const Position &p) {

}
Position LinkedBinaryTree::removeAboveExternal(const Position &p) {

}
void LinkedBinaryTree::preorder(Node *v, PositionList &pl) const {

}


int depth(const Tree &T, const Position &p) {

}

// find the depth
int height1(const Tree &T) {

}

// other method of find the depth
int height2(const Tree &T) {

}

void preorderPrint(const Tree &T, const Position &p) {

}


void parentPrint(const Tree &T, const Position &p) {

}

void postorderPrint(const Tree &T, const Position &p) {

}


