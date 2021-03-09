package Tree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BinarySearchTree <T extends Comparable<T>> {
	BinaryTreeNode<T> root = null;
	
	public enum PrintType {
		LEVELWISE, INORDER, POSTORDER, PREORDER, INORDER_ITR, POSTORDER_ITR, PREORDER_ITR;
	}
	
	public void Add(T value, boolean recursive) {
		if(root == null) {
			root = new BinaryTreeNode<T>(value);
			return;
		} else {
			if (recursive)
				AddRecursive(root, value);
			else 
				AddIterative(root, value);
		}
	}
	
	private BinaryTreeNode<T> AddRecursive(BinaryTreeNode<T> rootNode, T value) {
		if (rootNode == null)
			return new BinaryTreeNode<T>(value);
		
		if (rootNode.getData().compareTo(value) < 0) {
			 rootNode.setRight(AddRecursive(rootNode.getRight(), value));
		} else {
			rootNode.setLeft(AddRecursive(rootNode.getLeft(), value));
		}
		
		return rootNode;
	}
	
	
	private void AddIterative(BinaryTreeNode<T> rootNode, T value) {
		BinaryTreeNode<T> temp = rootNode;
		
		while(temp.getLeft() != null && temp.getRight() != null) {
			if (temp.getData().compareTo(value) < 0) 
				temp = temp.getRight();
			else 
				temp = temp.getLeft();
		}
		
		if (temp.getData().compareTo(value) < 0) 
			temp.setRight(new BinaryTreeNode<T>(value));
		else 
			temp.setLeft(new BinaryTreeNode<T>(value));	
	}
	
	public boolean FindElement(T value) {
		BinaryTreeNode<T> temp = root;
		
		while(temp.getLeft() != null && temp.getRight() != null) {
			if (temp.getData().compareTo(value) == 0) 
				return true;
			else if (temp.getData().compareTo(value) < 0) 
				temp = temp.getRight();
			else 
				temp = temp.getLeft();
		}
		
		return false;
	}
	
	public void PrintTree(PrintType p) throws Exception {
		switch(p) {
			case INORDER: PrintInOrderRecur(root); break;
			case LEVELWISE: PrintLevelWise(root); break;
			case PREORDER: PrintPreOrder(root); break;
			case POSTORDER: PrintPostOrder(root); break;
			default: throw new Exception("Print Type Not Supported");
		}
	}

	private void PrintPostOrder(BinaryTreeNode<T> rootNode) {
		if (rootNode == null) return;
		PrintInOrderRecur(rootNode.getLeft());
		PrintInOrderRecur(rootNode.getRight());
		System.out.println(rootNode.getData());
	}

	private void PrintLevelWise(BinaryTreeNode<T> rootNode) {
		Queue<BinaryTreeNode<T>> q = new LinkedList<BinaryTreeNode<T>>();
		q.add(rootNode);
		BinaryTreeNode<T> temp;
		while (!q.isEmpty()) {
			temp = q.poll();
			System.out.println(temp.getData());
			if (temp.getLeft() != null) q.add(temp.getLeft());
			if (temp.getRight() != null) q.add(temp.getRight());
		}
		 
	}

	private void PrintInOrderRecur(BinaryTreeNode<T> rootNode) {
		if (rootNode == null) return;
		PrintInOrderRecur(rootNode.getLeft());
		System.out.println(rootNode.getData());
		PrintInOrderRecur(rootNode.getRight());	
	}
	
	private void PrintPreOrder(BinaryTreeNode<T> rootNode) {
		if (rootNode == null) return;
		System.out.println(rootNode.getData());
		PrintInOrderRecur(rootNode.getLeft());
		PrintInOrderRecur(rootNode.getRight());	
	}
	
//	public T FindSuccessor(T value) {
//		Stack<BinaryTreeNode<T>> st = new Stack<BinaryTreeNode<T>>();
//		BinaryTreeNode<T> temp = root;
//		while(temp != null && temp.getData().compareTo(value) == 0) {
//			if (temp.getData().compareTo(value) < 0)
//				temp = temp.getRight();
//			else temp = temp.getLeft();
//		}
//		
//	}
//	
//	public T FindPredecessor(T value) {
//		
//	}
//	
//	public String Serialize() {
//		
//	}
//	
//	public BinaryTreeNode<T> Deserialize(String s) {
//		
//	}
}
