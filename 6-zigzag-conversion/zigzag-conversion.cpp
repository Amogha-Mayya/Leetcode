class Solution {
public:
int findcolumns(string s,int numRows){
    int i=0;
    int col = 0;
    int sum = 0;
    while(sum < s.size()){
        if(i%2 == 0)
        {
            sum+=numRows;
            col++;
        }
        else{
            sum+=(numRows-2);
            col++;
        }
        i++;
    }
    return col;
}
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int m = numRows;
        int n = findcolumns(s,numRows);
        int z = 0;
        int size = s.size();
        vector<vector<char>>temp(m,vector<char>(n,'#'));
        for(int i=0;i<n;i++){ // for loop for columns
            if(i%2 == 0){ // if col is even
                for(int k=0;k<m;k++){
                    if(z < size)
                        temp[k][i] = s[z];
                    z++;
                }
            }
            else{
                for(int k=m-2;k>0;k--){
                    if(z < size)
                        temp[k][i] = s[z];
                    z++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
        string str = "";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j] != '#')
                    str+=temp[i][j]; 
            }
        }
        return str;
    }
};