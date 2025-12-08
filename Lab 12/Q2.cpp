#include <iostream>
#include <string>

using namespace std;

#define BASE_CHAR_COUNT 256

void rollingHashSearch(string document, string target, int modulus) {
    int docLen = document.length();
    int targetLen = target.length();
    int matchPositions[100];
    int trueMatchCount = 0;
    int falsePositiveIndices[100];
    int collisionCount = 0;

    if (targetLen == 0 || targetLen > docLen) {
        cout << "No valid target to search.\n";
        return;
    }

    int targetHash = 0;
    int windowHash = 0;
    int exponent = 1;

    for (int i = 0; i < targetLen - 1; i++) {
        exponent = (exponent * BASE_CHAR_COUNT) % modulus;
    }

    for (int i = 0; i < targetLen; i++) {
        targetHash = (BASE_CHAR_COUNT * targetHash + target[i]) % modulus;
        windowHash = (BASE_CHAR_COUNT * windowHash + document[i]) % modulus;
    }

    for (int i = 0; i <= docLen - targetLen; i++) {

        if (targetHash == windowHash) {
            bool isRealMatch = true;
            for (int j = 0; j < targetLen; j++) {
                if (document[i + j] != target[j]) {
                    isRealMatch = false;
                    break;
                }
            }
            if (isRealMatch) {
                matchPositions[trueMatchCount] = i;
                trueMatchCount++;
            }
            else{
                falsePositiveIndices[collisionCount] = i;
                collisionCount++ ;
            }
        }

        if (i < docLen - targetLen) {
            windowHash = (BASE_CHAR_COUNT * (windowHash - document[i] * exponent) + document[i + targetLen]) % modulus;

            if (windowHash < 0)
                windowHash = windowHash + modulus;
        }
    }

    if(collisionCount > 0){
        cout << "Collisions occur at window : [" ;
        for(int k = 0 ; k < collisionCount ; k++){
            cout << falsePositiveIndices[k] << " ";
        }
        cout << "]" << endl;
        cout << "\n(These were discarded)\n\n";
    }

    cout << "Output: [";
    for(int k = 0 ; k < trueMatchCount ; k++){
        cout << matchPositions[k] << " ";
    }
    cout << "]" << endl;
}

int main() {
    string mainText = "Data structures and Algorithms are fun. Algorithms make tasks easier.";
    string searchTarget = "Algorithms";

    int primeModulus = 101;

    rollingHashSearch(mainText, searchTarget, primeModulus);

    return 0;
}
