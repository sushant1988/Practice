package LinkedList;

public class LinkedList<T> {
	private ListNode<T> Head = null;
	private ListNode<T> Rear = null;
		
	public ListNode<T> getHead() { return Head; }
	public ListNode<T> getRear() { return Rear; }
	
	public void InsertAtFront(T value) {
		if (Head != null) {
			ListNode<T> temp = new ListNode<T>(value);
			temp.setNext(Head);
			Head = temp;
		} else {
			Head = new ListNode<T>(value);
			Rear = Head;
		}		
	}
	
	public void InsertAtRear(T value) {
		if (Head != null) {
			ListNode<T> temp = new ListNode<T>(value);
			Rear.setNext(temp);
			Rear = temp;
		} else {
			Head = new ListNode<T>(value);
			Rear = Head;
		}		
	}
	
	public ListNode<T> Find(T value) {
		ListNode<T> temp = Head;
		
		while(temp != null && !temp.getValue().equals(value)) {
			temp = temp.next();
		}
		
		return temp;
	}
	
	public boolean DeleteElement(T value) {
		if (Head != null) {
			if (Head.getValue().equals(value)) {
				Head = Head.next();
				return true;
			}
			
			ListNode<T> cur = Head;
			ListNode<T> prev = cur;
			while(cur != null) {
				if(cur.getValue().equals(value)) {
					if (cur == Rear) Rear = prev;
				 	prev.setNext(cur.next());
				}
				prev = cur;
				cur = cur.next();
			}
		}
		
		return false;
	}
	
	public void PrintList() {
		ListNode<T> temp = Head;
		System.out.print("[");
		while (temp != null) {
			System.out.print(temp.getValue().toString() + ", ");
			temp = temp.next();
		}
		System.out.println("]");
	}
	
	public void PrintList(ListNode<T> head) {
		ListNode<T> temp = head;
		System.out.print("[");
		while (temp != null) {
			System.out.print(temp.getValue().toString() + ", ");
			temp = temp.next();
		}
		System.out.println("]");
	}
	
	/* Mth to Last Element in LinkList PIE Page 50 
	 * Time Complexity: O(N)
	 * Space Complexity: O(1)
	 */
	public T FindMthFromLastElemnt(int M) {
		ListNode<T> p1 = Head;
		ListNode<T> p2 = Head;
		
		int c = 0;
		
		while(p1 != null) { 
			c++;
			p1 = p1.next();
			if (c == M) break;
		}
		
		if ( c < M) return null;
		while (p1 != null) {
			p1 = p1.next();
			p2 = p2.next();
		}
		
		return p2.getValue();	
	}
	
	/* Mth to Last Element in LinkList PIE Page 50 
	 * Time Complexity: O(N)
	 * Space Complexity: O(N) due to recursion
	 */
	public int GetKthFromLastRecursive(ListNode<T> head, int k, ListNode<T> result) {
		if (head == null)
			return 0;
		
		int i = GetKthFromLastRecursive(head.next(), k, result) + 1;
		
		if (i == k)
			result = head;
		
		return i;
	}
	
	/* Find Circular LinkList 
	 * Time Complexity: O(N)
	 * Space Complexity: O(1) Constant
	 */
	public boolean isCircularList() {
		if (Head != null) {
			ListNode<T> fast = Head.next();
			ListNode<T> slow = Head;
			
			while(fast != null && fast.next() != null) {
				if (slow == fast || fast.next() == slow)
					return true;
				
				fast = fast.next().next();
				slow = slow.next();
			}
		}
		
		return false;
	}
	
	/* Reverse Recursive LinkList */
	public ListNode<T> ReverseRecursiveLinkList(ListNode<T> head) {
		if(head.next() == null) {
			return head;
		}
		
		ListNode<T> newHead = ReverseRecursiveLinkList(head.next());
		
		head.next().setNext(head);
		head.setNext(null);
		
		return newHead;
	}
	
	/* Reverse LinkList Iterative
	 * Time Complexity = O(N)
	 */
	public void ReverseIterativeLinkList() {
		ListNode<T> cur = Head;
		ListNode<T> next = Head.next();
		ListNode<T> prev = null;
		
		while(next != null) {
			cur.setNext(prev);
			prev = cur;
			cur = next;
			next = next.next();
		}
		
		cur.setNext(prev);	
		Head = cur;
	}

	/* Add two LinkList In Recursive 
	 * 
	 */
	public int AddLinkList(ListNode<Integer> result, ListNode<Integer> l1, ListNode<Integer> l2) {
		
		if (l1.next() == null && l2.next() == null) {
			result = new ListNode<Integer>();
			int d = l1.getValue() + l2.getValue();
			result.setValue(d % 10);
			return d / 10;
		}
		
		int sum = AddLinkList(result, l1.next(), l2.next()) + l1.getValue() + l2.getValue();
		ListNode<Integer> temp = new ListNode<Integer>();
		temp.setNext(result);
		result = temp;
		result.setValue(sum % 10);
		return sum / 10;
	}
	
	/* Add two LinkList In Iterative with uneven size of list. 
	 * 
	 */

}


