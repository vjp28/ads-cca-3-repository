#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    unordered_map<string, int> freq;
    vector<int> result;

    // Count occurrences of each string in stringList
    for (auto &s : stringList) {
        freq[s]++;
    }

    // For each query, append its frequency (or 0 if not found)
    for (auto &q : queries) {
        result.push_back(freq[q]);
    }

    return result;
}

int main() {
    string stringList_count_temp;
    getline(cin, stringList_count_temp);

    int stringList_count = stoi(stringList_count_temp);
    vector<string> stringList(stringList_count);

    for (int i = 0; i < stringList_count; i++) {
        string stringList_item;
        getline(cin, stringList_item);
        stringList[i] = stringList_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(queries_count_temp);
    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);
        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(stringList, queries);

    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) cout << "\n";
    }

    return 0;
}
