class Router {
public:
int maxSize;
 queue<string>q;
 unordered_map<int ,vector<int>>destTimeMap;//D-> {t1,t2,t3} time stamp
 unordered_map<string,vector<int>>packetStore;//key{s,d,t}
    Router(int memoryLimit) {
        maxSize= memoryLimit;
    }
    string makeKey(int S, int D, int T){
   return to_string(S) + "_"+ to_string(D) + "_"+ to_string(T);//joinig all
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key= makeKey(source, destination, timestamp);
        if(packetStore.find(key) != packetStore.end()){//if present in map priviously
            return false;
        }
        if(q.size() >= maxSize){
            forwardPacket();//means remove old packet
        }
        //add
        packetStore[key]= {source,destination, timestamp};//add new element as a key in queue
        q.push(key);
        destTimeMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetStore.empty()){
            return {};//if empty return empty arry
        }
        string key = q.front();//1st value
        q.pop();//remove old
        vector<int>packetDetails= packetStore[key];//{S,D,T}
        packetStore.erase(key);
        int D= packetDetails[1];//2nd number is destinattion
        destTimeMap[D].erase(destTimeMap[D].begin());//also delete from destmap which is front of the map
        return packetDetails;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        //we use binary search
        auto it= destTimeMap.find(destination);//first find
        if(it == destTimeMap.end() || it->second.empty()){//if not find and empty //  D -> {}
            return 0;
        }
        // vector<int>timeStamps= it->second;//{T!,T2, T3}
         int i=lower_bound(begin(it->second), end(it->second), startTime)- begin(it->second);
          int j= upper_bound(begin(it->second), end(it->second), endTime)- begin(it->second);
    return j-i;
        
    }
    
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */