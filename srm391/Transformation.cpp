// BEGIN CUT HERE

// END CUT HERE
#line 5 "Transformation.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
const int maxn=1000000;
bool p[maxn];
LL a[100],s[maxn],ans[100];
int tot;
LL gcd(LL a,LL b)
{
        if (a<b) {LL t;t=a;a=b;b=t;}
        if (a % b!=0) return gcd(b,a%b);else return b;
}
void pre()
{
        memset(p,true,sizeof(p));
        tot=-1;
        for (int i=2;i<maxn;i++)
        {
                if (p[i]) s[++tot]=i;
                LL x=i;
                while (x<maxn)
                {
                        p[x]=false;
                        x+=i;
                }
        }
}
LL c1(string a)
{
        int len=a.length();
        LL res=0;
        for (int i=0;i<len;i++) res=res*10+(int)a[i]-48;
        return res;
}
string c2(LL a)
{
        string res1,res2;
        res1.clear();res2.clear();
        while (a>0)
        {
                res1+=char(a%10+48);
                a/=10;
        }
        int len=res1.length();
        for (int i=len-1;i>=0;i--) res2+=res1[i];
        return res2;
}
class Transformation
{
        public:
        vector <string> transform(vector <string> A)
        {
                pre();
                int n=A.size();
                for (int i=0;i<n;i++) ans[i]=1;
                for (int i=0;i<n;i++) a[i]=c1(A[i]);
                for (int now=0;now<=tot;now++)
                {
                        int m=0,t=0;
                        for (int i=0;i<n;i++)
                        {
                                int ss=0;
                                while (a[i] % s[now]==0)
                                {
                                        ss++;
                                        a[i]/=s[now];
                                }
                                if (ss>=m) {t=i;m=ss;}
                        }
                        if (m!=0)
                        {
                                for (int i=0;i<m;i++) ans[t]=ans[t]*s[now];
                        }
                }
                for (int i=0;i<n;i++)
                        while (true)
                        {
                                LL k=(LL)1e+18;
                                for (int j=i+1;j<n;j++)
                                {
                                        LL t=gcd(a[i],a[j]);
                                        if (t!=1 && t<k) k=t;
                                }
                                if (k==(LL)1e+18) break;
                                if ((double)k*(double)k>1e+18)
                                {
                                        int o=-1;
                                        for (int z=i;z<n;z++)
                                                if (gcd(k,a[z])==k) {o=z;a[z]/=k;}
                                        ans[o]*=k;
                                        continue;
                                }
                                int o1=-1,o2=-1;
                                if (k!=1)
                                {
                                        for (int z=i;z<n;z++)
                                        {
                                                if (gcd(k,a[z])==k)
                                                {
                                                        o1=z;
                                                        if (k*k==a[z])
                                                        {
                                                                o2=z;a[z]/=(k*k);
                                                        }
                                                        else a[z]/=k;
                                                }
                                        }
                                        if (o2!=-1) ans[o2]*=(k*k); else ans[o1]*=k;
                                }
                        }
                for (int i=0;i<n;i++) ans[i]*=a[i];
                vector <string> res;
                res.clear();
                for (int i=0;i<n;i++) res.PB(c2(ans[i]));
                return res;
        }


};

