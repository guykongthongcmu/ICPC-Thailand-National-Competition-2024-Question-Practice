#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;
using namespace std::chrono;

class cake {
    int n, i, j, change;
    vector<int> cF;
    unordered_map<int, int> pieceInfo;

public:
    cake(int nF) {
        n = nF;
        i = 0;
        j = 0;
        change = 0;
    }

    void iniCakes() {
        for (int i = 1; i <= n; i++) {
            pieceInfo[i] = 0;
        }
    }

    void eat() {
        bool doneEating = false;
        int doneEat = 0;
        int eatVal = 1;
        int temp = 0;

        if (n != 1 && n != 2 && n != 0) {
            while (!doneEating) {
                j = 0;
                if (!isEdge(eatVal) && !isAdjacent(cF, eatVal) && eatVal < n) {
                    pieceInfo[eatVal] = -1;
                    cF.push_back(eatVal);
                    cout << "Ate " << eatVal << endl;

                    for (int i = 1; i <= n; i++) {
                        if (i != eatVal && pieceInfo[i] != -1) {
                            temp = pieceInfo[i] + abs(i - eatVal);
                            pieceInfo[i] = temp;
                            j++;
                        }
                    }

                    eatVal++;
                    doneEat++;
                    change += (j - eatVal);
                    printPieceInfo();
                } else if (noMoreEat()) {
                    cout << "Deliciousness: " << deliciousness(change) << endl;
                    doneEating = true;
                } else {
                    eatVal++;
                }
            }
        } else {
            cout << 0 << endl;
        }
    }

    int deliciousness(int value) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            if (pieceInfo[i] != -1) {
                total += pieceInfo[i];
            }
        }
        return total - value;
    }

    bool isEdge(int value) {
        return value == 1 || value == n;
    }

    bool noMoreEat() {
        for (int i = 1; i < n; i++) {
            if (pieceInfo[i] != -1) {
                if (!isEdge(i) && !isAdjacent(cF, i)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAdjacent(vector<int>& cFValues, int value) {
        for (int pieces : cFValues) {
            if (value == pieces || value == pieces - 1 || value == pieces + 1) {
                return true;
            }
        }
        return false;
    }

    void printPieceInfo() {
        vector<int> keys;
        for (auto& pair : pieceInfo) {
            keys.push_back(pair.first);
        }
        
        sort(keys.begin(), keys.end());

        for (int key : keys) {
            cout << key << ": " << pieceInfo[key] << " ";
        }
        cout << endl;
    }
};

int main() {
    int userInput;
    cin >> userInput;
    clock_t start = clock();

    cake test(userInput);
    test.iniCakes();
    test.eat();

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << duration * 1000 << "ms" << endl;
    cout << duration << "s" << endl;
    return 0;
}
