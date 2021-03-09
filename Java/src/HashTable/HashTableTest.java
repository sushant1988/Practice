package HashTable;

import java.util.*;
import java.util.Map.Entry;

public class HashTableTest {

	/* Print Fruits In Sorted by Freq in decreasing order
	 * Time Complexity : O(NlogN)
	 * Space Complexity: O(N)
	 */
	public static void PrintElementsInSortedOrderByFreq(String[] fruits) {
		HashMap<String, Integer> hmap = new HashMap<String, Integer>();
		
		for(String s : fruits) {
			hmap.put(s, hmap.getOrDefault(s, 0) + 1);
		}
		
		//System.out.println(hmap.toString());
		List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String, Integer>>(hmap.entrySet());
		Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
			@Override
			public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
				return o2.getValue().compareTo(o1.getValue());
			}
		});
		
		for(Map.Entry<String, Integer> m: list) {
			System.out.println(m.getKey() + " " + m.getValue());
		}
	}
	
	/* Print Fruits In Sorted by Freq in decreasing order using other easy techniques
	 * Time Complexity : O(NlogN)
	 * Space Complexity: O(N)
	 */
	public static void PrintElementsInSortedOrderByFreqUsingStream(String[] fruits) {
		HashMap<String, Integer> hmap = new HashMap<String, Integer>();
		
		for(String s : fruits) {
			hmap.put(s, hmap.getOrDefault(s, 0) + 1);
		}
		
		hmap.entrySet()
		.stream()
		.sorted(Map.Entry.<String, Integer>comparingByValue().reversed())
		.forEach(System.out::println);
	}
	
	
	public static void main(String[] args) {
		String [] s = new String[] {"orange", "straberry", "grape", "pear", "orange", "apple", "pear", "grape", "pear"};
		PrintElementsInSortedOrderByFreq(s);
		PrintElementsInSortedOrderByFreqUsingStream(s);
	}

}
