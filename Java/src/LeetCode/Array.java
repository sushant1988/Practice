package LeetCode;

import java.util.ArrayList;

public class Array {

	public static void main(String[] args) {
		int [] Arr = new int[]{3, 1, 6, 7, 10};
		ArrayList<Integer> a = new ArrayList<Integer>();
		for(int i = 0; i< Arr.length; i++ )
		{
			a.add(getValue(Arr, i));
		}
		
		System.out.println(a.toString());

	}

	private static Integer getValue(int[] arr, int i) {
		int index = i + 1;
		
		while(index != i) {
			if(index >= arr.length)
				index = 0;
			if( arr[index] > arr[i])
				return arr[index];
			
			index++;
		}
		
		return -1;
	}
}
