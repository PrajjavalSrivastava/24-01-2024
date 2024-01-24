class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) {
        int t[n+1][k+1];
        
        for(int i=0;i<n+1;i++){
            t[i][0] = 0;
            t[i][1] = 1;
        }
        
        for(int i=0;i<k+1;i++) t[1][i] = i;
        
        for(int i=2;i<n+1;i++){
            for(int j=2;j<k+1;j++){
                t[i][j] = INT_MAX;
                for(int x=1;x<j+1;x++){
                    int temp = 1 + max(t[i-1][x-1], t[i][j-x]);
                    t[i][j] = min(t[i][j], temp);
                }
            }
        }
        return t[n][k];
    }
};