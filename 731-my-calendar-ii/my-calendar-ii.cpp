class MyCalendarTwo {
public:
    map<int,int>m;
    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;
        int count = 0;
        for(auto it : m){
            count += it.second;

            if(count > 2){
                // triple booking
                m[startTime]--;
                m[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */