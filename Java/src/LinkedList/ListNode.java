package LinkedList;

public class ListNode<T> {
	private T data;
	private ListNode<T> next;
	
	public ListNode(T value) { this.data = value; this.next = null;}
	public ListNode() {}
	public ListNode<T> next() { return next; }
	public void setNext(ListNode<T> elem) { next = elem; }
	public void setValue(T value) { data = value; }
	public T getValue() { return data; }
}