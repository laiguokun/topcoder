#line 5 "MoreNim.cpp"
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
LL a[100],b[100];
bool cmp(LL a,LL b) {return a>b;}
LL change(string a)
{
        LL res=0;
        for (int i=0;i<a.length();i++) res=res*10+(int)a[i]-48;
        return res;
}
class MoreNim
{
        public:
        long long bestSet(vector <string> heaps)
        {
                int n=heaps.size();
                for (int i=0;i<n;i++) a[i]=change(heaps[i]);
                sort(a,a+n,cmp);
                for (int i=0;i<n;i++) b[i]=a[i];
                LL ans=0;
                for (int i=0;i<n;i++)
                {
                        if  (b[i]==0) ans+=a[i];
                        for (int j=62;j>=0;j--)
                        {
                                if (b[i] & (1LL << (LL) j))
                                {
                                        for (int k=i+1;k<n;k++)
                                                if (b[k] & (1LL << (LL) j)) b[k]^=b[i];
                                        break;
                                }
                        }
                }
                return ans;
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
