def containsNearbyDuplicate(nums, k):
    nums_hash = {}
    for i in range(0,len(nums)):
        if nums_hash.get(nums[i]) != None:
            if (i - nums_hash[nums[i]]) <= k:
                print("yes")
            else:
                nums_hash[nums[i]] = i
        else:
            nums_hash[nums[i]] = i            
    print("no")

nums = [1,2,1,1]
k = 1
containsNearbyDuplicate(nums,k)