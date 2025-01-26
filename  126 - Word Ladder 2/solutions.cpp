class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> list(wordList.begin(), wordList.end());
        if (list.find(endWord) == list.end())
            return ans;
        list.erase(beginWord);
        queue<tuple<string, int>> q;
        queue<tuple<string, int>> print;
        q.push({beginWord, 1});
        print.push({beginWord, 1});
        unordered_map<string, int> depth;
        depth[beginWord] = 1;
        bool found = false;
        int lev = 0;
        while (!q.empty() and !found) {
            auto [str, level] = q.front();
            q.pop();
            for (int i = 0; i < str.size(); i++) {
                char originalChar = str[i];
                for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                    str[i] = newChar;
                    if (list.find(str) != list.end()) {
                        q.push({str, level + 1});
                        print.push({str, level + 1});
                        list.erase(str);
                        depth[str] = level+1;
                        if (str == endWord) {
                            lev = level + 1;
                            found = true;
                            break;
                        }
                    }
                }
                str[i] = originalChar;
                if(found) break;
            }
        }
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, ans, path, list, depth);


        while(!print.empty()){
            auto [str,len] = print.front();
            print.pop();
            cout << str << " " << len << endl;
        }
        return ans;
    }
private:
    void dfs(string word, string endWord, vector<vector<string>> &ans,
    vector<string>& path, unordered_set<string> &list, unordered_map<string, int>& depth){
        if(word == endWord){
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        string originalWord = word;
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char c='a'; c<='z'; c++){
                word[i] = c;
                if(depth.find(word)!=depth.end() and depth[word] < depth[originalWord]){
                    path.push_back(word);
                    dfs(word, endWord, ans, path, list, depth);
                    path.pop_back();
                }
            }
            word[i] = original;
        }
    }
};