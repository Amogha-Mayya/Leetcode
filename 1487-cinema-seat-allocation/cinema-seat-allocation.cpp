class Solution {
public:
bool check1(int num){
    if(num == 2 || num == 3 || num == 4 || num == 5) return false;
    else return true;
}
bool check2(int num){
    if(num == 4 || num == 5 || num == 6 || num == 7) return false;
    else return true;
}
bool check3(int num){
    if(num == 6 || num == 7 || num == 8 || num == 9) return false;
    else return true;
}
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>>m;
        for(auto i:reservedSeats){
            int row = i[0];
            int col = i[1];
            m[row].push_back(col);
        }
        int count = 0;
        count += (n - m.size()) * 2; // complete free rows we can book 2 groups
        for(auto it:m){
            bool flag1=true,flag2=true,flag3=true;
            for(auto j:it.second){
                if(j >= 2 && j <= 5 && !check1(j)) flag1 = false;
                if(j >= 4 && j <= 7 && !check2(j)) flag2 = false;
                if(j >= 6 && j <= 9 && !check3(j)) flag3 = false;
            }
            if(flag1 && flag2 && flag3) count+=2;
            else if(flag1 && flag2) count+=1;
            else if(flag2 && flag3) count+=1;
            else if(flag1 && flag3) count+=1;
            else if(flag1 || flag2 || flag3) count+=1;
        }
        return count;
    }
};