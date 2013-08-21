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

ll e=1000000007;
ll i,j,k,m,n,l;
ll a0, ax, ay, b0, bx, by;

template <class T>
T exgcd(T a, T b, T &x, T &y){
	if (b==0) return x=1, y=0, a;
	return ret;
}

ll solve(){

}

int main(){
	m=1000000007;
	while (~scanf("%I64d", &n)){
		scanf("%I64d%I64d%I64d", &a0, &ax, &ay);
		scanf("%I64d%I64d%I64d", &b0, &bx, &by);
		A=(ax*bx)%e, B=(ax*by)%e, C=(ay*bx)%e, D=(ay*by)%e;
		printf("%I64d\n", solve());
	}
	return 0;
}


