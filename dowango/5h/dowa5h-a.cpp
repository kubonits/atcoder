#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n,m,a,b,x[100000]={},f,f2;
    char s[100001];
    long long k;
    vector<int> v[100001];
    scanf("%d %d %lld",&n,&m,&k);
    scanf("%s",s);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if(s[v[i][j]]=='B'&&(x[i]&1)==0){
                x[i]+=1;
            }
            else if(s[v[i][j]]=='R'&&(x[i]&2)==0){
                x[i]+=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if((x[v[i][j]]&1)==0&&(x[i]&4)==0){
                x[i]+=4;
            }
        }
    }
    if(k==1){
        for(int i=0;i<n;i++){
            if((x[i]&1)){
                printf("First\n");
            }
            else{
                printf("Second\n");
            }
        }
    }
    else if(k%2){
        for(int i=0;i<n;i++){
            f=0;
            for(int j=0;j<v[i].size();j++){
                if((x[v[i][j]]&4)==0){
                    f=1;
                    break;
                }
            }
            if(f){
                printf("First\n");
            }
            else{
                printf("Second\n");
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            f=0;
            for(int j=0;j<v[i].size();j++){
                if((x[v[i][j]]&2)==0){
                    f=1;
                }
            }
            if(f){
                printf("First\n");
            }
            else{
                printf("Second\n");
            }
        }
    }
}