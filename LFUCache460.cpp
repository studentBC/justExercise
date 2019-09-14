class LFUCache {
public:
    LFUCache(int capacity) {
        limit = capacity;
        th = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            cache[key][1]++;
            cache[key][2] = th;
            th++;
            return cache[key][0];
        }
    }
    
    void put(int key, int value) {
        if (limit == 0) return;
        if (cache.size() < limit) {
            if (cache.find(key) == cache.end()) {
                vector<int>temp;
                temp.emplace_back(value);
                temp.emplace_back(1);
                temp.emplace_back(th);
                th++;
                cache[key] = temp;
            } else {
                cache[key][0] = value;
                cache[key][1]++;
                cache[key][2] = th;
                th++;
            }
        } else {
            if (cache.find(key) != cache.end()) {
                cache[key][0] = value;
                cache[key][1]++;
                cache[key][2] = th;
                th++;
                return;
            }
            int least = INT_MAX, Th = INT_MAX, targetKey;
            //find the least frequently used
            for (auto it:cache) {
                if (it.second[1] < least) {
                    least = it.second[1];
                    Th = it.second[2];
                    targetKey = it.first;
                } else if (it.second[1] == least && Th > it.second[2]) {
                    Th = it.second[2];
                    targetKey = it.first;
                }
            }
            //cout << "go erase " << targetKey << endl;
            cache.erase(targetKey);
            vector<int>temp;
            temp.emplace_back(value);
            temp.emplace_back(1);
            temp.emplace_back(th);
            th++;
            cache[key] = temp; 
        }
    }
private:
    int limit, th;
    //0 : value 1 : count 2: th
    map<int,vector<int>>cache;
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//the fatest solution
static const auto ______ = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class LFUCache {
public:
    LFUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = lookupMap.find(key);
        if (it == lookupMap.end()) {
            return -1;
        }

        touch(it);

        return it->second.value;
    }

    void put(int key, int value) {
        if (capacity_ == 0) {
            return;
        }

        auto it = lookupMap.find(key);
        if (it == lookupMap.end()) {
            if (lookupMap.size() == capacity_) {
                auto leastSlot = freqList.front().slots.begin();
                lookupMap.erase(leastSlot->key);
                removeSlot(leastSlot);
            }

            FreqRecord record;
            record.freq = 0;

            auto freqRecordIt = freqList.insert(freqList.begin(), record);

            Slot slot;
            slot.key = key;

            auto slotIt = record.slots.insert(freqRecordIt->slots.end(), slot);
            slotIt->freqRecord = freqRecordIt;

            Record r;
            r.value = value;
            r.slot = slotIt;

            touch(lookupMap.insert(std::make_pair(key, r)).first);
        } else {
            it->second.value = value;
            touch(it);
        }

    }

private:
    int capacity_;

    struct FreqRecord;

    struct Slot {
        int key;
        std::list<FreqRecord>::iterator freqRecord;
    };

    using SlotList = std::list<Slot>;

    struct FreqRecord {
        int freq;
        SlotList slots;
    };

    using FreqList = std::list<FreqRecord>;
    FreqList freqList;

    struct Record {
        int value;
        SlotList::iterator slot;
    };

    // key -> record
    using Map = std::unordered_map<int, Record>;
    Map lookupMap;

    void touch(Map::iterator it) {
        Record& record = it->second;
        FreqList::iterator freqRecordIt = record.slot->freqRecord;
        int freq = freqRecordIt->freq + 1;
        FreqList::iterator nextFreqRecordIt = std::next(freqRecordIt);

        // Move slot
        if (nextFreqRecordIt == freqList.end() || nextFreqRecordIt->freq != freq) {
            FreqRecord record;
            record.freq = freq;
            freqList.insert(nextFreqRecordIt, record);
            nextFreqRecordIt = std::prev(nextFreqRecordIt);
        }

        Slot slot = *record.slot;
        slot.freqRecord = nextFreqRecordIt;
        SlotList& slotList = nextFreqRecordIt->slots;
        auto slotIt = slotList.insert(slotList.end(), slot);

        removeSlot(record.slot);

        record.slot = slotIt;
    }

    void removeSlot(SlotList::iterator slotIt) {
        auto freqRecordIt = slotIt->freqRecord;
        freqRecordIt->slots.erase(slotIt);
        if (freqRecordIt->slots.empty()) {
            freqList.erase(freqRecordIt);
        }
    }
};
