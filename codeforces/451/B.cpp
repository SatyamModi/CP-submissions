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

void solve() {
	int n;
	cin >> n;

	vi a(n, 0);
	loop(i, n) {
		cin >> a[i];
	}

	int idx = 0;
	// find the decreasing sequence 
	while (idx < n-1 && a[idx] < a[idx+1]) {
		idx++;
	}

	if (idx == n-1) {
		cout << "yes" << "\n";
		cout << 1 << " " << 1 << "\n";
	} else {
		int minc = -1;
		if (idx > 0) {
			minc = a[idx-1];
		}
		int j = idx;

		// find the last index j to which it is decreasing 
		while (j < n-1 && a[j] > a[j+1]) {
			j++;
		}

		int maxi = a[idx];
		int mini = a[j];

		if (mini > minc) {

			bool g = false;
			for (int k = j+1; k < n-1; k++) {
				if (a[k] < a[k+1] && a[k] > maxi && a[k+1] > maxi) {
					continue;
				} else {
					g = true;
				}
			}

			if (j != n-1) {
				if (a[n-1] < maxi) {
					g = true;
				} else {
					g = g;
				}
			} else {
				g = g;
			}

			if (g) {
				cout << "no" << "\n";
			} else {
				cout << "yes" << "\n";
				cout << idx+1 << " " << j+1 << "\n";
			}
		} else {
			cout << "no" << "\n";
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