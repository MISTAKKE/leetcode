class Solution:
    def reverseWords(self, s: str) -> str:
        return (s[::-1].split(' ')[::-1])




A = Solution()
print(A.reverseWords("dddf ffffffd"));
