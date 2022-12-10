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

	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int start = 0;
	int end = n-1;
	int s1 = 0;
	int s2 = 0;
	int turn = 0;
	while (start <= end) {
		if (turn == 0) {
			if (a[start] > a[end]) {
				s1 += a[start];
				start += 1;
			} else {
				s1 += a[end];
				end -= 1;
			}
			turn = 1;
		} else {
			if (a[start] > a[end]) {
				s2 += a[start];
				start += 1;
			} else {
				s2 += a[end];
				end -= 1;
			}
			turn = 0;
		}
	}

	cout << s1 << " " << s2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}