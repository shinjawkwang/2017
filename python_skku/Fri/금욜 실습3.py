def list_average(scores):
    total=0
    for i in range(len(scores)):
        total+=scores[i]
    return total/len(scores)

print(list_average([10, 20, 30, 45]))
