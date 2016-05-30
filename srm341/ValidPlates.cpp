    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "ValidPlates.cpp"  
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
    const int num=12;
    double matrix[num][num],g[num][num],ans[num][num],len,K;
    string res;
    void fz(double a[num][num],double b[num][num])
    {
        for (int i=0;i<num;i++)
                for (int j=0;j<num;j++) a[i][j]=b[i][j];
    }
    void multiply(double a[num][num],double b[num][num])
    {
        double c[num][num];
        fz(c,a);
        for (int i=0;i<num;i++)
                for (int j=0;j<num;j++) a[i][j]=0;
        for (int i=0;i<num;i++)
                for (int j=0;j<num;j++)
                        for (int k=0;k<num;k++)
                        {
                                a[i][j]=a[i][j]+(c[i][k]*b[k][j]);
                        }
    }
    double judge(int x)
    {
        x--;
        memset(ans,0,sizeof(ans));
        memset(matrix,0,sizeof(matrix));
        for (int i=1;i<=10;i++) ans[0][i]=1;
        fz(matrix,g);
        while (x>0)
        {
                if ((x%2)==1)
                {
                        multiply(ans,matrix);
                     //printf("%f\n",ans[0][1]);
                        double t=0;
                        for (int i=0;i<=9;i++) t+=ans[0][i];
                     //   printf("%f",t);
                        if (t>K) return t;
                }
                double matrix_[num][num];
                fz(matrix_,matrix);
                multiply(matrix,matrix_);
                x/=2;
        }
        double res=0;
        for (int i=0;i<=9;i++) res+=ans[0][i];
        return res;
    }
    int calc(int x,int k)
    {
        x--;
        memset(ans,0,sizeof(ans));
        memset(matrix,0,sizeof(matrix));
        ans[0][k]=1;
        fz(matrix,g);
        while (x>0)
        {
                if ((x%2)==1)
                {
                        multiply(ans,matrix);
                }
                double matrix_[num][num];
                fz(matrix_,matrix);
                multiply(matrix,matrix_);
                x/=2;
        }
        int res=0;
        for (int i=0;i<=9;i++) res+=(int)ans[0][i];
        return res;
    }
    void work(int now,int k,int last)
    {
        if (len>50)
        {
                if (now==(len-47))
                {
                        res+="...";
                        return;
                }
        }
        if (now==0) return;
        for (int i=0;i<=9;i++)
        {
                if (g[last][i]==0) continue;
                if ((i==0)&&(now==len)) continue;
                int t=calc(now,i);
                if (t<k) k-=t;
                else
                {
                        res+=(char)(i+48);
                        work(now-1,k,i);
                        return;
                }
        }
    }
    class ValidPlates
    {
            public:
            string getPlate(vector <string> profane, int seqno)
            {
                int n=profane.size();
                K=seqno;
                for (int i=0;i<=9;i++)
                {
                        for (int j=0;j<=9;j++) g[i][j]=1;
                        if (i!=0) g[10][i]=1;
                }
                g[10][10]=1;
                for (int i=0;i<n;i++)
                {
                        int len=profane[i].length();
                        int h=0;
                        while (h<len)
                        {
                                int k1=(int)profane[i][h]-48,k2=(int)profane[i][h+1]-48;
                                g[k1][k2]=0;
                                h=h+3;
                        }
                }
                int h=1,t=seqno;
                while (h<t)
                {
                        int mid=((LL)h+(LL)t)/2LL;
                        if (judge(mid)>=(double)seqno) t=mid;else h=mid+1;
                }
                if (judge(h)<(double)seqno) return "";
                if (h>1) seqno-=judge(h-1);
                len=h;
                work(len,seqno,10);
                return res;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0(){}
        //{ string Arr0; Arr0.clear();  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; string Arg2 = "1000"; verify_case(0, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; string Arg2 = "11"; verify_case(1, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000000000; string Arg2 = "2277659869"; verify_case(2, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00 01 02 03 04 05 06 07 08 09 11 12 13 14 15 16 17",
 "18 19 22 23 24 25 26 27 28 29 33 34 35 36 37 38 39",
 "44 45 46 47 48 49 55 56 57 58 59 66 67 68 69 77 78",
 "79 88 89 99 99 99 99 99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1023; string Arg2 = ""; verify_case(3, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00 01 02 03 04 05 06 07 08 09", "10 12 13 14 15 16 17 18 19", "20 21 22 23 24 25 26 27 28 29", "30 31 32 33 34 35 36 37 38 39", "40 41 42 43 44 45 46 47 48 49", "50 51 52 53 54 55 56 57 58 59", "60 61 62 63 64 65 66 67 68 69", "70 71 72 73 74 75 76 77 78 79", "80 81 82 83 84 85 86 87 88 89", "90 91 92 93 94 95 96 97 98 99"};vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000000000; string Arg2 = "79999999351623516571657999935799993"; verify_case(4, Arg2, getPlate(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00 01 02 03 04 05 06 07 08 09",
 "10 11 12 13 14 16 17 19",
 "20 21 22 23 24 25 26 27 28 29",
 "30 31 32 33 34 35 36 38 39",
 "41 42 43 44 45 46 49",
 "50 52 53 54 55 57 58 59",
 "60 61 62 63 64 65 66 67 68 69",
 "70 72 73 74 75 76 77 78 79",
 "80 81 82 83 84 85 86 87 88 89",
 "90 91 92 93 94 95 98 99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000000000; string Arg2 = "37151515151515151515151515151515151515151515151..."; verify_case(5, Arg2, getPlate(Arg0, Arg1)); }

// END CUT HERE
  
    };  

    // BEGIN CUT HERE  
    int main()  
    {
            ValidPlates ___test;  
            ___test.run_test(4);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE
