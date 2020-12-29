## word ladder 2 (hard)

**solution 1**
```cpp
class Solution {
private:
    vector<vector<string>> result;
    void dfs(unordered_map<string, unordered_set<string>> &record, string &current, string &beginWord, string &endWord, vector<string> &path) {
        if (current == beginWord) {
            vector<string> reversed = path;
            reverse(reversed.begin(), reversed.end());
            result.push_back(reversed);
            return ;
        }
        for (string word : record[current]) {
            path.push_back(word);
            dfs(record, word, beginWord, endWord, path);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> pool;
        for (string word: wordList)
            pool.insert(word);

        if (pool.count(endWord) == 0) return result;

        queue<string> levelQueue;
        unordered_map<string, unordered_set<string>> record;

        levelQueue.push(beginWord);
        record.insert({beginWord, {}});

        bool findLevel = false;

        while (!levelQueue.empty()) {
            int size = levelQueue.size();
            unordered_set<string> visited;

            for (int i = 0; i < size; i++) {
                string current = levelQueue.front();
                levelQueue.pop();

                for (int i = 0; i < current.size(); i++) {
                    string temp = current;
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (temp == current || pool.count(temp) == 0) continue;

                        levelQueue.push(temp);
                        visited.insert(temp);
                        record[temp].insert(current);

                        if (temp == endWord) findLevel = true;
                    }
                }
            }

            for (string word: visited)
                pool.erase(word);

            if (findLevel) break;
        }

        vector<string> path = {endWord};
        dfs(record, endWord, beginWord, endWord, path);

        return result;
    }
};
```
