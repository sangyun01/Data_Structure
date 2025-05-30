#include "heap.h"

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size() const {
    return T.size();    // using Vector STL size function
}

template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty() const {
    return size() == 0; // when size is zero -> true
}

template <typename E, typename C>
const E &HeapPriorityQueue<E, C>::min() {
    return *(T.root()); // Dereferencing the T.root() is min element 
}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e){
    T.addLast(e);   // push the lastly
    Position v = T.last();  // set the iterator v
    while(!T.isRoot(v)) {   // repeat the loop where root
        Position u = T.parent(v);   // bring the v parent node u
        if(!isLess(*v, *u)) // compare the element value.
            break;
        T.swap(v, u);   //if child node is small then swap the element
        v = u;          // bring the iterator parent node.
    }
}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin() {
    if(size() == 1) // only has root
        T.removeLast();
    else {
        Position u = T.root();  // root iterator sets u
        T.swap(u, T.last());    // swap the element value u and last element value
        T.removeLast();         // then remove the before root value(min value)
        while (T.hasLeft(u)) {  // if u has child (child left -> right)
            Position v = T.left(u); // 1st set v is u's left child
            if (T.hasRight(u) && isLess(*(T.right(u)), *v)) // if u also has right child then compare the left child and right child
                v = T.right(u); // if right child element value more smaller then overwrite T.right(u)
            if (isLess(*v, *u)) {   // compare the parent node and child node element value
                T.swap(u, v);   // child node is more smaller than parent node, swap u, v
                u = v;          // bring the iterator child node.
            }
            else break;
        }
    }
}

template class HeapPriorityQueue<int, Comparator<int>>; // using int type
template class HeapPriorityQueue<char, Comparator<char>>; // using char type