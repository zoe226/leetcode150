def summaryRanges(nums):
    result = []
    len_nums = len(nums)
    if len_nums == 0:
        return result
    i = 0
    start = nums[i]
    end = start
    substr = []
    i = 1
    while i < len_nums:
        while i < len_nums and nums[i] == nums[i-1] + 1:
            end = nums[i]
            i += 1
        if start == end:
            substr = str(start)
        else:
            substr = str(start) + "->" + str(end)
        result.append(substr)
        if i < len_nums:
            start = nums[i]
            end = start
        else:
            break
        i += 1
    if start == nums[len_nums-1]:
        substr = str(start)
        result.append(substr)
    return result

nums = [0,1,2,4,5,7]
summaryRanges(nums)