#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(iter(v));
    int minn = INT_MAX;
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            minn = min(minn, abs(v[i] + v[j] + v[k]));
            int j_k = v[j] + v[k];
            if (j_k > -v[i])
                k--;
            else if (j_k < -v[i])
                j++;
            else {
                cout << "0\n";
                return 0;
            }
        }
    }
    cout << minn << endl;
    return 0;
}