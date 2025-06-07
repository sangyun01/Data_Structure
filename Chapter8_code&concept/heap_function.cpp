#include "heap.h"

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size() const {
    return T.size();
}

template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty() const {
    return size() == 0;
}

template <typename E, typename C>
const E &HeapPriorityQueue<E, C>::min() {
    return *(T.root());
}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e){
    T.addLast(e);
    Position v = T.last();
    while(!T.isRoot(v)) {
        Position u = T.parent(v);
        if(!isLess(*v, *u)) {
            break;
        }
        T.swap(v, u);
        v = u;
    }
}



template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin() {
    if(size() == 1) {
        T.removeLast();
    }
    else {
        Position u = T.root();
        T.swap(u, T.last());
        T.removeLast();
        while (T.hasLeft(u)) {
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u);
            if (isLess(*v, *u)) { // true -> *v < *u 이다. /u(부모)가 v(자식)보다 우선순위가 커야한다. -> 숫자가 작아야한다. 
                T.swap(u, v);   // 그래서 부모와 자식을 바꾼다.
                u = v;  // 다시 반복
            }
            else break;
        }
    }
}

template class HeapPriorityQueue<int, Comparator<int>>;
template class HeapPriorityQueue<char, Comparator<char>>;