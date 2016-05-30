#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

struct dot{
    int x,y;
};

const double eps=1e-8;
const double pi=3.14159265358979;
int n,t,t2;
bool flag;
double ang;
dot p[50];
vector <int> ans;

inline int cha_mul(dot a,dot b,dot c,dot d){
    return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
}
inline int mul(dot a,dot b,dot c,dot d){
    return (b.x-a.x)*(d.x-c.x)+(b.y-a.y)*(d.y-c.y); 
}
inline double dis(dot a,dot b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool check(int n){
    t=cha_mul(p[n-1],p[n],p[n],p[0]);
    t2=cha_mul(p[n],p[0],p[0],p[1]);
    if (t*t2<=0) return false;
    ang=acos(mul(p[n-1],p[n],p[n],p[0])/dis(p[n-1],p[n])/dis(p[n],p[0]));
    ang+=acos(mul(p[n],p[0],p[0],p[1])/dis(p[n],p[0])/dis(p[0],p[1]));
    FOR(i,2,n){
        t=t2;
        t2=cha_mul(p[i-2],p[i-1],p[i-1],p[i]);
        ang+=acos(mul(p[i-2],p[i-1],p[i-1],p[i])/dis(p[i-2],p[i-1])/dis(p[i-1],p[i]));
        if (t*t2<=0) return false;
    }
    if (ang-eps>2*pi)return false;
    return true;
}
int DFS(int k){
    if (k==6){
        if (check(2))flag=true;
        return 0;
    }
    FOR(i,1,50){
        if (k&1) p[k>>1].y=i;
            else p[k>>1].x=i;
        DFS(k+1);
        if (flag){
            ans.push_back(i);
            return 0;
        }
    }
}
class ConvexArray{
    public:
    vector <int> getEnding(vector <int> A){
        n=A.size();
        FOR(i,0,n-1)
          if(i&1) p[i>>1].y=A[i];
             else p[i>>1].x=A[i];
        if (n<5){
            flag=false;
            DFS(n);
            reverse(ans.begin(),ans.end());
            if (!flag) ans.push_back(-1);
            return ans;
        }
        if (n&1){
            for(p[n>>1].y=1;p[n>>1].y<=50;p[n>>1].y++)
                if (check(n>>1)){
                    ans.push_back(p[n>>1].y);
                    return ans;
                }
            ans.push_back(-1);
        }else{
            if (!check((n>>1)-1)) ans.push_back(-1);
        }
        return ans;
    }
};

/*int main(){
    scanf("%d",&n);    
    FOR(i,0,n-1)
        if (i&1) scanf("%d",&p[i>>1].y);
        else scanf("%d",&p[i>>1].x);
    if (n<5){
        flag=false;
        DFS(n);
        system("pause");
        return 0;
    }
    if (n&1){
        for(p[n>>1].y=1;p[n>>1].y<=50;p[n>>1].y++)
            if (check(n>>1)){
                printf("%d",p[n>>1].y);
                system("pause");
                return 0;
            }
    }else{
        if (!check((n>>1)-1)) printf("%d\n",-1);
        return 0;
    }
    
}*/
