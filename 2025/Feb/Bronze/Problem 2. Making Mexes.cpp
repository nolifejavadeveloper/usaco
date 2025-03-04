#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> count(N + 1);
    int bridge = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        count[a]++;
    }

    for (int i = 0; i <= N; i++) {
        cout << max(count[i], bridge) << endl;
        if (count[i] == 0) bridge++;
    }
}
