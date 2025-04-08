#include <cstdio>
#include <iostream>

using namespace std;

class GameEntry {
    public:
        GameEntry(const string &n = "", int s = 0);
        ~GameEntry();
        string getName() const;
        int getScore() const;
    private:
        string name;
        int score;
};

GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {} //생성자
GameEntry::~GameEntry() {}  //소멸자
string GameEntry::getName() const { return name; }  // 이름 반환
int GameEntry::getScore() const { return score; }   // 점수 반환

class Scores {
    public:
        Scores(int maxEnt = 10);
        ~Scores();
        void add(const GameEntry &e);
        GameEntry remove(int i);
    private:
        int maxEntries;
        int numEntries;
        GameEntry *entries;
};

Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;
    numEntries = 0;
    entries = new GameEntry[maxEntries];    //maxEnt만큼 메모리 공간을 할당
}
Scores::~Scores() {
    delete[] entries;   // 생성자에서 new로 entries를 선언하였기 때문에
}
void Scores::add(const GameEntry &e) {
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
        if (newScore <= entries[maxEntries - 1].getScore()) {
            return; //10등 숫자보다 작으니까 굳이 반환필요 없이 바로 끝냄
        }
    }
    else {
        numEntries++; //값을 추가할거니까
    }

    int i = numEntries - 2; // -2인 이유
    //만약 5개가 이미 저장되어있다면, index는 0~4이다.
    //else의 코드에서 6개로 증가하였기에 index는 이제 0~5로 늘어났을것이다.
    //하지만 기존에 저장된 가장 낮은 값은 그대로 index 4에 위치한다.
    //따라서 index이기에 - 1을 하고, 가장 낮은 숫자의 index는 아직 증가하지 않았기에 -1을 해준다.

    while (i >= 0 && newScore > entries[i].getScore()) {
        //while문 설명 -> i >= 0이어야 한다. index는 0보다 작을 수 없기에.
        //이때 순서가 중요한데, &&의 경우 왼쪽부터 먼저 실행을 한다.
        //따라서 i=-1을 가져와서 error가 나는 상황을 미리 방지한다.
        //이후의 코드는 새로 받은 점수가 기존의 점수(낮은값부터)를 비교하여 대입 위치를 찾는다.
        entries[i + 1] = entries[i];    // 새로 받은 숫자가 더 큼을 의미하므로, 작은 숫자를 오른쪽으로 이동시킨다.
        i--;//왼쪽으로 이동하여 다시 비교를 시작한다.
    }

    //위의 과정을 지나면 빈칸이 생겨있다. 그 칸이 값을 넣을 곳이다.
    entries[i + 1] = newScore;
    //i+1인 이유는 위에서 i--를 해주었기에
    //ex. 80[0] 70[1] 60[2] 50[3] 40[4] 이 있고 65였다.
    //그러면 numEntries = 5 -> 6이 되고 i = 6 - 2 = 4이다.
    //40[4]와 65를 비교하면 40[5]가 되고 i = 3이 된다.
    //50[3]과 65를 비교하면 50[4]가 되고 i = 2가 된다.
    //60[2]과 65를 비교하면 60[3]이 되고 i = 1이 된다.
    //70[1]과 65를 비교하면 반복문 탈출한다. 따라서 i = 1인 상태이다.
    //이때 2의 인덱스에 넣어야 하므로, i + 1이다.
}

GameEntry Scores::remove(int i) {
    if ((i < 0) || (i >= numEntries)) {
        //삭제할 인덱스가 0보다 작거나 없는 인덱스를 삭제하면 오류가 난다.
        cout << "error" << endl;
    }
    GameEntry e = entries[i];
    //삭제할 인덱스를 받아서 그 이름과 점수를 객체 e에 저장한다.
    for (int j = i + 1; j < numEntries; j++) {
        // j는 삭제된 i 바로 오른쪽의 값
        // 그거를 numEntries까지 계속 한다. -> 뒤에 numEntries는 -1해야겠지?
        // index니까 +1씩 계속
        entries[j - 1] = entries[j];
        //왼쪽부터 슈슉 저장
    }
    numEntries--;   // index 1개가 빠졌으니까
    return e;
}

//sorting Array function
void insertionSort(char *A, int n) { //n개 문자의 배열 A이며, 값을 비교해야하기에 argument로 pointer 사용
    for (int i = 1; i < n; i++) {
        char cur = A[i];    //현재값(뽑아서 비교할 값)을 저장한다.

        int j = i - 1; //왼쪽이랑 비교할거니까..
        while ((j >= 0) && (A[j] > cur)) {
            //index가 음수면 안되니까,
            //왼쪽값이 현재값보다 크면 오름차순이 아니니까 작동해야해서
            A[j + 1] = A[j];
            j--; // 오름차순이 될 때까지 계속 비교
        }
        A[j + 1] = cur;
        //위에서 -1을 해서 다시 +1을 해줘서 current value를 대입한다.
    }
}

int main() {

    returen EXIT_SUCCESS;
}