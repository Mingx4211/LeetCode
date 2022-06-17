#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegTree {
public:
    vector<ll> tree;
    vector<ll> arr;
    vector<ll> t;
    vector<ll> mul;
    int p_mod;

    SegTree(int n, int p_mod) {
        tree = vector<ll>(4 * n);
        arr = vector<ll>(n + 1);
        t = vector<ll>(4 * n);
        mul = vector<ll>(4 * n, 1);
        this->p_mod = p_mod;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        build(1, n, 1);
    }

    void build(int l, int r, int p) {
        if (l == r) {
            tree[p] = arr[l] % p_mod;
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = (tree[p * 2] + tree[p * 2 + 1]) % p_mod;
    }

    void multi(int s, int e, int l, int r, int p, int k) {
        if (s <= l && r <= e) {
            tree[p] = (tree[p] * k) % p_mod;
            mul[p] = (mul[p] * k) % p_mod;
            t[p] = (t[p] * k) % p_mod;
            return;
        }
        //必须先 pushDown !!!!!!!!!!!!!!!!
        pushDown(l, r, p);
        int mid = (l + r) / 2;
        if (mid >= s) {
            multi(s, e, l, mid, p * 2, k);
        }
        if (mid < e) {
            multi(s, e, mid + 1, r, p * 2 + 1, k);
        }
        tree[p] = (tree[p * 2] + tree[p * 2 + 1]) % p_mod;
    }

    void add(int s, int e, int l, int r, int p, int k) {
        if (s <= l && r <= e) {
            tree[p] = (tree[p] + (k * (r - l + 1))) % p_mod;
            t[p] = (t[p] + k) % p_mod;
            return;
        }
        //必须先 pushDown!!!!!!!!!!!!!!
        pushDown(l, r, p);
        int mid = (l + r) / 2;
        if (mid >= s) {
            add(s, e, l, mid, p * 2, k);
        }
        if (mid < e) {
            add(s, e, mid + 1, r, p * 2 + 1, k);
        }
        tree[p] = (tree[p * 2] + tree[p * 2 + 1]) % p_mod;
    }

    void pushDown(int l, int r, int p) {
        if ((l != r) && (t[p] != 0 || mul[p] != 1)) {
            int mid = (l + r) / 2;
            tree[p * 2] = (tree[p * 2] * mul[p] + t[p] * (mid - l + 1)) % p_mod;
            tree[p * 2 + 1] = (tree[p * 2 + 1] * mul[p] + t[p] * (r - mid)) % p_mod;
            t[p * 2] = (t[p * 2] * mul[p] + t[p]) % p_mod;
            t[p * 2 + 1] = (t[p * 2 + 1] * mul[p] + t[p]) % p_mod;
            mul[p * 2] = (mul[p * 2] * mul[p]) % p_mod;
            mul[p * 2 + 1] = (mul[p * 2 + 1] * mul[p]) % p_mod;
        }
        t[p] = 0;
        mul[p] = 1;
    }

    ll query(int x, int y, int l, int r, int p) {
        if (x <= l && r <= y) {
            return tree[p];
        }
        pushDown(l, r, p);
        int mid = (l + r) / 2;
        ll res = 0;
        if (mid >= x) {
            res += query(x, y, l, mid, p * 2);
        } 
        if (mid < y) {
            res += query(x, y, mid + 1, r, p * 2 + 1);
        }
        return res % p_mod;
    }
};

int main() {
    int n, m, p_mod;
    cin >> n >> m >> p_mod;

    SegTree st(n, p_mod);
    int t, x, y, k;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> k;
            st.multi(x, y, 1, n, 1, k);
        }
        if (t == 2) {
            cin >> x >> y >> k;
            st.add(x, y, 1, n, 1, k);
        }
        if (t == 3) {
            cin >> x >> y;
            cout << st.query(x, y, 1, n, 1) << endl;
        }
    }

    return 0;
}