
class Node
    attr_accessor :val, :children
    def initialize(val)
        @val = val
        @children = []
    end
end


def postorder(root)
    a = Array.new

    iterate(root, a)
    
    return a
end

def iterate(root, a)
    if root.nil?
        return
    end
    for i in root.children
        iterate(i, a)
    end  
    a.push(root.val)
end