n=int(input("input the number:"))
m=n
rev=0
while m>0:
    rev*=10
    digit=m%10
    rev+=digit
    m=m//10
print("the sum of two numbers is {0}".format(n+rev))
