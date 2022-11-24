# Dhruv Tewari
# COE - 2
# Roll No - 2019UCO1624
# Computer Graphics

from matplotlib import pyplot as plt
import OpenGL.GL as opengl
import OpenGL.GLUT as openglut
import OpenGL.GLU as openglu

def bresenham(x1, y1, x2, y2):
    m_new  = 2*(y2 - y1)
    slope_error_new = m_new - (x2 - x1)
    y=y1
    x_coordinates = []
    y_coordinates = []
    for x in range(x1,x2+1):
        x_coordinates.append(x)
        y_coordinates.append(y)
        slope_error_new =slope_error_new + m_new
        if(slope_error_new>=0):
            y = y+1
            slope_error_new = slope_error_new - 2*(x2-x1)
    plt.plot(x_coordinates, y_coordinates, marker = "o", markersize = 1, markerfacecolor = "blue")
    plt.title('Generate Line Using Bresenham')
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

if __name__=='__main__':
   x1, y1 = 5,15
   x2, y2 = 100,30
   bresenham(x1, y1, x2, y2)
   exit()


openglut.glutInit()
openglut.glutInitDisplayMode(openglut.GLUT_SINGLE | openglut.GLUT_RGB)
openglut.glutInitWindowSize(700, 500)  # width, height
openglut.glutInitWindowPosition(100, 100)  # (x,y)
openglut.glutCreateWindow("Bresenham lines")
setup_window()
openglut.glutDisplayFunc(drawer_function)
openglut.glutMainLoop()