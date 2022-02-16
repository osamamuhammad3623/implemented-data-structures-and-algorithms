#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void bfs(vector<vector<int>> g, int start){
    cout << start << " ";
    start--;
    deque<int> q; // deque is used as inserting/erasing from both ends is O(1)
    vector<bool> visited(g.size()+1, 0);

    visited[start] = 1;
    for (auto neighbour: g[start]){
        q.push_back(neighbour);
    }

    while(!q.empty()){
        int current = q.front();
        current--;
        if (visited[current]){
            q.pop_front();
        }else{
            cout << current+1 << " ";
            visited[current] = 1;
            for (auto neighbour: g[current]){
            	q.push_back(neighbour);
            }
        }
    }
}

int main(void) {
	vector<vector<int>> g = { { 2, 3, 4 }, { 1, 3 }, { 1, 2 }, { 1, 5, 6 }, {4}, {6} };
	bfs(g, 1);
}
