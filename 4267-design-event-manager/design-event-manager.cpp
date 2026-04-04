class EventManager {
public:
    EventManager(vector<vector<int>>& events) {
        for (auto& e : events) {
            int priority = e[1];
            int id = e[0];
            priorityToIds[priority].insert(id);
            idToPriority[id] = priority;
        }
    }

    void updatePriority(int id, int newPriority) {
        int oldPriority = idToPriority[id];

        auto &s = priorityToIds[oldPriority];
        s.erase(id);
        if (s.empty()) priorityToIds.erase(oldPriority);

        priorityToIds[newPriority].insert(id);
        idToPriority[id] = newPriority;
    }

    int pollHighest() {
        if (priorityToIds.empty()) return -1;

        auto it = priorityToIds.rbegin();
        int highP = it->first;
        int eventId = *it->second.begin();

        priorityToIds[highP].erase(eventId);
        if (priorityToIds[highP].empty()) priorityToIds.erase(highP);

        return eventId;
    }

private:
    unordered_map<int, int> idToPriority;
    map<int, set<int>> priorityToIds;
    // events[i] = [eventIdi, priority​​​​​​​i]
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */