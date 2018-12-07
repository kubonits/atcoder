#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,k,a,r,mid,f[100010],cnt,b,m;
    scanf("%d %d",&n,&k);
    char t[100010];
    vector<vector<char> > s(n+1);
    for(int i=0;i<k;i++){
        scanf("%d",&a);
        f[a]=1;
        r=a;
    }
    for(int i=0;i<n;i++){
        scanf("%s",t);
        m=strlen(t);
        s[i+1].reserve(m);
        for(int j=0;j<m;j++){
            s[i+1].push_back(t[j]);
        }
    }
    a=100000;
    b=-1;
    for(int i=1;i<=n;i++){
        if(i!=r){
            m=max(s[r].size(),s[i].size())+2;
            for(int j=0;j<m;j++){
                if(s[r][j]!=s[i][j]){
                    if(f[i]){
                        a=min(a,j);
                        break;
                    }
                    else{
                        b=max(b,j);
                        break;
                    }
                }
                if(j==m-1){
                    if(f[i]){
                        a=min(a,j+1);
                        break;
                    }
                    else{
                        b=max(b,j+1);
                        break;
                    }
                }
            }
        }
    }
    if(a<=b){
        printf("-1\n");
    }
    else{
        for(int i=0;i<=b;i++){
            printf("%c",s[r][i]);
        }
        printf("\n");
    }
}