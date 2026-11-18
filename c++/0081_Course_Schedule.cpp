/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses -
 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course.
Return true if you can finish all courses. Otherwise, return false.*/

// Solution :- 

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // Adjacency list and indegree array
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);

        // Build the graph
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Push all courses with 0 indegree into the queue
        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCourses = 0;

        // Process the queue
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++;

            // Decrement indegree for neighboring courses
            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we can finish all courses, there are no cycles
        return completedCourses == numCourses;
    }
};
