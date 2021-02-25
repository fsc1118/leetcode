class ListNode
    attr_accessor :val, :next
    def initialize(val = 0, _next = nil)
        @val = val
        @next = _next
    end
end
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} list1
# @param {Integer} a
# @param {Integer} b
# @param {ListNode} list2
# @return {ListNode}
def merge_in_between(list1, a, b, list2)
    
    first_position  = nil
    second_position = nil
    count = 1
    head = list1
    pointer = head;
    while true
        if count == a
            first_position = pointer
        end
        if count == b + 2
            second_position = pointer
            break
        end
        pointer = pointer.next
        count = count + 1
    end
    first_position.next = list2
    while true
        if (list2.next.nil?)
            break
        end
        list2 = list2.next
    end
    list2.next = second_position
    return head;
end