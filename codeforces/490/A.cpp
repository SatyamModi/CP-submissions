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

	int n;
	cin >> n;

	vector<int> t(n, 0);
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < n; i++) {
		cin >> t[i];
		if (t[i] == 1) {
			v1.push_back(i+1);
		} else if (t[i] == 2) {
			v2.push_back(i+1);
		} else {
			v3.push_back(i+1);
		}
	}

	int k = min(v1.size(), min(v2.size(), v3.size()));
	cout << k << "\n";
	
	for (int i = 0; i < k; i++) {
		cout << v1[i] << " " << v2[i] << " " << v3[i] << "\n";
	}


}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}