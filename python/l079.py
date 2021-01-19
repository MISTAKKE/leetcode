# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def recursion(root, result):
            if root is None:
                return
            recursion(root.left, result)
            result.append(root.val)
            recursion(root.right, result)
            return result
        return recursion(root, [])

    def inorderTraversal2(self, root):
        s = []
        cur = root
        result = []
        while len(s)!=0 or cur is not None:
            if cur is None:
                cur = s.pop()
            else:
                while cur.left is not None:
                    s.append(cur)
                    cur = cur.left
            result.append(cur.val)
            cur = cur.right
        return result


t2 = TreeNode(2)
t1 = TreeNode(1)
t3 = TreeNode(3)
t2.left = t1
t2.right = t3

a = Solution()
print(a.inorderTraversal2(t2))

