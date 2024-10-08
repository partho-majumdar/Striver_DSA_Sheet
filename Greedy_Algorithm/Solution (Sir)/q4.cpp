#include <bits/stdc++.h>
using namespace std;

void findMinStops(int D, int m, vector<int> stations)
{
    int n = stations.size();
    int current_position = 0;
    int last_stop = 0;
    int stops = 0;
    vector<int> stop_stations;

    stations.push_back(D);

    for (int i = 0; i < n; i++)
    {
        if (stations[i + 1] - current_position > m)
        {
            stop_stations.push_back(i + 1);
            last_stop = stations[i];
            current_position = stations[i];
            stops++;
        }

        if (stations[i] - last_stop > m)
        {
            cout << "Can't reach destination\n";
            return;
        }
    }

    cout << "Minimum number of stops: " << stops << endl;
    for (int i = 0; i < stop_stations.size(); i++)
    {
        cout << "Stop at gas station " << stop_stations[i] << " (" << stations[stop_stations[i] - 1] << " miles)" << endl;
    }
}

int main()
{
    int D, m, n;

    cout << "Enter the total distance to the destination (D): ";
    cin >> D;
    cout << "Enter the maximum distance the car can travel with full tank (m): ";
    cin >> m;
    cout << "Enter the number of gas stations (n): ";
    cin >> n;

    vector<int> stations(n);
    cout << "Enter the distances of the gas stations from the start point:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> stations[i];
    }

    findMinStops(D, m, stations);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void minStops(int D, int m, int n, int stations[])
// {
//     int init = 0, refills = 0, stopIndex = 0;
//     int stops[n];
//     int i = 0;

//     while (init + m < D)
//     {
//         int nextStop = -1;
//         while (stopIndex < n && stations[stopIndex] <= init + m)
//         {
//             nextStop = stopIndex;
//             stopIndex++;
//         }

//         if (nextStop == -1)
//         {
//             cout << "impossible" << endl;
//             return;
//         }

//         init = stations[nextStop];
//         stops[i++] = nextStop + 1;
//         refills++;
//     }

//     cout << "Count: " << refills << endl;
//     for (int j = 0; j < i; ++j)
//     {
//         cout << "Stop at gas station " << stops[j] << " (" << stations[stops[j] - 1] << " miles)" << endl;
//     }
// }

// int main()
// {
//     int D, m, n;
//     cin >> D >> m >> n;
//     int stations[n];

//     for (int i = 0; i < n; ++i)
//     {
//         cin >> stations[i];
//     }

//     minStops(D, m, n, stations);
//     return 0;
// }