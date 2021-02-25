# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num)
def guess(num)

end


def guessNumber(n)
    min = 1
    max = n
    
    while true
        mid = (1 + n) / 2
        res = guess(mid)
        if res == 0
            return mid
        elsif res == 1
            min = mid + 1
        else
            max = mid - 1
        end
    end
end