    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "MatchNumbersHard.cpp"  
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
    const long long maxll=1000000000000000000LL;
    string change(LL x)
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
    LL ord(char x) {return (int)x-48;}
    char chr(int x) {return (char)(x+48);}
  /*  LL max(LL a,LL b) {if (a>b) return a;else return b;}
    LL min(LL a,LL b) {if (a<b) return a;else return b;}*/
    class MatchNumbersHard  
    {  
            public:  
            vector <string> maxNumber(vector <string> matches, string n)  
            {
                VS ans;
                ans.clear();
                string a,b;
                a.clear();b.clear();
                LL sum=0;
                for (int i=0;i<n.length();i++) sum=sum*10+ord(n[i]);
                LL dig=matches.size();
                LL s[10],ss[10];
                memset(s,0,sizeof(s));
                memset(ss,0,sizeof(ss));
                for (int i=0;i<dig;i++)
                {
                        s[i]=0;
                        for (int j=0;j<matches[i].length();j++) s[i]=s[i]*10+ord(matches[i][j]);
                        ss[i]=matches[i].length();
                }
                LL min1=maxll,min0=maxll;
                for (int i=1;i<dig;i++) min1=min(min1,s[i]);
                for (int i=0;i<dig;i++) min0=min(min0,s[i]);
                if (sum<min0)
                {
                        ans.push_back("0");
                        ans.push_back(a);
                        ans.push_back(b);
                        return ans;
                }
                if ((sum>=min0)&&(sum<min1))
                {
                        ans.push_back("1");
                        ans.push_back("0");
                        ans.push_back("0");
                        return ans;
                }
                LL anslen=(sum-min1)/min0+1;
                ans.push_back(change(anslen));
                LL now=1,ms=0;
                for (int i=dig-1;i>=0;i--)
                {
                        LL ns=ms+s[i];
                        if (now>anslen) break;
                        if (now<anslen) ns=ns+min0*(anslen-now);
                        if (ns>sum) continue;
                        LL head=now,tail=anslen;
                        while (head<tail)
                        {
                                LL mid=(head+tail)/2+1;
                                LL cheng=(mid-now+1),tt=0;
                                while (cheng>0)
                                {
                                        tt++;
                                        cheng/=10;
                                }
                                if (ss[i]+tt-1>19) {tail=mid-1;continue;}
                                double dd=ms+(mid-now+1)*s[i]+(anslen-mid)*min0;
                                if ((dd>(double)sum)||(dd<0)) {tail=mid-1;continue;}
                                if ((ms+(mid-now+1)*s[i]+(anslen-mid)*min0)<=sum) head=mid; else tail=mid-1;
                                if (head!=1)
                                  int t=1;
                        }
                        if (now<=50)
                                for (LL j=now;j<=min(head,LL(50));j++) a=a+chr(i);
                        if (head>=(anslen-50+1))
                                for (LL j=max(now,anslen-(LL)50+(LL)1);j<=head;j++)
                                  b=b+chr(i);
                        ms=ms+(head-now+1)*s[i];
                        now=head+1;
                }
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"6","7","8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "21"; string Arr2[] = {"3", "210", "210" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1","7","8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "21"; string Arr2[] = {"15", "100000000000000", "100000000000000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1", "835810052671059340", "835810052167105935", "658100521671059340", "835810055648722340"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "958100521671059340"; string Arr2[] = {"923372036854775807", "99999999999999999999999999999999999999999999999999", "99999999999999999999999999999999999999999999999999" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1","923372036854775807"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "923372036854775807"; string Arr2[] = {"1", "1", "1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"1","923372036854775806"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "923372036854775807"; string Arr2[] = {"2", "10", "10" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"1","5","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "10"; string Arr2[] = {"6", "100000", "100000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"1","923372036854775807"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "923372036854775806"; string Arr2[] = {"1", "0", "0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_7() { string Arr0[] = {"1", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1000000"; string Arr2[] = {"999991", "10000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(7, Arg2, maxNumber(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            MatchNumbersHard ___test;  
            ___test.run_test(2);
            return 0;
    }  
    // END CUT HERE
