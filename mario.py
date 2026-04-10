

from cs50 import get_int as get


x =  get ("Height: ")

for i in range(x):
    for j in range(x - i - 1):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")


    print()
    