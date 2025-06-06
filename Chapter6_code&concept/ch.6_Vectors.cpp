#include <cstdio>
#include <iostream>

using namespace std;

typedef int Elem;
class ArrayVector {
    public:
        ArrayVector();              //constructor
        ~ArrayVector();             //destructor
        int size() const;           //size
        bool empty() const;         // check the array is empty
        Elem &operator[](int i);    // V[i]
        Elem &at(int i);            // V[i] and check the index is invalid
        void erase(int i);          // remove the element at index i
        void insert(int i, const Elem &e);  // add the element at index i
        void reserve(int N);        // change the array size to N
    private:
        int capacity;               // size the array
        int n;                      // element the number of array index
        Elem *A;                    // pointer about array
}

ArrayVector::ArrayVector() : capacity(0), n(0), A(NULL) {}
ArrayVector::~ArrayVector() {
    delete[] A;
}
int ArrayVector::size() const {
    return n;
}
bool ArrayVector::empty() const {
    return n == 0;
}
Elem &ArrayVector::operator[](int i) {
    return A[i];
}
Elem &ArrayVector::at(int i) {
    if(i<0||i>n)
        return;
    return A[i];
}
void ArrayVector::erase(int i) {
    for (int j = i; j < n - 1; j++) {
        A[j] = A[j + 1];
    }
    n--;
}
void ArrayVector::reserve(int N) {
    if(capacity >= N) {
        return;
    }
    Elem *B = new Elem[N];
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    if (A!=NULL) {
        delete[] A;
    }
    A = B;
    capacity = N;
}
void ArrayVector::insert(int i, const Elem &e) {
    if(n>=capacity) {
        reserve(max(1, 2 * capacity));
    }
    for (int j = n - 1; j >= i; j--) {
        A[j + 1] = A[j];
    }
    A[i] = e;
    n++;
}

int main()
{

    return 0;
}