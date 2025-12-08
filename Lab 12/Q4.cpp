#include <iostream>
#include <string>

using namespace std;

void buildPrefixTable(const string& searchTarget, int prefixArray[])
{
    int targetLength = searchTarget.length();
    prefixArray[0] = 0;
    int commonLen = 0;
    int cursor = 1;

    while (cursor < targetLength)
    {
        if (searchTarget[cursor] == searchTarget[commonLen])
        {
            commonLen++;
            prefixArray[cursor] = commonLen;
            cursor++;
        }
        else
        {
            if (commonLen != 0)
                commonLen = prefixArray[commonLen - 1];
            else
            {
                prefixArray[cursor] = 0;
                cursor++;
            }
        }
    }
}

int main()
{
    string document = "ababababc";
    string target = "abab";

    int docLen = document.length();
    int targetLen = target.length();

    int prefixArray[200];
    buildPrefixTable(target, prefixArray);

    cout << "LPS Array: [";
    for (int i = 0; i < targetLen; i++)
    {
        cout << prefixArray[i];
        if (i != targetLen - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    int occurrenceIndices[200];
    int matchCount = 0;
    int docIndex = 0;
    int targetIndex = 0;

    while (docIndex < docLen)
    {
        if (target[targetIndex] == document[docIndex])
        {
            docIndex++;
            targetIndex++;
        }

        if (targetIndex == targetLen)
        {
            occurrenceIndices[matchCount++] = docIndex - targetIndex;
            targetIndex = prefixArray[targetIndex - 1];
        }
        else if (docIndex < docLen && target[targetIndex] != document[docIndex])
        {
            if (targetIndex != 0)
                targetIndex = prefixArray[targetIndex - 1];
            else
                docIndex++;
        }
    }

    cout << "Output: [";
    for (int k = 0; k < matchCount; k++)
    {
        cout << occurrenceIndices[k];
    }
    cout << "]";
}
