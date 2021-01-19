class Solution:
    def PredictTheWinner(self, nums) -> bool:
        size = len(nums)
        fir = [[0 for i in range(size)] for j in range(size)]
        sec = [[0 for i in range(size)] for j in range(size)]
        for i in range(size):
            sec[i][i] = 0
            fir[i][i] = nums[i]
        for i in range(size -1):
            for j in range(size - i -1):
                x = j
                y = 1+i+j
                if(nums[y] + sec[x][y-1] > nums[x] + sec[x+1][y]):
                    fir[x][y] = nums[y] + sec[x][y-1]
                    sec[x][y] = fir[x][y-1]
                else:
                    fir[x][y] = nums[x] + sec[x+1][y]
                    sec[x][y] = fir[x+1][y]

        return fir[0][size-1] >= sec[0][size-1]




A = Solution()
li = [5, 100, 7]
print(A.PredictTheWinner(li));
