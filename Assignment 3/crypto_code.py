# coding: utf-8

#importing diophantine library
from sympy.solvers.diophantine import diophantine
from sympy import symbols

x, y, z = symbols("x, y, z", integer=True)


def gcd(a, b): #defining the gcd function
    if (a == 0):
        return b

    return gcd(b % a, a)


def modInverse(a, m): #defining the mod-inverse function i.e a^(-1) = a^(p-2)
    g = gcd(a, m)
    if (g != 1):
        print("Inverse doesn't exist")

    else:
        return power(a, m - 2, m)


def power(x, y, m):#defining the pow function for calculating (x^y)mod m
    if (y == 0):
        return 1
    p = power(x, y // 2, m) % m
    p = (p * p) % m

    if (y % 2 == 0):
        return p
    else:
        return ((x * p) % m)


y1 = 11226815350263531814963336315 #rhs of eqn 1
y2 = 9190548667900274300830391220  #rhs of eqn 2
y3 = 4138652629655613570819000497  #rhs of eqn 3
p = 19807040628566084398385987581  #initializing the prime number p 

t1=y2*modInverse(y1,p)            #finding the g^2021

t2=y3*modInverse(y1,p)            #finding the g^9189


#from fermat's little therom , we get g^(p-1) mod p = 1 . This can be written as (g*g^(p-2))mod p =1. 

arr=diophantine(2021*x + 9189*y - 19807040628566084398385987579) #finding the (g^2021)^a * (g^9189)^b = g^(p-2)  . 
print(arr)


t2=modInverse(t2,p)      #since the b was found to be negative , we are firstly taking the inverse of g^9189

t1=power(t1,12518049677253765339779944149928,p) # finding the (g^2021)^a where a comes from above diophantine solution equation 

t2=power(t2,2753178647370685731375652273481,p)  # finding the (g^9189)^b where b comes from above diophantine solution equation 

t1=(t1*t2)%p      #finding the g^(p-2)

t1=modInverse(t1,p)  #finding the inverse of (g^(p-2)) to find the value of g.


g=t1
print("value of g is",g)


g = g ** 324   #using equation 1 to calculate the password
g = modInverse(g, p)
password = y1 * g
print("value of password is ",(password % p))  

