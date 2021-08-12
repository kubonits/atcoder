#include<iostream>
#include<algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <deque>
#include<stack>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include<cstring>

int x[101],y[101],a[20][20],px=0,py=0;

void move(int gx,int gy){
    for(int j=0;j<abs(px-gx);j++){
        cout<<(px>gx?"U":"D");
    }for(int j=0;j<abs(py-gy);j++){
        cout<<(py>gy?"L":"R");
    }
    px=gx;
    py=gy;
}

void solve(int n,int sx,int sy,int gx,int gy,int f){
    if(n==100){
        return;
    }if(n+1!=100&&min(sx,gx)<=x[n+1]&&x[n+1]<=max(sx,gx)&&min(sy,gy)<=y[n+1]&&y[n+1]<=max(sy,gy)){
        solve(n+1,sx,sy,x[n+1],y[n+1],0);
        int xx=px;
        int yy=py;
        int dis=abs(px-x[n])+abs(py-y[n]);
        for(int i=min(px,x[n]);i<=max(px,x[n]);i++){
            for(int j=min(py,y[n]);j<=max(py,y[n]);j++){
                if(dis>abs(x[n]-i)+abs(y[n]-j)&&a[i][j]==-1){
                    xx=i;
                    yy=j;
                    dis=abs(x[n]-i)+abs(y[n]-j);
                }
            }
        }move(xx,yy);
        cout<<"O";
        a[x[n+1]][y[n+1]]=-1;
        a[xx][yy]=n+1;
        x[n+1]=xx;
        y[n+1]=yy;
    }
    move(x[n],y[n]);
    cout<<"I";
}

int main(){
    stack<int> st;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            a[i][j]=-1;
        }
    }
    x[100]=100;
    y[100]=100;
    for(int i=0;i<100;i++){
        cin>>x[i]>>y[i];
        a[x[i]][y[i]]=i;
    }
    for(int i=0;i<10;i++){
        if(i%2==0){
            for(int j=0;j<20;j++){
                if((i<10||j<10)&&a[i][j]!=-1){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }else if(!(i<10||j<10)&&a[i][j]==-1){
                    a[i][j]=st.top();
                    x[st.top()]=i;
                    y[st.top()]=j;
                    st.pop();
                    cout<<"O";
                }if(j!=19){
                    cout<<"R";
                }
            }
        }else{
            for(int j=19;j>=0;j--){
                if((i<10||j<10)&&a[i][j]!=-1){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }else if(!st.empty()&&!(i<10||j<10)&&a[i][j]==-1){
                    a[i][j]=st.top();
                    x[st.top()]=i;
                    y[st.top()]=j;
                    st.pop();
                    cout<<"O";
                }if(j!=0){
                    cout<<"L";
                }
            }
        }cout<<"D";
    }for(int j=0;j<20;j++){
        if(j%2==0){
            for(int i=10;i<20;i++){
                if((i<10||j<10)&&a[i][j]!=-1){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }else if(!(i<10||j<10)&&a[i][j]==-1){
                    a[i][j]=st.top();
                    x[st.top()]=i;
                    y[st.top()]=j;
                    st.pop();
                    cout<<"O";
                }if(i!=19){
                    cout<<"D";
                }
            }
        }else{
            for(int i=19;i>=10;i--){
                if((i<10||j<10)&&a[i][j]!=-1){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }else if(!st.empty()&&!(i<10||j<10)&&a[i][j]==-1){
                    a[i][j]=st.top();
                    x[st.top()]=i;
                    y[st.top()]=j;
                    st.pop();
                    cout<<"O";
                }if(i!=10){
                    cout<<"U";
                }
            }
        }if(j!=19){
            cout<<"R";
        }
    }

/*     for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<a[i][j]<<"\t";
        }cout<<endl;
    } */



    for(int j=19;j>=10;j--){
        if(j%2==0){
            for(int i=19;i>=10;i--){
                if(a[i][j]<64){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }if(i!=10){
                    cout<<"U";
                }
            }
        }else{
            for(int i=10;i<20;i++){
                if(a[i][j]<64){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }if(i!=19){
                    cout<<"D";
                }
            }
        }if(j!=10){
            cout<<"L";
        }
    }
    cout<<"U";
    for(int j=10;j>=3;j--){
        if(j%2==0){
            for(int i=9;i>=2;i--){
                a[i][j]=st.top();
                x[st.top()]=i;
                y[st.top()]=j;
                st.pop();
                cout<<"O";
                if(i!=2){
                    cout<<"U";
                }
            }
        }else{
            for(int i=2;i<10;i++){
                a[i][j]=st.top();
                x[st.top()]=i;
                y[st.top()]=j;
                st.pop();
                cout<<"O";
                if(i!=9){
                    cout<<"D";
                }
            }
        }
       if(j!=3) {cout<<"L";}
    }
    px=9;
    py=3;

    for(int i=0;i<100;i++){
        solve(i,px,py,x[i],y[i],1);
    }

/* for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<a[i][j]<<"\t";
        }cout<<endl;
    } */
    //move(10,10);
    /* for(int j=10;j<20;j++){
        if(j%2==0){
            for(int i=10;i<20;i++){
                if(a[i][j]!=-1){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }if(i!=19){
                    cout<<"D";
                }
            }
        }else{
            for(int i=19;i>=10;i--){
                if(a[i][j]!=-1){
                    st.push(a[i][j]);
                    a[i][j]=-1;
                    cout<<"I";
                }if(i!=10){
                    cout<<"U";
                }
            }
        }if(j!=19){
            cout<<"R";
        }
    } */
/* for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<a[i][j]<<"\t";
        }cout<<endl;
    } */
    /* for(int j=19;j>=10;j--){
        if(j%2==0){
            for(int i=19;i>=10;i--){
                a[i][j]=st.top();
                x[st.top()]=i;
                y[st.top()]=j;
                st.pop();
                cout<<"O";
                if(i!=10){
                    cout<<"U";
                }
            }
        }else{
            for(int i=10;i<20;i++){
                a[i][j]=st.top();
                x[st.top()]=i;
                y[st.top()]=j;
                st.pop();
                cout<<"O";
                if(i!=19){
                    cout<<"D";
                }
            }
        }if(j!=10){
            cout<<"L";
        }
    } */

    /* px=10;
    py=10;
    for(int i=50;i<100;i++){
        solve(i,px,py,x[i],y[i],1);
    } */
}