def f(n):
    return n**2-1


def rootsearch( f,a,b,dx):
    x1= a
    f1=f(a)
    x2=a+dx
    f2=f(x2)
    while f1 * f2 >= 0 :
        if x1 >= b : return None, None
        x1=x2
        f1=f2
        x2 = x1+ dx 
        f2=f(x2)
    else:
        return x1, x2

print( rootsearch(f,-2,2,0.1))