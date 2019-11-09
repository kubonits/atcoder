#include<cstdio>
#include<set>
#include<utility>
#include<vector>
#include<stack>
using namespace std;

struct ans{
    int y;
    int x;
    char c;
};
int main(){
    int n,m,rx[100],ry[100],by[300],bx[300],b,gx,gy,x,y,cnt=0;
    char c[110],g[40][40];
    stack<pair<int,int> > st;
    scanf("%d %d %d",&n,&m,&b);
    scanf("%d%d",&gy,&gx);
    set<pair<int,int> > bs,as;
    vector<ans> v;
    for(int i=0;i<m;i++){
        scanf("%d %d %c",&ry[i],&rx[i],&c[i]);
    }
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            g[i][j]='X';
        }
    }
    g[gy][gx]='G';
    for(int i=0;i<b;i++){
        scanf("%d%d",&by[i],&bx[i]);
        g[by[i]][bx[i]]='B';
        bs.insert({by[i],bx[i]});
    }
    if(g[(gy+n-1)%n][(gx+n)%n]=='X'){
        g[(gy+n-1)%n][(gx+n)%n]='D';
        st.push({(gy+n-1)%n,(gx+n)%n});
    }
    if(g[(gy+n+1)%n][(gx+n)%n]=='X'){
        g[(gy+n+1)%n][(gx+n)%n]='U';
        st.push({(gy+n+1)%n,(gx+n)%n});
    }
    if(g[(gy+n)%n][(gx+n-1)%n]=='X'){
        g[(gy+n)%n][(gx+n-1)%n]='R';
        st.push({(gy+n)%n,(gx+n-1)%n});
    }
    if(g[(gy+n)%n][(gx+n+1)%n]=='X'){
        g[(gy+n)%n][(gx+n+1)%n]='L';
        st.push({(gy+n)%n,(gx+n+1)%n});
    }
    while(!st.empty()){
        cnt++;
        y=st.top().first;
        x=st.top().second;
        st.pop();
        if(g[(y+n-1)%n][(x+n)%n]=='X'){
            g[(y+n-1)%n][(x+n)%n]='D';
            st.push({(y+n-1)%n,(x+n)%n});
        }
        if(g[(y+n+1)%n][(x+n)%n]=='X'){
            g[(y+n+1)%n][(x+n)%n]='U';
            st.push({(y+n+1)%n,(x+n)%n});
        }
        if(g[(y+n)%n][(x+n-1)%n]=='X'){
            g[(y+n)%n][(x+n-1)%n]='R';
            st.push({(y+n)%n,(x+n-1)%n});
        }
        if(g[(y+n)%n][(x+n+1)%n]=='X'){
            g[(y+n)%n][(x+n+1)%n]='L';
            st.push({(y+n)%n,(x+n+1)%n});
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            if(g[i][j]!='B'&&g[i][j]!='G'&&g[i][j]!='X'){
                printf("%d %d %c\n",i,j,g[i][j]);
            }
        }
    }
}