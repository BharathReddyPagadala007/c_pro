name = input("enter ur name:")
print(name)
print("hi ,"+ name+ " " +"how are u")

i = input("enter number: ")
print(i)

print("=====================================================")
num = input("Enter number:")
print(num)
name1 = input("Enter name: ")
print(name1)

# Printing type of input value
print ("type of number", type(num))
print ("type of name", type(name1))

print("=====================================================")

num = int(input("Enter number:"))
print(num)
name1 = int(input("Enter name: "))
print(name1)

# Printing type of input value
print ("type of number", type(num))
print ("type of name", type(name1))


print("=====================================================")

floatNum = float(input("Enter a num: "))
print(floatNum, "is of type", type(floatNum))



print("=====================================================")
print("taking multiple inputs")

x ,y = input("enter two numbers separated by space:").split()
print("first number :",x)
print("second number :",y)

"""
what does split() do?
https://www.geeksforgeeks.org/python/python-get-a-list-as-input-from-user/
"""
# did u get it
"""
input() function can be combined with split() to accept multiple elements in a single line and store them in a list. The split() method separates input based on spaces and returns a list.


"""
li = input("enter elements sepa ").split()
print("list :",li)
print("type of li:",type(li))


"""
input() collects the user input as a string.
.split() divides the string into parts wherever there is a space.
The result is stored as a list of strings.
"""

print("=====================================================")




print("=====================================================")
