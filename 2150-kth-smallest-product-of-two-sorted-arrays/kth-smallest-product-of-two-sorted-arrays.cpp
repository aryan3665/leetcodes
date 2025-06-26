class Solution {
public:
    long long findcountsmallest(vector<int>& nums1, vector<int>& nums2,
                                long long midproduct) {
        long long productcount = 0;
        int n = nums2.size();
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= 0) {
                int l = 0;
                int r = n - 1;
                int m = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1LL*nums1[i] * nums2[mid];

                    if(product<=midproduct){
                        m=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }
                productcount+=m+1;
            } else {
                // product negative hoga aur right hand side me smaller value
                // milegi

                 int l = 0;
                int r = n - 1;
                int m =n;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1LL*nums1[i] * nums2[mid];

                    if(product<=midproduct){
                        m=mid;
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }
                 productcount+=n-m;
            }
        }
        return productcount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long result = 0;
        long long l = -1e10; // min possible product
        long long r = 1e10;  // max possible product
        while (l <= r) {
            //t.c.o(log(r-l))
            long long midproduct = l + (r - l) / 2;
            // check if its kth smallest or not
            long long countsmallest =
                findcountsmallest(nums1, nums2, midproduct);//t.c,(o(n*log(nums2.size()-->m)))==o(n*log(m))

            if (countsmallest >= k) {
                result=midproduct;
                r = midproduct - 1;
            } else {
                l = midproduct + 1;
            }
        }

        return result;//total t.c.o(n*log(m)*log(r-l))
    }
};