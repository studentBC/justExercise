class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr = (int*)calloc(length, sizeof(int));
        time = 0;
        len = length;
    }

    void set(int index, int val) {
        temp[index] = val;
        arr[index] = val;
    }

    int snap() {
        if (temp.size() == 0) {
            for (int i = 0; i < len; i++) temp[i] = arr[i];
        }
        data[time] = temp;
        temp.clear();
        time++;
        return time-1;
    }

    int get(int index, int snap_id) {
        if (data[snap_id].find(index) != data[snap_id].end()) {
            return data[snap_id][index];
        } else {
            for (int i = snap_id-1; i > -1; i--) {
                if (data[i].find(index) != data[i].end()) {
                    return data[i][index];
                }
            }
            return 0;
        }
    }
private:
    int* arr;
    int time, len;
    map<int,map<int,int>>data;
    map<int,int>temp;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
class SnapshotArray {
    vector<int> a;
    vector<vector<int>> snapshots;
    
public:
    SnapshotArray(int length) {
        a = vector<int>(length, 0);
    }
    
    void set(int index, int val) {
        a[index] = val;
    }
    
    int snap() {
        snapshots.push_back(a);
        return snapshots.size() - 1;
    }
    
    int get(int index, int snap_id) {
        return snapshots[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
