class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        
        map<char,int> freq;
        for(int i=0;i<tasks.size();i++) {
            freq[tasks[i]]++;
        }
        for(auto it=freq.begin();it!=freq.end();it++) {
            pq.push(it->second);
        }
        
        queue<pair<int,int> > aux;
        int t=1;
        while(!pq.empty() || !aux.empty()) {
            
            // check if eligible tasks to load into heap
            while(!aux.empty() && aux.front().first <= t) {
                pq.push(aux.front().second);
                aux.pop();
            }
            
            // pop from heap
            if(!pq.empty()) {
                int freq = pq.top();                
                freq--;
                pq.pop();            
                if(freq>0) {
                    int time = t + n +1;
                    aux.push(make_pair(time,freq));                    
                }                
                t++;
            } else {
                t = aux.front().first;
                
            }                                    
        }
        return t-1;
        
    }
};
