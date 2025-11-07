#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    d = d % n; // handle cases where d > n
    vector<int> rotated(n);

    for (int i = 0; i < n; i++) {
        rotated[i] = arr[(i + d) % n];
    }

    return rotated;
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
    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = [](string temp) {
        stringstream ss(temp);
        string s;
        vector<string> tokens;
        while (ss >> s) tokens.push_back(s);
        return tokens;
    }(arr_temp_temp);

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = stoi(arr_temp[i]);
    }

    vector<int> result = rotateLeft(d, arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }

    cout << "\n";
    return 0;
}
