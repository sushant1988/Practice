package Tree;

public class BinaryTreeNode<T> {
	private T data;
	private BinaryTreeNode<T> left;
	private BinaryTreeNode<T> right;
	
	public BinaryTreeNode(T value) { data = value;}
	public BinaryTreeNode<T> getLeft() { return left; }
	public void setLeft(BinaryTreeNode<T> left) { this.left = left; }
	public BinaryTreeNode<T> getRight() { return right;	}
	public void setRight(BinaryTreeNode<T> right) {	this.right = right;	}
	public T getData() { return data; }
}
