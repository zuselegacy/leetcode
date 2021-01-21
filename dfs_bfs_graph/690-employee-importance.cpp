/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(int id) {
        int importance = hash[id]->importance;
        for(auto i : hash[id]->subordinates) {
            importance = importance + dfs(i);
        }
        return importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto employee: employees) {
            hash[employee->id] = employee;                        
        }
        
        return dfs(id);
    }
    map<int,Employee*> hash;
};
