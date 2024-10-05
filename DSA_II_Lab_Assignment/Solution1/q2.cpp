#include <bits/stdc++.h>
using namespace std;

void minRefills(int D, int m, int n, vector<int> &stations)
{
    int num_refills = 0, current_pos = 0, last_stop = 0, stop_count = 0;

    while (current_pos < D)
    {
        if (current_pos + m >= D)
        {
            break;
        }

        while (stop_count < n && stations[stop_count] <= current_pos + m)
        {
            last_stop = stations[stop_count];
            stop_count++;
        }

        if (current_pos == last_stop)
        {
            cout << "ERROR" << endl;
        }

        current_pos = last_stop;
        num_refills++;
        cout << "Stop at gas station " << stop_count << " (" << current_pos << " miles)" << endl;
    }
    cout << "Minimum stops: " << num_refills;
}

int main()
{
    int D, m, n;
    cin >> D >> m >> n;
    vector<int> stations(n);

    for (int stop_count = 0; stop_count < n; stop_count++)
    {
        cin >> stations[stop_count];
    }

    minRefills(D, m, n, stations);
    return 0;
}
