class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        vector<int>temp(10,0);
        for(int it:arr)
        {
            temp[it]++;
        }
        string num1="",num2="";
        bool flag = true;
        for(int digit = 0;digit<=9;digit++)
        {
            while (temp[digit]--) 
            {
                if (flag)
                    num1 += (digit + '0');
                else
                    num2 += (digit + '0');
                flag = !flag;
            }
        }
       
        string res = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) 
        {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res += char(sum % 10 + '0') ;
            carry = sum / 10;
        }
        reverse(res.begin(),res.end());
        
        int k=0;
        while(res[k] =='0')
        {
            k++;
        }
        res.erase(0,k);
        return res;
    }
};