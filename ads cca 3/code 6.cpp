#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long long> arr(n + 2, 0); // +2 for handling b+1 index safely

    for (auto &q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long long maxVal = 0;
    long long current = 0;

    for (int i = 1; i <= n; i++) {
        current += arr[i];
        if (current > maxVal)
            maxVal = current;
    }

    return maxVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    cout << arrayManipulation(n, queries) << "\n";
    return 0;
}
