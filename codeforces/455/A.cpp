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

ll fun(vector<ll> &v, ll i, map<ll,ll> &freq, vector<ll> &csum) {
	ll n = v.size();
	if (i == n) {
		return 0;
	}

	if (csum[i] != -1) {
		return csum[i];
	}

	if (i == n-1) {
		csum[i] = v[i]*freq[v[i]];
		return csum[i];
	} else {
		ll c1 = v[i]*freq[v[i]] + fun(v, i+2, freq, csum);
		ll c2 = fun(v, i+1, freq, csum);
		csum[i] = max(c1, c2);
		return csum[i];
	}
}

void solve() {

	ll n;
	cin >> n;

	vector<ll> a(n, 0);
	map<ll,ll> freq;
	for(int i = 0; i <n; i++) {
		cin >> a[i];
		freq[a[i]] = 0;
	}

	// first sort the array , then find the consecutive 
	// elements and form a group. There can be more than 
	// one group formed. This means we need to look for each group
	// individually.
	sort(a.begin(), a.end());

	set<ll> s(a.begin(), a.end());
	vector<ll> uniq(s.begin(), s.end());

	// get unique elements from the array
	sort(uniq.begin(), uniq.end());

	// get frequency of each element
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}

	int i = 0;
	ll c = 0;
	while (i < uniq.size()) {
		vector<ll> v;
		v.push_back(uniq[i]);
		i += 1;
		while (i < uniq.size() && uniq[i] == 1 + uniq[i-1]) {
			v.push_back(uniq[i]);
			i += 1;
		}

		vector<ll> csum(v.size(), -1);
		c += fun(v, 0, freq, csum);
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