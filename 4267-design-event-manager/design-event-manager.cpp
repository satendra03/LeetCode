class EventManager {
public:
    EventManager(vector<vector<int>>& events) {
        data = events;
        sort(data.begin(), data.end());
        for (auto& e : data) {
            priority[e[1]].insert(e[0]); // priority[val] = {id1, id2...}
        }
    }

    void updatePriority(int eventId, int newPriority) {
        int priorityOfId = getPriorityById(eventId);
        priority[priorityOfId].erase(eventId);
        if(priority[priorityOfId].empty()) priority.erase(priorityOfId);
        priority[newPriority].insert(eventId);

        int left = 0, right = data.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid][0] == eventId) {
                data[mid][1] = newPriority; // Update the actual data
                break;
            }
            if (data[mid][0] > eventId) right = mid - 1;
            else left = mid + 1;
        }
    }

    int pollHighest() {
        if (priority.empty()) return -1;

        auto it = priority.rbegin();
        int highP = it->first;
        int eventId = *it->second.begin();

        priority[highP].erase(eventId);
        if (priority[highP].empty()) priority.erase(highP);

        return eventId;
    }

private:
    vector<vector<int>> data;
    map<int, set<int>> priority;
    // events[i] = [eventIdi, priority​​​​​​​i]

    int getPriorityById(int eventId) {
        int left = 0;
        int right = data.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid][0] == eventId)
                return data[mid][1];
            else if (data[mid][0] > eventId)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */