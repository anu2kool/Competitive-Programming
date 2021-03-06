#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef map<char, ll> um;
typedef unordered_set<ll> us;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ln cout<<endl;
#define input(x) cin>>x;
#define print(x) cout<<x<<endl;
#define reset(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b, c) for(ll i = a; i < b; i += c)
#define FORD(i, a, b) for(ll i = a; i > b; i--)
#define FOREACH(it, v) for(auto it = v.begin();  it != v.end(); it++)
#define FORALL(it, v) for(auto it: v)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(arr, r) arr, arr + r
#define showv(v) for(auto it: v) cout<<it<<' '; ln;
#define showm(v) for(auto it: v) cout<<it.F<<','<<it.S<<' '; ln;
#define show2d(v) for(auto it: v) {for(auto j: it) cout<<j<<' '; ln;}
#define printv(v) for(auto it: v) cout<<it<<endl;
#define sortv(v) sort(all(v));
#define revv(v) reverse(all(v));
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define gcd __gcd
#define checkbit(n, i) (n >> i & 1) // check ith bit
#define bitcount __builtin_popcount // count set bits
#define firstbitindex __builtin_ctz // count trailing zeros
#define lastbitindex __builtin_clz // count leading zeros
#define bitparity __builtin_parity // check set bits are even or odd
#define findv(v, x) (find(all(v), x) != v.end()) // find in a vector
#define findsm(u, x) (u.find(x) != u.end()) // find in a set / map
#define findstr(s, x) (s.find(x) != string::npos) // find in a string
#define sz(a) a.size()
#define precise(x) cout<<fixed<<setprecision(x);

const ll MAXN = 1e+2+7, MOD = 998244353, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Variables Here----->>//
ll t, n, hashstart, hashend;
string s, lprefix, lsuffix, middle;

//<<-----Implement Functions Here---->>//

string solve()
{
	cin>>n;
	vstr prefix(n), suffix(n);
	lprefix = lsuffix = middle = "";
	FOR(i, 0, n)
	{
		cin>>s;
		FOR(j, 0, sz(s))
		{
			if(s[j]=='*')
			{
				hashstart = j;
				break;
			}
			prefix[i] += s[j];
		}
		if(sz(prefix[i])>sz(lprefix))
			lprefix = prefix[i];
		FORD(j, sz(s)-1, -1)
		{
			if(s[j]=='*')
			{
				hashend = j;
				break;
			}
			suffix[i] += s[j];
		}
		if(sz(suffix[i])>sz(lsuffix))
			lsuffix = suffix[i];
		FOR(j, hashstart+1, hashend)
			if(s[j]!='*')
				middle += s[j];
	}
	if(sz(lprefix))
		FOR(i, 0, n)
			FOR(j, 0, sz(prefix[i]))
				if(prefix[i][j]!=lprefix[j])
					return "*";
	if(sz(lsuffix))
		FOR(i, 0, n)
			FOR(j, 0, sz(suffix[i]))
				if(suffix[i][j]!=lsuffix[j])
					return "*";
	revv(lsuffix)
	return lprefix + middle + lsuffix;
}

//<<----------Start of Main---------->>//
int main()
{
	fastio
	cin>>t;
	FOR(i, 1, t+1)
		print("Case #"<<i<<": "<<solve())
	return 0;
}