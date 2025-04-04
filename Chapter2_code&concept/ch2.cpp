#include <cstdio>
#include <iostream>

using namespace std;

class Person {
    private:                    //private 변수
        string name;
        string idNum;

    public:                     //public 변수
        Person();               //생성자
        Person(const string &name, const string &idNum);    //default
        ~Person();              //소멸자
        void print();           //print함수 void형으로 선언
        string getName();       //name이 private이라서 getName이용하여 받아오기 위해 함수 선언, 이름이니까 string
};

Person::Person() : name(""), idNum("") {}
Person::Person(const string &name, const string &idNum) : name(name), idNum(idNum) {}
Person::~Person() {}
void Person::print() {
    cout << "Name " << name << endl;
    cout << "IDnum " << idNum << endl;
}

class Student : public Person {
    private:
        string major;
        int gradYear;

    public:
        Student();
        Student(const string &name, const string &idNum, const string &major, const int gradYear);
        ~Student();
        void print();
        void changeMajor(const string &newMajor);
};

Student::Student() : Person(), major(""), gradYear(0) {}    //Person의 상속을 받으므로 Person()으로 name과 idNum 받음
Student::Student(const string &name, const string &idNum, const string &major, const int gradYear) : Person(name, idNum), major(major), gradYear(gradYear) {}
Student::~Student() {}
void Student::print() {
    Person::print();    //위의 print함수 먼저 실행 즉, 이름과 학번 먼저 뽑고
    cout << "major" << major << endl;   //전공
    cout << "Year" << gradYear << endl; //학년 출력
}

class Base {
    private:
        int priv;
    protected:
        int prot;
    public:
        int publ;
};

class Derived: public Base {
    void someMemberFunction() {
        //cout << priv; // error 발생 -> private 변수라서
        cout << prot;   // 상속을 받기때문에 접근하여 출력이 가능하다.
        cout << publ;   // public은 가능
    }
};

class Unrelated{
    Base X;

    void anotherMemberFunction() {
        //cout << X.priv; //private이라서 오류
        //cout << X.prot; //상속 받지 않기에 오류
        cout << X.publ; //가능
    }
};

int main() {

    Person person("Mary", "12-345");    //Person class로 person 선언
    Student student("Bob", "98-764", "Math", 2012); //위와 비슷비슷
    Student *s = new Student("Caral", "34-927", "Physics", 2014); //포인터를 이용한 new 객체 생성

    //person.changeMajor("Physics"); -> Person은 major가 없으므로 오류를 발생
    student.changeMajor("English"); //가능함 근데 함수는 안만들긴 함..ㅇㅇ..

    return EXIT_SUCCESS;
}