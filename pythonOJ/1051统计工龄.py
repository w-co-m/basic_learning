from collections import Counter
n = int(input())
ages = list(map(int, input().split()))
age_count = Counter(ages)
for age in sorted(age_count.keys()):
    print(f"{age}:{age_count[age]}")
