#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define loop(i, n) for (int i = 0; i < n; i++)
#define input(t) cin >> t
// #define push_back pb

typedef vector<int> vi;
typedef pair<int,int> pi;

string strip(string s) {
	int idx = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			idx = i;
			break;
		}
	}

	s = s.substr(idx);

	return s;
}


vector<string> split (const string &s, char delim) {
	vector<string> result;
	stringstream ss (s);
	string item;

	while (getline (ss, item, delim)) {
        result.push_back(strip(item));
    }

    return result;
}


string join(vector<string> v, string delim) {
	string out="";
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size()-1) {
			out.append(v[i]);
		} else {
			out.append(v[i]);
			out.append(delim);
		}
	}
	return out;
}

bool prime(ll n, vector<bool> &isPrime, vector<bool> &done) {
	if (done[n]) {
		return isPrime[n];
	}

	if (n == 1) {
		done[1] = true;
		isPrime[1] = false;
		return false;
	}
	if (n == 2) {
		done[2] = true;
		isPrime[2] = true;
		return true;
	} else {

		for (ll i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				done[n] = true;
				isPrime[n] = false;
				return false;
			}
		}
		done[n] = true;
		isPrime[n] = true;
		return true;
	}
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.first < b.first) {
		return true;
	} else  {
		return false;
	}
}

int search(int q, int start, int end, vector<pair<int, int>> &v) {

	if (start == end) {
		return start + 1;
	} else {
		int mid = (start + end)/2;
		if (v[mid].first > q) {
			return search(q, start, mid, v);
		} else if (q > v[mid].second) {
			return search(q, mid+1, end, v);
		} else {
			return mid+1;
		}
	}
}

void solve() {

	int t;
	cin >> t;
	while (t-- > 0) {

		int n;
		cin >> n;

		vi a(2*n, 0);
		loop(i, 2*n) {
			cin >> a[i];
		}

		vi b(n+1, 0);

		vi res;
		loop(i, 2*n) {
			if (b[a[i]] == 0) {
				res.push_back(a[i]);
				b[a[i]] = 1;
			} else {
				continue;
			}
		}

		loop(i, n) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}