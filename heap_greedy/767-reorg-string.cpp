class Char {
  public:
    bool operator<(const Char& other) const {
        if(freq!=other.freq)
            return freq< other.freq;
        return c<other.c;
        
    }
    char c;
    int freq;
};

class Solution {
public:    
    string reorganizeString(string s) {
        map<char,int> freq;
        priority_queue<Char> pq;
        
        for(int i=0;i<s.size();i++) {
            freq[s[i]]++;
        }
        for(auto it=freq.begin();it!=freq.end();it++) {
            Char c;
            c.c = it->first;
            c.freq = it->second;
            pq.push(c);
            
        }
        
        string result;
        while(!pq.empty()) {
            Char c1 = pq.top();
            pq.pop();
            if(pq.empty()) {
                result.push_back(c1.c);
                break;
            }
            Char c2 = pq.top();
            pq.pop();
            
            result.push_back(c1.c);
            c1.freq--;
            if(c1.freq > 0)
                pq.push(c1);
            result.push_back(c2.c);
            c2.freq--;
            if(c2.freq >0)
                pq.push(c2);                            
        }
        return result.size() == s.size()?result:"";
        
    }
};
