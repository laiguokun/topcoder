    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "ThreeBuses.cpp"  
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
      
    double c3(double x)
    {
        if (x<0) return 0;
        return x*x*x;
    }
    double c2(double x)
    {
        if (x<0) return 0;
        return x*x;
    }
    class ThreeBuses  
    {  
            public:  
            double getProbability(vector <int> wait, vector <int> travel, int timeLeft)  
            {  
                if ((timeLeft-=(travel[0]+travel[1]+travel[2]))<0) return 0;
                for (int i=0;i<3;i++)
                        for (int j=i+1;j<3;j++)
                        {
                                if (wait[i]<wait[j])
                                {
                                        int t;
                                        t=wait[i];wait[i]=wait[j];wait[j]=t;
                                }
                        }
                if (wait[0]==0) return 1;
                if (wait[1]==0)
                {
                        if (timeLeft<=wait[0]) return (double)timeLeft/(double)wait[0];
                        else return 1;
                }
                if (wait[2]==0)
                {
                        double ans=0;
                        ans+=c2(timeLeft)/2.0;
                        ans-=c2(timeLeft-wait[0])/2.0;
                        ans-=c2(timeLeft-wait[1])/2.0;
                        ans+=c2(timeLeft-wait[0]-wait[1])/2.0;
                        return ans/((double)wait[0]*(double)wait[1]);
                }
                double ans=0;
                ans+=c3(timeLeft)/6.0;
                ans-=c3(timeLeft-wait[0])/6.0;
                ans-=c3(timeLeft-wait[1])/6.0;
                ans-=c3(timeLeft-wait[2])/6.0;
                ans+=c3(timeLeft-wait[0]-wait[1])/6.0;
                ans+=c3(timeLeft-wait[1]-wait[2])/6.0;
                ans+=c3(timeLeft-wait[0]-wait[2])/6.0;
                ans-=c3(timeLeft-wait[0]-wait[1]-wait[2])/6.0;
                return ans/((double)wait[0]*(double)wait[1]*(double)wait[2]);
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 1470}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 =  47; double Arg3 = 1.0; verify_case(0, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 35; double Arg3 = 1.0; verify_case(1, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 100, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 52; double Arg3 = 0.21; verify_case(2, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {100, 100, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; double Arg3 = 0.020281904761904737; verify_case(3, Arg3, getProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            ThreeBuses ___test;  
            ___test.run_test(-1);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
