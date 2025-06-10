#pragma once

#include <iostream>
#include <list>
#include <vector>

struct stringHash {
    std::size_t operator()(const std::string& key) const {
        std::size_t hash = 0;
        for (char c : key) {
            hash = (hash * 31) + c;
        }
        return hash;
    }
};

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
    void erase(const K& k);         // remove entry with key k
    void erase(const Iterator& p);  // erase entry at p
    Iterator begin();
    Iterator end();
protected:
    typedef std::list<Entry> Bucket;        // 2nd bucket list Iteratorx
    typedef std::vector<Bucket> BktArray;   // 1st bucket array Iterator
    Iterator finder(const K& k);
    Iterator inserter(const Iterator& p, const Entry& e);
    void eraser(const Iterator& p);
    typedef typename BktArray::iterator Bltor;
    typedef typename Bucket::iterator Eltor;
    static void nextEntry(Iterator& p) { ++p.ent; }
    static bool endOfBkt(const Iterator& p) { return p.ent == p.bkt->end(); }
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
        Entry& operator*() const;
        bool operator==(const Iterator& p) const;
        Iterator& operator++();
        friend class HashMap;
    };
};
