class MyCalendar {
public:
vector<pair<int,int>>v;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        if(v.empty()){
            v.push_back({startTime,endTime});
            return true;
        }

        for(auto it:v){
            int s = it.first;
            int e = it.second;
            // overlap
            if(startTime < e && endTime > s)
                return false;
        }  
        // no overlap
        v.push_back({startTime,endTime});
            return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */