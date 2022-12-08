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
	int n, m;
	cin >> n >> m;
	vector<int> a(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	ll s = 0;
	int prev = 1;
	for (int i = 0; i < m; i++) {
		if (a[i] >= prev) {
			s += a[i]-prev;
		} else {
			s += n-(prev-a[i]);
		}
		prev = a[i];
	}
	cout << s << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}