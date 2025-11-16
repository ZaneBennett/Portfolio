import java.io.*;
import java.util.*; 

public class Main
{
	public static void main(String[] args) 
	{
	    
	    boolean menu = true;
	    char value;
	    char value2;
	    Node up;
	    Tree theTree = new Tree();
	    System.out.println("Enter a word to convert to a binary search tree: ");
	    Console con = System.console();
	    String word = con.readLine();
	    System.out.print(" " + word + "\n\n");
	    for (int i = 0; i < word.length(); i++)
	    {
	        value = word.charAt(i);
	        theTree.insert(value);
	    }
	    
		System.out.println("----------BST Generated----------");
		
		while(menu)
		{
		    System.out.println("\nPlease choose an option:");
		    System.out.println("1. Display the Tree");
		    System.out.println("2. Display the leaves from right to left");
		    System.out.println("3. Display the complete 3-member subtrees of the BST");
		    System.out.println("4. Replace the letter of a node");
		    System.out.println("5. Validate the BST rules: Is this a valid BST?");
		    System.out.println("6. Exit");
		    System.out.println("Enter a choice:");
		    word = con.readLine();
		    int num = Integer.parseInt(word);
		    System.out.print(" " + num + "\n\n");
		    switch(num)
		    {
		        case 1:
		            theTree.displayTree();
		            break;
                case 2:
                    theTree.displayLeaves(theTree.root);
                    break;
                case 3:
                    theTree.displaySubTrees(theTree.root);
                    break;
                case 4:
                    System.out.println("Enter an existing letter in the BST: ");
		            value = (con.readLine()).charAt(0);
		            System.out.println(value);
		            up = (theTree.recFind(theTree.root, value));
	                System.out.println("\nEnter the replacing letter: ");
		            value2 = (con.readLine()).charAt(0);
		            System.out.println(value2);
                    up = (theTree.recFind(theTree.root, value));
	                up.iData = value2;
	                System.out.print("\nThe BT is successfully updated.\n");
	                theTree.displayTree();
                    break;
                case 5:
                    if(theTree.testBST(theTree.root, true))
	                {
	                    System.out.println("This is a valid BST.");
	                }
	                else
	                    System.out.println("ERROR! This is not a valid BST.");
                    break;
                case 6:
                    menu = false;
                    break;
		    }
		}
	}
}

class Node
   {
   public char iData;              // data item (key)
   public Node leftChild;         // this node's left child
   public Node rightChild;        // this node's right child

   public void displayNode()      // display ourself
      {
      System.out.print('{');
      System.out.print(iData);
      System.out.print("} ");
      }
   }
   
   class Tree
   {
   public Node root;             // first node of tree

// -------------------------------------------------------------
   public Tree()                  // constructor
      { root = null; }            // no nodes in tree yet
// -------------------------------------------------------------
   public Node find(char key)      // find node with given key
      {                           // (assumes non-empty tree)
      Node current = root;               // start at root
      while(current.iData != key)        // while no match,
         {
         if(key < current.iData)         // go left?
            current = current.leftChild;
         else                            // or go right?
            current = current.rightChild;
         if(current == null)             // if no child,
            return null;                 // didn't find it
         }
      return current;                    // found it
      }  // end find()
// Task IV:
    public Node recFind(Node node, char key)
    {
        if(node.iData == key)
            return node;
        
        if(node.iData > key)
        {
            node = recFind(node.leftChild, key);
        }
        else
        {
            node = recFind(node.rightChild, key);
        }
        
        if(node == null)
        {
            return null;
        }
        
        return node;
    }
// -------------------------------------------------------------
   public void insert(char id)
      {
      Node newNode = new Node();    // make new node
      newNode.iData = id;           // insert data
      if(root==null)                // no node in root
         root = newNode;
      else                          // root occupied
         {
         Node current = root;       // start at root
         Node parent;
         while(true)                // (exits internally)
            {
            parent = current;
            if(id < current.iData)  // go left?
               {
               current = current.leftChild;
               if(current == null)  // if end of the line,
                  {                 // insert on left
                  parent.leftChild = newNode;
                  return;
                  }
               }  // end if go left
            else                    // or go right?
               {
               current = current.rightChild;
               if(current == null)  // if end of the line
                  {                 // insert on right
                  parent.rightChild = newNode;
                  return;
                  }
               }  // end else go right
            }  // end while
         }  // end else not root
      }  // end insert()
// -------------------------------------------------------------
   public boolean delete(char key) // delete node with given key
      {                           // (assumes non-empty list)
      Node current = root;
      Node parent = root;
      boolean isLeftChild = true;

      while(current.iData != key)        // search for node
         {
         parent = current;
         if(key < current.iData)         // go left?
            {
            isLeftChild = true;
            current = current.leftChild;
            }
         else                            // or go right?
            {
            isLeftChild = false;
            current = current.rightChild;
            }
         if(current == null)             // end of the line,
            return false;                // didn't find it
         }  // end while
      // found node to delete

      // if no children, simply delete it
      if(current.leftChild==null && current.rightChild==null)
         {
         if(current == root)             // if root,
            root = null;                 // tree is empty
         else if(isLeftChild)
            parent.leftChild = null;     // disconnect
         else                            // from parent
            parent.rightChild = null;
         }

      // if no right child, replace with left subtree
      else if(current.rightChild==null)
         if(current == root)
            root = current.leftChild;
         else if(isLeftChild)
            parent.leftChild = current.leftChild;
         else
            parent.rightChild = current.leftChild;

      // if no left child, replace with right subtree
      else if(current.leftChild==null)
         if(current == root)
            root = current.rightChild;
         else if(isLeftChild)
            parent.leftChild = current.rightChild;
         else
            parent.rightChild = current.rightChild;

      else  // two children, so replace with inorder successor
         {
         // get successor of node to delete (current)
         Node successor = getSuccessor(current);

         // connect parent of current to successor instead
         if(current == root)
            root = successor;
         else if(isLeftChild)
            parent.leftChild = successor;
         else
            parent.rightChild = successor;

         // connect successor to current's left child
         successor.leftChild = current.leftChild;
         }  // end else two children
      // (successor cannot have a left child)
      return true;                                // success
      }  // end delete()
// -------------------------------------------------------------
   // returns node with next-highest value after delNode
   // goes to right child, then right child's left descendents
   private Node getSuccessor(Node delNode)
      {
      Node successorParent = delNode;
      Node successor = delNode;
      Node current = delNode.rightChild;   // go to right child
      while(current != null)               // until no more
         {                                 // left children,
         successorParent = successor;
         successor = current;
         current = current.leftChild;      // go to left child
         }
                                           // if successor not
      if(successor != delNode.rightChild)  // right child,
         {                                 // make connections
         successorParent.leftChild = successor.rightChild;
         successor.rightChild = delNode.rightChild;
         }
      return successor;
      }
// -------------------------------------------------------------
   public void traverse(int traverseType)
      {
      switch(traverseType)
         {
         case 1: System.out.print("\nPreorder traversal: ");
                 preOrder(root);
                 break;
         case 2: System.out.print("\nInorder traversal:  ");
                 inOrder(root);
                 break;
         case 3: System.out.print("\nPostorder traversal: ");
                 postOrder(root);
                 break;
         }
      System.out.println();
      }
// -------------------------------------------------------------
   private void preOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         System.out.print(localRoot.iData + " ");
         preOrder(localRoot.leftChild);
         preOrder(localRoot.rightChild);
         }
      }
// -------------------------------------------------------------
   private void inOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         inOrder(localRoot.leftChild);
         System.out.print(localRoot.iData + " ");
         inOrder(localRoot.rightChild);
         }
      }
// -------------------------------------------------------------
   private void postOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         postOrder(localRoot.leftChild);
         postOrder(localRoot.rightChild);
         System.out.print(localRoot.iData + " ");
         }
      }
// Task II:
    public void displayLeaves(Node node)
    {
        if(node != null)
         {
            displayLeaves(node.rightChild);
            displayLeaves(node.leftChild);
            if(node.rightChild == null && node.leftChild == null)
            {
                System.out.print(node.iData + " ");
            }
         }
    }
// Task V:
    public boolean testBST(Node node, boolean bool)
    {
        if(bool == false)
            return false;
        
        if(node != null)
         {
            if((node.rightChild != null && (node.rightChild).iData < node.iData) || (node.leftChild != null && (node.leftChild).iData > node.iData))
            {
                return false;
            }
            bool = testBST(node.rightChild, bool);
            bool = testBST(node.leftChild, bool);
         }
        return bool;
    }
// Task III:
    public void displaySubTrees(Node node)
      {
      if(node != null)
         {
            if(node.leftChild != null && node.rightChild != null)
            {
                System.out.println(node.iData + " " + node.leftChild.iData + " " + node.rightChild.iData);
            }
            displaySubTrees(node.leftChild);
            displaySubTrees(node.rightChild);
         }
      }
// -------------------------------------------------------------
   public void displayTree()
      {
      Stack globalStack = new Stack();
      globalStack.push(root);
      int nBlanks = 32;
      boolean isRowEmpty = false;
      System.out.println(
      "......................................................");
      while(isRowEmpty==false)
         {
         Stack localStack = new Stack();
         isRowEmpty = true;

         for(int j=0; j<nBlanks; j++)
            System.out.print(' ');

         while(globalStack.isEmpty()==false)
            {
            Node temp = (Node)globalStack.pop();
            if(temp != null)
               {
               System.out.print(temp.iData);
               localStack.push(temp.leftChild);
               localStack.push(temp.rightChild);

               if(temp.leftChild != null || temp.rightChild != null)
                  isRowEmpty = false;
               }
            else
               {
               System.out.print("--");
               localStack.push(null);
               localStack.push(null);
               }
            for(int j=0; j<nBlanks*2-2; j++)
               System.out.print(' ');
            }  // end while globalStack not empty
         System.out.println();
         nBlanks /= 2;
         while(localStack.isEmpty()==false)
            globalStack.push( localStack.pop() );
         }  // end while isRowEmpty is false
      System.out.println(
      "......................................................");
      }  // end displayTree()
// -------------------------------------------------------------
   }  // end class Tree