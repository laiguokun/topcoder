    //#line 7 "Meteorites.cpp"  
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
    const double pi = acos(0.) * 2;
    const double eps=1e-20;
    struct T{double a,b;int c;};
    double cx[60],cy[60],cr[60],nowlength;
    bool f[60];
    T p[1000];
    int tot;
    double sqr(double x){return x*x;}
    double dist(int a,int b)
    {return sqrt(sqr(cx[a]-cx[b])+sqr(cy[a]-cy[b]));}
    bool inside(int a,int b)
    {
        if (cr[a]>=cr[b]) return false;
        if (cr[b]-cr[a]-dist(a,b)>-eps) return true;else return false;
    }
    bool cross(int a,int b){return !(cr[a]+cr[b]-dist(a,b)<eps);}
    double circlelength(int a){return 2*pi*cr[a];}
    void ins(double x,double y,int k)
    {
        tot++;
        p[tot].a=x;p[tot].b=y;p[tot].c=k;
    }
    bool cmp(T a,T b)
    {
        double x1=a.a-p[0].a,y1=a.b-p[0].b;
        double x2=b.a-p[0].a,y2=b.b-p[0].b;
        return (x1*y2)-(y1*x2)-0>eps;
    }
    double length(double x1,double y1,double x2,double y2)
    {
        double cj=x1*y2-x2*y1;
        if (fabs(cj)<eps)
        {
                if ((fabs(y1-y2)<eps)&&(fabs(x1-x2)<eps)) return 0;else return nowlength/2;
        }
        else
        {
                double a=sqr(x1)+sqr(y1),b=sqrt(sqr(x2)+sqr(y2)),c=sqrt(sqr(x2-x1)+sqr(y2-y1));
                //double jiao=acos((sqr(a)+sqr(b)-sqr(c))/(2*a*b));
                double jiao=acos((x1*x2+y1*y2)/(a));
                return (jiao/(2*pi))*nowlength;
        }
    }
    void ins2(double x2,double y2,double x3,double y3,int i)
    {
        if ((y2-0>eps)&&(y3-0<-eps)) ins(cr[i],0,1);
        if (fabs(y2)>eps) ins(x2,y2,-1);
        ins(x3,y3,1);
    }
    void ins1(double x2,double y2,double x3,double y3,int i)
    {
        double cj=x3*y2-x2*y3;
        if (cj<-eps){ins2(-x3,-y3,x3,y3,i);ins2(x2,y2,-x3,-y3,i);}
        else ins2(x2,y2,x3,y3,i);
    }
    class Meteorites  
    {  
            public:  
            double perimeter(vector <int> x, vector <int> y, vector <int> r)  
            {
                int n=x.size();
                double ans=0;
                for (int i=0;i<n;i++){cx[i]=x[i];cy[i]=y[i];cr[i]=r[i];}
                memset(f,true,sizeof(f));
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                                if ((i!=j)&&(inside(i,j))) f[i]=false;
                for (int i=0;i<n;i++)
                {
                        nowlength=circlelength(i);
                        if (f[i]) ans+=nowlength; else continue;
                        p[0].a=r[i];p[0].b=0;
                        tot=0;
                        for (int j=0;j<n;j++)
                        {
                                if ((i==j)||(!f[j])) continue;
                                if (cross(i,j))
                                {
                                        double x1=(x[j]-x[i])*(r[i]/dist(i,j)),y1=(y[j]-y[i])*(r[i]/dist(i,j));
                                        double a=r[j],b=r[i],c=dist(i,j),co=(sqr(b)+sqr(c)-sqr(a))/(2*b*c),si=sqrt(1-sqr(co));
                                        double x2=(x1*co-y1*si),y2=(x1*si+y1*co),x3=x1*co+y1*si,y3=y1*co-x1*si;
                                        ins1(x2,y2,x3,y3,i);
                                }
                        }
                        int h=1;
                        for (int j=1;j<=tot;j++)
                        {
                                if ((p[j].a==r[i])&&(p[j].b==0))
                                {
                                        double t;
                                        t=p[j].a;p[j].a=p[h].a;p[h].a=t;
                                        t=p[j].b;p[j].b=p[h].b;p[h].b=t;
                                        int t1;
                                        t1=p[j].c;p[j].c=p[h].c;p[h].c=t1;
                                        h++;
                                }
                        }
                        if (tot>1) sort(p+h,p+tot+1,cmp);
                        int sum=0;
                        for (int j=1;j<=tot;j++)
                        {
                                if (sum>0) ans-=length(p[j-1].a,p[j-1].b,p[j].a,p[j].b);
                                sum+=p[j].c;
                        }
                        if (sum>0) ans-=length(p[tot].a,p[tot].b,r[i],0);
                }
                return ans;
            }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] ={5, 6, 9, 11, 11, 11, 11, 15, 16, 17, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {21, 12, 7, 10, 12, 15, 17, 16, 6, 13, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 5, 3, 2, 1, 3, 3, 4, 6, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 63.72326520248748; verify_case(0, Arg3, perimeter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-10,-10,-10,0,0,0,10,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,0,10,-10,0,10,-10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,7,7,7,7,7,7,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 135.3757009200326; verify_case(1, Arg3, perimeter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {-100,100,100,-100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100,-100,100,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {110,110,110,110}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 2008.3301227325105; verify_case(2, Arg3, perimeter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,100000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 628318.5307179586; verify_case(3, Arg3, perimeter(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            Meteorites ___test;  
            ___test.run_test(0);
            system("pause");
            return 0;
    }  
    // END CUT HERE  

