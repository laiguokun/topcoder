    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "RadarGuns.cpp"  
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
const int maxint=5000000;
const int num=60;
int n,m;
bool yck[num],xck[num];
int g[num][num],match[num],l[num],r[num],slack[num];
int min(int a,int b) {if (a<b) return a;else return b;}
int max(int a,int b) {if (a>b) return a;else return b;}
bool find(int x)
{
        xck[x]=true;
        for (int i=0;i<n;i++)
        {
                if (yck[i]) continue;
                if (l[x]+r[i]!=g[x][i]) slack[i]=min(slack[i],l[x]+r[i]-g[x][i]);
                else
                {
                        yck[i]=true;
                        int t=match[i];
                        match[i]=x;
                        if ((t==-1)||(find(t)))  return true;
                        match[i]=t;
                }
        }
        return false;
}
void km()
{
        memset(match,-1,sizeof(match));
        for (int i=0;i<n;i++)
        {
                l[i]=-maxint;
                for (int j=0;j<n;j++) l[i]=max(l[i],g[i][j]);
        }
        memset(r,0,sizeof(r));
        for (int i=0;i<n;i++)
        {

                for (int j=0;j<n;j++) slack[j]=maxint*10;
                while (true)
                {
                        memset(xck,false,sizeof(xck));
                        memset(yck,false,sizeof(yck));
                        if (find(i)) break;
                        int t=maxint;
                        for (int i1=0;i1<n;i1++) if (!yck[i1]) t=min(t,slack[i1]);
                        for (int i1=0;i1<n;i1++) if (xck[i1]) l[i1]-=t;
                        for (int i1=0;i1<n;i1++) if (yck[i1]) r[i1]+=t;
                        for (int i1=0;i1<n;i1++) if (!yck[i1]) slack[i1]-=t;
                }
        }
}
      
    class RadarGuns  
    {  
            public:  
            vector <int> getRange(vector <int> enterTimes, vector <int> exitTimes, int speedTime, int fineCap)  
            {  
                n=enterTimes.size();
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                        {
                                g[i][j]=-maxint;
                                if (enterTimes[i]<exitTimes[j])
                                {
                                        int k=max(0,speedTime-(exitTimes[j]-enterTimes[i]));
                                        g[i][j]=-min(k*k,fineCap);
                                }
                        }
                km();
                int ans=0;
                bool o;
                o=true;
                VI res;
                for (int i=0;i<n;i++)
                {
                        if (g[match[i]][i]==-maxint) {o=false;break;}
                        ans-=g[match[i]][i];
                }
                if (o) res.PB(ans);
                ans=0;o=true;
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                                if (g[i][j]!=-maxint) g[i][j]=-g[i][j];
                km();
                for (int i=0;i<n;i++)
                {
                        if (g[match[i]][i]==-maxint) {o=false;break;}
                        ans+=g[match[i]][i];
                }
                if (o) res.PB(ans);
                return res;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {263, 586, 271, 779, 334, 428, 869, 540, 287, 571, 754, 558, 314, 379, 387, 878, 803, 838, 790, 206, 445, 909, 658, 229, 496, 930, 531, 132, 137, 654, 655};
 vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
int Arr1[] =  {339, 723, 382, 123, 706, 920, 167, 550, 630, 636, 60, 491, 510, 475, 600, 508, 221, 558, 905, 455, 538, 934, 147, 494, 537, 452, 330, 892, 322, 319, 903};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 738; int Arg3 = 909; int Arr4[] = {0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 100; int Arr4[] = {200, 200 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }
        void test_case_2(){} //{ int Arr0[] = {1000, 584, 390, 392, 109}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {987, 724, 814, 597, 422}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 30; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 42; int Arr4[] = {48, 56 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            RadarGuns ___test;  
            ___test.run_test(0);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
