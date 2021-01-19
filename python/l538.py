class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def getval(root):
            if root is None:
                return 0
            left = 0
            right = 0
            if root.left is not None:
                left = getval(root.left)
            if root.right is not None:
                right = getval(root.right)
            return left+right+root.val
        root.val = getval(root)
        return root
        



A = Solution()
print(A.reverseWords("dddf ffffffd"));
