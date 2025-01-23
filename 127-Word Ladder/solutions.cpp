class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool beginPresent = false;
        bool endPresent = false;
        int beginIndex = -1;

        for (int i = 0; i < wordList.size(); i++) {
            string str = wordList[i];
            if (str == beginWord) {
                beginPresent = true;
                beginIndex = i;
            }
            if (str == endWord)
                endPresent = true;
        }
        if (!endPresent)
            return 0;
        if (!beginPresent) {
            wordList.push_back(beginWord);
            beginIndex = wordList.size() - 1;
        }

        int n = wordList.size();
        vector<set<int>> adj(n);
        vector<bool> visited(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j and differBySingleChar(wordList[i], wordList[j])) {
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }
        }

        // cout << "Size: " << n << endl;
        // cout << "beginIndex: " << beginIndex << endl;
        // print(adj, wordList);

        queue<vector<int>> q;
        q.push({beginIndex, 1});
        visited[beginIndex] = true;
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> data = q.front();
                int index = data[0];
                int val = data[1];
                q.pop();
                for (auto strI : adj[index]) {
                    if (!visited[strI]) {
                        q.push({strI, val + 1});
                        visited[strI] = true;
                        if (wordList[strI] == endWord)
                            ans = max(ans, val + 1);
                    }
                }
            }
        }
        return ans;
    }

private:
    bool differBySingleChar(const string& word1, const string& word2) {
        int diffCount = 0;
        for (size_t i = 0; i < word1.length(); ++i) {
            if (word1[i] != word2[i]) {
                ++diffCount;
                if (diffCount > 1)
                    return false;
            }
        }
        return diffCount == 1;
    }
    void print(const vector<set<int>>& adj, vector<string>& wordList) {
        for (int i = 0; i < adj.size(); ++i) {
            cout << "[" << i << "," << wordList[i] << "] -> {";
            auto it = adj[i].begin();
            while (it != adj[i].end()) {
                cout << *it << "," << wordList[*it];
                if (++it != adj[i].end()) {
                    cout << ", ";
                }
            }
            cout << "}" << endl;
        }
    }
};