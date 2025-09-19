class Spreadsheet {
public:
    // Stores cell values: key = cell name (like "A1"), value = integer stored in that cell
    unordered_map<string, int> mp;

    // Constructor (rows not used here, but can be extended for larger logic)
    Spreadsheet(int rows) {}

    // Sets the value of a specific cell
    void setCell(string cell, int value) { 
        mp[cell] = value; 
    }

    // Resets the cell value to 0
    void resetCell(string cell) { 
        mp[cell] = 0; 
    }

    // Evaluates a formula of the form "=X+Y" 
    // where X and Y can be either cell names (like "A1") or integers (like "5")
    int getValue(string formula) {
        string s1 = "", s2 = "";
        int i = 1; // skip '=' at the start

        // Extract first operand (until '+')
        while (formula[i] != '+') {
            s1 += formula[i];
            i++;
        }

        i++; // skip '+'

        // Extract second operand (till end of formula)
        while (i < formula.size()) {
            s2 += formula[i];
            i++;
        }

        int ans = 0;

        // Check if first operand is a cell (A-Z...) or integer
        if (s1[0] >= 'A' && s1[0] <= 'Z')
            ans = mp[s1];          // fetch value from cell
        else
            ans = stoi(s1);        // convert string number to int

        // Same check for second operand
        if (s2[0] >= 'A' && s2[0] <= 'Z')
            ans += mp[s2];
        else
            ans += stoi(s2);

        return ans; // return final computed value
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */