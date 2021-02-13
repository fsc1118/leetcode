/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         int add = 0;
         ListNode firstNode = new ListNode();
         ListNode pointer1 = firstNode;
         ListNode pointer2=null;
         boolean a;
         while ((a = (l1!= null)) && l2 != null) {
             ListNode result = new ListNode();
             pointer2 = result;
             pointer1.next = pointer2;
             pointer1 = pointer2;
             int value = l1.val + l2.val + add;
             if (value <= 9) {
                 result.val = value;
                 add = 0;
             } else {
                 result.val = value - 10;
                 add = 1;
             }
             l1 = l1.next;
             l2 = l2.next;
         }
         if (l2 == null && l1 == null && add ==1) {
                 ListNode result = new ListNode(1);
                 pointer1.next = result;
                 return firstNode.next;
        }
         if (!a) {
            
             while (l2 != null) {
                 int i = l2.val+add;
                 if (i >9){
                     i = i - 10;
                     add = 1;
                 } else{
                     add = 0;
                 }
                 ListNode result = new ListNode(i);
                 pointer2 = result;
                 pointer1.next = pointer2;
                 pointer1 = pointer2;
                 l2 = l2.next;
             }
             if (add == 1){
                 ListNode result = new ListNode(1);
                 pointer2.next = result;
             }
         } else {
             while (l1 != null) {
                 int i = l1.val+add;
                // System.out.println(i);
                 if (i >9){
                     i = i - 10;
                     add = 1;
                 } else{
                     add = 0;
                 }
                 ListNode result = new ListNode(i);
                 pointer2 = result;
                 pointer1.next = pointer2;
                 pointer1 = pointer2;
                 l1 = l1.next;
             }
             if (add == 1){
                 ListNode result = new ListNode(1);
                 pointer2.next = result;
             }
         }
         return firstNode.next;
     }
 }