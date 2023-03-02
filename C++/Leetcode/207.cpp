// 207. 课程表


/*
    拓扑排序，dfs，T=O(n+m), S=O(n+m)，n 为课程数，m 为先修课程的要求数
*/
class Solution {
public:
    vector<int> vis; // vis数组有三种状态，-1:正在搜索；0:没有搜索过；1:已搜索完成
    vector<vector<int>> edges; // 邻接表存储边的信息，有向图
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
                if (!dfs(i)) return false;
            }
        }
        return true;
    }
    bool dfs(int u)
    {
        vis[u] = -1; // 搜索开始，标记为-1，正在搜索
        for (const auto& v : edges[u])
        {
            if (vis[v] == 0)
            {
                if(!dfs(v)) return false;
            }
            else if (vis[v] < 0) // 在搜索过程中，发现有重复的路径可以到达v，说明有环
            {
                return false;
            }
        }
        vis[u] = 1; // 从u点能走的路径全部走完，搜索完成，标记为1
        return true;
    }
};


/*
    拓扑排序，bfs，T=O(n+m), S=O(n+m)，n 为课程数，m 为先修课程的要求数
*/
class Solution {
public:
    vector<int> vis; // vis数组保存节点u的入度个数
    vector<vector<int>> edges;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
                q.push(i); // 首先入度为0的进入队列，表示该门课程不需要先修课程
            }
        }

        int cnt = 0; // 表示有多少个课程按顺序学习可以正常修完
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ++cnt;
            for (const auto& v : edges[u]) // 1）遍历u课程的边，即需要学习完u后才能开始学v
            {
                --vis[v]; // 2）删除从u到v的边，v课程的入度减1 (这里没有真的删除u到v的边，只是减了v的入度)
                if (vis[v] == 0) q.push(v); // 当v课程的入度为0，表示这门课程已不需要先修课程，入队列
            }
        }

        return cnt == numCourses;
    }
};