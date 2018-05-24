class Solution{
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict){
		wordDict.insert(endWord);
		queue<string> toVisit;
		addNextWords(beginWord, wordDict, toVisit);

		int dist =2;
		while(!toVisit.empty()){
			int num = toVisit.size();
			for(int i=0; i<num; i++){
				string word = toVisit.front();
				toVisit.pop();
				if(word==endWord)	return dict;
				addNextWords(word, wordDict, toVisit)；
			}
			dist++;
		}
	}
}