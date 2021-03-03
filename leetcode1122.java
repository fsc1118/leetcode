package leetcode;

import java.util.*;

class leetcode1122 {
    Map<Integer, Set<Integer>> map = new HashMap<>();
    private void swap(int[] array, int position1, int position2){
        int temp = array[position1];
        array[position1] = array[position2];
        array[position2] = temp;
    }
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        for (int i = 0; i < arr1.length; i++){
            if (map.containsKey(arr1[i])){
                map.get(arr1[i]).add(i);
            } else{
                Set<Integer> set = new HashSet<>();
                set.add(i);
                map.put(arr1[i], set);
            }
        }
        //System.out.println(map.size());
        int size = 0;
        for (int i : arr2) {
            Iterator<Integer> iterator = map.get(i).iterator();
            while (iterator.hasNext()){
                int index = iterator.next();
                if (size == index){
                    size++;
                    continue;
                }
                swap(arr1, index, size);
                map.get(arr1[index]).remove(size);
                map.get(arr1[index]).add(index);
                //System.out.println(Arrays.toString(arr1));
                size++;
            }
        }
        Arrays.sort(arr1, size, arr1.length);
        return arr1;
    }
}