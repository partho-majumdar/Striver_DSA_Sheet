#include <bits/stdc++.h>
using namespace std;

void minStops(int D, int m, int n, int stations[])
{
    int init = 0, refills = 0, stopIndex = 0;
    int stops[n]; 
    int i = 0;

    while (init + m < D)
    {
        int nextStop = -1;
        while (stopIndex < n && stations[stopIndex] <= init + m)
        {
            nextStop = stopIndex;
            stopIndex++;
        }

        if (nextStop == -1)
        {
            cout << "impossible" << endl;
            return;
        }

        init = stations[nextStop];
        stops[i++] = nextStop + 1;
        refills++;
    }

    cout << "Count: " << refills << endl;
    for (int j = 0; j < i; ++j)
    {
        cout << "Stop at gas station " << stops[j] << " (" << stations[stops[j] - 1] << " miles)" << endl;
    }
}

int main()
{
    int D, m, n;
    cin >> D >> m >> n;
    int stations[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> stations[i];
    }

    minStops(D, m, n, stations);
    return 0;
}