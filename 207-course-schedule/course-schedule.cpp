class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> toDoThisIhaveToCompleteThese(n);
        vector<unordered_set<int>> canCompleteTheseIfDoneThis(n);
        for(auto pre:prerequisites){
            int a = pre[0];
            int b = pre[1];
            toDoThisIhaveToCompleteThese[b].insert(a);
            canCompleteTheseIfDoneThis[a].insert(b);
        }

        // cout << "First, have to complete these if I want to completer this:\n";
        // for(int i=0; i<n; i++){
        //     cout << i << " -> ";
        //     printSet(toDoThisIhaveToCompleteThese[i]);
        //     cout << endl;
        // }
        // cout << endl;
        // cout << "I can do these I have i done this one:\n";
        // for(int i=0; i<n; i++){
        //     cout << i << " -> ";
        //     printSet(canCompleteTheseIfDoneThis[i]);
        //     cout << endl;
        // }

        vector<int>freeCourses;
        for(int i=0; i<n; i++){
            if(toDoThisIhaveToCompleteThese[i].size() == 0) freeCourses.push_back(i);
        }
        // cout << endl;
        // printArr(freeCourses);

        if(!freeCourses.size()) return false; // if there is no course that is independent then we cant even start

        vector<int> completedCourses;
        for(auto course:freeCourses) completedCourses.push_back(course);

        vector<bool> completed(n);
        int ans = true;
        for(auto course:completedCourses){
            if(!completed[course]){
                unordered_set<int> prevCourse;
                ans = ans and explore(course,canCompleteTheseIfDoneThis,completed,prevCourse);
            }
        }

        if(!ans) return ans;

        bool allCompleted = true;
        for(auto isCompleted:completed) if(!isCompleted) allCompleted = false;
        return allCompleted;

    }
private:
    // void printSet(unordered_set<int> & a){
    //     for(auto i:a) cout << i << " ";
    // }
    // void printArr(vector<int>& a){
    //     for(auto i:a) cout << i << " ";
    // }
    bool explore(int course,vector<unordered_set<int>>& canCompleteTheseIfDoneThis,
        vector<bool>& completed,unordered_set<int>&prevCourse
    ){
        completed[course] = true;
        prevCourse.insert(course);
        bool ans = true;
        for(auto nextCourse:canCompleteTheseIfDoneThis[course]){
            if(completed[nextCourse] and prevCourse.find(nextCourse)!=prevCourse.end()) return false;
            else if(!completed[nextCourse])
                ans = ans and explore(nextCourse,canCompleteTheseIfDoneThis,completed,prevCourse);
        }
        prevCourse.erase(course);
        return ans;
    }
};