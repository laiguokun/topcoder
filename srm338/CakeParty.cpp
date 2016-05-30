    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "CakeParty.cpp"  
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
    int na[20],nb[20];
    void fj(int a,int& len,int na[])
    {
        if (a==0) {len++;na[len]=0;}
        while (a>0)
        {
                len++;
                na[len]=a%10;
                a/=10;
        }
    }
    int cmp(int a,int b)
    {
        int lena=-1,lenb=-1;
        fj(a,lena,na);
        fj(b,lenb,nb);
        int k=0;
        while ((k<=lena)&&(k<=lenb))
        {
                if (na[lena-k]<nb[lenb-k]) return a;
                if (na[lena-k]>nb[lenb-k]) return b;
                k++;
        }
        return a;
    }
    int work(int a,int b)
    {
        int lena=-1,lenb=-1;
        fj(a,lena,na);
        fj(b,lenb,nb);
        if (lenb>lena)
        {
                int now=1;
                for (int i=1;i<=lena+1;i++) now*=10;
                return cmp(a,now);
        }
        else return a;
    }
    string ys(string s1,int a,string s2,int b)
    {
        string res;
        res.clear();
        int lena=-1,lenb=-1;
        fj(a,lena,na);
        fj(b,lenb,nb);
        res+=s1;
        for (int i=lena;i>=0;i--) res+=char(na[i]+48);
        res+=s2;
        for (int i=lenb;i>=0;i--) res+=char(nb[i]+48);
        return res;
    }
    class CakeParty  
    {  
            public:  
            string makeMove(vector <int> pieces)  
            {
                string ans;
                int first=0,n=pieces.size(),p=0,odd;
                for (int i=0;i<n;i++)
                {
                        if (pieces[i]>p)
                        {
                                p=pieces[i];
                                first=i;
                                odd=1;
                        }
                        else
                        {
                                if (pieces[i]==p)
                                {
                                        first=cmp(first,i);
                                        odd++;
                                }
                        }
                }
                if ((odd%2)==0)
                {
                        ans=ys("CAKE ",first," PIECES ",1);
                }
                else
                {
                        if (odd>1) ans=ys("CAKE ",first," PIECES ",1);
                        else
                        {
                                int p_=0,odd_=0;
                                for (int i=0;i<n;i++)
                                {
                                        if (pieces[i]==p) continue;
                                        if (pieces[i]>p_)
                                        {
                                                p_=pieces[i];
                                                odd_=1;
                                        }
                                        else if (pieces[i]==p_) odd_++;
                                 }
                                 if ((odd_==0)||((odd_%2)==1))
                                 {
                                        ans=ys("CAKE ",first," PIECES ",p-p_);
                                 }
                                 else
                                 {
                                        ans=ys("CAKE ",first," PIECES ",work(p-p_+1,p));
                                 }
                        }
                }
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 47"; verify_case(0, Arg1, makeMove(Arg0)); }
	void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(1, Arg1, makeMove(Arg0)); }
	void test_case_2() { int Arr0[] = {3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 1 PIECES 2"; verify_case(2, Arg1, makeMove(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(3, Arg1, makeMove(Arg0)); }
	void test_case_4() { int Arr0[] = {3,3,112}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 2 PIECES 110"; verify_case(4, Arg1, makeMove(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 205, 196, 196}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(5, Arg1, makeMove(Arg0)); }
	void test_case_6() { int Arr0[] = {670, 337, 124, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 125, 337, 337, 337, 337, 26, 128, 337, 337, 337, 337, 285, 337, 337, 337, 337, 337};vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 10 PIECES 1"; verify_case(6, Arg1, makeMove(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            CakeParty ___test;
            ___test.run_test(6);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
