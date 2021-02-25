# @param {Integer} n
# @param {Integer} start
# @return {Integer}
def xor_operation(n, start)
    result = 0
    count = 0
    while count < n
        result = result ^ (start + count * 2)
        count = count + 1
       #puts(result)
    end
    
    return result
end