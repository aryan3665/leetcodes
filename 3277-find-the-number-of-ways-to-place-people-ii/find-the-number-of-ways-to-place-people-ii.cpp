class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0]!=b[0]){
                return a[0]<b[0];
            }
            return a[1]>b[1];
        });
int ans=0;
        for( int i =0; i<points.size(); i++){
            int temp= INT_MIN;
            for(int j=i+1; j<points.size(); j++){
                if(points[i][1]>=points[j][1] && points[j][1]>temp){
ans++;
temp= points[j][1];
                }
            }
        }
        return ans;
    }
};