#include "heap.h"

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size() const {

}

template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty() const {

}

template <typename E, typename C>
const E &HeapPriorityQueue<E, C>::min() {

}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e){

}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin() {

}

template class HeapPriorityQueue<int, Comparator<int>>;
template class HeapPriorityQueue<char, Comparator<char>>;