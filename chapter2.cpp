#include <cstdlib>
#include <iostream>

using namespace std;
//using MealType = string;

enum MealType
{
    NO_PREF,
    REGULAR,
    VEGETARIAN
};

string MealtypeToString(MealType mt) {
    switch(mt) {
        case NO_PREF:
            return "NO Preference";
        case REGULAR:
            return "Regular";
        case VEGETARIAN:
            return "Vegetarian";
        default:
            return "Unknown";
    }
}

class Passenger {
    public:
        Passenger();
        Passenger(const string &nm, MealType mp, const string &ffn = "NONE");
        //Passenger(const Passenger &pass);
        
        bool isFrequentFlyer() const;
        void makeFrequenFlyer(const string &newFreqFlyerNo);

        friend ostream &operator<<(ostream &os, const Passenger &pass);

    private:
        string name;
        MealType mealPref;
        bool isFreqFlyer;
        string freqFlyerNo;
};

//initailizer list
Passenger::Passenger() 
    : name("NO NAME"), mealPref(NO_PREF), isFreqFlyer(false), freqFlyerNo("NONE") {}

Passenger::Passenger(const string &nm, MealType mp, const string &ffn) 
    : name(nm), mealPref(mp), isFreqFlyer(ffn != "NONE"), freqFlyerNo(ffn) {}

bool Passenger::isFrequentFlyer() const { //Passenger class 외부에서 선언 -> ::사용
    return isFreqFlyer;
}

void Passenger::makeFrequenFlyer(const string& newFreqFlyerNo) {
    isFreqFlyer = true;
    freqFlyerNo = newFreqFlyerNo;
}

ostream& operator<<(ostream& os, const Passenger& pass){
    os << "Passenger Name: " << pass.name << endl;
    os << "Meal Preference: " << MealtypeToString(pass.mealPref) << endl;
    os << "Frequent Flyer: " << (pass.isFreqFlyer ? "YES" : "NO") << endl;
    if(pass.isFreqFlyer) {
        os << "Frequent Flyer number: " << pass.freqFlyerNo << endl;
    }

    return os;
}


int main() {

    Passenger p1;
    Passenger p2("John Smith", VEGETARIAN, "293145");
    Passenger p3("Pocahontas", REGULAR);
    Passenger p4(p3); //p3 shallow copy -> 주소 복사는 아니기에 이후에 값은 변화 X
    Passenger p5 = p2;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    cout << p5 << endl;


    return EXIT_SUCCESS;
}