//ch1.1 ex)code with comment

#include <cstdio>
//c++은 헤더파일 뒤에 .h를 선언하지 않는다.
//cstdio 라이브러리는 c언어에서 사용하는 stdio.h과 동일하며 printf()와 같은 함수를 포함하는 헤더파일이다.
#include <iostream>
//iostream 라이브러리는 c++에서 사용하는 std::cout등을 포함하는 헤더파일이다.

using namespace std;
//cout이나 endl과 같은 함수는 std의 namespace안에 정의되어 있음.
//이를 호출하게 되면 std 안에 있는 namespace 함수는 std::를 생략하고 사용이 가능하다.
//동일한 이름의 함수가 있게 되면, 충돌이 발생할 수 있기 때문에 사용을 하는데 있어 주의를 해야 한다.
//만약 using std::string이라면 std의 string만 std생략이 가능하다.

using MealType = string;    // MealType도 string형을 의미한다.
typedef string Elem;        // Elem은 string형을 의미한다. 즉 위의 코드와 동일함.

class Passenger {   //Class Passenger 선언
    public:         //public class 외부에서도 접근이 가능
        Passenger();    //생성자
        Passenger(const string &nm, MealType mp, const string &ffn = "NONE");   //생성자의 default value
        Passenger(const Passenger &pass);   //
        bool isFrequentFlyer() const;   //회원인지 확인 true / false
        void makeFrequenFlyer(const string &newFreqFlyerNo); //번호 생성해주는 함수

    private:
        string name;        //승객이름
        MealType mealPref;  //음식 선호 -> string형
        bool isFreqFlyer;   //회원여부
        string freqFlyerNo; //회원번호
};

bool Passenger::isFrequentFlyer() const { //Passenger class 외부에서 선언 -> ::사용
    return isFreqFlyer;
}

void Passenger::makeFrequenFlyer(const string& newFreqFlyerNo) { //string형의 숫자를 받아서
    isFreqFlyer = true; // 회원이라면
    freqFlyerNo = newFreqFlyerNo; //새로 받은 값을 freqFlyerNo에 저장해준다.
}



int main(void) {    //int main()도 가능함.
    int x, y;       //값을 입력받을 argument
    int sum;        //입력받은 2개의 argument를 정수형 변수 sum에 저장한다.

    cout << "Please enter two num";     //"Please enter two num" 출력한다.
    cin >> x >> y;                      //순서대로 x, y의 값을 입력받는다. 공백으로 구분한다.

    sum = x + y;
    cout << "The value of sum is" << sum << endl;   //endl은 줄바꿈 \n과 동일함 end-of-line

    //string code
    string s = "to be";     //std 생략 가능
    string t = "not" + s;   //string끼리 비교가능
    string u = s + "or" + t; //to be or not to be가 출력

    if(s > t)       // t랑 n비교하면 t가 더 크므로 true를 반환한다.
        cout << u;  //따라서 출력한다.

    return EXIT_SUCCESS;    // return 0;과 동일하다.
}