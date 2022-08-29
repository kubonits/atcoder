#include<cstdio>
#include<stack>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int main(){
    int r,c,n,x,y,x1,y1;
    stack<int> s;
    vector<pair<int,int> > v;
    scanf("%d %d %d",&r,&c,&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&x,&y,&x1,&y1);
        if((x==0||y==0||x==r||y==c)&&(x1==0||y1==0||x1==r||y1==c)){
            if(x==0){
                v.push_back(make_pair(y,i));
            }
            else if(y==c){
                v.push_back(make_pair(c+x,i));
            }
            else if(x==r){
                v.push_back(make_pair(2*c+r-y,i));
            }
            else{
                v.push_back(make_pair(2*c+2*r-x,i));
            }
            if(x1==0){
                v.push_back(make_pair(y1,i));
            }
            else if(y1==c){
                v.push_back(make_pair(c+x1,i));
            }
            else if(x1==r){
                v.push_back(make_pair(2*c+r-y1,i));
            }
            else{
                v.push_back(make_pair(2*c+2*r-x1,i));
            }
        }
    }
    if(v.size()){
        sort(v.begin(),v.end());
        s.push(v[0].second);
        for(int i=1;i<v.size();i++){
            if(!s.empty()&&v[i].second==s.top()){
                s.pop();
            }
            else{
                s.push(v[i].second);
            }
        }
    }
    if(s.size()){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}