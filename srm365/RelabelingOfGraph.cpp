#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int n,t,a[50],d[50];
bool map[50][50];
vector <int> ans;

void Floyd(){
    FOR(k,0,n)FOR(i,0,n)FOR(j,0,n)
        if (map[i][k]&&map[k][j]) map[i][j]=true;
}
class RelabelingOfGraph{
    public:
    vector <int> renumberVertices(vector <string> m){
        n=m.size();
        n--;
        FOR(i,0,n)FOR(j,0,n)
            if (m[i][j]=='1') map[i][j]=true;
        Floyd();
        FOR(i,0,n)if (map[i][i]) return ans;
        FOR(i,0,n) 
          FOR(j,0,n)
            if (map[i][j]) d[i]++;
        FORD(i,n,0){
            FORD(j,n,0) if (!d[j]){
                FOR(k,0,n)
                    if (map[k][j]) d[k]--;
                a[j]=i;d[j]=-1;
                break;
            }
        }
        FOR(i,0,n) ans.push_back(a[i]);
        return ans;
    }    
};
