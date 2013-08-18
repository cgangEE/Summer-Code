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
#define N 2000
#define M 10000
#define H 3000007

int i,j,k,m,n,l;

struct Q{
    int i, x, y, ret;
    void init(int ii){ i=ii; scanf("%d%d", &x, &y); }
    bool operator <(const Q&q)const{ return y<q.y; }
};

template <int SZ>
class BIT{
    int a[SZ+10];
public:
    void clear(){ clr(a, 0); }
    void ins(int x, int k){
        while (x<=n){
            a[x]+=k;
            x+=x&-x;
        }
    }
    int qry(int x){
        int ret=0;
        while (x>0){
            ret+=a[x];
            x-=x&-x;
        }
        return ret;
    }
};

bool cmp(Q a, Q b){ return a.i<b.i; }

Q q[M+10];
BIT<N> bit;
int idx;
char s[N+10], t[N+10];
int h[H+10], r[H+10];

bool equal(int h, int r, int i, int j){
    if (h-r!=i-j) return false;
    do
        if (s[h--]!=s[i--]) return false;
    while (h>=r);
    return true;
}

void gao(int k, int i, int j){
    while (h[k]!=-1 && !equal(h[k], r[k], i, j)) k=(k+1)%H;
    if (h[k]==-1) h[k]=i, r[k]=j, bit.ins(n-j, 1);
    else if (j>r[k]){
        bit.ins(n-r[k], -1);
        bit.ins(n-j, 1);
        h[k]=i, r[k]=j;
    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%s", s), n=strlen(s);

        scanf("%d", &m);
        repf(i, 1, m) q[i].init(i);
        sort(q+1, q+1+m);

        bit.clear(), clr(h, -1);
        int pre=1;

        repf(i, 1, m){
            for (; pre<=q[i].y; ++pre){
                int k=0;
                repd(j, pre-1, 0){
                    k=(k*131+s[j])%H;
                    gao(k, pre-1, j);    
                }
            }
            q[i].ret=bit.qry(n+1-q[i].x);
        }

        sort(q+1, q+1+m, cmp);
        repf(i, 1, m) printf("%d\n", q[i].ret);
    }
    return 0;
}


