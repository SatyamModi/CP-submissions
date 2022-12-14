#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define loop(i, n) for (int i = 0; i < n; i++)
#define input(t) cin >> t
// #define push_back pb

typedef vector<int> vi;

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

int minDist(int n, int m, vector<int> &dist) {

	if (dist[n] != -1) {
		return dist[n];
	} else {
		if (n > 1) {
			if (n > 2) {
				dist[n] = min(1 + minDist(n-1, m, dist), 1 + minDist(n*2, m, dist));
			} else {
				dist[n] = 1 + minDist(4, m, dist);
			}
		} else {
			dist[n] = 1 + minDist(n+1, m, dist);
		}
		return dist[n];
	}
}

void solve() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int a, b, c, n;
		cin >> a >> b >> c >> n;

		if ((n+b+c-2*a) >= 0 && (n+b+c-2*a)%3 == 0) {
			if ((n+a+c-2*b) >= 0 && (n+a+c-2*b)%3 == 0) {
				if ((n+b+a-2*c) >= 0 && (n+b+a-2*c)%3 == 0) {
					cout << "YES" << "\n";
				} else {
					cout << "NO" << "\n";
				}
			} else {
				cout << "NO" << "\n";
			}
		} else {
			cout << "NO" << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}