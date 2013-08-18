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
#define N 300

int i,j,k,m,n,l;
int a[N+10][N+10];

bool check(int y, int i, int j){
	int x=0;
	while (i+x<j-x){
		if (a[i+x][y]!=a[j-x][y]) return false;
		x++;
	}
	return true;
}

bool check2(int x, int i, int j){
	int y=0;
	while (i+y<j-y){
		if (a[x][i+y]!=a[x][j-y]) return false;
		y++;
	}
	return true;
}

bool find(int z){
	repf(i, 1, m-z+1){
		int j=i+z-1, w=0;
		repf(k, 1, n){
			if (check2(k, i, j)){
			   	w++;
				if (w==z){
					repf(x, i, j) if (!check(x, k-z+1, k)) continue;
					return true;
				}
			}
			else w=0;
		}
	}
	return false;
}


int gaoOdd(){
	int x=0, y=(min(n,m)+1)/2;
	while (x!=y){
		int z=(x+y+1)/2;
		if (find(z*2-1)) x=z;
		else y=z-1;
	}
	return x*2-1;

}

int gaoEven(){
	int x=0, y=min(n,m)/2;
	while (x!=y){
		int z=(x+y+1)/2;
		if (find(2*z)) x=z;
		else y=z-1;
	}
	return x*2;
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d", &n, &m);
		repf(i, 1, n) repf(j, 1, m) scanf("%d", &a[i][j]);
		printf("%d\n", max(gaoOdd(), gaoEven()));	
	}
	return 0;
}

