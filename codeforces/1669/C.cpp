#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define loop(i, n) for (int i = 0; i < n; i++)
#define input(t) cin >> t
#define output(s) cout << s << "\n"
// #define push_back pb

typedef vector<int> vi;
typedef pair<int, int> pi;

// vector<int> a(N, 0);
string strip(string s)
{
	int idx = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			idx = i;
			break;
		}
	}

	s = s.substr(idx);

	return s;
}

vector<string> split(const string &s, char delim)
{
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
	{
		result.push_back(strip(item));
	}

	return result;
}

string join(vector<string> v, string delim)
{
	string out = "";
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
		{
			out.append(v[i]);
		}
		else
		{
			out.append(v[i]);
			out.append(delim);
		}
	}
	return out;
}

bool prime(ll n, vector<bool> &isPrime, vector<bool> &done)
{
	if (done[n])
	{
		return isPrime[n];
	}

	if (n == 1)
	{
		done[1] = true;
		isPrime[1] = false;
		return false;
	}
	if (n == 2)
	{
		done[2] = true;
		isPrime[2] = true;
		return true;
	}
	else
	{

		for (ll i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
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

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first < b.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isSquare(int n)
{
	int x = (int)sqrt(n);
	return (x * x == n);
}

void solve()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		vector<int> a(n, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int ev0 = 0;
		int od0 = 0;
		int ev1 = 0;
		int od1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				if (a[i] % 2 == 0)
				{
					ev0 = 1;
				}
				else
				{
					od0 = 1;
				}
			}
			else
			{
				if (a[i] % 2 == 0)
				{
					ev1 = 1;
				}
				else
				{
					od1 = 1;
				}
			}
		}

		if ((od1 == 1 && ev1 == 1) || (od0 == 1 && ev0 == 1))
		{
			cout << "NO"
				 << "\n";
		}
		else
		{
			cout << "YES"
				 << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	solve();
}
