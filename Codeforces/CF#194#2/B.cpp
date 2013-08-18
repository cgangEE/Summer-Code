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
#define N 10
int i,j,k,m,n,l;
struct P{
	int x, y;
	bool input(){
		return (~scanf("%d%d", &x, &y));
	}
};
P a[N+10];

bool gao(mii &mp){
	int i=0;
	foreach(it, mp){
		i++;
		if (i==2 && it->second!=2){
		   	return false;
		}
		else if ((i==3 || i==1) && it->second!=3){
		   	return false;
		}
	}
	return true;
}

int main(){
	while (a[0].input()){
		repf(i, 1, 7) a[i].input();
		map<int,int> mx, my;
		map<ll, int> mm;
		rep(i, 8) mx[a[i].x]++, my[a[i].y]++, mm[a[i].x*1000100ll+a[i].y]++;
		if (!gao(mx) || !gao(my)){
			puts("ugly"); continue;
		}

		k=0;
		foreach(i, mx) foreach(j, my){
			if (mm[i->first*1000100ll+j->first]) k++;
		}
		if (k==8)
			puts("respectable");
		else 
			puts("ugly");
	}
    return 0;
}

