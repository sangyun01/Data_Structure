#pragma once

#include <vector>

template <typename E>
struct Comparator { // It compare the a and b
    bool operator()(const E& a, const E& b) const {
        return a < b;
    }
};

template <typename E>
class VectorCompleteTree {
    private:
        std::vector<E> V;   // using the STL vector
    public:
        typedef typename std::vector<E>::iterator Position; // define the Postion replace the std::vector<E>::iterator
    protected:
        Position pos(int i) { return V.begin() + i; }       // Returns an iterator pointing to the i-th element
        int idx(const Position &p) const { return p - V.begin(); } // reverse calculate idx by using the iterator p
    public:
        VectorCompleteTree() : V(1) {}              // constructor
        int size() const { return V.size() - 1; }   // not using the index 0 => V.size()-1
        Position left(const Position &p) { return pos(2 * idx(p)); }        // parent * 2 -> left child
        Position right(const Position &p) { return pos(2 * idx(p) + 1); }   // parent * 2 + 1 -> right child
        Position parent(const Position &p) { return pos(idx(p) / 2); }      // (left or right) child / 2 -> parent node
        bool hasLeft(const Position &p) const { return 2 * idx(p) <= size(); }          // when has left child 2 * idx <= size -> if size -> 5 / p = 2 -> true , p = 3 -> false
        bool hasRight(const Position &p) const { return 2 * idx(p) + 1 <= size(); }     // when has right child 2 * idx + 1 <= size -> if size -> 5 / p = 2 -> true , p = 3 -> false
        bool isRoot(const Position &p) const { return idx(p) == 1; }        // root index is 1. indexing starts at 1
        Position root() { return pos(1); }  // root idx -> 1
        Position last() { return pos(size()); } // last idx same as size() value
        void addLast(const E &e) { V.push_back(e); }    
        void removeLast() { V.pop_back(); }             
        void swap(const Position &p, const Position &q) {
            E e = *q;   // e is temporary vaiable
            *q = *p;
            *p = e;
        }
};

template <typename E, typename C>
class HeapPriorityQueue {
    public:
        int size() const;
        bool empty() const;
        void insert(const E &e);
        const E &min();
        void removeMin();
    private:
        VectorCompleteTree<E> T;    // VectorCompleteTree based heap
        C isLess;   // compare the C

        typedef typename VectorCompleteTree<E>::Position Position;
};