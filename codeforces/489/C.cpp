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
	// cin >> t;
	t = 1;
	
	while (t-- > 0) {
		int m, s;
		cin >> m >> s;

		if (s == 0) {
			if (m == 1) {
				cout << 0 << " " << 0  << "\n";
			} else {
				cout << -1 << " " << -1 << "\n";
			}
		} else if (s > 9*m) {
			cout << -1 << " " << -1 << "\n";
		} else {
			string ans = "";
			int n = m;
			int s1 = s;
			while (m != 0) {
				if (s >= (m-1)*9) {
					ans += to_string(s - (m-1)*9);
					m--;
					for (int i = 0; i < m; i++) {
						ans += '9';
					}
					break;
				} else {
					if (m == n) {
						ans += '1';
						m--;
						s--;
					} else {
						ans += '0';
						m--;
					}
				}
			}

			string res1 = ans;
			string res2 = "";


			while (s1 >= 9) {
				res2 += '9';
				s1 -= 9;
			}

			if (n > res2.length()) {
				res2 += to_string(s1);
				int idx2 = 0;
				int l = res2.length();
				while (idx2 < n-l) {
					res2 += '0';
					idx2++;
				}
			}
			
			cout << res1 << " " << res2 << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    // string s = "cbad";
    // sort(s.begin(), s.end(), greater<char>());
    // cout << s << "\n";

}