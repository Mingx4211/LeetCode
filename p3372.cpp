#include <bits/stdc++.h>

#define N 400000

using namespace std;


typedef long long ll;

class SegmentTree {
public:
    vector<ll> tree;
    vector<ll> t;
    vector<ll> arr;

    SegmentTree(int n) {
        tree = vector<ll> (4 * n);
        t = vector<ll> (4 * n);
        arr = vector<ll> (n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    ll build(int s, int e, int p) {
        if (s == e) {
            tree[p] = arr[s];
            return tree[p];
        }
        int mid = (s + e) / 2;
        ll sum = 0;
        sum += build(s, mid, p * 2);
        sum += build(mid + 1, e, p * 2 + 1);
        tree[p] = sum;
        return sum;
    }

    void update(int s, int e, int l, int r, int k, int p) {
        if (s <= l && r <= e) {
            if (l == r) {
                tree[p] += k;
            } else {
                tree[p] += (r - l + 1) * k, t[p] += k;
            }
            return;
        }
        int mid = (l + r) / 2;
        if (t[p] != 0 && l != r)     pushDown(l, r, p);
        if (mid >= s) {
            update(s, e, l, mid, k, p * 2);
        }
        if (mid < e) {
            update(s, e, mid + 1, r, k, p * 2 + 1);
        }
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    ll getSum(int s, int e, int l, int r, int p) {
        if (s <= l && r <= e) {
            return tree[p];
        }
        int mid = (l + r) / 2;
        if (t[p] != 0 && l != r)     pushDown(l, r, p);
        ll sum = 0;
        if (mid >= s) {
            sum += getSum(s, e, l, mid, p * 2);
        }
        if (mid < e) {
            sum += getSum(s, e, mid + 1, r, p * 2 + 1);
        }
        return sum;
    }

    void pushDown(int l, int r, int p) {
        int mid = (l + r) / 2;
        if (mid == l)   tree[p * 2] += t[p];
        else    tree[p * 2] += (mid - l + 1) * t[p], t[p * 2] += t[p];
        if (mid == r)   tree[p * 2 + 1] += t[p];
        else    tree[p * 2 + 1] += (r - mid) * t[p], t[p * 2 + 1] += t[p];
        t[p] = 0;
    }
};


int main() {
    freopen("input", "r", stdin);
    int n, m;
    cin >> n >> m;
    SegmentTree st(n);
    ll t, x, y, k;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> k;
            st.update(x, y, 1, n, k, 1);
        }
        if (t == 2) {
            cin >> x >> y;
            cout << st.getSum(x, y, 1, n, 1) << endl;
        }
    }
    return 0;
}