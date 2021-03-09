package Heap;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PriorityHeap<T extends Comparable<T>> {
	private ArrayList<T> items = new ArrayList<T>();
	private boolean isMinHeap = true;
	private int Size = 0;
	
	public PriorityHeap() {}
	public PriorityHeap(boolean isMinHeap) { this.isMinHeap = isMinHeap; }
	public PriorityHeap(T[] arr, boolean isMinHeap) { 
		this.isMinHeap = isMinHeap; 
		// add all items from arr to our heap array
		for(T item: arr) items.add(item);
		BuildHeap(); 
	}
	public PriorityHeap(T[] arr) { 
		// add all items from arr to our heap array
		for(T item: arr) items.add(item);
		BuildHeap(); 
	}
	
	/*
	 * Time Complexity: O(NlogN)
	 */
	private void BuildHeap() {
		Size = items.size(); // update size of heap
		// heapify from non-leaf nodes to all the way to top
		for (int i = Size / 2; i >= 0 ; i--) {
			Heapify(i);
		}
	}
	
	private int getLeft(int index) { return (index * 2) + 1 >= Size? -1: (index * 2) + 1; }
	private int getRight(int index) { return (index * 2) + 2 >= Size? -1: (index * 2) + 2; }
	private int getParent(int index) { return index < 0 ? -1: index/2; }
	
	/*
	 * Add Element in to Heap
	 * Time Complexity: log(N).
	 */
	public void Add(T item) {
		items.add(Size++, item);
		Heapify(0);
	}
	
	/*
	 * log(N) operation since we are always checking only one size of tree. either left or right child 
	 * if there is change.
	 */
	private void Heapify(int i) {
		int left = getLeft(i);
		int right = getRight(i);
		int parent = i;
		
		if (isMinHeap) {
			// Min Heap Compare with left and right child swap with min-child
			if (left != -1 && items.get(parent).compareTo(items.get(left)) > 0)
				parent = left;
			if (right != -1 && items.get(parent).compareTo(items.get(right)) > 0)
				parent = right;
		} else {
			// Max Heap Compare with left and right child swap with max-child
			if (left != -1 && items.get(parent).compareTo(items.get(left)) < 0)
				parent = left;
			if (right != -1 && items.get(parent).compareTo(items.get(right)) < 0)
				parent = right;
		}
		
		if (parent != i) {
			swap(i, parent);
			Heapify(parent);
		}
	}
	
	/*
	 * Swap element in array list.
	 */
	private void swap(int i, int parent) {
		T temp = items.get(i);
		items.set(i, items.get(parent));
		items.set(parent, temp);
	}
	
	/*
	 * Extract Top Element on basic of type of Heap (Min/Max).
	 * O(1) operation since it just swap first with last element and return last element
	 * and decrease size of heap.
	 */
	public T ExtractTop() {
		if (Size > 0) {
			swap(0, --Size);
			Heapify(0);
			return items.get(Size);
		}
		
		return null;
	}
	
	/*
	 * Get Top element.
	 */
	public T Peek() {
		if (Size > 0)
			return items.get(0);
		
		return null;
	}
	
	/*
	 * Sort Heap Take O(NlogN).
	 */
	public List<T> SortHeap(boolean isAsc) {
		List<T> result = new ArrayList<T>();
		int size = Size;
		// we are extrating min or max N time and each extract take logN operation.
		while(size > 0) {
			result.add(ExtractTop());
			size--;
		}
		
		if (isAsc) {
			if(!isMinHeap)
				Collections.reverse(result);
		} else {
			if(isMinHeap)
				Collections.reverse(result);
		}
		
		// Re arrange element into Heap after sorting
		BuildHeap();
		
		return result;
	}
}
