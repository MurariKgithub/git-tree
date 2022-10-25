class Node:
    def __init__(self,data=0) -> None:
        self.data = data
        self.left = None
        self.right =None
class BST:
    def __init__(self) -> None:
        self.root = None
    def create_node(self,data):
        new_node = Node(data)
        if(self.root==None):
            print("node is inserted at the start with data: ",data)
            self.root = new_node
        else:
            temp = self.root
            while(temp):
                if(temp.data==data):
                    return
                elif(temp.data<data and temp.right == None):
                    print("Node is inserted at the right with data: ",data)
                    temp.right = new_node
                    break
                elif(temp.data>data and temp.left ==None):
                    temp.left =new_node
                    print("Node is inserted at the left with data: ",data)
                    break
                elif(temp.data>data):
                    temp = temp.left
                else:
                    temp= temp.right
            
    def preorder(self,root):
        if(root==None):   
            
            return
        print(root.data,end=" ")
        self.preorder(root.left)
        self.preorder(root.right)
    def inorder(self,root):
        if(root==None):   
            return
        
        self.inorder(root.left)
        print(root.data,end=" ")
        self.inorder(root.right)
    def postorder(self,root):
        if(root==None):   
            return
        
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.data,end=" ")
obj = BST()
obj.create_node(10)
obj.create_node(7)
obj.create_node(5)
obj.create_node(8)
obj.create_node(20)
obj.create_node(13)
print("Pre order: ")
obj.preorder(obj.root)
print("\nIN order :")
obj.inorder(obj.root)
print("\nPost Order: ")
obj.postorder(obj.root)
        