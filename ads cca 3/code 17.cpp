#include <bits/stdc++.h>
using namespace std;

long largestRectangle(vector<int> h) {
    stack<int> st;
    long maxArea = 0;
    int n = h.size();
    int i = 0;

    while (i < n) {
        if (st.empty() || h[st.top()] <= h[i]) {
            st.push(i++);
        } else {
            int top = st.top();
            st.pop();
            long width = st.empty() ? i : i - st.top() - 1;
            long area = (long)h[top] * width;
            maxArea = max(maxArea, area);
        }
    }

    while (!st.empty()) {
        int top = st.top();
        st.pop();
        long width = st.empty() ? i : i - st.top() - 1;
        long area = (long)h[top] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    cout << largestRectangle(h) << endl;
    return 0;
}
