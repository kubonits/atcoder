/*
https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d
*/
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
int n,m,parent[100001],iri[100001],a,b,jun[100001],parent2[100001];
vector<int> to[100001],from[100001],ans;
stack<int> st;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+m-1;i++){
        scanf("%d %d",&a,&b);
        to[a].push_back(b);
        from[b].push_back(a);
        iri[b]++;
    }
    for(int i=1;i<=n;i++){
        if(iri[i]==0){
            st.push(i);
        }
    }
    while(st.size()){
        int i =st.top();
        st.pop();
        ans.push_back(i);
        for(int j=0;j<to[i].size();j++){
            iri[to[i][j]]--;
            if(iri[to[i][j]]==0){
                st.push(to[i][j]);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        //printf("%d\n",ans[i]);
        jun[ans[i]]=i+1;
        for(int j=0;j<from[ans[i]].size();j++){
            if(parent2[ans[i]]<jun[from[ans[i]][j]]){
                parent2[ans[i]]=jun[from[ans[i]][j]];
                parent[ans[i]]=from[ans[i]][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",parent[i]);
    }
}