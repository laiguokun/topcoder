    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "RandomFights.cpp"  
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
    double a[100000],b[100000];
    double s1[100000],s2[100000],c1[100000],c2[100000],rr[100000];  
    bool cmp(double a,double b){return a<b;}  
    void sc(vector <int> x,double r[],int n)
    {
        int j=0;
        int m=x.size();
        for (int i=0;i<n;i++)
        {
                r[i]=x[j];
                int s=(j+1)%m;
                x[j]=((x[j]^x[s])+13)%49999;
                j=s;
        }
    }
    class RandomFights  
    {  
            public:  
            double expectedNrOfPoints(vector <int> A, vector <int> B, int n)  
            {
                sc(A,a,n);
                sc(B,b,n);
                sort(a,a+n,cmp);
                sort(b,b+n,cmp);
                s1[0]=b[0];s2[n-1]=b[n-1];
                c1[0]=b[0]*b[0];c2[n-1]=b[n-1]*b[n-1];
                for (int i=1;i<n;i++)
                {
                        s1[i]=s1[i-1]+b[i];
                        c1[i]=c1[i-1]+b[i]*b[i];
                }
                for (int i=n-2;i>=0;i--)
                {
                        s2[i]=s2[i+1]+b[i];
                        c2[i]=c2[i+1]+b[i]*b[i];
                }
                int p=0;
                double ans=0;
                for (int i=0;i<n;i++)
                {
                        while ((p<n)&&(b[p]<a[i])) p++;
                        if (p>0) ans+=((double)p*a[i]*a[i]-2.0*a[i]*(s1[p-1])+c1[p-1]);
                        if (p<n) ans-=((double)(n-p)*a[i]*a[i]-2.0*a[i]*(s2[p])+c2[p]);
                }
                return ans/(double)n;
             /*  ans=0;
               for (int i=0;i<n;i++)
               {
                        for (int j=0;j<n;j++)
                                if (a[i]>b[j]) ans+=(a[i]-b[j])*(a[i]-b[j]);else  ans-=(a[i]-b[j])*(a[i]-b[j]);
                        printf("%f\n",ans);
               }
               return ans/(double)n;*/
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; double Arg3 = 4.0; verify_case(0, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 0.0; verify_case(1, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {3,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 20.0; verify_case(2, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {45,35,236,2342,5543,21,32,2,6,23,24,23,41,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2345,45,2345,345}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; double Arg3 = 1.2721986164E8; verify_case(3, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {34,3245,2534,53,53,46,346,246,346,2,624,624,6,245,6324,6542,624,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {345,234,523,4624,6,2456,345,634,634,7,3457,376,34,6234,62,523,52,35,32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = -9713701.714285715; verify_case(4, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50000; double Arg3 = 0.0; verify_case(5, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            RandomFights ___test;
            ___test.run_test(5);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE
