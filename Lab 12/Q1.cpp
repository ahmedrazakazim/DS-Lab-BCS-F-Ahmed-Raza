#include <iostream>
#include <string>

using namespace std;

void performBruteForceSearch(const string& mainText, const string& searchPattern) {
    int textLen = mainText.length();
    int patternLen = searchPattern.length();
    long totalChecks = 0;
    
    
    const int MAX_INDICES = 200;
    int foundIndices[MAX_INDICES]; 
    int matchTally = 0;

    for (int i = 0; i <= textLen - patternLen; ++i) {
        int j;
        for (j = 0; j < patternLen; ++j) {
            totalChecks++;
            if (mainText[i + j] != searchPattern[j]) {
                break;
            }
        }
        
        if (j == patternLen) {
            if (matchTally < MAX_INDICES) {
                foundIndices[matchTally] = i;
                matchTally++;
            }
        }
    }

    cout << "Output: [";
    for (int k = 0; k < matchTally; ++k) {
        cout << foundIndices[k] << " ";
    }
    cout << "]" << endl;
    cout << "Comparisions: " << totalChecks << endl;
}

int main() {
    string mainText = "the quick brown fox jumps over the lazy dog";
    string searchPattern = "the";

    performBruteForceSearch(mainText, searchPattern);

    return 0;
}
