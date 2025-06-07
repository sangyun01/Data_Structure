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
        std::vector<E> V;
    public:
        typedef typename std::vector<E>::iterator Position;
    protected:
        Position pos(int i) {
            
        }
        int idx(const Position &p) const {
            
        }
    public:
        VectorCompleteTree() : V(1) {}             
        int size() const { 
            
        }
        Position left(const Position &p) { 

        }
        Position right(const Position &p) { 
            
        }
        Position parent(const Position &p) { 
            
        }
        bool hasLeft(const Position &p) const { 
            
        } 
        bool hasRight(const Position &p) const { 
            
        }
        bool isRoot(const Position &p) const { 
            
        }
        Position root() { 

        }
        Position last() { 
            
        }
        void addLast(const E &e) { 
            
        }
        void removeLast() { 

        }
        void swap(const Position &p, const Position &q) {

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
        VectorCompleteTree<E> T;
        C isLess;

        typedef typename VectorCompleteTree<E>::Position Position;
};