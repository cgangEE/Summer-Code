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
#define N 300000

int i,j,k,m,n,l;
int a[N+10];

bool ok(int k){
	rep(i, n) if (a[i]%k>m) return false;
	return true;
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		int k=-1;
		rep(i, n) scanf("%d", &a[i]), _checkmin(k, a[i]);
		repd(j, k, 1){
			if (ok(j)){
			   	printf("%d\n", j); break;
			}
		}
	}
	return 0;
}


