class Solution:
    def __distance(self, index: int, target_character, target_string: str, string_length: int) -> int:
        pointer1 = index;
        pointer2 = index;
        while(1):
            if (pointer1 < 0):
                if (target_string[pointer2] == target_character):
                    return pointer2 - index;
                else:
                    pointer2 = pointer2 + 1
            elif (pointer2 >= string_length):
                if (target_string[pointer1] == target_character):
                    return index - pointer1;
                else:
                    pointer1 = pointer1 - 1
                
            elif (target_string[pointer1] == target_character):
                return index - pointer1;
            elif (target_string[pointer2] == target_character):
                return pointer2 - index;
            else:
                pointer1 = pointer1 - 1;
                pointer2 = pointer2 + 1;
            
    
    def shortestToChar(self, s: str, c: str) -> List[int]:
        returned_list = list()
        length = len(s)
        print(length)
        for i in range(0, length):
            returned_list.append(self.__distance(i, c, s, length))
        return returned_list