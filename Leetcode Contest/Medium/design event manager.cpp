class EventManager {
private: 
   unordered_map<int,int>mp;//id->prio
   priority_queue<pair<int,int>>pq;//prio, -id
public:
    EventManager(vector<vector<int>>& events) {
        for(auto& e: events){
            int id = e[0];
            int prio = e[1];
            mp[id]= prio;
            pq.push({prio,-id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(mp.find(eventId) == mp.end()) return;//not find the id
        mp[eventId]= newPriority;//update the value in map
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
           
                auto[prio,negId]= pq.top();
                int id = -negId;//original
                if(mp.count(id) && mp[id] == prio){//if mp latest value == top prio
                  pq.pop();
                  mp.erase(id);
                  return id;
                }
                pq.pop();//invalid prio/id
            
        }
        return -1;
    }
};