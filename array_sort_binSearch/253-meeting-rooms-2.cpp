class Point {
    public:
    int time;
    bool isStart;
    bool operator<(const Point& other) const {
        if(time != other.time)
            return time>other.time;
        else
            return isStart;
    }

};
class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<Point> pq;
        for(int i=0;i<intervals.size();i++) {
            Point p;
            p.time = intervals[i][0];
            p.isStart = true;
            pq.push(p);
            p.time = intervals[i][1];
            p.isStart = false;
            pq.push(p);
        }

        int rooms=0;
        int ans=0;
        while(!pq.empty()) {
            Point p = pq.top();
            pq.pop();
            if(p.isStart) {
                rooms++;
                ans = max(ans,rooms);
            } else
                rooms--;
        }
        return ans;

    }
};
