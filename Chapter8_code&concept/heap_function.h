#pragma once

#include <vector> // using the vector STL

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
        Position pos(int i) { return V.begin() + i; } // V.begin() -> 벡터의 시작 주소를 가져와서 i만큼 이동한 iterator 위치
        int idx(const Position &p) const { return p - V.begin(); } // iterator p의 위치(주소)를 먼저 가져와서 그 시작 주소를 빼면 그 숫자가 해당 index 값
    public:
        VectorCompleteTree() : V(1) {}              // 생성자
        int size() const { return V.size() - 1; }   // 벡터의 size함수를 이용하는 대신 0을 안쓰니까 -1
        Position left(const Position &p) { return pos(2 * idx(p)); } // p의 left children은 부모 idx의 * 2
        Position right(const Position &p) { return pos(2 * idx(p) + 1); } // p의 right children은 부모 idx의 * 2 + 1
        Position parent(const Position &p) { return pos(idx(p) / 2); }    // (left or right) child / 2 -> parent node -> 나머지는 필요 없으니까
        bool hasLeft(const Position &p) const { return 2 * idx(p) <= size(); } // when has left child 2 * idx <= size -> if size -> 5 / p = 2 -> true , p = 3 -> false
        bool hasRight(const Position &p) const { return 2 * idx(p) + 1 <= size(); } // when has right child 2 * idx + 1 <= size -> if size -> 5 / p = 2 -> true , p = 3 -> false
        bool isRoot(const Position &p) const { return idx(p) == 1; } // root index is 1. indexing starts at 1
        Position root() { return pos(1); }                           // root idx -> 1
        Position last() { return pos(size()) } // last idx same as size() value
        void addLast(const E &e) { V.push_back(e); }
        void removeLast() { V.pop_back(); }
        void swap(const Position &p, const Position &q) {
            E e = *q;
            *q = *p;
            *p = *e;
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