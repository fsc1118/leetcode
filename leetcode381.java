package leetcode;

import java.util.*;

class RandomizedCollection {

    private Map<Integer, Integer> map = new HashMap<>();
    private List<Integer> list = new ArrayList<>();
    private Map<Integer, Set<Integer>> position = new HashMap<>();
    private int size = 0;
    /** Initialize your data structure here. */
    public RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        list.add(val);
        size++;
        if (map.containsKey(val) && map.get(val) != 0){
            map.put(val, map.get(val) + 1);
            position.get(val).add(size - 1);
            return false;
        }      
        map.put(val, 1);
        Set <Integer> newList = new HashSet<>();
        newList.add(size - 1);
        position.put(val, newList);
        //System.out.println(list);
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!map.containsKey(val) || map.get(val) == 0)
            return false;
        map.put(val, map.get(val) - 1);
        int index = position.get(val).iterator().next();
       //System.out.println("Index: "+index);
        position.get(val).remove(index);
        int lastElement = list.get(size - 1);
       
        list.set(size - 1, val);
        list.set(index, lastElement); //System.out.println("before: "+list);
        position.get(lastElement).remove(size - 1);
        position.get(lastElement).add(index);
        //System.out.println(lastElement+" "+position.get(lastElement));
        size--;
        list.remove(size);
        //System.out.println("after："+list);
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        //System.out.println(size);
        return  list.get(new Random().nextInt(size));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */