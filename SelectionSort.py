"""
Selection Sort
Nathan Boyden COP 3530
10/7/24
"""
# I'm not sure if this sorting algorthim is suppose to be backwards but that's what the psuedocode showed :)

# Askes user for size, ensures answer in a number, and creates an empty array 
print("How large of an array would you like to sort?")
n = int(input())
a = [] 

# Loops through the empty array while user fills it
for i in range(n):
    print("Enter the number you would like to be in the array.")
    ip = int(input())
    a.append(ip)

# Prints unsorted array
print("UNSORTED")
print(a)

# Selection Sort method
def SelectionSort():
    # The (n-2) in the psueocode doesnt work so I put (n-1)
    for i in range(n-1):
        maxIndex = i
        for j in range((i+1),n):
            if a[j] > a[maxIndex]:
                maxIndex = j
        
        temp = a[i]
        a[i] = a[maxIndex]
        a[maxIndex] = temp
    
    print("SORTED")
    print(a)
            
    
    
    

SelectionSort()
