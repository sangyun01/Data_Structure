    #include <cstdio>
    #include <iostream>

    using namespace std;

    // 목표 스택 구현 -> iterator 써서
    // stakc -> LIFO -> single Linked

    typedef string Elem;

    class SNode {
        Elem elem;
        SNode *next;

        friend class SLinkedList;
    };

    class SLinkedList {
        public:
            SLinkedList();
            ~SLinkedList();
            bool empty() const;
            const Elem &front() const;
            void addFront(const Elem &e);
            void removeFront();
        private:
            SNode *head;
    };

    class ArrayStack {
        public :
            ArrayStack();
            ~ArrayStack();
            int size() const;
            bool empty() const;
            const Elem &top();
            void push(const Elem &e);
            void pop();
        private:
            SLinkedList S;
            int n;
    };

    SLinkedList::SLinkedList() : head(nullptr) {}
    SLinkedList::~SLinkedList() {
        while (!empty()) {
            removeFront();
        }
    }
    bool SLinkedList::empty() const {
        return head == nullptr;
    }
    const Elem&SLinkedList::front() const {
        return head->elem;
    }
    void SLinkedList::addFront(const Elem &e) {
        SNode *v = new SNode;
        v->elem = e;
        v->next = head;
        head = v;
    }
    void SLinkedList::removeFront() {
        SNode *old = head;
        head = old->next;
        delete old;
    }

    ArrayStack::ArrayStack() : S(), n(0) {}
    ArrayStack::~ArrayStack() {}
    bool ArrayStack::empty() const {
        return n == 0;
    }
    int ArrayStack::size() const {
        return n;
    }
    const Elem&ArrayStack::top() const {
        return S.front();
    }
    void ArrayStack::push(const Elem &e) {
        S.addFront(e);
        n++;
    }
    void ArrayStack::pop() {
        S.removeFront();
        n--;
    }

    int main() {

        return EXIT_SUCCESS;
    }
