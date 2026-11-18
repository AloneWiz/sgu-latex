#include <iostream>
#include <vector>
#include <queue>

void bfs(int start_node, const std::vector < std::vector < int >> & adj_list) {
    int num_vertices = adj_list.size();

    std::vector<bool> visited(num_vertices, false);
    std::vector<int> dist(num_vertices, -1);
    std::queue<int> q;

    visited[start_node] = true;
    dist[start_node] = 0;
    q.push(start_node);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (int neighbor : adj_list[current_node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[current_node] + 1;
                q.push(neighbor);
            }
        }
    }
}