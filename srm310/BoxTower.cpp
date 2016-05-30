    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "BoxTower.cpp"  
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
    int n,ans,f[1<<15][15][6];
    vector <int> xx,yy,zz;
    void ins(int k1,int k2,int k3,int a,int b)
    {
        for (int i=0;i<n;i++)
        {
                if ((k1&(1<<i))!=0) continue;
                int zt=k1|(1<<i);
                //0
                if ((xx[i]<=a)&&(yy[i]<=b)) f[zt][i][0]=max(f[zt][i][0],f[k1][k2][k3]+zz[i]);
                //1
                if ((yy[i]<=a)&&(xx[i]<=b)) f[zt][i][1]=max(f[zt][i][1],f[k1][k2][k3]+zz[i]);
                //2
                if ((xx[i]<=a)&&(zz[i]<=b)) f[zt][i][2]=max(f[zt][i][2],f[k1][k2][k3]+yy[i]);
                //3
                if ((zz[i]<=a)&&(xx[i]<=b)) f[zt][i][3]=max(f[zt][i][3],f[k1][k2][k3]+yy[i]);
                //4
                if ((yy[i]<=a)&&(zz[i]<=b)) f[zt][i][4]=max(f[zt][i][4],f[k1][k2][k3]+xx[i]);
                //5
                if ((zz[i]<=a)&&(yy[i]<=b)) f[zt][i][5]=max(f[zt][i][5],f[k1][k2][k3]+xx[i]);
        }
    }
    class BoxTower  
    {  
            public:  
            int tallestTower(vector <int> x, vector <int> y, vector <int> z)  
            {
                    xx.clear();yy.clear();zz.clear();
                    n=x.size();ans=0;
                    xx=x;yy=y;zz=z;
                    memset(f,0,sizeof(f));
                    int maxn=(1<<n)-1;
                    for (int i=0;i<n;i++)
                    {
                        f[1<<i][i][0]=f[1<<i][i][1]=z[i];
                        f[1<<i][i][2]=f[1<<i][i][3]=y[i];
                        f[1<<i][i][4]=f[1<<i][i][5]=x[i];
                        ans=max(x[i],max(y[i],z[i]));
                    }
                    for (int i=1;i<=maxn;i++)
                    {
                        for (int j=0;j<n;j++)
                        {
                                //0
                                ans=max(ans,f[i][j][0]);
                                ins(i,j,0,x[j],y[j]);
                                //1
                                ans=max(ans,f[i][j][1]);
                                ins(i,j,1,y[j],x[j]);
                                //2
                                ans=max(ans,f[i][j][2]);
                                ins(i,j,2,x[j],z[j]);
                                //3
                                ans=max(ans,f[i][j][3]);
                                ins(i,j,3,z[j],x[j]);
                                //4
                                ans=max(ans,f[i][j][4]);
                                ins(i,j,4,y[j],z[j]);
                                //5
                                ans=max(ans,f[i][j][5]);
                                ins(i,j,5,z[j],y[j]);
                        }
                    }
                    return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 50, 40, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 50, 40, 20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 50, 40, 20, 30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 150; verify_case(0, Arg3, tallestTower(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 30; verify_case(1, Arg3, tallestTower(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 33}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 33; verify_case(2, Arg3, tallestTower(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 110; verify_case(3, Arg3, tallestTower(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {
            BoxTower ___test;  
            ___test.run_test(-1);
            return 0;
    }  
    // END CUT HERE  
