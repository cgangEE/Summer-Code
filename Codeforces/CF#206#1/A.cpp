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
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x>t) t=x;}
template <class T> void checkmin(T &t, T x){if (x<t) t=x;}
template <class T> void _checkmax(T &t, T x){if (t==-1 || x>t) t=x;}
template <class T> void _checkmin(T &t, T x){if (t==-1 || x<t) t=x;}
#define INF (INT_MAX/1)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator 
#define N 100000

int i,j,k,m,n,l,r,Ql,Qr;
int s[N+10], a[N+10], tmp;

int main(){
	while (~scanf("%d%d%d%d%d", &n, &l, &r, &Ql, &Qr)){
		repf(i, 1, n) scanf("%d", &a[i]), s[i]=a[i]+s[i-1];
		int ret=INT_MAX;
		repf(i, 0, n){
			tmp=s[i]*l+(s[n]-s[i])*r;
			if (i>n-i){
				tmp+=(i-(n-i)-1)*Ql;
			}
			else if (i<n-i){
				tmp+=(n-i-i-1)*Qr;
			}
			checkmin(ret, tmp);
		}
		printf("%d\n", ret);
	}
	return 0;
}


