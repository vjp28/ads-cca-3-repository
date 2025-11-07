#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr(n);  // initialize n empty sequences
    vector<int> result;          // stores output for type 2 queries
    int lastAnswer = 0;

    for (auto &q : queries) {
        int type = q[0];
        int x = q[1];
        int y = q[2];
        int idx = (x ^ lastAnswer) % n;  // XOR and modulo operation

        if (type == 1) {
            arr[idx].push_back(y);       // append y to arr[idx]
        } else if (type == 2) {
            lastAnswer = arr[idx][y % arr[idx].size()];  // get value
            result.push_back(lastAnswer);                // store output
        }
    }
    return result;
}

int main() {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = [](string temp) {
        stringstream ss(temp);
        string s;
        vector<string> tokens;
        while (ss >> s) tokens.push_back(s);
        return tokens;
    }(first_multiple_input_temp);

    int n = stoi(first_multiple_input[0]);
    int q = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }
    }

    vector<int> result = dynamicArray(n, queries);

    for (int val : result) {
        cout << val << endl;
    }

    return 0;
}
