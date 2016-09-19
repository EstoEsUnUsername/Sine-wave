#include <iostream>
#include <GL/glut.h>
#include <math.h>

int xc = 0, yc = 0;
int radio = 100;

template <typename T> class Vector2D
{
private:
    T x;
    T y;

public:
    explicit Vector2D(const T& x=0, const T& y=0) : x(x), y(y) {}
    Vector2D(const Vector2D<T>& src) : x(src.x), y(src.y) {}
    virtual ~Vector2D() {}

    // set get
    inline T X() const { return x; }
    inline T Y() const { return y; }
    inline T X(const T& x) { this->x = x; }
    inline T Y(const T& y) { this->y = y; }

    // operadores
    inline Vector2D<T> operator-() const
        { return Vector2D<T>(-x, -y); }

    inline Vector2D<T> operator+() const
        { return Vector2D<T>(+x, +y); }

    inline Vector2D<T> operator+(const Vector2D<T>& v) const
        { return Vector2D<T>(x+v.x, y+v.y); }

    inline Vector2D<T> operator-(const Vector2D<T>& v) const
        { return Vector2D<T>(x-v.x, y-v.y); }

    inline Vector2D<T> operator*(const T& s) const
        { return Vector2D<T>(x*s, y*s); }

    // producto punto
    inline T operator*(const Vector2D<T>& v) const
        { return x*v.x + y*v.y; }

    inline T norm() const { return sqrt(x*x + y*y); }

    // retorno de angulo en radianes
    static T angle(const Vector2D<T>& v1, const Vector2D<T>& v2)
    {
        return acos( (v1 * v2) / (v1.norm() * v2.norm()) );
    }
};

void drawAxes() //Ejes
{
    glBegin(GL_LINES);
    glColor3f(400.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(400.0, 0.0, 0.0);
    glColor3f(0.0, 4000.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 400.0, 0.0);
    glEnd();
    glutSwapBuffers();
}

void point(int x, int y) { // Dibujo de cada pixel
    glBegin(GL_POINTS);
    glColor3b(1, 1, 1);
    int es = 0;
    glVertex2i(xc+x, yc+y);
    Vector2D<double> p1(0, 0);
    Vector2D<double> p2(xc+x,yc+y);
    Vector2D<double> p3(radio, 0);
    double rad = Vector2D<double>::angle(p2-p1, p3-p1);
    double deg = rad * 180.0 / 3.14159265359;
    es = yc + y;
    if(es < 0){
        es = 360 - deg;
    }else es = deg;
    glVertex2i(es, yc+y);

    /*---------------*/

    glVertex2i(xc+y, yc+x);
    Vector2D<double> p4(0, 0);
    Vector2D<double> p5(xc+y, yc+x);
    Vector2D<double> p6(radio, 0);
    double rad1 = Vector2D<double>::angle(p5-p4, p6-p4);
    double deg1 = rad1 * 180.0 / 3.14159265359;
    es = yc + x;
    if(es < 0){
        es = 360 - deg1;
    }else es = deg1;
    glVertex2i(es, yc+x);

    /*---------------*/

    glVertex2i(xc-y, yc+x);
    Vector2D<double> p7(0, 0);
    Vector2D<double> p8(xc-y, yc+x);
    Vector2D<double> p9(radio, 0);
    double rad2 = Vector2D<double>::angle(p8-p7, p9-p7);
    double deg2 = rad2 * 180.0 / 3.14159265359;
    es = yc + x;
    if(es < 0){
        es = 360 - deg2;
    }else es = deg2;
    glVertex2i(es, yc+x);

    /*----------------*/

    glVertex2i(xc-x, yc+y);
    Vector2D<double> p10(0, 0);
    Vector2D<double> p11(xc-x, yc+y);
    Vector2D<double> p12(radio, 0);
    double rad3 = Vector2D<double>::angle(p11-p10, p12-p10);
    double deg3 = rad3 * 180.0 / 3.14159265359;
    es = yc + y;
    if(es < 0){
        es = 360 - deg3;
    }else es = deg3;
    glVertex2i(es, yc+y);

    /*----------------*/

    glVertex2i(xc-x, yc-y);
    Vector2D<double> p13(0, 0);
    Vector2D<double> p14(xc-x, yc-y);
    Vector2D<double> p15(radio, 0);
    double rad4 = Vector2D<double>::angle(p14-p13, p15-p13);
    double deg4 = rad4 * 180.0 / 3.14159265359;
    es = yc-y;
    if(es < 0){
        es = 360 - deg4;
    }else es = deg4;
    glVertex2i(es, yc-y);

    /*----------------*/

    glVertex2i(xc-y, yc-x);
    Vector2D<double> p16(0, 0);
    Vector2D<double> p17(xc-y, yc-x);
    Vector2D<double> p18(radio, 0);
    double rad5 = Vector2D<double>::angle(p17-p16, p18-p16);
    double deg5 = rad5 * 180.0 / 3.14159265359;
    es = yc - x;
    if(es < 0){
        es = 360 - deg5;
    }else es = deg5;
    glVertex2i(es, yc-x);

    /*----------------*/

    glVertex2i(xc+y, yc-x);
    Vector2D<double> p19(0, 0);
    Vector2D<double> p20(xc+y, yc-x);
    Vector2D<double> p21(radio, 0);
    double rad6 = Vector2D<double>::angle(p20-p19, p21-p19);
    double deg6 = rad6 * 180.0 / 3.14159265359;
    es = yc - x;
    if(es < 0){
        es = 360 - deg6;
    } else es = deg6;
    glVertex2i(es, yc-x);

    /*-----------------*/
    glVertex2i(xc+x, yc-y);
    Vector2D<double> p22(0, 0);
    Vector2D<double> p23(xc+x, yc-y);
    Vector2D<double> p24(radio, 0);
    double rad7 = Vector2D<double>::angle(p23-p22, p24-p22);
    double deg7 = rad7 * 180.0 / 3.14159265359;
    es = yc - y;
    if(es < 0){
        es = 360 - deg7;
    }else es = deg7;
    glVertex2i(es, yc-y);
    glEnd();
}


void bresenham(int r){
    int x = r,y = 0;
    float pk=0; // Parametro de decision
    int k;

    while(x >= y){
        point(x, y);
        y = y + 1;
        pk+= 1 + 2*y;
        if(2 *(pk-x) + 1 > 0){
            x = x - 1;
            pk += 1 - 2*x;
        }
    }
    glFlush();
    drawAxes();
}

void circle(void){
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham(radio);
}

void Init(){
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(1.0,1.0,1.0);
    gluOrtho2D(-400 , 400 , -400 , 400);
}

int main(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Middle point Algorithm - Sine wave");
    Init();
    glutDisplayFunc(circle);
    glutMainLoop();
    return 0;
}
