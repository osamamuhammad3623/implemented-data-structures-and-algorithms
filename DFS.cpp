#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> *g, int start){

    stack<int> st;
    vector<bool> visited((*g).size(), 0); // mark all nodes as unvisited

    visited[start] = 1; // mark starting node as visited
    cout << start << " ";

    // add neighbours to the stack
    for (auto neighbour: (*g)[start]){
        st.push(neighbour);
    }

    while(!st.empty()){
        int current = st.top();
        if (visited[current]){
            st.pop();
        }else{
            cout << current << " ";
            visited[current] = 1;
            for (auto neighbour: (*g)[current]){
                st.push(neighbour);
            }
        }
    }
}

int main(void) {
	vector<vector<int>> g = {
							{ 1,2 , 3},
							{ 0,2},
							{ 0,1 },
							{ 0 ,4,5},
							{3},
							{3}
							};
	dfs(&g, 0);
}
