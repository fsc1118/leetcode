def max_product(nums)
    max = -1
    second_max = -1
    for value in nums do
       # puts(second_max)
        if value > max
            second_max = max
            max = value
        elsif value > second_max and value <= max
           # puts(value)
            second_max = value
        end
    end
    return (max - 1) * (second_max - 1)
end