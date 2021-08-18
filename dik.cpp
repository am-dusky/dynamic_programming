#include<bits/stdc++.h>
using namespace std;
#define n 5
void print(vector<int>dis,int source);

void dij_algo(vector<pair<int,int>>g[n+1],int source){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap
    vector<int>dis(n+1,INT_MAX);
    dis[source]=0;
    pq.push(make_pair(0,source));//(dis,node)
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();

        vector<pair<int,int>>::iterator it;
        for(auto it:g[prev]){
            int next=it.first;
            int nextDis=it.second;
            if(dis[next]>dist+nextDis){
                dis[next]=dis[prev]+nextDis;
                pq.push(make_pair(dis[next],next));
            }
        }
    }
    print(dis,source);
}

void print(vector<int>dis,int source){
    cout<<"The distance from source vertix are: \n";
    for(int i=1;i<=n;i++){
        cout<<source<<" - "<<i<<" : "<<dis[i]<<"\n"; 
    }
    return;
}

int main(){
    int m,source;
    cout<<"Enter the number of edges: ";
    cin>>m;
    vector<pair<int,int>>g[n+1]; //1 based indexing
    int a,b,wt;
    cout<<"Enter two vertices and weight between them: ";
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }
    cout<<"Enter the source vertix: ";
    cin>>source;
    dij_algo(g,source);
    return 0;
}