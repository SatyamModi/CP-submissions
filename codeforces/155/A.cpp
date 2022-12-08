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

bool cmp(const vector<int> &a, const vector<int> &b) {
	return a[0] < b[0];
}


void solve() {
	int n;
	cin >> n;
	vector<int> a(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int c = 0;
	int lo = a[0];
	int hi = a[0];

	for (int i = 1; i < n; i++) {
		if (a[i] > hi) {
			c += 1;
			hi = a[i];
		} else if (a[i] < lo){
			c += 1;
			lo = a[i];
		} else {
			continue;
		}
	}

	cout << c << "\n";
	
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}