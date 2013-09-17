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
#define N 12

struct P{
	int c, x, y, nei, wu, hp, d;
	void init(char *s){
		c=s[0];
		scanf("%d%d%d%d%d", &x, &y, &nei, &wu, &hp);
		d=0;
	}
};

int i,j,k,m,n,l;
int f[N+10][N+10][3];
P a[N+10];
int ans[10], hp[10];
char s[100];

void move(P &p){
	if (p.c=='S'){
		if (p.x==12) p.d=1;
		else if (p.x==1) p.d=0;
		if (p.d==0) p.x++;
		else p.x--;
	}
	else if (p.c=='W'){
		if (p.y==12) p.d=1;
		else if (p.y==1) p.d=0;
		if (p.d==0) p.y++;
		else p.y--;
	}
	else if (p.c=='E'){
		if (p.x==12 || p.y==12) p.d=1;
		else if (p.x==1 || p.y==1) p.d=0;
		if ((p.x==1 && p.y==12) || (p.x==12 && p.y==1)) return;
		if (p.d==0) p.x++, p.y++;
		else p.x--, p.y--;
	}
}

int gao(P p){
	if (p.c=='S') return (0.5*p.nei+0.5*p.wu)*(p.hp+10.)/100.;
	if (p.c=='W') return (0.8*p.nei+0.2*p.wu)*(p.hp+10.)/100.;
	return (0.2*p.nei+0.8*p.wu)*(p.hp+10.)/100.;
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d", &n);
		m=0;
		while (~scanf("%s", s) && strcmp(s, "0")!=0)
			a[m++].init(s);

			while (n--){
				clr(f, 0);
				rep(i, m) if (a[i].hp>0) if (f[a[i].x][a[i].y][0]<2){
					k=++f[a[i].x][a[i].y][0];
					f[a[i].x][a[i].y][k]=i;
				}
				else f[a[i].x][a[i].y][0]++;

				repf(x, 1, 12) repf(y, 1, 12) 
					if (f[x][y][0]==2){
						int i=f[x][y][1], j=f[x][y][2];
						if (a[i].c!=a[j].c){
							int r=gao(a[i]), s=gao(a[j]);
							a[i].hp-=s, a[j].hp-=r;
						}
					}
				rep(i, m) if (a[i].hp>0)
					move(a[i]);
			}

			clr(ans, 0), clr(hp, 0);
			rep(i, m) if (a[i].hp>0){
				if (a[i].c=='S') ans[0]++, hp[0]+=a[i].hp;
				else if (a[i].c=='W') ans[1]++, hp[1]+=a[i].hp;
				else ans[2]++, hp[2]+=a[i].hp;
			}
			rep(i, 3) printf("%d %d\n", ans[i], hp[i]);
			puts("***");
	}
	return 0;
}


