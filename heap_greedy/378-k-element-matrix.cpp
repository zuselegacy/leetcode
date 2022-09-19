class Element {
    public:    
    int val;
    int row;
    int col;
    bool operator<(const Element& other) const{
        if(val!=other.val)
            return val > other.val;
        else if(row!=other.row)
            return row > other.row;
        else 
            return col > other.col;
    }    
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Element> pq;
        int n = k<matrix.size()? k:matrix.size();
        for(int i=0;i<n;i++) {
            Element e;
            e.val = matrix[i][0];
            e.row = i;
            e.col = 0;
            pq.push(e);
        }
        int val;
        while(k>0) {
            Element e = pq.top();
            val = e.val;
            pq.pop();
            if(e.col < (matrix[0].size()-1)) {
                e.col++;
                e.val = matrix[e.row][e.col];
                pq.push(e);
            }
            k--;            
        }
        return val;
        
    }
};
