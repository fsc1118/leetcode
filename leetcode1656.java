class OrderedStream {
    int ptr;
    Map<Integer, String> map = new HashMap<>();
    public OrderedStream(int n) {
        ptr = 1;
    }
    
    public List<String> insert(int idKey, String value) {
        map.put(idKey, value);
        List<String> list = new LinkedList<>();
        while (map.containsKey(ptr)){
            list.add(map.get(ptr++));
        }
        return list;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */