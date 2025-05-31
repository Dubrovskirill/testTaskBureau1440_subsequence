#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsAllLetters(const vector<int>& sequence) {
    vector<bool> hasNumber(27, false);
    for (int num : sequence) {
        if (num >= 1 && num <= 26) {
            hasNumber[num] = true;
        }
    }
    
    for (int i = 1; i <= 26; i++) {
        if (!hasNumber[i]) {
            return false;
        }
    }
    return true;
}

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
    
    return minLength;
}


int main() {

    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    if (!containsAllLetters(sequence)) {
        cout << "NONE" << endl;
        return 0;
    }
    
    int result = findMinSubsequenceLength(sequence);
    cout << result << endl;
    
    return 0;
}
