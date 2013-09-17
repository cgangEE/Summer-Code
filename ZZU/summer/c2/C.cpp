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
#define N 1000

int i,j,k,m,n,l;

template <int SZ>
class UFS{
	int f[SZ+10];
public:
	void clear(){ rep(i, SZ+10) f[i]=i; }
	int find(int i){
		if (f[i]==i) return i;
		return f[i]=find(f[i]);
	}
	void unions(int i, int j){
		i=find(i), j=find(j);
		f[i]=j;
	}
};


UFS<N> ufs;

int main(){
	while (~scanf("%d", &n) && n){
		scanf("%d", &m);
		ufs.clear();
		int ret=0;
		while (m--){
			scanf("%d%d", &j, &k);
			if (ufs.find(j)!=ufs.find(k)){
				ufs.unions(j, k);
				ret++;
			}
		}
		printf("%d\n", n-1-ret);
	}
	return 0;
}


