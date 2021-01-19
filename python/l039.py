class Solution(object):
    def combinationSum(self, candidates, target):
        def comb(numlist, target, endis, nowval, nowlist, resultlist):
            # resultlist is list of list, each list sum is [0, target]
            if target == 0:
                return resultlist
            for i in range(endis, len(numlist), 1):
                if target - numlist[i] > 0 :
                    nowfork = nowlist[:]
                    nowfork.append(numlist[i])
                    comb(numlist, target - numlist[i], i, nowval + numlist[i], nowfork, resultlist)
                if target - numlist[i] == 0:
                    nowfork = nowlist[:]
                    nowfork.append(numlist[i])
                    resultlist.append(nowfork)
            return resultlist
        candidates.sort()
        return comb(candidates, target, 0, 0, [], [])

a = Solution()
print(a.combinationSum([10,1,2,7,6,1,5], 8))
