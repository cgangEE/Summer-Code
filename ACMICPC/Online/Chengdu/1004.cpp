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

int i,j,k,m,n,l;

char s[][100]={
"",
"a",
"ab",
"aab",
"aabb",
"aaaba",
"aaabab",
"aaababb",
"aaababbb",
"aaaababba",
"aaaababbaa",
"aaaababbaaa",
"aaaababbaaaa",
"aaaababbaabab"};
    
char t[]="babbaa";

int main(){
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
        scanf("%d%d", &m, &n);
        printf("Case #%d: ", te);
        if (m>=3){
            rep(i, n) putchar('a'+i%3);
        }
        else if (m==1){
            rep(i, n) putchar('a');
        }
        else{
            if (n<=10) printf(s[n]);
            else{
                printf("aaaa");
                n-=4;
                rep(i, n/6) printf(t);
                if (n%6<=2){
                    rep(i, n%6) putchar('a');
                }
                else
                    rep(i, n%6) putchar(t[i]);

            }
        }
        putchar('\n');
    }
    return 0;
}
