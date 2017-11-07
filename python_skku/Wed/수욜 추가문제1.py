n=int(input("input the number:"))
reverse=0
m=n
while m>0:
    reverse*=10
    digit=m%10
    reverse+=digit
    m=m//10
print("The sum of two numbers is {0}".format(n+reverse))
