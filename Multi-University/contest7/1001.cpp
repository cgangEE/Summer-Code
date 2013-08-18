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

#define N 60000
#define M 5

int i,j,k,m,n,l;
int a[N+10][M+10];
multiset<int> st[1<<M];

int gao(int k){
	if (st[k].empty()) return 0;
	multiset<int>::itr x=st[k].begin(), y=--st[k].end();
	return *y-*x;
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		rep(k, 1<<m)  st[k].clear();
		repf(i, 1, n){
			int type;
			scanf("%d", &type);
			if (type==0){
				rep(j, m) scanf("%d", &a[i][j]);
				rep(k, 1<<m){
					l=0;
					rep(j, m) l+=a[i][j]*( (k&(1<<j))?1:-1);
					st[k].insert(l);
				}
			}
			else{
				int e;
				scanf("%d", &e);
				rep(k, 1<<m){
					l=0;
					rep(j, m) l+=a[e][j]*( (k&(1<<j))?1:-1);
					st[k].erase(st[k].find(l));
				}
			}

			int ret=0;
			rep(k, 1<<m) checkmax(ret, gao(k));
			printf("%d\n", ret);
		}
	}
	return 0;
}
