#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long

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
	while (t-- > 0) {
		int n;
		cin >> n;
		vector<int> res;
		int x1 = n/1e4;
		n = n - (1e4 * x1);
		int x2 = n/1e3;
		n = n - 1e3*x2;
		int x3 = n/1e2;
		n = n - 1e2*x3;
		int x4 = n/1e1;
		n = n - 1e1*x4;
		int x5 = n;

		if (x1 != 0) {
			res.push_back(x1*1e4);
		} 

		if (x2 != 0) {
			res.push_back(x2*1e3);
		}

		if (x3 != 0) {
			res.push_back(x3*1e2);
		}

		if (x4 != 0) {
			res.push_back(x4*1e1);
		}

		if (x5 != 0) {
			res.push_back(x5);
		}

		cout << res.size() << "\n";
		for (int i = 0; i < res.size(); i++) {
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