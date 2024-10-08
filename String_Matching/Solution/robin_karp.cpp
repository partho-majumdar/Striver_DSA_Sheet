#include <bits/stdc++.h>
using namespace std;

class KarpRabin
{
private:
    const int PRIME = 101;

    double calculateHash(const char *str, int end)
    {
        double hash = 0;
        for (int i = 0; i < end; i++)
        {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    double updateHash(double prevHash, char oldChar, char newChar, int patternLength)
    {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash += newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }

public:
    void search(const char *text, const char *pattern)
    {
        int patternLength = strlen(pattern);
        int textLength = strlen(text);

        if (patternLength > textLength)
        {
            cout << "Pattern is longer than text, no match possible.\n";
            return;
        }

        double patternHash = calculateHash(pattern, patternLength);
        double textHash = calculateHash(text, patternLength);

        for (int i = 0; i <= textLength - patternLength; i++)
        {
            if (textHash == patternHash)
            {
                if (strncmp(&text[i], pattern, patternLength) == 0)
                {
                    cout << "Pattern found at index " << i << "\n";
                }
            }

            if (i < textLength - patternLength)
            {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }
    }
};

int main()
{
    KarpRabin kr;
    char text[] = "23412345123";
    char pattern[] = "123";
    kr.search(text, pattern);
    return 0;
}
