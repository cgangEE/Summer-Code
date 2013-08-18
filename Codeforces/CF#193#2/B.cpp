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
#include <deque>
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
#define N 200000

struct P{
    int i, x;
    P(){}
    P(int i, int x):i(i),x(x){}
};

int i,j,k,m,n,l;
ll a[N+10];
int o[N+10];

#define lson i*2, x, z
#define rson i*2+1, z+1, y

template<int SZ>
class SegTree{
	int a[SZ*4+10];
public:
	void clear(){ clr(a, 0); }
    void build(int i, int x, int y){
        if (x==y){
            a[i]=x;
            return;
        }
        int z=mid(x, y);
        build(lson), build(rson);
        a[i]= ::a[a[i*2]] >= ::a[a[i*2+1]] ? a[i*2]: a[i*2+1];
    }
	int query(int i, int x, int y, int l, int r){
		if (x==l && y==r) return a[i];

		int z=mid(x, y);
		if (r<=z) return query(lson, l, r);
		else if (l>z) return query(rson, l, r);
		else{
            int j=query(lson, l, z) , k=query(rson, z+1, r);
            return ::a[j]>=::a[k]?j:k;
        }
	}
};

SegTree<N> st;

int main(){
    while (~scanf("%d%d", &n, &m)){
        clr(a, 0);
        repf(i, 1, n) scanf("%d", &o[i]);
        repf(i, 1, m) a[1]+=o[i];
        repf(i, 2, n-m+1) a[i]=a[i-1]-o[i-1]+o[m+i-1];
        
        st.clear();
        st.build(1, 1, n-m+1);
        ll now=-1; 
        pair<int,int> ans;
        repf(i, 1, n-2*m+1){
            k=st.query(1, 1, n-m+1, i+m, n-m+1);
            if (a[i]+a[k]>now)
                now=a[i]+a[k], ans=make_pair(i, k);
        }
        
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}
