import glob
import os


if not os.path.exists("./a"):
    print("please compile the compiler by running `make`")
    exit()

try:
    x = int(input("1. Errors\n2. Syntax\nchoose[1:2]: "))
    if x != 1 and x != 2:
        raise Exception
except Exception as a:
    print(a)
    exit()


if x == 1:
    tmp = glob.glob("./examples/errors/*.vr")
elif x == 2:
    tmp = glob.glob("./examples/*.vr")


for i in tmp:
    os.system(f"./a {i}")
