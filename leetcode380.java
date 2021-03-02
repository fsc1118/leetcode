package leetcode;

import java.util.*;

class RandomizedSet {

    private Map<Integer, Integer> map = new HashMap<>();
    /* The first entry:value
    The second: index
    */
    private List<Integer> list = new ArrayList<>();
    private int size = 0;
    
    public RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (map.containsKey(val))
            return false;
        map.put(val, size); //size refers to the index it resides in the list
        size++;
        list.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!map.containsKey(val))
            return false;
        int index = map.get(val); //index of the removed value in the list
        int lastElement = list.get(size - 1); //last element in the list
        list.set(size - 1, val);
        list.set(index, lastElement); //swap the position
        map.put(lastElement, index); //update the index of the last element in the map
        map.remove(val);
        size--;
        list.remove(size); // remove the element
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random random = new Random();
        return list.get(random.nextInt(size));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */