# Dhruv Tewari
# COE - 2
# Roll No - 2019UCO1624
# Computer Graphics
from matplotlib import pyplot as plt
import OpenGL.GL as opengl
import OpenGL.GLUT as openglut
import OpenGL.GLU as openglu

def DDA(x0, y0, x1, y1):
    deltax = abs(x0 - x1)
    detay = abs(y0 - y1)
    steps = max(deltax, detay)
    xinc = deltax/steps
    yinc = detay/steps
    x = float(x0)
    y = float(y0)

    x_coordinates = []
    y_coordinates = []
    for i in range(steps):
        x_coordinates.append(x)
        y_coordinates.append(y)
        x = x + xinc
        y = y + yinc
    plt.plot(x_coordinates, y_coordinates, marker = "o", markersize = 1, markerfacecolor = "blue", color='green')
    plt.title('Generate Line Using DDA')
    plt.show()

def setup_window():
    opengl.glClearColor(0.9, 0.7, 0.6, 0.6)
    opengl.glColor3f(0.0, 0.0, 0.0)
    opengl.glPointSize(2.0)
    openglu.gluOrtho2D(0, 700, 0, 500)


def draw_axis():
    opengl.glClear(opengl.GL_COLOR_BUFFER_BIT)
    opengl.glBegin(opengl.GL_POINTS)
    for i in range(1, 450):
        opengl.glVertex2f(50, i + 20)
    for i in range(1, 650):
        opengl.glVertex2f(i + 20, 50)
    opengl.glEnd()
    opengl.glFlush()

def draw_dda_line(m, c, init_point, iters):
    opengl.glBegin(opengl.GL_POINTS)
    unit_x, unit_y = False, False
    if abs(m) < 1:
        unit_x = True
        diff_x = 1
        diff_y = m
    else:
        unit_y = True
        diff_x = 1 / m
        diff_y = 1

    def closest_int(n):
        return int(n + 0.5)

    opengl.glVertex2f(init_point[0], init_point[1])
    prev_x, prev_y = init_point
    for i in range(iters):
        next_x = prev_x + diff_x
        next_y = prev_y + diff_y
        if not unit_y:
            draw_y = closest_int(next_y)
            draw_x = next_x
        if not unit_x:
            draw_x = closest_int(next_x)
            draw_y = next_y
        opengl.glVertex2f(draw_x, draw_y)
        prev_x, prev_y = next_x, next_y
    opengl.glEnd()
    opengl.glFlush()

def drawer_function():
    draw_axis()
    slopes = [1, 3, 0.5] 
    c=1
    INIT_POINT = (160, 100) 
    ITERS = 300
    for slope in slopes:
        draw_dda_line(slope, c, INIT_POINT, ITERS)

if __name__ == "__main__":
    x0, y0 = 10, 20
    x1, y1 = 60, 50
    DDA(x0, y0, x1, y1)
    exit()



openglut.glutInit()
openglut.glutInitDisplayMode(openglut.GLUT_SINGLE | openglut.GLUT_RGB)
openglut.glutInitWindowSize(700, 500)  # width, height
openglut.glutInitWindowPosition(100, 100)  # (x,y)
openglut.glutCreateWindow("DDA lines")
setup_window()
openglut.glutDisplayFunc(drawer_function)
openglut.glutMainLoop()