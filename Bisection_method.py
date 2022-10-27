from msilib.schema import Condition
from pickle import TRUE


def f(x):
    return x**3-1

def bisection( x0,x1,e) :
    condition = True
    ans=0
    while condition :
        x2=(x0+x1)/2
        if f(x0) * f(x1) < 0:
            x1 =x2
        else :
            x0 =x2
        condition = abs(f(x2)) > e
        ans=x2
    return ans
print(bisection(-1,2,0.1))