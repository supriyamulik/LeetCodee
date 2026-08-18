// approach is to start by using a queue ds and storing the startword with step as 1, now for each char in the word we try replacing with a to z, and if found that after replacing a certain chr we get the word form teh wordlist we add that word to the queue with step 2 we repeatedly do this until we get the word end so here we re traversing level by level there can be more that one replacemnts tht re valid so they will be at the same level so we will chack from a to z everytime nd push it to the queue , if we are done with the queue and didnt get the endWord so will return 0 as it conot be formed. Here as we are replacing char by char nd checking from teh wordlist where the new word is present or not we are storing the words in the set for easy retrival and comparing 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // adding the start word with step 1

        unordered_set<string> st(wordList.begin(), wordList.end()); // to reduce the overhead of frequently traversing the entire vector to check for the newWord we use a set

        st.erase(beginWord); // ersed the strt word as we have already looked that and dded in the queue

        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) // if we found the end word we will stop and return the steps
            {
                return steps;
            }
            for(int i=0; i<word.size(); i++) // traversing every word
            {
                char orignal = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) //traversing every char of the word
                {
                    word[i] = ch;
                    if(st.find(word) != st.end()) // now we have the new word with replaced char will check in the set whether there exist tht word in the list, this condition is true if it exists
                    {
                        st.erase(word);  // we will remove the word form the list 
                        q.push({word,steps+1}); // and push it to the queue with step 
                    }
                }
                word[i] = orignal; // replace back the orignal word to avoid conflicts with firther chnged char
            }
        }
        return 0; // if not found the end word till the queue is empty return 0
    }
};