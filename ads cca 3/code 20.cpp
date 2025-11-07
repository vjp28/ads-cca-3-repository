#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> st;
    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty()) {
            int val = (a[i] & st.top()) ^ (a[i] | st.top());
            maxVal = max(maxVal, val);

            if (st.top() > a[i])
                st.pop();
            else
                break;
        }
        st.push(a[i]);
    }

    cout << maxVal << endl;
    return 0;
}
