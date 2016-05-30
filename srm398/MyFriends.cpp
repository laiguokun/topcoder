#line 5 "MyFriends.cpp"
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
const int num=50;
double g[num+5][num+5],g_[num+5][num+5];
double ff[num+5];
int f[num+5];
void fz(double a[],double b[])
{
        for (int i=0;i<=num;i++) a[i]=b[i];
}
class MyFriends
{
        public:
        string calcFriends(vector <int> sumFriends, int k)
        {
                int n=sumFriends.size();
                string Y="POSSIBLE",N="IMPOSSIBLE";
                memset(g,0,sizeof(g));
                for (int i=0;i<n;i++)
                {
                        for (int j=0;j<n;j++)
                        {
                                if (j==i || j==(i+k)%n) continue;
                                g[i][j]=1;
                                g_[i][j]=1;
                        }
                        g[i][n]=sumFriends[i];
                        g_[i][n]=sumFriends[i];
                }
                for (int i=0;i<n;i++)
                {
                        int t=-1;
                        for (int j=i;j<n;j++)
                                if (fabs(g[j][i])>1e-9) t=j;
                        if (t==-1) {continue;}
                        double arr[num+5];
                        fz(arr,g[i]);
                        fz(g[i],g[t]);
                        fz(g[t],arr);
                    //    printf("%f\n",g[i][i]);
                        for (int j=i+1;j<n;j++)
                        {
                              //  printf("%f\n",g[j][i]);
                                if (fabs(g[j][i])<1e-9) continue;
                             //   printf("%f\n",g[j][i]);
                                double t=g[i][i]/g[j][i];
                                for (int k=i;k<=n;k++)
                                        g[j][k]=g[j][k]*t-g[i][k];
                        }
                }
                memset(ff,0,sizeof(ff));
                memset(f,0,sizeof(f));
                for (int i=n-1;i>=0;i--)
                {
                        if (fabs(g[i][i])<1e-9) continue;
                        for (int j=i+1;j<n;j++)
                                g[i][n]-=(g[i][j]*ff[j]);
                      //  printf("y%f\n",g[i][n]/g[i][i]);
                       // printf("%f\n",res);
                        ff[i]=g[i][n]/g[i][i];
                        f[i]=floor(ff[i]);
                        if (fabs(ff[i]-f[i])>1e-9) f[i]++;
                        printf("%f %d\n",ff[i],f[i]);
                        if (f[i]<0 || f[i]>=n)
                        {
                               // return Y;
                                return "IMPOSSIBLE";
                        }
                        if (fabs(ff[i]-f[i])>1e-9) return N;
                }
              /*  for (int i=0;i<n;i++)
                {
                        int res=0;
                        for (int j=0;j<n;j++) res+=g_[i][j]*f[j];
                        if (res!=sumFriends[i])
                                int t=1;
                }*/
                for (int i=0;i<n;i++)
                {
                        for (int j=0;j<n;j++)
                                for (int k=j+1;k<n;k++)
                                        if (f[j]>f[k]){int t=f[j];f[j]=f[k];f[k]=t;}
                        for (int j=n-2;j>=0;j--)
                                if ((f[n-1]>0) && (f[j]>0))
                                {
                                        f[n-1]--;
                                        f[j]--;
                                }
                        if (f[n-1]!=0)
                        {
                              //  return Y;
                                return "IMPOSSIBLE";
                        }
                }
                return "POSSIBLE";
        }


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
