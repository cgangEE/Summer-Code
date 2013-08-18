#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define N 100000

template <int SZ>
class BIT{
    int a[SZ+10];
public:
    void clear(){ clr(a, 0); }
    void ins(int x, int k){
        while (x<=SZ)
            a[x]+=k, x+=x&-x;
    }
    int qry(int x){
        int ret=0;
        while (x>0)
            ret+=a[x], x-=x&-x;
        return ret;
    }
};

int i,j,k,m,n,l;
int a[N+10], x[N+10], y[N+10];
vector<pair<int,int> > q[N+10];
pair<int,int> ans[N+10];
BIT<N*3> bitL, bitR;
map<int,int> mp, mp2;
int lefts, rights;

void gao(int i){
    rep(w, sz(q[i])){
        int idx=q[i][w].first, x=q[i][w].second;
        if (mp2[x]) ans[idx]=make_pair(-1,-1);
        else{
            int j=bitL.qry(x), k=bitR.qry(x);
            ans[idx]=make_pair(k , (j+k)*3+lefts-j+rights-k);
        }
    }
    if (x[i]){
        mp2[a[i]]++;
        
        bitL.ins(a[i], 1), lefts++;
        gao(x[i]);
        bitL.ins(a[i], -1), lefts--;
        
        bitR.ins(a[i], 1), rights++;
        gao(y[i]);
        bitR.ins(a[i], -1), rights--;
        
        mp2[a[i]]--;
    }
}

int main(){

    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d", &n);
        mp.clear();
        repf(i, 1, n) scanf("%d", &a[i]), mp[a[i]]++, q[i].clear();
        
        scanf("%d", &m), clr(x, 0), clr(y, 0);
        while (m--) scanf("%d", &i), scanf("%d%d", &x[i], &y[i]);
        
        scanf("%d", &m);
        repf(i, 1, m) 
            scanf("%d%d", &j, &k), q[j].pb(make_pair(i, k)), mp[k]++;
            
        i=0;
        for(mii::iterator it=mp.begin(); it!=mp.end(); ++it)
            it->second=++i;
        
        repf(i, 1, n) a[i]=mp[a[i]];
        repf(i, 1, n) rep(j, sz(q[i])) q[i][j].second=mp[q[i][j].second];
        
        bitL.clear(), bitR.clear(), mp2.clear(), lefts=rights=0;
        gao(1);
        repf(i, 1, m){
            if (ans[i].first==-1) puts("0");
            else printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }
    return 0;
}
