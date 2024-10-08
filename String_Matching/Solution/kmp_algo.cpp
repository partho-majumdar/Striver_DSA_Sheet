#include <iostream>
#include <string>

using namespace std;

void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0; // length of the previous longest prefix suffix

    lps[0] = 0; // lps[0] is always 0

    // loop calculates lps[i] for i = 1 to M
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // consider the previous lps[]
            }
            else
            { // if len is 0, then lps[i] is 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // reset j to lps[j-1]
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1]; // reset j to lps[j-1]
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    KMPSearch(pat, txt);

    return 0;
}