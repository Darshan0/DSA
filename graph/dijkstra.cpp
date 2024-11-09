#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>  dijkstra(int V, vector<vector<int> > adj[], int S){
    priority_queue< pair<int,int>, vector<pair<int,int> >,greater<pair<int, int> > > pq;
    vector<int> dist(V,INT_MAX);

    dist[S] = 0;
    pq.push({0,S});

    while(!pq.empty())

}

int main() {

}


