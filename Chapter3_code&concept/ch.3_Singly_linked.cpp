#include <cstdio>
#include <iostream>

using namespace std;

class SNode {
    string elem;        // value를 elem에 저장
    SNode *next;        // next 노드를 가르키는 ptr

    friend class SLinkedList; // StringLinkedList class에 접근하기 위해서 friend 선언
};

class SLinkedList {
    public:
        SLinkedList();
        ~SLinkedList();
        bool empty() const;
        const string &front() const;
        void addFront(const string &e);
        void removeFront();
    private:
        SNode *head;
};

SLinkedList::SLinkedList() : head(NULL) {}  // 처음 생성하고, 이때 head는 tail이면서 null을 가르키게 된다.  
SLinkedList::~SLinkedList() {
    while (!empty()) {  // NULL일 때까지
        removeFront();  // 앞에서부터 계속 삭제
    }
}
bool SLinkedList::empty() const {
    return head == NULL; // head가 NULL이면 빈 값값
}
const string &SLinkedList::front() const {
    return head->next; // head의 다음값이 가장 맨 앞
}

void SLinkedList::addFront(const string &e) {
    SNode *v = new SNode;   // v라는 새로운 노드 생성
    v->elem = e;            // v의 elem에 e값 저장
    v->next = head;         // v의 next는 기존에 있던 head이다.
    head = v;               // head 교체
}

void SLinkedList::removeFront() {
    SNode *old = head; // 앞에 있는 값을 가져오기 위해 head 저장
    head = old->next;
    delete old;
}

int main() {

    return EXIT_SUCCESS;
}