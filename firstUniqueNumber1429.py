class FirstUnique:
    num = []
    count = dict()
    uniq = []
    def __init__(self, nums: List[int]):
        self.count.clear()
        self.num.clear()
        self.uniq.clear()
        for i in nums:
            if i in self.count.keys():
                self.count[i]+=1
            else:
                self.count[i] = 1
        for i in nums:
            if self.count[i] == 1:
                self.uniq.append(i)

    def showFirstUnique(self) -> int:
        if len(self.uniq):
            return self.uniq[0]
        else:
            return -1

    def add(self, value: int) -> None:
        self.num.append(value)
        if value in self.count.keys():
            self.count[value]+=1
            if self.count[value] == 2:
                self.uniq.remove(value)
        else:
            self.count[value] = 1
            self.uniq.append(value)
                


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
