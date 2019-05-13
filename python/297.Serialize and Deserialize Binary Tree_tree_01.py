class Codec:
    def preorder(self, root):
        if not root:
            return ['#']
        
        return [str(root.val)] + self.preorder(root.left) + self.preorder(root.right)

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        return ' '.join(self.preorder(root))

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        return self.helper(data.split(), TreeNode(0))
    
    def helper(self, data, index):
        if data[index.val] == '#':
            index.val += 1
            return None
        node = TreeNode(data[index.val])
        index.val += 1
        node.left = self.helper(data, index)
        node.right = self.helper(data, index)
        return node