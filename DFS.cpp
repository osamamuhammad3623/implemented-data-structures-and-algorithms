#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> g, int start){
    cout << start << " ";
    start--; // for 0-based indexing
    stack<int> st;
    vector<bool> visited(g.size()+1, 0); // mark all nodes as unvisited

    visited[start] = 1; // mark starting node as visited
	
    // add neighours to the stack
    for (auto neighbour: g[start]){
        st.push(neighbour);
    }

    while(!st.empty()){
        int current = st.top();
        current--; // // for 0-based indexing
        if (visited[current]){
            st.pop();
        }else{
            cout << current+1 << " ";
            visited[current] = 1;
            for (auto neighbour: g[current]){
                st.push(neighbour);
            }
        }
    }
}

int main(void) {
	vector<vector<int>> g = { { 2, 3, 4 }, { 1, 3 }, { 1, 2 }, { 1, 5, 6 }, {4}, {6} };
	dfs(g, 1);
}
