package Heap;

import java.util.Arrays;

public class TestHeap {

	public static void main(String[] args) {
		PriorityHeap<Integer> ph = new PriorityHeap<Integer>();
		ph.Add(5);
		ph.Add(2);
		ph.Add(9);
		assert ph.ExtractTop() == 2;
		ph.Add(1);
		assert ph.Peek() == 1;
		assert ph.SortHeap(false).equals(Arrays.asList(9, 5, 1));
		assert ph.ExtractTop() == 1;
		
		PriorityHeap<Integer> phMax = new PriorityHeap<Integer>(new Integer [] {3, 6, 1, 4, 9, 7}, false);
		assert phMax.ExtractTop() == 9;
		assert phMax.Peek() == 7;
		assert phMax.SortHeap(true).equals(Arrays.asList(1, 3, 4, 6, 7));
		assert phMax.ExtractTop() == 9;
	}

}
