    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "StoneGameStrategist.cpp"  
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
    const int maxn=1000;
    string change(int x)
    {
        string s1,s2;
        s1.clear();s2.clear();
        if (x==0) return "0";
        while (x>0)
        {
                s1=s1+char((x%10)+48);
                x=x/10;
        }
        for (int i=s1.length()-1;i>=0;i--) s2=s2+s1[i];
        return s2;
    }
      
    class StoneGameStrategist  
    {  
            public:  
            string play(vector <int> piles)  
            {
                int d[60];
                memset(d,0,sizeof(d));
                d[piles.size()-1]=piles[0];
                for (int i=1;i<piles.size();i++) d[piles.size()-1-i]=piles[i]-piles[i-1];
                for (int i=1;i<=maxn;i++)
                {
                        for (int j=piles.size()-1;j>=0;j--)
                        {
                                if (i>d[j]) continue;
                                int c[60];
                                for (int k=0;k<piles.size();k++) c[k]=d[k];
                                c[j]=c[j]-i;
                                if (j!=0) c[j-1]=c[j-1]+i;
                                int x=0;
                                for (int k=0;k<piles.size();k++) if ((k%2)==0) x^=c[k];
                                if (x==0)
                                {
                                        string a=change(i),b=change(piles.size()-1-j);
                                        return "TAKE "+a+" STONES FROM PILE "+b;
                                }
                        }
                }
                return "YOU LOSE";
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YOU LOSE"; verify_case(0, Arg1, play(Arg0)); }
	void test_case_1() { int Arr0[] = {6,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TAKE 6 STONES FROM PILE 1"; verify_case(1, Arg1, play(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TAKE 3 STONES FROM PILE 0"; verify_case(2, Arg1, play(Arg0)); }
	void test_case_3() { int Arr0[] = {3,5,9,11,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TAKE 2 STONES FROM PILE 0"; verify_case(3, Arg1, play(Arg0)); }
	void test_case_4() { int Arr0[] = {32,136,251,369,403,593,624,657,729,731,769}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YOU LOSE"; verify_case(4, Arg1, play(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            StoneGameStrategist ___test;  
            ___test.run_test(1);
            return 0;
    }  
    // END CUT HERE
