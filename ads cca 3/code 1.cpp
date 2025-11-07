#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<int> reverseArray(vector<int> a) {
    reverse(a.begin(), a.end());
    return a;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(arr_count);
    for (int i = 0; i < arr_count; i++) {
        cin >> arr[i];
    }

    vector<int> res = reverseArray(arr);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];
        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";
    fout.close();

    return 0;
}
