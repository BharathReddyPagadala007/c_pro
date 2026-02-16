#====================================================

# using a loop

a =[]
print("type of a :",type(a))

n = int(input("enter the number of eleents :"))



for i in range(n):
    element = input(f"eneter element {i+1}: ")
    a.append(element)
print("list : ",a)


"""
for i in range(n):
    element = int(input(f"eneter element {i+1}: "))
    a.append(element)
print("list : ",a)


for i in range(n):
    element = float(input(f"eneter element {i+1}: "))
    a.append(element)
print("list : ",a)
"""
                       
"""
 https://www.geeksforgeeks.org/python/python-get-a-list-as-input-from-user/
"""


#====================================================

# map()

"""
When your list contains numbers, you can combine split() with map() to automatically convert input to integers (or floats).
map(int, ...) applies int() to every element of the list returned by split().
Wrapping it with list() converts the map object into a proper list of integers.

"""


li = list( map(int, input("Enter numbers separated by space: ").split()) )

print("List:", li)
print("list li[2]",li[2])




#============================================================

n = int(input("Enter the number of elements: "))
#a = [input(f"Enter element {i+1}: ") for i in range(n)]
a = [int(input(f"Enter element {i+1}: ")) for i in range(n)]

print("List:", a)
"""
   a = [int(input(f"Enter element {i+1}: ") for i in range(n))]
TypeError: int() argument must be a string, a bytes-like object or a real number, not 'generator'
"""



#============================================================




li = [x.split(",") for x in input("Enter nested list (use commas and semicolons): ").split(";")]
print("Nested List:", li)

"""
Enter nested list (use commas and semicolons): 1,2,3;4,5;6,7,8
Nested List: [['1', '2', '3'], ['4', '5'], ['6', '7', '8']]

"""






#============================================================
