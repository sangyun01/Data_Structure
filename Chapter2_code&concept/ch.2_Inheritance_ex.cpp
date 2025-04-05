#include <cstdio>
#include <iostream>

using namespace std;

//수열 클래스 선언
class Progression{
    public:
        Progression(long f = 0);
        virtual ~Progression(); //상속 중 부모클래스이기에 virtual선언하여 소멸 과정에서 메모리 누수 방지
        void printProgression(int n);
    protected:
        virtual long firstValue();
        virtual long nextValue();
    protected:
        long first;
        long cur;
};

Progression::Progression(long f) : first(f), cur(f) {}  //생성자
Progression::~Progression() {}                          //소멸자
void Progression::printProgression(int n) {             //출력 함수 선언 총 n개
    cout << firstValue();                               //처음 값 출력
    for (int i = 2; i <= n; i++) {                      //2부터 해서 n까지 총 n개 발생 
        cout << ' ' << nextValue();                     
    }
    cout << endl;
}

long Progression::firstValue() {
    cur = first;    //처음값을 현재값에 저장
    return cur;
}

long Progression::nextValue() {
    cur += 1;       // 1씩 증가
    return cur;
}

//등차수열 class 선언
class ArithProgression: public Progression {
    public:
        ArithProgression(long i = 1);   //default = 1 인 inc
        ~ArithProgression();

    protected:
        virtual long nextValue();       //virtual 위에 선언 해서 안써도 되긴 함, 등차수열 시 요기로 override
    protected:
        long inc;
};

ArithProgression::ArithProgression(long i) : Progression(), inc(i) {}     //Progression()이라 하는 부분이 Polymorphism(다형성)이다.
ArithProgression::~ArithProgression() {}
long ArithProgression::nextValue() {    //function define
    cur += inc;
    return cur;
}

//등비수열 class 선언
class GeomProgression : public Progression {
    public:
        GeomProgression(long b = 2);    //default = 2, 즉 base는 2인 등비수열
        ~GeomProgression();             //소멸자
    protected:
        virtual long nextValue();       //virtual 위에 선언 있어서 마찬가지로 없어도 상관 없음, 등비 수열시 여기로 override
    protected:
        long base;
};

GeomProgression::GeomProgression(long b) : Progression(1), base(b) {}   //등비수열이라 초기값이 0이면 의미가 없어서 1로 초기화 선언
GeomProgression::~GeomProgression() {}
long GeomProgression::nextValue() {
    cur *= base;
    return cur;
}

int main() {
    Progression *prog;

    cout << "Arithmetic Progression with default increment : " << endl;
    prog = new ArithProgression();  //default 생성자
    prog->printProgression(10);     //10개 호출
    cout << "Arithmetic Progression with increment 5 : " << endl;
    prog = new ArithProgression(5); //5씩 증가
    prog->printProgression(10);     //10개 호출

    cout << "Geometric Progression with default base : " << endl;
    prog = new GeomProgression();
    prog->printProgression(10);
    cout << "Geometric Progression with base 3 : " << endl;
    prog = new GeomProgression(3);  //3배씩 증가
    prog->printProgression(10);
    
    return EXIT_SUCCESS;
}