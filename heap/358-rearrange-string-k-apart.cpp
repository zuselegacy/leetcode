class Char {
    public:
    bool operator<(const Char& other) const {
        if (freq!=other.freq)
            return freq<other.freq;
        return c<other.c;
    }
    char c;
    int freq;
    
};
class Solution {
public:
    string rearrangeString(string s, int k) {
        priority_queue<Char> pq;
        string result;
        
        map<char,int> freq;
        for(int i=0;i<s.size();i++) {
            freq[s[i]]++;
        }
        for(auto it=freq.begin();it!=freq.end();it++) {
            Char c;
            c.c = it->first;
            c.freq = it->second;
            pq.push(c);
        }
        
        queue<pair<int,Char> > aux;
        int i=0;
        
        while(!pq.empty() || !aux.empty()) {
            
            // check if eligible chars to load into heap
            while(!aux.empty() && aux.front().first <= i) {
                pq.push(aux.front().second);
                aux.pop();
            }
            
            // pop from heap
            if(!pq.empty()) {
                Char c = pq.top();                            
                pq.pop();            
                result.push_back(c.c);
                c.freq--;
                if(c.freq>0) {
                    int index = i + k;
                    aux.push(make_pair(index,c));                    
                }                
                i++;
            } else {
                return "";
                
            }                                    
        }
        return result;
        
        
    }
};
