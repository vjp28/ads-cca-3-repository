#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

// Find representative (with path compression)
int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

// Union two sets (by size)
void merge(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) swap(pa, pb);
        parent[pb] = pa;
        sz[pa] += sz[pb];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) parent[i] = i;

    while (q--) {
        char type;
        cin >> type;

        if (type == 'M') {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        } 
        else if (type == 'Q') {
            int a;
            cin >> a;
            cout << sz[findParent(a)] << "\n";
        }
    }

    return 0;
}
