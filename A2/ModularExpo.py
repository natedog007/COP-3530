'''
Modular Exponentiation (ME) 
Nathan Boyden COP 3530
10/14/24
'''

# Inputs for base(a), exponent(k), and mod(n).
a = int(input("a: "))
k = int(input("k: "))
n = int(input("n: "))   


def BinaryK(k):
    K = []  
    temp = k
    i = 0
    while temp > 0:
        K.append(temp % 2)
        temp = temp // 2
    return K
    
    
def ModularExpo(a, K, n):
    if n == 1:
        return 0
    b = 0
    A = a 
    if K[0] == 1: 
        b = a
    
    for i in range(1, len(K)):
        A = (A * A) % n
        if K[i] == 1: 
            b = (A * b) % n 
        return b


K = BinaryK(k)

r = ModularExpo(a,K,n)

print(f"{a}^{k} mod {n} = {r}")