class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle = 30 * hour + 0.5 * minutes;
        double minuteangle = 6 * minutes; 
        return min(abs(hourangle - minuteangle), 360 - abs(hourangle - minuteangle));
    }
};