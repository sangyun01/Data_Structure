#pragma once

#include <iostream>
#include <list>
#include <vector>

// using the hash function change the string to number
struct stringHash {
    std::size_t operator()(const std::string& key) const {
        std::size_t hash = 0;
        for (char c : key) {
            hash = (hash * 31) + c;
        }
        return hash;
    }
};

// entry consist of key and value pair
template<typename K, typename V>
class Entry {
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}
    const K& key() const { return _key; }
    const V& value() const { return _value; }
    void setKey(const K& k) { _key = k; }
    void setValue(const V& v) { _value = v; }
private:
    K _key;
    V _value;
};

// define the hashMap 
template <typename K, typename V, typename H>
class HashMap {
public:
    typedef Entry<const K, V> Entry;
    class Iterator;                 // 3rd user code of Iterator -> when the using the move the other entry
public:
    HashMap(int capacity = 100);    // constructor
    int size() const;               // return the hash table size
    bool empty() const;             // check the hash table is empty
    Iterator find(const K& k);      // find the position of Key value
    Iterator put(const K& k, const V& v);   // input the element pair k, v
    void erase(const K& k);         // using the key to remove entry
    void erase(const Iterator& p);  // using the Iterator to remove entry
    Iterator begin();   // return the Iterator to first entry
    Iterator end();     // return the Iterator to last entry
protected:
    typedef std::list<Entry> Bucket;        // 2nd bucket list Iteratorx
    typedef std::vector<Bucket> BktArray;   // 1st bucket array Iterator
    Iterator finder(const K& k);            // find the entry and return the Iterator
    Iterator inserter(const Iterator& p, const Entry& e); // input the entry and return the Iterator
    void eraser(const Iterator& p); // remove teh entry
    typedef typename BktArray::iterator Bltor; // define name BktArray iterator is Bltor
    typedef typename Bucket::iterator Eltor; // define name Bucket iterator is Eltor
    static void nextEntry(Iterator& p) { ++p.ent; } // move the Iterator to next entry
    static bool endOfBkt(const Iterator& p) { return p.ent == p.bkt->end(); } // return the hash is empty then true.
private:
    int n;
    H hash;
    BktArray B;
public:
    class Iterator {
    private:
        Eltor ent;
        Bltor bkt;
        const BktArray* ba;
    public:
        Iterator(const BktArray& a, const Bltor& b, const Eltor& q = Eltor()) : ent(q), bkt(b), ba(&a) {}
        Entry& operator*() const; // Dereference
        bool operator==(const Iterator& p) const; // compare the iterator
        Iterator& operator++(); // increse(move) the Iterator
        friend class HashMap;
    };
};
