def draw_triangle(length):
    for i in range(1, length+1):
        for j in range(length-i, -1, -1):
            print(end=" ")
        for k in range(1, i+1):
            print("*", end=" ")
        print("")
draw_triangle(5)
