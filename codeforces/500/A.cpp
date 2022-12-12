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

	int n,t ;
	cin >> n >> t;

	vector<int> a(n, 0);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}

	map<int,int> d;
	for (int i = 1; i < n; i++) {
		d[i] = i + a[i];
	}

	int flag = 0;
	int start = 1;
	while (start != n){
		start = d[start];
		// cout << start << "\n";
		if (start == t) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}