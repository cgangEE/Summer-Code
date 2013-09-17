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
#define N 200

int i,j,k,m,n,l;
int a[N+10];
int d[N+10];
int x, y;
queue<int> q;


int main(){
	while (~scanf("%d", &n) && n){
		scanf("%d%d", &x, &y);
		repf(i, 1, n) scanf("%d", &a[i]);
		clr(d, -1);
		while (q.size()) q.pop();
		q.push(x), d[x]=0;

		while (q.size()){
			int i=q.front(); q.pop();
			if (i-a[i]>0) {
			if (d[i-a[i]]==-1)
				d[i-a[i]]=d[i]+1, q.push(i-a[i]);
			}

			if (i+a[i]<=n){
			if (d[i+a[i]]==-1)
				d[i+a[i]]=d[i]+1, q.push(i+a[i]);
			}
		}
		printf("%d\n", d[y]);

	}
	return 0;
}


