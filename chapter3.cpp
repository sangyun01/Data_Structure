//chapter 3 - array
#include <cstdlib>
#include <iostream>

using namespace std;

class GameEntry {
    public:
        GameEntry(const string & = " ", int s = 0);
        string getName() const;
        int getScore() const;
    private:
        string name;
        int score;
};

GameEntry::GameEntry(const string & n, int s) : name(n), score(s) {}
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

class Scores{
    public:
        Scores(int maxEnt = 10);
        ~Scores();
        void add(const GameEntry &e);
        GameEntry remove(int i);
        void print();

    private:
        int maxEntries;
        int numEntries;
        GameEntry *entries;
};

Scores::Scores(int maxEnt){ //생성자
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores(){ //소멸자
    delete[] entries;
}

void Scores::add(const GameEntry &e){
    int newScore = e.getScore();
    if(numEntries == maxEntries) {
        if(newScore < entries[maxEntries-1].getScore())
            return;
    }
    else
        numEntries++;

    int i = numEntries - 2;
    while (i >=0 && newScore > entries[i].getScore()) {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
}

GameEntry Scores::remove(int i) {
    if((i<0)||(i<=numEntries))
        cout << "Invalid Index" << endl;
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++){
        entries[j - 1] = entries[j];
    }
    numEntries--;
    return e;
}

int main(){
    Scores scoreBoard(5);

    scoreBoard.add(GameEntry("A", 90));
    scoreBoard.add(GameEntry("B", 80));
    scoreBoard.print();

    return 0;
}