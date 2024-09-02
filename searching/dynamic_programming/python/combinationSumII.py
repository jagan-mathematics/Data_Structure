def combinationSum2(candidates, target):
    candidates.sort()  # Sort to handle duplicates easily
    dp = [[] for _ in range(target + 1)]
    dp[0] = [[]]  # Base case: one way to make 0, which is the empty set

    for candidate in candidates:
        # Traverse backwards to prevent using the same element multiple times
        for t in range(target, candidate - 1, -1):
            for combination in dp[t - candidate]:
                new_combination = combination + [candidate]
                if new_combination not in dp[t]:
                    dp[t].append(new_combination)

    return dp[target]


# Example usage:
candidates = [10,4,2,7,6,2,5]
target = 8
print(combinationSum2(candidates, target))
