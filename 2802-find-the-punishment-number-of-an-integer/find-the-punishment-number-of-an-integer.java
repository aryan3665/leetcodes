class Solution {
    public int punishmentNumber(int n) {
        return solve(n);
    }

    static int solve(int n) {
        // Base case
        if (n == 1) return 1;

        int result = solve(n - 1);

        // Recursive case
        if (isvalid(n)) {
            return (n * n) + result;
        } else {
            return result;
        }
    }

    static boolean isvalid(int n) {
        String s = String.valueOf(n * n); // Convert the square of n to a String
        return canPartition(s, 0, n);
    }

    // Helper recursion to check all contiguous substring partitions
    static boolean canPartition(String s, int index, int target) {
        // Base case: reached the end of the string
        if (index == s.length()) {
            return target == 0;
        }

        int currentSum = 0;
        // Try cutting the string at every possible position from 'index'
        for (int j = index; j < s.length(); j++) {
            currentSum = currentSum * 10 + (s.charAt(j) - '0');
            
            // Pruning: stop early if the current number already exceeds target
            if (currentSum > target) {
                break;
            }
            
            // Recurse for the remaining string with reduced target
            if (canPartition(s, j + 1, target - currentSum)) {
                return true;
            }
        }
        return false;
    }
}
