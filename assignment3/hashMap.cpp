#include "hashMap.h"
#include <iostream>
#include <list>
#include <vector>

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Entry& HashMap<K, V, H>::Iterator::operator*() const {
    return *ent; // Dereference
}

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::Iterator::operator==(const Iterator& p) const {
    if (ba != p.ba || bkt != p.bkt) // other array or bucket
        return false; // return false
    else if (bkt == ba->end()) // end means lastly 
        return true; // return true
    else
        return ent == p.ent; // when the same entry true, other case is false
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator& HashMap<K, V, H>::Iterator::operator++() {
    ++ent; // move the next Iterator
    if (endOfBkt(*this)) { // when the empty
        ++bkt; // move the next Iterator
        while (bkt != ba->end() && bkt->empty())
            ++bkt; // repeat the process
        if (bkt == ba->end()) // when the last
            return *this; // return the Iterator
        ent = bkt->begin(); // move the Iterator begin to go around searching the hash
    }
    return *this;
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::end() {
    return Iterator(B, B.end()); // move the Iterator go end 
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::begin() {
    if (empty())    // when the hash is empty then go end
        return end();
    Bltor bkt = B.begin(); // define bucket Iterator to begin
    while (bkt->empty())
        ++bkt;  // find the not empty entry
    return Iterator(B, bkt, bkt->begin()); // and return the iterator
}


template <typename K, typename V, typename H>
HashMap<K, V, H>::HashMap(int capacity) : n(0), B(capacity) {} // constructor

template <typename K, typename V, typename H>
int HashMap<K, V, H>::size() const {
    return n; // return the size
}

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::empty() const {
    return size() == 0; // check the hash is empty
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::finder(const K& k) {
    int i = hash(k) % B.size(); // using the hash function
    Bltor bkt = B.begin() + i; // using the bkt Iterator and offset
    Iterator p(B, bkt, bkt->begin()); // find the key where the first
    while (!endOfBkt(p) && (*p).key() != k) // when not lastly and not find the key 
        nextEntry(p); // move the next entry
    return p;
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::find(const K& k) {
    Iterator p = finder(k); // using the key and finder return the iterator
    if (endOfBkt(p)) // not exist
        return end(); // return end()
    else // exist
        return p; // return iterator p
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::inserter(const Iterator& p, const Entry& e) {
    Eltor ins = p.bkt->insert(p.ent, e); // insert the entry
    n++; // increase the number of entry
    return Iterator(B, p.bkt, ins); // return the iterator
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::put(const K& k, const V& v) {
    Iterator p = finder(k); // first find the key and return Iterator
    if (endOfBkt(p)) { // when not exist the key
        return inserter(p, Entry(k, v)); // input the entry
    }
    else {
        p.ent->setValue(v); // change the value where the basic of key
        return p; // return the Iterator
    }
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::eraser(const Iterator& p) {
    p.bkt->erase(p.ent); // using the Iterator and delete the entry
    n--; // decrease the number of entries
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const Iterator& p) {
    eraser(p); // using the erase process through Iterator
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const K& k) {
    Iterator p = finder(k); // using the erase process through key
    if (endOfBkt(p)) {
        std::cout << "error" << std::endl;
        return;
    }
    eraser(p);
}

template class HashMap<std::string, int, stringHash>;