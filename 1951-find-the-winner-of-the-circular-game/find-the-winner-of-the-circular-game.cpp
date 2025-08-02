class Solution {
public:
    // Recursive function to find the winner
    int winner(vector<bool>& person, int n, int index, int k, int personleft) {
        // Base case: Only one person left
        if (personleft == 1) {
            for (int i = 0; i < person.size(); i++) {
                if (person[i] == 0) return i + 1; // Return 1-based index
            }
        }

        // Calculate position to eliminate
       int kill=(k-1)%personleft;
       while(kill--){
        index=(index+1)%n;
        while(person[index]==1){
             index=(index+1)%n;
        }
       }

        // Eliminate current person
        person[index] = 1;

        // Move to next alive person
        while (person[index] == 1) {
            index = (index + 1) % n;
        }

        // Recursive call
        return winner(person, n, index, k, personleft - 1);
    }

    int findTheWinner(int n, int k) {
        vector<bool> person(n, 0); // false = alive, true = eliminated
        return winner(person, n, 0, k, n);
    }
};
