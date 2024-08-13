# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
import queue
def hasPathSum(root,targetSum):
        if root == None:
            return False
        nodeq = queue.Queue()
        valq = queue.Queue()
        nodeq.put(root)
        valq.put(root.val)
        while not nodeq.empty():
            tempNode = nodeq.get()
            tempVal = valq.get()
            if tempNode.left == None and tempNode.right == None:
                if tempVal == targetSum:
                    return True
                continue
            if tempNode.left:
                nodeq.put(tempNode.left)
                valq.put(tempNode.left.val + tempVal)
            if tempNode.right:
                nodeq.put(tempNode.right)
                valq.put(tempNode.right.val + tempVal)
        return False
root = TreeNode(5)
root.left = TreeNode(4)
root.right = TreeNode(8)
root.left.left = TreeNode(11)
root.left.left.left = TreeNode(7)
root.left.left.right = TreeNode(2)
root.right.left = TreeNode(13)
root.right.right = TreeNode(4)
root.right.right.right = TreeNode(1)
targetSum = 22
hasPathSum(root,targetSum)