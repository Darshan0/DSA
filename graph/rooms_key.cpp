#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int> >& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        stack<int> stack;
        visited[0] = 1;
        stack.push(0);

        while(!stack.empty()){
            int node = stack.top();
            stack.pop();
            for (int it : rooms[node]){
                if(visited[it] != 1){
                    visited[it] = 1;
                    stack.push(it);
                }
            }
        }

        for(int seen : visited){
            if(seen == 0)
                return false;
        }
        return true;
    }
};