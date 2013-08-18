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
int a[N+10];
int s;
deque<P> q;

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d", &n), s=0, q.clear();
        repf(i, 1, n){
            scanf("%d", &a[i]);
            s+=a[i];
            while (q.size() && s<=q.back().x) q.pop_back();
            q.push_back(P(i, s));
        }
        
        int ans=0, t=0;
        repf(i, 1, n){
            if (q.front().x-t>0){
                 ans++;
                // cout<<i<<' '<<q.front().i<<' '<<t<<endl;
            }
            while (q.size() && q.front().i<=i) q.pop_front();
            s+=a[i], t+=a[i];
            while (q.size() && s<=q.back().x) q.pop_back();
            q.push_back(P(i+n,s));
        }
        printf("%d\n", ans);
        
    }
    return 0;
}
