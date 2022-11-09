
//The recursive formula for preorder traversal:：
preOrder(r)=print r->preOrder(r->left)->preOrder(r->right)
//Inorder traversal
inOrder(r)=inOrder(r->left)->print r->inOrder(r->right)
//postorder traversal
postOrder(r)=postOrder(r->left)->postOrder(r->right)->print r

// The travace of bianary tree
void preOrder(Node*root){if(root==null)return;print root preOrder(root->left);preOrder(root->right);}

void inOrder(Node*root){if(root==null)return;inOrder(root->left);print root inOrder(root->right);}

void postOrder(Node*root){if(root==null)return;postOrder(root->left);postOrder(root->right);print root}

// Search of BinarySearchTree
public class BinarySearchTree {
  private Node tree;

  public Node find(int data) {
    Node p = tree;
    while (p != null) {
      if (data < p.data)
        p = p.left;
      else if (data > p.data)
        p = p.right;
      else
        return p;
    }
    return null;
  }

  public static class Node {
    private int data;
    private Node left;
    private Node right;

    public Node(int data) {
      this.data = data;
    }
  }

}

  // Insert of BinarySearchTree
  public void insert(int data) {
    if (tree == null) {
      tree = new Node(data);
      return;
    }

    Node p = tree;
    while (p != null) {
      if (data > p.data) {
        if (p.right == null) {
          p.right = new Node(data);
          return;
        }
        p = p.right;
      } else { // data < p.data
        if (p.left == null) {
          p.left = new Node(data);
          return;
        }
        p = p.left;
      }
    }
  }

  // Delete of BinarySearchTree
public void delete(int data) {
  Node p = tree; // p points to the delete node
  Node pp = null; // pp points to the father node
  while (p != null && p.data != data) {
    pp = p;
    if (data > p.data) p = p.right;
    else p = p.left;
  }
  if (p == null) return; // Not found

  // To delete two nodes
  if (p.left != null && p.right != null) { 
    Node minP = p.right;
    Node minPP = p; 
    while (minP.left != null) {
      minPP = minP;
      minP = minP.left;
    }
    p.data = minP.data; // replace the data of minP
    p = minP; // delete minP
    pp = minPP;
  }

  // To delete leaf node
  Node child; // child node of p
  if (p.left != null) child = p.left;
  else if (p.right != null) child = p.right;
  else child = null;

  if (pp == null) tree = child; // to delete the root node
  else if (pp.left == p) pp.left = child;
  else pp.right = child;
}