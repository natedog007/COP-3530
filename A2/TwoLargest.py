"""
Two Largest
Nathan Boyden COP 3530
10/8/24
"""

print("How large of an array would you like?")
n = int(input())
a = [] 

for i in range(n):
    print("Enter the number you would like to be in the array.")
    ip = int(input())
    a.append(ip)


def TwoLargest():
    large_1 = 0
    large_2 = 0
    for i in range(0,n):
        if a[i] > large_1:
            large_2 = large_1
            large_1 = a[i]
        elif large_2 < a[i]:
            large_2 = a[i]
    print("Largest: " + str(large_1))
    print("Second Largest: " + str(large_2))

TwoLargest()