# Dhruv Tewari
# COE - 2
# Roll No - 2019UCO1624
# Computer Graphics

from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
def init():
   glClearColor(0.0, 0.0, 0.0, 1.0)
   glMatrixMode(GL_PROJECTION)
   glLoadIdentity()
   gluOrtho2D(-250, 250, -250, 250)
def getPlotPoints(x_centre, y_centre, x, y):
   glVertex2f(x_centre - x, y_centre + y)
   glVertex2f(x_centre + x, y_centre - y)
   glVertex2f(x_centre - x, y_centre - y)
   glVertex2f(x_centre + x, y_centre + y)
def drawHyperbolaMidpoint(x_centre, y_centre, a, b):
    x=a
    y=0
    p = b*b*(a+0.5)*(a+0.5)-a*a-a*a*b*b
    glClear(GL_COLOR_BUFFER_BIT)
    glColor3f(1.0, 0.0, 0.0)
    glPointSize(2.0)
    glBegin(GL_POINTS)
    getPlotPoints(x_centre, y_centre, x, y)
    while y <= (b*b)*(x/(a*a)):
        if p > 0:
            p = p - (a**2)*(2 * y + 3)
        else:
            x += 1
            p = p - (a**2)*(2 * y + 3) + 2*(b*b)*x
        y+=1
        getPlotPoints(x_centre, y_centre, x, y)
    p = b*b*(x+1)*(x+1) - a*a*(y+0.5)*(y+0.5) - a*a*b*b
    glColor3f(0.0, 1.0, 0.0)
    for i in range(100):
        if p <= 0: 
            y += 1
            p = p + (b**2)*(2*x+3) - 2*(a**2)*y
        else:
            p = p + (b**2)*(2*x+3)
        x+=1
        getPlotPoints(x_centre, y_centre, x, y)
    glEnd()
    glFlush()
    
def main():
   x, y, a, b = 50, 50, 10, 9
   glutInit(sys.argv)
   glutInitDisplayMode(GLUT_RGB)
   glutInitWindowSize(500, 500)
   glutInitWindowPosition(0, 0)
   glutCreateWindow("Hyperbola Midpoint Algorithm")
   glutDisplayFunc(lambda: drawHyperbolaMidpoint(x, y, a, b))
   init()
   glutMainLoop()
main()