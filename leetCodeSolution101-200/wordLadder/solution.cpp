class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        for(int i=0;i<wordList.size();i++)
        {
            s.insert(wordList[i]);
        }
        if(s.find(endWord)==s.end())
            return 0;
        queue<string>q;
        int depth=0;
        q.push(beginWord);
        while(!q.empty())
        {
            depth=depth+1;
            int lsize=q.size();
            while(lsize--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    string temp=curr;
                    for(char x='a';x<='z';x++)
                    {
                        temp[i]=x;
                        if(temp.compare(curr)==0)
                            continue;
                        if(temp.compare(endWord)==0)
                        {
                            return depth+1;
                        }
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
  }
};
