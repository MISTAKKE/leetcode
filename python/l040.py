class Solution:
    def combinationSum2(self, candidates, target):
        candidates.sort()
        def comb(candidates, target, result, start, nowlist):
            for i in range(start, len(candidates)):
                idxval = candidates[i]
                if target - idxval > 0:
                    newlist = nowlist[:]
                    newlist.append(idxval)
                    comb(candidates, target - idxval, result, i+1, newlist)
                if target - idxval ==0:
                    newlist = nowlist[:]
                    newlist.append(idxval)
                    if newlist not in result:
                        result.append(newlist)
            return result

        return comb(candidates, target, [], 0, [])

a = Solution()
print(a.combinationSum2([10,1,2,7,6,1,5], 8))
