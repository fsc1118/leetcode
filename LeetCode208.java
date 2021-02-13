import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

import java.util.*;
class Trie {
	Map<Character, Node> map;
	class Node {
		boolean isEnd;
		Node(char c){
			this.c = c;
			this.map = new HashMap<>();
		}
		char c;
		Map<Character, Node> map;
	}
    /** Initialize your data structure here. */
    public Trie() {
		map = new HashMap<>();
    }
    
    public void insert(String word) {
		int length = word.length() - 1;
		Map<Character, Node> currentMap = map;
		for (int i = 0; i <= length; i++){
			char c = word.charAt(i);
			if (!currentMap.containsKey(c)){
				currentMap.put(c, new Node(c));
			}
            if (i == length){
				currentMap.get(c).isEnd = true;
			}
			currentMap = currentMap.get(c).map;

		}
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
		int length = word.length() - 1;
		Map<Character, Node> currentMap = map;
		for (int i = 0; i <= length; i++){
			char c = word.charAt(i);
			if (currentMap.containsKey(c)){
				if (i == length)
					return currentMap.get(c).isEnd;
				currentMap =currentMap.get(c).map;
				
			}
			else
				return false;
		}
		return true;
		
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
		int length = prefix.length() - 1;
		Map<Character, Node> currentMap = map;
		for (int i = 0; i <= length; i++){
			char c = prefix.charAt(i);
			if (currentMap.containsKey(c))
				currentMap =currentMap.get(c).map;
			else
				return false;
		}
		return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */