#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, U;
    cin >> N >> U;
    vector<vector<bool>> drawing(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            drawing[i][j] = c == '#';
        }
    }

    int totalOps = 0;

    for (int y = 0; y < N / 2; y++) {
        for (int x = 0; x < N / 2; x++) {
            bool base = drawing[x][y];
            int y2 = (N - 1) - y;
            int x2 = (N - 1) - x;

            int count = 0;
            if (drawing[x][y2] != base) count++;
            if (drawing[x2][y2] != base) count++;
            if (drawing[x2][y] != base) count++;

            totalOps += min(4 - count, count);
        }
    }

    cout << totalOps << endl;


    for (int i = 0; i < U; i++) {
        int r, c;
        cin >> r >> c;
        r -= 1;
        c -= 1;

        bool base = drawing[r][c];

        int y2 = (N - 1) - c;
        int x2 = (N - 1) - r;

        int count = 0;
        if (drawing[r][y2] != base) count++;
        if (drawing[x2][y2] != base) count++;
        if (drawing[x2][c] != base) count++;
        // cout << min(4 - count, count) << " OLD" << "OLD COUNT: " << count << endl;;
        totalOps -= min(4 - count, count);

        drawing[r][c] = !drawing[r][c];

        base = !base;
        count = 0;
        if (drawing[r][y2] != base) count++;
        if (drawing[x2][y2] != base) count++;
        if (drawing[x2][c] != base) count++;

        totalOps += min(4 - count, count);

        // cout << min(4 - count, count) << " NEW" << endl;

        cout << totalOps << endl;

    }


    return 0;
}
