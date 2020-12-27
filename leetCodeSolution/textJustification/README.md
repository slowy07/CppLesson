## text justification (Hard)

**solution 1**
```cpp
class Solution {
public:
    string justify(const vector<string>& line, int maxWidth) {
        if (line.size() == 1) return left_justify(line, maxWidth);
        int characters = line.size() - 1;
        for (auto& word : line)
            characters += word.size();
        int extra_spaces = maxWidth - characters;        
        int extra_spaces_word = extra_spaces / (line.size() - 1);
        int extra_spaces_start = extra_spaces % (line.size() - 1);
        string text = line[0];
        for (int i = 1; i < line.size(); ++i) {
            for (int j = 0; j < extra_spaces_word + 1; ++j)
                text += ' ';
            if (extra_spaces_start > 0) {
                text += ' ';
                extra_spaces_start--;
            }
            text += line[i];
        }
        return text;
    }
    string left_justify(const vector<string>& line, int maxWidth) {
        string text;
        for (auto& word : line)
            text += word + " ";
        text.pop_back();
        while (text.size() < maxWidth)
            text += ' ';
        return text;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        vector<vector<string>> lines;
        while (i < words.size()) {
            vector<string> line;
            int totalWidth = words[i].size();
            line.push_back(words[i++]);
            while (i < words.size() && totalWidth + words[i].size() + 1 <= maxWidth) {
                totalWidth += words[i].size() + 1;
                line.push_back(words[i++]);
            }
            lines.push_back(line);
        }
        vector<string> text;    
        for (int j = 0; j < lines.size() - 1; ++j) {
            text.push_back(justify(lines[j], maxWidth));
        }
        text.push_back(left_justify(lines.back(), maxWidth));
        return text;
    }
};
```
