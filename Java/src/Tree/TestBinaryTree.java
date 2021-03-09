package Tree;

import Tree.BinarySearchTree.PrintType;

public class TestBinaryTree {

	public static void main(String[] args) throws Exception {

		BinarySearchTree<Integer> bt = new BinarySearchTree<Integer>();
		bt.Add(5, true);
		bt.Add(3, true);
		bt.Add(2, true);
		bt.Add(9, true);
		bt.Add(7, true);
		bt.PrintTree(PrintType.LEVELWISE);
	}
}
