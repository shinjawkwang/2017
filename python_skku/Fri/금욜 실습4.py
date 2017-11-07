def print_reverse(num):
    if num//10<1:
        print(num)
    else:
        print(num%10, end="")
        print_reverse(num//10)
