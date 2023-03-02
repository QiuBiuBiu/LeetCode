// 210. 课程表 II


/*
    拓扑排序，dfs，T=O(n+m), S=O(n+m)，n 为课程数，m 为先修课程的要求数
    参考207题。
    PS: 写完发现课程的依赖关系(edges)我刚好写反了，所以导致dfs的拓扑关系是正着存的，bfs是反着存的。
*/
class Solution {
public:
    int index = -1;
    vector<int> tops;
    vector<int> vis;
    vector<vector<int>> edges;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        index = -1;
        tops.resize(numCourses);
        vis.resize(numCourses);
        edges.resize(numCourses);
        for (const auto& edge : prerequisites)
        {
            edges[edge[0]].emplace_back(edge[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
            {
                if (!dfs(i)) return vector<int>{};
            }
        }
        return tops;
    }
    bool dfs(int u)
    {
        vis[u] = -1;
        for (const auto& v : edges[u])
        {
            if (vis[v] == 0)
            {
                if (!dfs(v)) return false; 
            }
            else if (vis[v] < 0)
            {
                return false;
            }
        }
        tops[++index] = u;
        vis[u] = 1;
        return true;
    }
};

/*
    拓扑排序，bfs，T=O(n+m), S=O(n+m)，n 为课程数，m 为先修课程的要求数
*/
class Solution {
public:
    vector<int> vis;
    vector<vector<int>> edges;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses);
        edges.resize(numCourses);
        for (const auto& edge : prerequisites)
        {
            edges[edge[0]].emplace_back(edge[1]);
            ++vis[edge[1]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
            {
                q.push(i);
            }
        }

        int index = numCourses;
        vector<int> tops(numCourses);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            tops[--index] = u;
            for (const auto& v : edges[u])
            {
                --vis[v];
                if (vis[v] == 0) q.push(v);
            }
        }
        if (index == 0) return tops;
        return vector<int>{};
    }
};