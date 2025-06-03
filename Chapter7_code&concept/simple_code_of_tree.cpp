#include <iostream>

template <typename E>
class Position<E> {
    public:
        E &operator*();
        Position parent() const;
        PositionList children() const;
        bool isRoot() const;
        bool isExternal() const;
};

template <typename E>
class PositionList<E> {

};

template <typename E>
class tree<E> {
    public:
        class Position;
        class PositionList;
    public:
        int size() const;           
        bool empty() const;
        Position root() const;
        PositionList positions() const;
};