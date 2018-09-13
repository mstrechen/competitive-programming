import turtle

delta = 1e-1

SIZE = 1e2

def draw(vx,vy,ux,uy, x, y,t):
    ux+=vx
    uy+=vy
    turtle.pd()
    x_1 = x
    y_1 = y;
    while(t>0):
        x+=ux*delta
        y+=uy*delta
        uy-=delta*10
        turtle.goto(x*SIZE,y*SIZE)
        t-=delta
    turtle.pu()
    turtle.goto(x_1,y_1)

draw(1,1,1,1,0,0,2)
