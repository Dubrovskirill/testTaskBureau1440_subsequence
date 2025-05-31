#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

int findMinSubsequenceLength(const vector<int>& sequence) {
    int n = sequence.size();
    int minLength = n;
    unordered_map<int, int> lastPos;
    vector<int> count(27, 0);
    int uniqueCount = 0;
    
    for (int i = 0; i < n; i++) {
        int num = sequence[i];
        if (num >= 1 && num <= 26) {
            if (count[num] == 0) {
                uniqueCount++;
            }
            count[num]++;
            lastPos[num] = i;
            
            if (uniqueCount == 26) {
                int minPos = i;
                for (int j = 1; j <= 26; j++) {
                    minPos = min(minPos, lastPos[j]);
                }
                minLength = min(minLength, i - minPos + 1);
            }
        }
    }
    
    return uniqueCount == 26 ? minLength : -1;
}

int main() {
    ifstream input("data_prog_contest_problem_2.txt");
    if (!input.is_open()) {
        cout << "File opening error" << endl;
        return 1;
    }

    int n;
    input >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        input >> sequence[i];
    }
    
    int result = findMinSubsequenceLength(sequence);
    if (result == -1) {
        cout << "NONE" << endl;
    } else {
        cout << "The length of the minimum subsequence: " << result << endl;
    }
    
    return 0;
}
