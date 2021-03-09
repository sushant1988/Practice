package Sorting;

import java.util.Arrays;

public class BasicSorting {
	
	private enum SortType {BUBBLE_SORT, SELECTION_SORT, INSERTION_SORT, QUICK_SORT, MERGE_SORT};

	/*
	 * Swap method to swap contents of array.
	 */
	public static void swap(int [] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	/* Time Complexity = O(N^2)
	 * Space Complexity = O(1) Constant
	 * Bubble sort do two pass algorithm, and compare its neighbor every time and swap 
	 * if it is greater, hence with every pass the largest element is fixed at the end of the array.  
	 * Performance enhancement , if at any point if the array is sorted
	 * we don't need to go further and can break out early.
	 */
	public static void BubbleSort(int [] arr) {
		boolean sorted = true;
		for(int i=0; i<arr.length; i++) {
			sorted = true;
			for(int j=0; j < arr.length -1 -i; j++) {
				if (arr[j] > arr[j + 1]) {
					sorted = false;
					swap(arr, j+1, j);
				}
			}
			
			if (sorted)
				break;
		}		
	}
	
	/*
	 * Use Quick Select Partition algorithm
	 * Time Complexity = O(NlogN) it dividing the data in half makes it tree type structure ..
	 *  each level take n operation and height of tree is logN hence it is NlogN.
	 * Space Complexity = O(1)
	 */
	public static void QuickSort(int [] arr, int low, int high) {
		if (low <= high) {
			int pivI = Partition(arr, low, high);
			QuickSort(arr, low, pivI - 1);
			QuickSort(arr, pivI + 1, high);
		}
	}
	
	/*
	 * Partition the data by pivot and fix the position of pivot element.
	 * Time Complexity: O(N) operation; O(high-low) to be precise.
	 */
	private static int Partition(int[] arr, int low, int high) {
		
		int piv = arr[low]; // Pivot value is low , we can always try to find better ways to get pivot
		int wall = low;
		// I am keeping the wall as index on the left of wall -- all the elements are smaller or equal to pivot including wall  
		// as well.
		for(int i=low+1; i <= high; i++) {
			if (arr[i] <= piv) {
				wall++;
				swap(arr, i, wall);
			}
		}
		swap(arr, wall, low);
		return wall;
	}

	/*
	 * Time Complexity = O(NlogN);
	 * Space Complexity = O(1);
	 */
	public static void MergeSort(int [] arr, int low, int high) {
		if(low<high) {
			int mid = (low + high/2);
			MergeSort(arr, low, mid);
			MergeSort(arr, mid+1, high);
			Merge(arr, low, high, mid);
		}
	}	
	
	/*
	 * Merge array without using extra space or array.
	 */
	private static void Merge(int[] arr, int low, int high, int mid) {
		int start = low, start2 = mid + 1;	
		
		// check if the array is already sorted.
		if(arr[mid] <= arr[start2])
			return;
		
		while( start <= mid && start2 <= high) {
			if (arr[start] <= arr[start2])
				start++;
			else {
				int value = arr[start2];
				int index = start2;
				
				// shift all the elements by 1 to make space for element from right side.
				while(index != start) {
					arr[index] = arr[index-1];
					index--;
				}
				arr[index] = value; // add to correct position
				
				// update all the end pointers
				start++; // as start is maintaining all the sorted part
				start2++;	// as we have got the element from right side
				mid++;	// since we have moved all the elements by 1, hence our original mid element has been moved by 1.
			}
		}
	}

	/*
	 * Simulate that you are sorting while inserting to array, we do insertion from back of array instead of front. 
	 * Time Complexity: O(n^2) and best case it is O(N) if the array is already sorted.
	 * Space Complexity: O(1)
	 */
	public static void InsertionSort(int [] arr) {
		for(int i=1; i<arr.length; i++) {
			int value = arr[i];
			int j = i-1;
			// Keep replacing a[j+1} with a[j] as it is greater than value
			while(j >= 0 && arr[j] > value) {
				arr[j+1] = arr[j]; j--;
			}
			arr[j+1] = value;
		}
	}
	
	/*
	 * Selection Sort: looks for min-value in whole array and compare with corresponding element at index and swap if it smaller.
	 * Time Complexity: O(N^2)
	 * Space Complexity = O(1) Constant
	 */
	public static void SelectionSort(int [] arr) {
		for(int i=0; i<arr.length; i++) {
			int minI = i; // minimum index
			
			// looking for minimum value
			for(int j = i+1; j < arr.length; j++) {
				if (arr[minI] > arr[j])
					minI = j;
			}
			// if minimum index is not equal to starting index then swap.
			if (minI != i)
				swap(arr, minI, i);
		}
	}	

	public static void main(String[] args) {
		for (int i=0; i< SortType.values().length; i++) {
			int [] arr = new int[] {4, -1, 2, 9, 7, 1, 3, 10};
			switch (SortType.values()[i]) {
				case BUBBLE_SORT:
					BubbleSort(arr); break;
				case SELECTION_SORT:
					SelectionSort(arr); break;
				case INSERTION_SORT:
					InsertionSort(arr); break;
				case QUICK_SORT:
					QuickSort(arr, 0, arr.length-1); break;
				case MERGE_SORT:
					MergeSort(arr, 0, arr.length-1); break;
			}
			assert Arrays.equals(arr, new int[] {-1, 1, 2, 3, 4, 7, 9, 10});
		}
	}

}
