def longestConsecutive(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    hashmap = dict()
    result = 0
    for n in nums:
        if (n not in hashmap):
            left = hashmap[n - 1]  if n - 1 in hashmap else 0
            right = hashmap[n + 1] if n + 1 in hashmap else 0
            temp = left + right + 1
            result = max(result, temp)
            hashmap[n] = temp
            hashmap[n - left] = temp
            hashmap[n + right] = temp

    return result











