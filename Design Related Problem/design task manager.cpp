class TaskManager {
public:
priority_queue<pair<int,int>>priority_task;//priority,taskId
unordered_map<int, int>task_owner;//taskId, userId
unordered_map<int, int>taskPriority;//task,prio
//every tasks store userId, taskId, priority
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task: tasks){
            add(task[0],task[1], task[2]);//add in map
        }
    }
    
    void add(int userId, int taskId, int priority) {
        priority_task.push({priority,taskId});//store in pq
        taskPriority[taskId]=priority;//store in taskpriority map
        task_owner[taskId]=userId;//store in task owner map
    }
    
    void edit(int taskId, int newPriority) {
        priority_task.push({newPriority,taskId});
        taskPriority[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        taskPriority[taskId]=-1;//make stale low priority
    }
    
    int execTop() {
        while(!priority_task.empty()){
            auto[priority,taskId]=priority_task.top();
            priority_task.pop();

            if(priority== taskPriority[taskId]){//fresh not stale
                taskPriority[taskId]=-1;
                return task_owner[taskId];
            }
        }
        return -1;
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
