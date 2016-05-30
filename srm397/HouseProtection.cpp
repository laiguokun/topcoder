#line 5 "HouseProtection.cpp"
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
const double pi=acos(-1.0);
const double eps=1e-15;
bool g[50][50],ck[50];
int match[50];
int bx[50],by[50],rx[50],ry[50];
int d[50][50];
int n,m;
int dist(int x1,int x2,int y1,int y2)
{
        return (x1-y1)*(x1-y1)+(x2-y2)*(x2-y2);
}
bool search(int x)
{
        for (int i=0;i<m;i++)
                if (ck[i] && g[x][i])
                {
                        ck[i]=false;
                        if (match[i]==-1 || search(match[i]))
                        {
                                match[i]=x;
                                return true;
                        }
                }
        return false;
}
class HouseProtection
{
        public:
        double safetyFactor(vector <int> possibleXForBlue, vector <int> possibleYForBlue, vector <int> possibleXForRed, vector <int> possibleYForRed, int R)
        {
                n=possibleXForBlue.size();m=possibleXForRed.size();
                for (int i=0;i<n;i++)
                {
                        bx[i]=possibleXForBlue[i];
                        by[i]=possibleYForBlue[i];
                }
                for (int i=0;i<m;i++)
                {
                        rx[i]=possibleXForRed[i];
                        ry[i]=possibleYForRed[i];
                }
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++) d[i][j]=dist(bx[i],by[i],rx[j],ry[j]);
                double ans=max(n,m)*pi*R*R;
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                        {
                                double r=sqrt((double)d[i][j])/2;
                                int t;
                                if (r>R){r=R;t=r*r*4;}else t=d[i][j];
                              //  printf("%.2f\n",r);
                                int s=0;
                                memset(g,false,sizeof(g));
                                memset(match,-1,sizeof(match));
                                for (int x=0;x<n;x++)
                                        for (int y=0;y<m;y++)
                                                if (d[x][y]-t<=-eps) g[x][y]=true;
                                for (int x=0;x<n;x++)
                                {
                                        memset(ck,true,sizeof(ck));
                                        if (search(x)) s++;
                                }
                                s=(n+m-s);
                                ans=max(ans,s*(pi*r*r));
                        }
                return ans;
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
