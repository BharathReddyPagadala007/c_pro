import sys
def get_list():
    return list(map(int,sys.stdin.readline().strip().split()))

arr = get_list()

#reads int from a single line and stores ina  list

print(arr)
print(type(arr))

