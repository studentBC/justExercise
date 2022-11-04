class TimeMap:

    def __init__(self):
        global tp
        tp = dict()

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in tp.keys():
            tp[key].append([timestamp, value])
        else:
            tp[key] = [[timestamp, value]]

    def get(self, key: str, timestamp: int) -> str:
        #print(key, timestamp)
        if key in tp.keys():
            left , right = 0, len(tp[key])-1
            while left<=right:
                mid = (left+right)//2
                if tp[key][mid][0] == timestamp:
                    return tp[key][mid][1]
                elif tp[key][mid][0] > timestamp:
                    right = mid-1
                else:
                    left= mid+1
                    
            #print(left, mid, right)
            if tp[key][right][0] > timestamp:
                return ""
            return tp[key][right][1]
                
        else:
            return ""
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
