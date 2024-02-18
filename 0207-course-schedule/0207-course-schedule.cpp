/*
    Courses & prerequisites, return true if can finish all courses
    Ex. numCourses = 2, prerequisites = [[1,0]] -> true

    All courses can be completed if there's no cycle (visit already visited)

    Time: O(V + E)
    Space: O(V + E)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // map each course to prereq list
        unordered_map<int, vector<int>> m;
        // build graph
        for (int i = 0; i < prerequisites.size(); i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // all courses along current DFS path
        unordered_set<int> visited;
        // DFS
        for (int course = 0; course < numCourses; course++) {
            // if dfs returns false, there's a cycle, can't finish all courses
            if (!dfs(course, m, visited)) {
                return false; // can't finish all courses, so return false
            }
        }
        // no cycle, can finish all courses
        return true;
    }
private:
    bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visited) {
        // if course is already visited, there's a cycle
        if (visited.find(course) != visited.end()) {
            return false;
        }
        // if no prereqs, return true
        if (m[course].empty()) {
            return true;
        }
        // mark course as visited
        visited.insert(course);
        for (int i = 0; i < m[course].size(); i++) {
            int nextCourse = m[course][i]; // next course in prereq list
            // if next course has a cycle, return false
            if (!dfs(nextCourse, m, visited)) {
                return false;
            }
        }
        m[course].clear(); // clear prereq list
        visited.erase(course); // mark course as unvisited
        return true;
    }
};
