#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 100000

ll i,j,k,m,n,l,a,b;
ll f[N+10];

int gcd(int a, int b){ return b==0?a:gcd(b, a%b); }

ll solve(){
	ll lcm=(ll)a/gcd(a,b)*b;
	if (a>b) swap(a, b);
	
	ll ret=0;
	n--;
	m=n%lcm;
	rep(i, lcm/a){
		ll j=((ll)i)*a/b*b;
		ll k=(i*a+a-1)/b*b;
		if (j==k) f[i]=a*(i*a-j);
		else f[i]=(k-i*a)*(2*i*a+a-j-k);
		if (i) f[i]+=f[i-1];

		n--;
		if (i*a<=m && m<i*a+a){
			if (i) ret+=f[i-1];
			if (j==k || m<k) ret+=(m-i*a+1)*(i*a-j);
			else{
				ret+=(k-i*a)*(i*a-j)+(m-k+1)*(k-i*a);
			}
		}
		n++;
	}

	ret+=n/lcm*f[lcm/a-1];
	return ret;
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		cin>>n>>a>>b;
		cout<<solve()<<endl;
	}
	return 0;
}


