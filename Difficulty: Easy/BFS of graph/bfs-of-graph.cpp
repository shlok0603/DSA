class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {

        int V = adj.size();

        vector<int> ans;
        vector<bool> vis(V, false);

        queue<int> q;

        q.push(0);
        vis[0] = true;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neigh : adj[node]) {

                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }

        return ans;
    }
};