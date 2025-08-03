class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        unordered_map<int,int> validFruits;
        int left_max = startPos-k;
        int right_max = startPos+k;
        for(auto i:fruits)
        {
            if(i[0]<left_max || i[0]>right_max)
            continue;
            validFruits[i[0]] = i[1];
        }
        unordered_map<int,int> leftFruits;
        unordered_map<int,int> rightFruits;
        int sum = 0;
        for(int st = startPos; st>=left_max;st--)
        {
            if(st == startPos)
            continue;
            if(validFruits.count(st))
            {
                sum+= validFruits[st];
            }
            leftFruits[st] = sum;
        }
        sum = 0;
        for(int st = startPos; st<=right_max;st++)
        {
            if(st == startPos)
            continue;
            if(validFruits.count(st))
            sum+=validFruits[st];
            rightFruits[st] = sum;
        }
        int max_ans = validFruits[startPos];
        int left_first = 0, right_first = 0;
        int curr = validFruits[startPos];
        int copy_k = k;
        k--;
        for(int i = startPos+1;i<=right_max;i++)
        {
            curr+= validFruits[i];
            int rem_k = max(0,k - (i-startPos));
            max_ans = max(max_ans, curr + leftFruits[startPos - rem_k]);
            k--;
        }
        curr = validFruits[startPos];
        k = copy_k-1;
        for(int i = startPos-1;i>=left_max;i--)
        {
            curr+= validFruits[i];
            int rem_k = max(0,k - (startPos - i));
            max_ans = max(max_ans, curr + rightFruits[startPos + rem_k]);
            k--;
        }
        return max_ans;
    }
};