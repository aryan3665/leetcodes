class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>result;
        result.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string currfolder=folder[i];
            string last =result.back();
            last+='/';

            if(currfolder.find(last)!=0){
                result.push_back(currfolder);
            }

        }
        return result;
    }
};