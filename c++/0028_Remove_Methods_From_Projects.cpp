/* You are maintaining a project that has n methods numbered from 0 to n - 1.
You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.
There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
A group of methods can only be removed if no method outside the group invokes any methods within it.
Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.*/

// Solution :- 

#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        
        // Step 1: Build the adjacency list for graph traversal
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 2: BFS/DFS from `k` to find all suspicious methods
        std::vector<bool> isSuspicious(n, false);
        std::queue<int> q;
        
        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!isSuspicious[v]) {
                    isSuspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // Step 3: Check if any non-suspicious method invokes a suspicious method
        bool canRemove = true;
        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
                canRemove = false;
                break;
            }
        }

        // Step 4: Construct result list
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (canRemove) {
                if (!isSuspicious[i]) {
                    result.push_back(i);
                }
            } else {
                result.push_back(i);
            }
        }

        return result;
    }
};