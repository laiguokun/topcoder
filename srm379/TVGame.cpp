    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "TVGame.cpp"  
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
    const int mode=121547;
    const int num=50;
    LL g[num][num];
    LL gcd(LL a,LL b,LL& x,LL& y)
    {
        if ((a%b)==0)
        {
                x=0;y=1;return b;
        }
        LL x1,y1,res=gcd(b,a%b,x1,y1);
        x=y1;
        y=x1-(a/b)*y1;
        return res;

    }
    LL extend_gcd(LL a)
    {
        LL x,y;
        LL k=gcd(a,-mode,x,y);
        x=((x*k) % mode+mode)%mode;
        return x;
    }
    void fz(LL a[],LL b[])
    {
        for (int i=0;i<num;i++) a[i]=b[i];
    }
    class TVGame  
    {  
            public:  
            int expectedProfit(vector <string> board)  
            {
                int n=board.size();
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                        {
                                if (board[i][j]>='0' && board[i][j]<='9') g[i][j]=(int)board[i][j]-48;
                                else g[i][j]=(int)'A'-(int)board[i][j]-1;
                        }
                LL ans=1;
                for (int i=0;i<n;i++)
                {
                        for (int j=i+1;j<n;j++)
                        {
                                if (g[j][i]!=0)
                                {
                                        LL t[num];
                                        fz(t,g[i]);fz(g[i],g[j]);fz(g[j],t);
                                        ans=-ans;
                                }
                        }
                        ans=(ans*g[i][i])%mode;
                        if (g[i][i]==0) continue;
                        LL t=extend_gcd(g[i][i]);
                      //  ans=(ans*t)%mode;
                        for (int j=i;j<n;j++) g[i][j]=(g[i][j]*t)%mode;
                        for (int j=i+1;j<n;j++)
                                for (int k=n-1;k>=i;k--) g[j][k]=(g[j][k]-g[j][i]*g[i][k])%mode;
                }
                if ((n & 1)==0) ans=-ans;
                ans=((ans % mode)+mode)%mode;
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"35",
 "44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, expectedProfit(Arg0)); }
	void test_case_1() { string Arr0[] = {"36BBFA8HE59EH7A2G0DBDDBA8", 
"60HH7B62DA049960A37CFBBC7",
 "4AGB6G1EA8885B12I586052GC",
 "GC0H6IC7B6G52CCGH4FGHCE8A", 
"5G6E6C30H68ECHA7G0B8C29D0",
 "FD61AA47957I89B8000I6C4FF",
 "D713FGH08884HGI06EHD4B574",
 "343H6920F53EF2C688882EI01",
 "C9AGHHC7I95IA8HC2FAC403G1",
 "6B864A5D88I6EFG7G66425D04",
 "GIH94D519F07G9F477H540HE3",
 "IHAF7FCBE2C6B811EGEI021C3", 
"F27161ECGA58012807I1F740F", 
"D1BCD2B21HB0H1866D010B07D",
 "IFA1HB98HFCGDAF259F0B1CA4",
 "7B031DBG04469H7E3G17H8426",
 "5C3ABH7B9B465H98279DD1B73",
 "I0EIGH9I1FGH5G865876EBA21",
 "59IC32ID402F88C4378BD37HB",
 "F45C268AI7IFEH0A0H00DCIA3",
 "B3B1623H6A097330E92GBIF5I", 
"DI119C0B0D5A32ABG2IECH226",
 "1319HG7481E6B24H9A11FA9F5",
 "448797EDG2E50HI00AE28C5DG",
 "A7728A22E0G17AI02863FBCB3"};vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 121539; verify_case(1, Arg1, expectedProfit(Arg0)); }
	void test_case_2() { string Arr0[] = {"12A",
 "A12",
 "2A1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(2, Arg1, expectedProfit(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAAA",
 "BBBB",
 "CCCC",
 "DDDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, expectedProfit(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            TVGame ___test;
            ___test.run_test(3);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE

