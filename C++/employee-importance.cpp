/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
private:
    int dfs(unordered_map<int, Employee*> &eMap, Employee* leader) {
        int importance = leader->importance;
        for (int id : leader->subordinates) {
            importance += dfs(eMap, eMap[id]);
        }
        
        return importance;
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> eMap;
        for (Employee* e : employees) {
            eMap[e->id] = e;
        }
        return dfs(eMap, eMap[id]);
    }
};