#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define loop(i, n) for (int i = 0; i < n; i++)

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
        result.push_back (strip(item));
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

void solve() {

	int t;
	cin >> t;
	// t = 1;
	
	while (t-- > 0) {
		int n;
		cin >> n;
		vector<int> a(n, 0);
		vector<int> b(n, 0);
		int mina = 1e9;
		int minb = 1e9;

		loop(i, n) {
			cin >> a[i];
			mina = min(a[i], mina);
		}
		loop(i, n) {
			cin >> b[i];
			minb = min(b[i], minb);
		}
		ll c = 0;
		loop(i,n) {
			if (a[i] == mina) {
				c += b[i]-minb;
			} else if (b[i] == minb) {
				c += a[i]-mina;
			} else {
				c += max(a[i]-mina, b[i]-minb);
			}
		}
		cout << c << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}