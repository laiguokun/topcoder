    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "LongLongNim.cpp"  
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
    const int mode=1<<22;
    const int len=22;
    int f[mode][2];  
      
    class LongLongNim  
    {  
            public:  
            int numberOfWins(int maxN, vector <int> moves)  
            {
                for (int i=0;i<mode;i++) f[i][1]=-1;
                int m=moves.size();
                int now=0,sum=0,i;
                for (i=1;i<=min(maxN,len);i++)
                {
                        bool ok=false;
                        for (int j=0;j<m;j++)
                        {
                                if (moves[j]>i) continue;
                                if ((now & (1<<(moves[j]-1)))==0) ok=true;
                        }
                        now*=2;
                        if (ok) now++;else sum++;
                        now%=mode;
                       //     if (i==21)
                       //         int t=1;
                       // if (i>=11) printf("%d\n",now & (1<<(i-11)));
                }
                i--;
                if (maxN<=len) return sum;
                f[now][0]=i;f[now][1]=sum;
                while (true)
                {
                        i++;
                        if (i>maxN) return sum;
                       // printf("%d",now&(1<<19));
                        bool ok=false;
                        for (int j=0;j<m;j++)
                                if ((now & (1<<(moves[j]-1)))==0) ok=true;
                        now*=2;
                        if (ok) now++;else sum++;
                        now%=mode;
                        if (f[now][1]!=-1)
                        {
                                int circle=i-f[now][0];
                                int circlesum=sum-f[now][1];
                                sum+=((maxN-i)/circle)*circlesum;
                                int rest=(maxN-i)%circle;
                                for (int i=1;i<=rest;i++)
                                {
                                        bool ok=false;
                                        for (int j=0;j<m;j++)
                                                if ((now & (1<<(moves[j]-1)))==0) ok=true;
                                        now*=2;
                                        if (ok) now++;else sum++;
                                        now%=mode;
                                }
                                return sum;
                        }
                        f[now][0]=i;f[now][1]=sum;
                }
                return sum;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 999; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 499; verify_case(1, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000000000; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 333333333; verify_case(2, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6543;int Arr1[] = {2,4,7,11,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1637; verify_case(3, Arg2, numberOfWins(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            LongLongNim ___test;  
            ___test.run_test(3);
            system("pause");
            return 0;  
    }  
    // END CUT HERE
