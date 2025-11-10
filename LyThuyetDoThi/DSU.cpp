#include <bits/stdc++.h>
using namespace std;

int parent[1005], sz[1005];
 
void make_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1; // hoặc rank[i] = 0
    }
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    // In nhóm đại diện
    for (int i = 1; i <= n; i++)
        cout << "Phan tu " << i << " thuoc nhom " << find_set(i) << "\n";
}
