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

	vector<pair<int,int>> v;
	loop(i, n) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}

	sort(v.begin(), v.end(), cmp);
	int flag = 0;
	for (int i = 0; i < n-1; i++) {
		pair<int,int> p1 = v[i];
		pair<int,int> p2 = v[i+1];
		if (p1.second > p2.second) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		cout << "Happy Alex" << "\n";
	} else {
		cout << "Poor Alex" << "\n";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}