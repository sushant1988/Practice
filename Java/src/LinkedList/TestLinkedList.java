package LinkedList;

public class TestLinkedList {	 
	
	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.InsertAtFront(1);
		list.InsertAtFront(2);
		list.InsertAtRear(3);
		list.InsertAtRear(6);
		//list.DeleteElement(2);
		list.PrintList();
		//if(list.Find(4) != null) System.out.println("it worked");
		System.out.println("Mth Value = " + list.FindMthFromLastElemnt(4));
		list.ReverseIterativeLinkList();
		list.PrintList();
		list.PrintList(list.ReverseRecursiveLinkList(list.getHead()));
		
//		var lists = new LinkedList();
//		lists.add(1);
//		lists.addLast(3);
//		lists.addFirst(2);
//		System.out.println(lists);
//		
//		Stack<Integer> st = new Stack<Integer>();
//		st.add(1);
//		st.push(2);
//		st.push(3);
//		st.pop();
//		st.remove(0);
//		System.out.println(st);
	}
}
