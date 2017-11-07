x=float(input("write x"))
y=float(input("write y"))
if x>0 and y>0:
    print("it is in first square")
elif x>0 and y<0:
    print("it is in forth square")
elif x<0 and y>0:
    print("it is in second square")
elif x<0 and y<0:
    print("it is in third square")
else:
    print("it is not on any square!")
