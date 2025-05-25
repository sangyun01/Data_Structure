#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

/*
//PriorityQueue
template <typename E, typename C>
class PriorityQueue {
    public:
        int size() const;
        bool isempty() const;
        void insert(const E &e);
        const E &min() const throw(QueueEmpty);
        void removeMin() throw(QueueEmpty);
};
*/

/*
//ListPriorityQueue
template <typename E, typename C>
class ListPriorityQueue {
    public:
        int size() const;
        bool isempty() const;
        void insert(const E &e);
        const E &min() const throw(QueueEmpty);
        void removeMin() throw(QueueEmpty);
    private:
        std::list<E> L; // Container to store elements : used in insert(), min(), removeMin()
        C isLess;
};

template <typename E, typename C>
int ListPriorityQueue<E, C>::size() const {
    return L.size();
}

template <typename E, typename C>
bool ListPriorityQueue<E, C>::isempty() const {
    return L.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::insert(const E &e) {
    typename std::list<E>::iterator p;  // define interator p
    p = L.begin();                      // start where the begin position
    while (p != L.end() && !isLess(e, *p))  // when the lastly repeat, but break when e > *p (e - *p > 0 => true => !true = false => break) // isLess(7, 1) -> false 7 < 1
        ++p;
    L.insert(p, e);
}

template <typename E, typename C>
const E &ListPriorityQueue<E, C>::min() const {
    return L.front();
}

template <typename E, typename C>
void ListPriorityQueue<E,C>::removeMin() const {
    L.pop_front();
}
*/

template <typename E>
class VectorCompleteTree {
    private:
        std::vector<E> V;
    public:
        typedef typename std::vector<E>::iterator Position;
    protected:
        Position pos(int i) { return V.begin() + i; }
        int idx(const Position &p) const { return p - V.begin(); }
    public:
        VectorCompleteTree() : V(1) {}    // start the index 1
        int size() const {
            return V.size() - 1;                // -1 -> reason why start the index 1
        }
        Position left(const Position &p) {      // iterator n -> 2n(left child)
            return pos(2 * idx(p));
        }
        Position right(const Position &p) {
            return pos(2 * idx(p) + 1);         // iterator n -> 2n + 1(right child)
        }
        Position parent(const Position &p) {
            return pos(idx(p) / 2);             // floor the idx(2n or 2n + 1) / 2 => mod 2 => n(parent)
        }
        bool hasLeft(const Position &p) const {
            return 2 * idx(p) <= size();        
        }
        bool hasRight(const Position &p) const {
            return 2 * idx(p) + 1 <= size();
        }
        bool isRoot(const Position &p) const {
            return idx(p) == 1;
        }
        //1         -> p = 1 -> isRoot() -> true
        //2|3       -> p = 3 -> hasLeft() 6 =< 6 -> true
        //4|5||6    -> p = 3 -> hasRight() 7 =< 6 -> false
        Position root() {
            return pos(1);  // move the vector p = 1
        }
        Position last() {
            return pos(size()); // move the vector p = last(size())
        }
        void addLast(const E &e) {
            V.push_back(e);     //Queue
        }
        void removeLast() {
            V.pop_back();       
        }
        void swap(const Position &p, const Position &q) {
            E e = *q;
            *q = *p;
            *p = e;
        }
};

template <typename E, typename C>
class HeapPrioriyQueue {
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

template <typename E, typename C>
int HeapPrioriyQueue<E, C>::size() const {
    return T.size();
}

template <typename E, typename C>
bool HeapPrioriyQueue<E, C>::empty() const {
    return size() == 0;
}

template <typename E, typename C>
void HeapPrioriyQueue<E, C>::insert(const E &e) {
    T.addLast(e);                   // add element 
    Position v = T.last();          // last idx => we set recently add element position v
    while (!T.isRoot(v)) {          // when v is root -> !true -> false -> loop break
        Position u = T.parent(v);   // v's parent -> u
        if (!isLess(*v, *u))        // if *v < *u => !(true) -> false => 즉, 부모 노드의 element의 값이 더 크므로 break
            break;
        T.swap(v, u);               // when the *v > *u => swap  
        v = u;                      // 위로 갱신해서 계속하여 반복을 하기 위해서
    }
}

template <typename E, typename C>
const E &HeapPrioriyQueue<E, C>::min() {
    return *(T.root());
}

template <typename E, typename C>
void HeapPrioriyQueue<E, C>::removeMin() {
    if (size() == 1)
        T.removeLast();
    else {
        Position u = T.root();
        T.swap(u, T.last());
        T.removeLast();
        while (T.hasLeft(u)) {
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*T.right(u), *v))
                v = T.right(u);
            if (isLess(*v, *u)) {
                T.swap(u, v);
                u = v;
            }
            else
                break;
        }        
    }
}
