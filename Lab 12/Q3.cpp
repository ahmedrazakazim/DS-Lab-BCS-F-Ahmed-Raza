#include <iostream>
#include <string>

using namespace std;

#define ALPHABET_SIZE 256

void preprocessBadChar(const string& target, int charShiftTable[])
{
    int len = target.length();
    for (int i = 0; i < ALPHABET_SIZE; i++)
        charShiftTable[i] = -1;
    for (int i = 0; i < len; i++)
        charShiftTable[(int)target[i]] = i;
}

void computeMatchLength(const string& target, int suffixLength[])
{
    int len = target.length();
    suffixLength[len - 1] = len;
    int k = len - 1;
    int l = 0;

    for (int i = len - 2; i >= 0; i--)
    {
        if (i > k && suffixLength[i + len - 1 - l] < i - k)
            suffixLength[i] = suffixLength[i + len - 1 - l];
        else
        {
            if (i < k)
                k = i;
            l = i;
            while (k >= 0 && target[k] == target[k + len - 1 - l])
                k--;
            suffixLength[i] = l - k;
        }
    }
}

void preprocessGoodSuffix(const string& target, int suffixShiftTable[])
{
    int len = target.length();
    int suffixLenArray[200];
    computeMatchLength(target, suffixLenArray);

    for (int i = 0; i < len; i++)
        suffixShiftTable[i] = len;

    int m = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (suffixLenArray[i] == i + 1)
        {
            for (; m < len - 1 - i; m++)
                suffixShiftTable[m] = len - 1 - i;
        }
    }

    for (int i = 0; i < len - 1; i++)
        suffixShiftTable[len - 1 - suffixLenArray[i]] = len - 1 - i;
}

void boyerMooreSearch(const string& document, const string& target)
{
    int docLen = document.length();
    int targetLen = target.length();
    int charShiftTable[ALPHABET_SIZE];
    int suffixShiftTable[200];
    int matchPositions[200];
    int matchCount = 0;

    preprocessBadChar(target, charShiftTable);
    preprocessGoodSuffix(target, suffixShiftTable);

    int docIndex = 0;
    while (docIndex <= docLen - targetLen)
    {
        int targetIndex = targetLen - 1;

        while (targetIndex >= 0 && target[targetIndex] == document[docIndex + targetIndex])
            targetIndex--;

        if (targetIndex < 0)
        {
            matchPositions[matchCount++] = docIndex;
            docIndex = docIndex + suffixShiftTable[0];
        }
        else
        {
            int charJump = targetIndex - charShiftTable[(int)document[docIndex + targetIndex]];
            int suffixJump = suffixShiftTable[targetIndex];

            int shiftAmount;
            if (charJump > suffixJump)
                shiftAmount = charJump;
            else
                shiftAmount = suffixJump;

            if (shiftAmount < 1)
                shiftAmount = 1;

            docIndex = docIndex + shiftAmount;
        }
    }

    cout << "Output: [";
    for (int i = 0; i < matchCount; i++)
    {
        cout << matchPositions[i];
        if (i != matchCount - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    string text = "ACGTACGTGACG";
    string pattern = "ACG";

    boyerMooreSearch(text, pattern);

    return 0;
}
