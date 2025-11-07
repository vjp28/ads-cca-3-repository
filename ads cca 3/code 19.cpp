#include <bits/stdc++.h>
using namespace std;

int poisonousPlants(vector<int> p) {
    stack<pair<int, int>> st;
    int maxDays = 0;

    for (int i = 0; i < p.size(); i++) {
        int days = 0;

        while (!st.empty() && p[i] <= st.top().first) {
            days = max(days, st.top().second);
            st.pop();
        }

        if (st.empty()) {
            days = 0; // survives forever
        } else {
            days += 1; // dies 1 day after
        }

        maxDays = max(maxDays, days);
        st.push({p[i], days});
    }

    return maxDays;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << poisonousPlants(p) << endl;
    return 0;
}
