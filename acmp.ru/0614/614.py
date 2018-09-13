s = input()
m = {}
def g(p, b):
    a = int(b==0)
    if((p,b) in m):
        return m[(p,b)]
    if(b):
        P = s.find(')', p+1)
        if(P!=-1):
            a+=g(P, b - 1)
    P = s.find('(', p+1)
    if(P!=-1):
        a+=g(P, b + 1)
    m[(p,b)] = a
    return a
print(g(-1,0))
