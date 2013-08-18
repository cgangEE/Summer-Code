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

int i,j,k,m,n,l;
char s[N+10];
int a[N+10], f[N+10];

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%s", s), n=strlen(s), clr(f, 0), clr(a, 0);
        repd(i, n-1, 0) a[++a[0]]=s[i]-'0';
        repd(i, a[0], 1) f[i]=(f[i+1]+a[i])%10;
        do{
            for (i=1, a[1]++; a[i]>9; ++i) a[i]-=10, a[i+1]++;
            checkmax(a[0], i);
            repd(j, i, 1) f[j]=(f[j+1]+a[j])%10;

        }
        while (f[1]!=0);
        repd(i, a[0], 1) printf("%d", a[i]);
        puts("");
    }   
}
