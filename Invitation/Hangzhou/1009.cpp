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
#define N 40

int i,j,k,m,n,l;
char a[N+10][N+10];

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
};

int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		rep(i, n) rep(j, m){
			a[i][j]=getchar();
			while (strchr("HCO", a[i][j])==NULL) a[i][j]=getchar();
		}
		int d=-1;
		P h, c;
		rep(i, n) rep(j, m) if (a[i][j]=='H')
			rep(x, n) rep(y, m) if (a[x][y]=='C')
				if (d==-1 || abs(x-i)+abs(y-j)<d)
					d=abs(x-i)+abs(y-j), h=P(i,j), c=P(x,y);
		cout<<h.x<<' '<<h.y<<' '<<c.x<<' '<<c.y<<endl;
		   
	}
	return 0;
}


