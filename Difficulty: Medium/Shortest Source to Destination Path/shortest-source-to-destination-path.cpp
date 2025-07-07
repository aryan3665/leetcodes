// User function Template for C++

class Solution {
  public:
  typedef pair<int,pair<int,int>>p;
  int m,n;
  int row[4]={-1,1,0,0};
  int col[4]={0,0,-1,1};
   bool isvalid(int i, int j) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        //bhaiya chalo abb dijikstra ko 2d array ke liye lagaaaaate hain
       m=A.size();
       n=A[0].size();
       
       if(n==0||m==0||A[0][0]==0||A[X][Y]==0)return -1;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        result[0][0]=0;
       while(!pq.empty()){
           int dist=pq.top().first;
           int x1=pq.top().second.first;
           int y1=pq.top().second.second;
           A[x1][y1]=0;
            pq.pop();
            
            for(int k=0;k<4;k++){
                int nx=x1+row[k];
                int ny=y1+col[k];
                if(isvalid(nx,ny)&&A[nx][ny]==1&&dist+1<result[nx][ny]){
                    result[nx][ny]=1+dist;
                    pq.push({1+dist,{nx,ny}});
                }
            }
           
       }
       if(result[X][Y]==INT_MAX)return -1;
       return result[X][Y];
        
    }
};