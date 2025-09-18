class TaskManager {
public:
     set <pair<int,int>> taskPriority;
     unordered_map<int,int> taskMapPriority;
     unordered_map<int,int> taskMapUser;

    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            int userid=tasks[i][0];
            int taskid=tasks[i][1];
            int priority=tasks[i][2];

            taskMapPriority[taskid]=priority;
            taskMapUser[taskid]=userid;
            taskPriority.insert({-priority,-taskid});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMapPriority[taskId]=priority;
        taskMapUser[taskId]=userId;
        taskPriority.insert({-priority,-taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority=taskMapPriority[taskId];
        taskPriority.erase({-oldPriority,-taskId});
        taskPriority.insert({-newPriority,-taskId});
        taskMapPriority[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        int oldPriority=taskMapPriority[taskId];
        taskPriority.erase({-oldPriority,-taskId});
        taskMapPriority.erase(taskId);
        taskMapUser.erase(taskId);
    }
    
    int execTop() {
        if(taskPriority.empty())return -1;
        int taskId=taskPriority.begin()->second;
        int userid=taskMapUser[-taskId];
        taskPriority.erase(taskPriority.begin());
        taskMapPriority.erase(taskId);
        taskMapUser.erase(taskId);

        return userid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */