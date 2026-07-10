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
    int getImportance(vector<Employee*> employees, int id) {

        unordered_map<int,Employee*> mp;
        for(auto it: employees)
        {
            mp[it->id] = it;
        }

        int imp =0;

        queue<Employee*> q;
        q.push(mp[id]);


        while(!q.empty())
        {
            int n = q.size();

            for(int i=0; i<n; i++)
            {
                Employee* temp = q.front();
                q.pop();

                imp += temp->importance;

                for(auto sub : temp->subordinates)
                {
                    q.push(mp[sub]);
                }
            }
        }
    return imp;
    }
};
