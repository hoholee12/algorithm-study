








#LIST is freedom
my_list = []
my_list = [1, 2, 3]
my_list = [1, "hello", 3.4]
for i in range(3):
    print(my_list[i], end = " ")   # to end with space instead of newline

my_list[1] = "test me"

for i in range(3):
    print(my_list[i], end = " ")


print("\n" + "=" * 50)


    

#TUPLE is immutable, can only be redeclared. cannot append
my_tuple = ()
my_tuple = ("french", "german", 1, 2, 3)
my_tuple = (1, 2, 3, 4, 5)
# normally can only append tuple(with more than one elem)
#but me can cast it to workaround
temp = ["henlo"]
my_tuple += tuple(temp)

for i in range(6):
    print(my_tuple[i], end = " ") 



print("\n" + "=" * 50)



    
# tuple cant do this
# also doubles as comment if not hmmigned to anything
printme = """
my_tuple[2] = "test me"

for i in range(5):
    print(my_tuple[i])
"""

print(printme)




print("\n" + "=" * 50)





#STRING is immutable but does have an index and can be appended
stringme = "test me"
stringme += " test"

print(stringme + " hmm" * 3) # "," is " " while "+" is ""
print(stringme[1:-1])



print("\n" + "=" * 50)



#SET is mutable but not indexed(still can be iterated by for loop, anything is iteratable)
#add() remove() update() is only used for set
my_set = {1, 2, 3}
#print(my_set[2])   impossible because set is unordered and does not have index

my_set.add(4)   #to add one
my_set.update([5, 6, 7, 8]) #to add a bunch, use list
print(my_set)

A = {1, 2, 3}
B = {2, 3, 4, 5}



print("\n" + "=" * 50)



#bitwise on set
print(A | B)    #1, 2, 3, 4, 5
print(A ^ B)    #1, 4, 5
print(A & B)    #2, 3
print(A - B)    #1





print("\n" + "=" * 50)





#DICTionary is same as set and unordered(not indexed)
#has a key,value pair
my_dict = {"test":"me", 2:"me"} # values can be duplicated
print(my_dict["test"])

del my_dict[2]  #this only works for dictionary. NOT sets. use remove() for sets.
my_dict["test"] = "me"
print(my_dict)

del my_dict # delete entire dict




print("\n" + "=" * 50)





#range
numbers = range(6)
print(list(numbers)) #0, 1, 2, 3, 4, 5
numbers = range(1, 6)
print(list(numbers))  #1, 2, 3, 4, 5
print(tuple(numbers))
print(set(numbers))

print(dict.fromkeys(numbers, "lol"))

#range can be reversed
numbers = range(5, -1, -1)  #top, bottom, add
print(list(numbers))    #5, 4, 3, 2, 1, 0





print("\n" + "=" * 50)





#conditional statements
num = -1
if (num > 0) == True:   #boolean works
    print("greater than 0")
elif (num == 0) == True:
    print("equals 0")
else:
    print("less than 0")





print("\n" + "=" * 50)




#loops
n = 100
sum = 0
i = 1
while i <= n:
    sum += i
    i += 1          #python doesnt have ++        
print(sum)

sum = 0
for val in range(101):
    sum += val
print(sum)

sum = 0
for val in list(range(101)):
    sum += val
print(sum)





print("\n" + "=" * 50)






#break, continue
for val in "lolwut":
    if val == "l":
        continue    #skip printing 'l'
    elif val == "w":
        break       #stop on 'w'
    print(val)

#pass: placeholder since python cant have empty body
for val in "hello":
    pass





print("\n" + "=" * 50)




#keep in mind: order not guaranteed neither on set nor dictionary
for val in my_set:
    print(val, end = " ")
    #my_set.remove(val)  #me cannot change any size during iteration
my_dict = {1:2, 2:3, 3:4}
for val in my_dict:
    print(val, end = " ")
    #del my_dict[val]   #me cannot change any size during iteration

for val in my_list:
    print(val, end = " ")
    my_list.remove(val) #however mutable and ordered ones work(like LIST)





print("\n" + "=" * 50)






#functions
def hello(hi, hello="tester"):      #keep in mind: dynamic type, and also default params
    print(hi, hello)

hello("hi")
hello("hi", "james")




print("\n" + "=" * 50)




def hi(*lol):   #phmmed as tuple for varargs
    print(type(lol))
    for i in lol:
        print(i)
        for j in i:
            print(j)

hi("steve", "harvey")
hi(["stevie", "wonders"])






print("\n" + "=" * 50)






#recursion
def factorial(x):
    if x == 1:
        return 1
    else:
        return x * factorial(x - 1)
print(factorial(6))





print("\n" + "=" * 50)






#lambda: shorter one-liner anonymous(?) version of a function
factolamb = lambda x: 1 if x == 1 else x * factolamb(x - 1)
print(factolamb(6))

print(6**2) #square
square = lambda x: x**2
print(square(6))

testlamb = lambda x: 1 if x == 1 else (2 if x == 2 else x)  #lambda cant have elif. use nested if else.
print(testlamb(3))





print("\n" + "=" * 50)






#map(func, iterable source vararg)  #does whatever func outputs
numbers = (1, 2, 3, 4)
result = map(factolamb, numbers)    #produces map object
result = list(result)   #change type so we can see them
                        #(JUST iterating map object wont do stuff)
print(result)
#use lambda with map
result = list(map(lambda x: x**2, numbers))
print(result)





print("\n" + "=" * 50)






#me can map a test ton more sources
numbers = {1:2, 2:3, 3:4, 4:5}
test = [3, 4, 5, 6]
result = list(map(lambda x, y, z: x + y + z, test, numbers.keys(), numbers.values()))
print(result)





print("\n" + "=" * 50)






#filter(func, iterable source) #func returns boolean for which element to pick only
result = list(filter(lambda x: True if x % 2 == 0 else False, result))  #only return even numbers
print(result)
#None is lambda x: x.
numbers = {True, False, True, False}
result = list(filter(None, numbers))    #ends at first False.
print(result)





print("\n" + "=" * 50)






# imports yolo.py
#it is imported only once(pragma once)
import yolo
import yolo
import yolo
import yolo
import yolo
#me can use importlib to reload
import importlib
importlib.reload(yolo)
#me can also list things that are in module
print(dir(yolo))
print(dir())    #list everything in current namespace





print("\n" + "=" * 50)






print(yolo.add(4, 5))
import math
print(math.log2(5))
from math import pi, e  #specific
from math import *      #or all
print(math.pi, pi, e)





print("\n" + "=" * 50)






#rename imports
import math as m
print(m.pi)

#python uses sys.path to search for modules
from sys import path        #is a list btw
path += ["test me"]
print(path)





print("\n" + "=" * 50)







#FILE IO(r: read, w: write, x: do not overwrite, a: append, t: textmode, b: binarymode, +: r+w)
try:
    f = open("tester.txt", "r+b")  #default: rt
    f.close()
except:
    with open("tester.txt", "w") as f:
        pass

    
#same as 'using' in c#; makes sure it is closed properly.
with open("tester.txt", "w", encoding = "utf-8") as f:
    f.write("test me hmmhole\n")
    f.write("lol\nlol\n\nlool")
with open("tester.txt", "rt", encoding = "utf-8") as f:
    print(f.read())
#or use try finally
try:
    f = open("tester.txt", "rt", encoding = "utf-8")
    print(f.read())
    #fseek, ftell
    f.seek(0)
    print(f.read(6))
    print(f.tell())

    #use for loop to loop by line
    f.seek(0)
    for i in f:
        print(i, end = "")
    print(f.tell())
    #or just readline
    f.seek(0)
    print(f.readline()) #returns single string
    my_list = f.readlines() # returns list of strings in the file
    print(my_list)
finally:
    f.close()




print("\n" + "=" * 50)



    

#exception handling(need to import sys)
import sys
test_list = [1, 0, 3, "test me"]

for i in test_list:
    try:
        r = 1 / i
    except:
        print(i)    #0(because zerodivision) and 'test me'(because type)
        print(sys.exc_info()[0])    





print("\n" + "=" * 50)





#class
class my_class:
    "this my class baby"    #describe features __doc__
    a = 10
    str = 0
    def __init__(self, *something):    #constructor
        self.str = "henlo"
        self.a = "tester"
    def func(self, a, b):
        print(self.str, self.a)
        print(a + b)

   

A = my_class()
A.func(10, 5)
print(A.a)  # all public
print(my_class.__doc__)






print("\n" + "=" * 50)






#how to iterate
my_list = [1, 2, 3, 4, "test me"]
my_iter = iter(my_list)
print(next(my_iter))
print(my_iter.__next__())   #same stuff
for i in my_iter:   #iterate rest of it
    print(i)
for i in my_list:   #or why not just use it directly
    print(i)

#iterator to return all odd nums until 100
class liter:
    num = 1
    def __iter__(self):
        self.num = 1
        return self
    def __next__(self):
        if self.num > 100:
            raise StopIteration
        
        num = self.num
        self.num += 2
        return num

my_iter = iter(liter())
for i in my_iter:
    print(i)

#yield
def generator():
    for i in range(100, 0, -1):
        yield i
    
for i in generator():
    print(i)


del sum #cleanup some conflicting names variables
def fibonacci(nums):
    x, y = 0, 1
    for _ in range(nums):
        x, y = y, x + y #does not change immediately. ex) x = y = 1, but y = x(still 0) + y = 1
        print(x, y)
        yield x

def square(nums):
    for i in nums:
        yield i**2;

print(sum(square(fibonacci(10))))


#operator overloading
class point:
    x = 0
    y = 0
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
    def __add__(self, other): 
        x = self.x + other.x
        y = self.y + other.y
        return point(x, y)
    def __sub__(self, other): 
        x = self.x - other.x
        y = self.y - other.y
        return point(x, y)
    def __mul__(self, other): 
        x = self.x * other.x
        y = self.y * other.y
        return point(x, y)
    def __pow__(self, other): 
        x = self.x ** other.x
        y = self.y ** other.y
        return point(x, y)
    def __truediv__(self, other):   #float div
        x = self.x / other.x
        y = self.y / other.y
        return point(x, y)
    def __floordiv__(self, other):   #integer div
        x = self.x // other.x
        y = self.y // other.y
        return point(x, y)
    def __mod__(self, other):   
        x = self.x % other.x
        y = self.y % other.y
        return point(x, y)
    def __lshift__(self, other):   
        x = self.x << other.x
        y = self.y << other.y
        return point(x, y)
    def __rshift__(self, other):
        x = self.x >> other.x
        y = self.y >> other.y
        return point(x, y)
    def __and__(self, other):
        x = self.x & other.x
        y = self.y & other.y
        return point(x, y)
    def __or__(self, other):
        x = self.x | other.x
        y = self.y | other.y
        return point(x, y)
    def __xor__(self, other):
        x = self.x ^ other.x
        y = self.y ^ other.y
        return point(x, y)
    def __invert__(self):       #bitwise NOT
        x = ~self.x
        y = ~self.y
        return point(x, y)

    #comparison operators
    def __lt__(self, other):
        self_mag = (self.x ** 2) + (self.y ** 2)
        other_mag = (other.x ** 2) + (other.y ** 2)
        return self_mag < other_mag
    def __le__(self, other):
        self_mag = (self.x ** 2) + (self.y ** 2)
        other_mag = (other.x ** 2) + (other.y ** 2)
        return self_mag <= other_mag
    def __eq__(self, other):
        self_mag = (self.x ** 2) + (self.y ** 2)
        other_mag = (other.x ** 2) + (other.y ** 2)
        return self_mag == other_mag
    def __ne__(self, other):
        self_mag = (self.x ** 2) + (self.y ** 2)
        other_mag = (other.x ** 2) + (other.y ** 2)
        return self_mag != other_mag
    def __gt__(self, other):
        self_mag = (self.x ** 2) + (self.y ** 2)
        other_mag = (other.x ** 2) + (other.y ** 2)
        return self_mag > other_mag
    def __ge__(self, other):
        self_mag = (self.x ** 2) + (self.y ** 2)
        other_mag = (other.x ** 2) + (other.y ** 2)
        return self_mag >= other_mag
