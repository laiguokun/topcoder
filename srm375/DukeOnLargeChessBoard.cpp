    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "DukeOnLargeChessBoard.cpp"  
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
    const int maxn=1000000;
    int min(int a,int b){if (a<b) return a;else return b;}
    int max(int a,int b){if (a>b) return a;else return b;}
    int up[maxn+50],down[maxn+50];
    int getnum(string s,int a,int b)
    {
        int res=0;
        for (int i=a;i<=b;i++) res=res*10+(int)s[i]-48;
        return res;
    }
    string makestr(int x)
    {
        string res;
        res.clear();
        int now=100000;
        while (now>0)
        {
                if ((x/now)==0) res+=(char)48;else res+=(char)(x/now)+48;
                x=x % now;
                now=now/10;
        }
        return res;
    }
    void fg(int x,int y1,int y2)
    {
        down[x]=min(down[x],y1);
        up[x]=max(up[x],y2);
    }
    bool inside(int y,int x)
    {
        if (y<up[x] && y>down[x]) return false;else return true;
    }
    class DukeOnLargeChessBoard  
    {  
            public:  
            string lastCell(string initPosition)  
            {  
                int x=getnum(initPosition,1,6),y=getnum(initPosition,9,14);
                for (int i=0;i<maxn;i++)
                {
                        up[i]=-1;
                        down[i]=maxn;
                }
                up[x]=y;down[x]=y;
                while (true)
                {
                        if (x<maxn-1 && (down[x+1]>y || up[x+1]<y))
                        {
                                fg(x,y,y);
                                x++;
                                continue;
                        }
                        if (y<maxn-1 && inside(y,x) && (y!=down[x]||(down[x]==up[x])))
                        {
                                int t=maxn-1;
                                if (down[x]>y) t=min(t,down[x]-1);
                                fg(x,y,t);
                                y=t;
                                continue;
                        }
                        if (y>0 && inside(y,x) && (y!=up[x]||(down[x]==up[x])))
                        {
                                int t=0;
                                if (up[x]<y) t=max(t,up[x]+1);
                                t=max(t,down[x+1]-1);
                                fg(x,t,y);
                                y=t;
                                continue;
                        }
                        if (x>0 && (down[x-1]>y || up[x-1]<y))
                        {
                                fg(x,y,y);
                                x--;
                                continue;
                        }
                        int t=1;
                        break;
                }
                return '('+makestr(x)+','+' '+makestr(y)+')';
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(000002, 999997)"; string Arg1 = "(000000, 999996)"; verify_case(0, Arg1, lastCell(Arg0)); }
	void test_case_1() { string Arg0 = "(999999, 000000)"; string Arg1 = "(000000, 000000)"; verify_case(1, Arg1, lastCell(Arg0)); }
	void test_case_2() { string Arg0 = "(000002, 000003)"; string Arg1 = "(000000, 999999)"; verify_case(2, Arg1, lastCell(Arg0)); }
	void test_case_3() { string Arg0 = "(999998, 000001)"; string Arg1 = "(999999, 000000)"; verify_case(3, Arg1, lastCell(Arg0)); }
	void test_case_4() { string Arg0 = "(123456, 235711)"; string Arg1 = "(000000, 112256)"; verify_case(4, Arg1, lastCell(Arg0)); }
	void test_case_5() { string Arg0 = "(987654, 123456)"; string Arg1 = "(864197, 000000)"; verify_case(5, Arg1, lastCell(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            DukeOnLargeChessBoard ___test;  
            ___test.run_test(2);
            system("pause");  
            return 0;
    }  
    // END CUT HERE  
