#include<iostream>
#include<cmath>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define plus(a,b) a=(a+b)%mo;
using namespace std;

const int mo=1000001;
long long f[51][51][51][101];

class RooksPlacement{
    public:
    int countPlacements(int N,int M,int K){
        f[0][0][0][0]=1;
        FOR(i,1,N){
            FOR(a1,0,M)FOR(a2,0,M-a1)
            FOR(k,a1+a2,K){
                f[i][a1][a2][k]=f[i-1][a1][a2][k];
                if (a1<M&&k&&a2)plus(f[i][a1][a2][k],f[i-1][a1+1][a2-1][k-1]*(a1+1));
                if (a1&&k) plus(f[i][a1][a2][k],f[i-1][a1-1][a2][k-1]*(M-a1-a2+1));
                if (a2>1&&k>1) plus(f[i][a1][a2][k],f[i-1][a1][a2-2][k-2]*((M-a1-a2+2)*(M-a1-a2+1)/2)%mo);
            }
        }
            
    int ans=0;
    FOR(a1,0,M)FOR(a2,0,M-a1) plus(ans,f[N][a1][a2][K]);
    return ans;   
    }         
};
