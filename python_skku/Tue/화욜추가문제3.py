print("Select a menu")
print("1. food 2. drink")
a=int(input())
if a==1:
    print("You have selected food. Which food?")
    print("1. Korean 2. American 3. Chinese")
    b=int(input())
    if b==1:
        print("You have selected Korean food. Which food?")
        print("1. Rice 2. Bulgogi")
        c=int(input())
        if c==1:
            print("Enjoy your Rice!")
        elif c==2:
            print("Enjay your Bulgogi!")
        else:
            print("oops. you have selected wrong number.")
    elif b==2:
        print ("You have selected American food. Which food?")
        print("1. Hamburger 2. Salad")
        d=int(input())
        if d==1:
            print("Enjoy your Hamburger!")
        elif d==2:
            print("Enjoy your Salad!")
        else:
            print("oops. you have selected wrong number.")
    elif b==3:
        print("You have selected Chinese food. Which food?")
        print("1. Noodle 2. Dimsum")
        e=int(input())
        if e==1:
            print("Enjoy your Noodle!")
        elif e==2:
            print("Enjoy your Dimsum!")
        else:
            print("oops. you have selected wrong number.")
elif a==2:
    print("you have selected drink. Which drink?")
    print("1. Cola 2. Orange juice 3. Water")
    f=int(input())
    if f==1:
        print("Enjoy your Cola!")
    elif f==2:
        print("Enjoy your Orange juice!")
    elif f==3:
        print("Enjoy your Water!")
    else:
        print("oops. you have selected wrong number.")
