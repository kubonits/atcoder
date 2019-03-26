#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n,m,a,b[100001]={},sosuu[100001]={};
    vector<int> x[100001],y[100001];
    scanf("%d %d",&n,&m);
    for(int i=2;i<=100000;i++){
        sosuu[i]=1;
    }
    for(int i=2;i<=m;i++){
        if(sosuu[i]){
            for(int j=2*i;j<=m;j+=i){
                sosuu[i]=0;
            }
        }
    }
}