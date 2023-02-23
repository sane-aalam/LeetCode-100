
// create a set data structure
// push the all list string into the set
// create queue ,push the starting word
// for every itration,we will check out this abaiable 
// if it is present then remove into the set 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st;

        for(auto it: wordList){
            st.insert(it);
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;

            q.pop();

            if(word == endWord){
                return level;
            }

            for(int i = 0; i<word.size(); i++){
                char orginal = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push({word,level + 1});
                        st.erase(word);
                    }
                }
                word[i] = orginal;
            }
        }
        return 0;
    }
};
