'''
Extended Euclidian Algorithm 
Nathan Boyden COP 3530
10/7/24
'''

# Inputs 
print("First Number: ")
num1 = int(input())
print("Second Number")
num2 = int(input())

# Extended Euclidian Algorithm 

def EEA(a, b):
    s = 0
    old_s = 1
    t = 1
    old_t = 0
    old_r = a
    r = b
    
    while r != 0:
        q = (old_r // r)
        old_r,r = r,old_r - q*r
        # Changed from "-" to "+"
        old_s,s = s,old_s + q*s
        old_t,t = t,old_t - q*t
        
    print("GCD=" + str(old_r))
    print(str(t) + " " + str(s))
    print(str(old_r) + " " + str(r))
    return (old_t,old_s)

# Passing in inputs
EEA(num1, num2)
