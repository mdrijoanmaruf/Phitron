#include <windows.h>
#include <GL/glut.h>
#include <math.h>

// ================= Circle =================
void circle(float x, float y, float r){
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0;i<=100;i++){
        float ang = i * 2 * 3.1416 / 100;
        glVertex2f(x + r*cos(ang), y + r*sin(ang));
    }
    glEnd();
}

// ================= Gradient Sky =================
void sky(){
    glBegin(GL_QUADS);
        glColor3f(0.05f, 0.3f, 0.8f);  // Top deep blue
        glVertex2f(-1,1);
        glVertex2f(1,1);

        glColor3f(0.3f, 0.7f, 1.0f);  // Middle blue
        glVertex2f(1, 0.4);
        glVertex2f(-1, 0.4);

        glColor3f(0.7f, 0.9f, 1.0f);  // Bottom light blue horizon
        glVertex2f(1, -0.1);
        glVertex2f(-1, -0.1);
    glEnd();
}

// ================= Mountains =================
void mountains(){
    glBegin(GL_TRIANGLES);
        // Left mountain - darker
        glColor3f(0.25,0.25,0.3);
        glVertex2f(-1,0.0);
        glColor3f(0.35,0.35,0.4);
        glVertex2f(-0.6,0.7);
        glColor3f(0.25,0.25,0.3);
        glVertex2f(-0.2,0.0);

        // Middle mountain - tallest
        glColor3f(0.28,0.28,0.32);
        glVertex2f(-0.4,0.0);
        glColor3f(0.4,0.4,0.45);
        glVertex2f(0.1,0.8);
        glColor3f(0.28,0.28,0.32);
        glVertex2f(0.6,0.0);

        // Right mountain
        glColor3f(0.3,0.3,0.35);
        glVertex2f(0.2,0.0);
        glColor3f(0.38,0.38,0.43);
        glVertex2f(0.9,0.6);
        glColor3f(0.3,0.3,0.35);
        glVertex2f(1.2,0.0);
    glEnd();

    // Snow Tops - enhanced
    glColor3f(0.95,0.95,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6,0.7);
        glVertex2f(-0.48,0.52);
        glVertex2f(-0.72,0.52);

        glVertex2f(0.1,0.8);
        glVertex2f(-0.02,0.58);
        glVertex2f(0.22,0.58);

        glVertex2f(0.9,0.6);
        glVertex2f(0.78,0.42);
        glVertex2f(1.02,0.42);
    glEnd();
}

// ================= Land =================
void land(){
    glBegin(GL_QUADS);
        glColor3f(0.15,0.55,0.15);  // Darker green top
        glVertex2f(-1,-0.1);
        glVertex2f(1,-0.1);

        glColor3f(0.1,0.5,0.1);  // Lighter green bottom
        glVertex2f(1,-0.45);
        glVertex2f(-1,-0.45);
    glEnd();
}

// ================= River =================
void river(){
    glBegin(GL_QUADS);
        glColor3f(0.05,0.35,0.85);  // Top darker blue
        glVertex2f(-1,-0.45);
        glVertex2f(1,-0.45);

        glColor3f(0.0,0.25,0.75);  // Bottom deeper blue
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();

    // Enhanced water shine with better waves
    glColor4f(1,1,1,0.5);
    glBegin(GL_LINES);
        glLineWidth(1.5);
        for(float i=-0.95;i<=0.95;i+=0.15){
            glVertex2f(i,-0.55);
            glVertex2f(i+0.1,-0.58);
            glVertex2f(i+0.1,-0.7);
            glVertex2f(i+0.2,-0.73);
        }
        glLineWidth(1.0);
    glEnd();
}

// ================= Sun =================
void sun(){
    // Sun glow (outer halo)
    glColor4f(1,0.8,0.2,0.15);
    circle(0.7,0.75,0.22);

    glColor4f(1,0.85,0.1,0.25);
    circle(0.7,0.75,0.18);

    // Main sun body
    glColor3f(1,0.95,0.1);
    circle(0.7,0.75,0.12);

    // Sun shine highlight
    glColor4f(1,1,0.8,0.4);
    circle(0.72,0.77,0.04);
}

// ================= Cloud =================
void cloud(float x,float y){
    // Cloud shadow
    glColor4f(0.8,0.8,0.8,0.3);
    circle(x-0.02,y-0.02,0.105);
    circle(x+0.1,y-0.02,0.105);
    circle(x-0.14,y-0.02,0.105);
    
    // Main cloud
    glColor3f(1,1,1);
    circle(x,y,0.1);
    circle(x+0.12,y,0.1);
    circle(x-0.12,y,0.1);
    circle(x,y+0.07,0.095);
    circle(x+0.06,y+0.05,0.08);
    circle(x-0.06,y+0.05,0.08);
    
    // Cloud highlight
    glColor4f(1,1,1,0.6);
    circle(x-0.06,y+0.05,0.05);
}

// ================= Tree =================
void tree(float x,float y){
    // Trunk with gradient effect
    glColor3f(0.35,0.18,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.035,y);
        glVertex2f(x+0.035,y);
        glVertex2f(x+0.03,y-0.25);
        glVertex2f(x-0.03,y-0.25);
    glEnd();

    // Foliage - multi-layered for depth
    glColor3f(0.0,0.5,0.0);  // Darker green base
    circle(x-0.12,y-0.05,0.12);
    circle(x+0.12,y-0.05,0.12);
    
    glColor3f(0.0,0.65,0.0);  // Medium green
    circle(x,y+0.08,0.14);
    circle(x-0.08,y,0.11);
    circle(x+0.08,y,0.11);
    
    glColor3f(0.1,0.75,0.1);  // Lighter green top
    circle(x,y+0.15,0.08);
    
    // Tree shadow
    glColor4f(0,0.3,0,0.2);
    circle(x+0.08,y-0.08,0.08);
}

// ================= House =================
void house(float x,float y){
    // House walls with shading
    glBegin(GL_POLYGON);
        glColor3f(0.95,0.35,0.25);  // Bright red-orange
        glVertex2f(x-0.2,y);
        glColor3f(0.85,0.25,0.15);  // Darker shade
        glVertex2f(x+0.2,y);
        glVertex2f(x+0.2,y-0.25);
        glVertex2f(x-0.2,y-0.25);
    glEnd();

    // Roof with gradient
    glBegin(GL_TRIANGLES);
        glColor3f(0.7,0.05,0.05);  // Dark red peak
        glVertex2f(x,y+0.2);
        glColor3f(0.65,0.1,0.1);   // Lighter sides
        glVertex2f(x-0.25,y);
        glVertex2f(x+0.25,y);
    glEnd();

    // Door
    glColor3f(0.3,0.15,0.05);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.06,y-0.25);
        glVertex2f(x+0.06,y-0.25);
        glVertex2f(x+0.06,y-0.11);
        glVertex2f(x-0.06,y-0.11);
    glEnd();
    
    // Door handle
    glColor3f(1,0.85,0);
    circle(x+0.04,y-0.18,0.008);
    
    // Windows
    glColor3f(0.7,0.9,1);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.15,y-0.06);
        glVertex2f(x-0.08,y-0.06);
        glVertex2f(x-0.08,y-0.13);
        glVertex2f(x-0.15,y-0.13);
    glEnd();
    
    glBegin(GL_POLYGON);
        glVertex2f(x+0.08,y-0.06);
        glVertex2f(x+0.15,y-0.06);
        glVertex2f(x+0.15,y-0.13);
        glVertex2f(x+0.08,y-0.13);
    glEnd();
    
    // Window frames
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_LINES);
        glLineWidth(1.5);
        glVertex2f(x-0.115,y-0.06);
        glVertex2f(x-0.115,y-0.13);
        glVertex2f(x-0.08,y-0.095);
        glVertex2f(x-0.15,y-0.095);
        glVertex2f(x+0.115,y-0.06);
        glVertex2f(x+0.115,y-0.13);
        glVertex2f(x+0.08,y-0.095);
        glVertex2f(x+0.15,y-0.095);
        glLineWidth(1.0);
    glEnd();
}

// ================= Birds =================
void bird(float x,float y){
    // Bird body - main torso
    glColor3f(0.9,0.2,0.1);  // Vibrant red
    circle(x,y,0.04);
    
    // Bird head - larger
    glColor3f(0.95,0.25,0.15);  // Bright red
    circle(x+0.035,y+0.025,0.025);
    
    // Crest on head
    glColor3f(0.85,0.15,0.05);  // Dark red
    circle(x+0.045,y+0.055,0.012);
    
    // Eye - bright and visible
    glColor3f(1,1,1);  // White
    circle(x+0.05,y+0.035,0.008);
    glColor3f(0,0,0);  // Black pupil
    circle(x+0.051,y+0.036,0.004);
    
    // Beak - yellow/orange
    glColor3f(1,0.7,0.1);
    glBegin(GL_TRIANGLES);
        glVertex2f(x+0.058,y+0.02);
        glVertex2f(x+0.08,y+0.02);
        glVertex2f(x+0.065,y+0.01);
    glEnd();
    
    // Left wing - green
    glColor3f(0.1,0.7,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.015,y);
        glVertex2f(x-0.08,y+0.015);
        glVertex2f(x-0.07,y-0.02);
    glEnd();
    
    // Left wing highlight
    glColor3f(0.2,0.85,0.3);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.025,y-0.005);
        glVertex2f(x-0.06,y+0.005);
        glVertex2f(x-0.05,y-0.015);
    glEnd();
    
    // Right wing - green
    glColor3f(0.1,0.65,0.15);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.015,y);
        glVertex2f(x+0.08,y+0.015);
        glVertex2f(x+0.07,y-0.02);
    glEnd();
    
    // Right wing highlight
    glColor3f(0.2,0.8,0.25);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.025,y-0.005);
        glVertex2f(x+0.06,y+0.005);
        glVertex2f(x+0.05,y-0.015);
    glEnd();
    
    // Tail - long feathers with green and red
    glColor3f(0.85,0.15,0.1);  // Red tail base
    glBegin(GL_POLYGON);
        glVertex2f(x-0.045,y-0.01);
        glVertex2f(x-0.12,y-0.02);
        glVertex2f(x-0.11,y-0.04);
        glVertex2f(x-0.04,y-0.03);
    glEnd();
    
    // Tail green accent
    glColor3f(0.15,0.75,0.25);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.055,y-0.015);
        glVertex2f(x-0.105,y-0.025);
        glVertex2f(x-0.095,y-0.035);
        glVertex2f(x-0.045,y-0.025);
    glEnd();
    
    // Chest - lighter red with pattern
    glColor3f(1,0.4,0.2);
    circle(x+0.01,y-0.015,0.025);
    
    // Feet - orange
    glColor3f(1,0.6,0.2);
    glBegin(GL_LINES);
        glLineWidth(2.0);
        glVertex2f(x-0.01,y-0.045);
        glVertex2f(x-0.01,y-0.08);
        glVertex2f(x+0.01,y-0.045);
        glVertex2f(x+0.01,y-0.08);
        glLineWidth(1.0);
    glEnd();
}

// ================= Boat =================
void boat(float x,float y){
    // Main hull with modern design
    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);  // Navy blue hull
        glVertex2f(x-0.2,y);
        glVertex2f(x+0.2,y);
        glColor3f(0.15,0.25,0.45);  // Darker bottom
        glVertex2f(x+0.18,y-0.08);
        glVertex2f(x-0.18,y-0.08);
    glEnd();
    
    // Hull edge highlight (waterline)
    glColor3f(0.4,0.6,0.8);
    glBegin(GL_LINE_LOOP);
        glLineWidth(2.5);
        glVertex2f(x-0.2,y);
        glVertex2f(x+0.2,y);
        glVertex2f(x+0.18,y-0.08);
        glVertex2f(x-0.18,y-0.08);
        glLineWidth(1.0);
    glEnd();
    
    // Cabin - white modern design
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.12,y-0.01);
        glVertex2f(x+0.12,y-0.01);
        glVertex2f(x+0.12,y+0.055);
        glVertex2f(x-0.12,y+0.055);
    glEnd();
    
    // Cabin roof - slanted modern style
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.2,0.2);  // Vibrant red roof
        glVertex2f(x-0.125,y+0.055);
        glVertex2f(x+0.125,y+0.055);
        glColor3f(0.6,0.1,0.1);  // Darker red top
        glVertex2f(x+0.1,y+0.12);
        glVertex2f(x-0.1,y+0.12);
    glEnd();
    
    // Cabin roof edge
    glColor3f(0.4,0.05,0.05);
    glBegin(GL_LINES);
        glLineWidth(1.5);
        glVertex2f(x-0.125,y+0.055);
        glVertex2f(x-0.1,y+0.12);
        glVertex2f(x+0.125,y+0.055);
        glVertex2f(x+0.1,y+0.12);
        glLineWidth(1.0);
    glEnd();
    
    // Porthole windows - left side
    glColor3f(0.5,0.8,1);  // Light blue glass
    circle(x-0.08,y+0.025,0.012);
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_LINE_LOOP);
        glLineWidth(1.0);
        glVertex2f(x-0.092,y+0.025);
        glVertex2f(x-0.068,y+0.025);
        glVertex2f(x-0.068,y+0.025);
        glVertex2f(x-0.092,y+0.025);
        glLineWidth(1.0);
    glEnd();
    
    // Porthole windows - right side
    glColor3f(0.5,0.8,1);
    circle(x+0.08,y+0.025,0.012);
    
    // Door on cabin
    glColor3f(0.4,0.15,0.05);  // Brown door
    glBegin(GL_POLYGON);
        glVertex2f(x-0.04,y-0.005);
        glVertex2f(x+0.04,y-0.005);
        glVertex2f(x+0.04,y+0.045);
        glVertex2f(x-0.04,y+0.045);
    glEnd();
    
    // Door handle - gold
    glColor3f(1,0.8,0.1);
    circle(x+0.032,y+0.02,0.006);
    
    // Mast - tall and modern
    glColor3f(0.3,0.3,0.3);  // Gray metal
    glBegin(GL_POLYGON);
        glVertex2f(x-0.008,y+0.055);
        glVertex2f(x+0.008,y+0.055);
        glVertex2f(x+0.006,y+0.25);
        glVertex2f(x-0.006,y+0.25);
    glEnd();
    
    // Mast shine
    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.004,y+0.055);
        glVertex2f(x+0.002,y+0.055);
        glVertex2f(x+0.001,y+0.25);
        glVertex2f(x-0.003,y+0.25);
    glEnd();
    
    // Main sail - large and billowing
    glColor3f(0.95,0.95,1);  // Off-white sail
    glBegin(GL_POLYGON);
        glVertex2f(x,y+0.08);
        glVertex2f(x+0.15,y+0.12);
        glVertex2f(x+0.12,y+0.24);
        glVertex2f(x,y+0.22);
    glEnd();
    
    // Main sail shadow for depth
    glColor3f(0.8,0.8,0.9);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.02,y+0.09);
        glVertex2f(x+0.12,y+0.12);
        glVertex2f(x+0.09,y+0.22);
        glVertex2f(x+0.01,y+0.2);
    glEnd();
    
    // Jib sail - front sail
    glColor3f(1,1,1);  // Pure white
    glBegin(GL_POLYGON);
        glVertex2f(x-0.02,y+0.085);
        glVertex2f(x+0.08,y+0.11);
        glVertex2f(x+0.06,y+0.235);
        glVertex2f(x-0.02,y+0.21);
    glEnd();
    
    // Jib sail shadow
    glColor3f(0.85,0.85,0.95);
    glBegin(GL_POLYGON);
        glVertex2f(x,y+0.09);
        glVertex2f(x+0.06,y+0.115);
        glVertex2f(x+0.04,y+0.225);
        glVertex2f(x,y+0.2);
    glEnd();
    
    // Sail details - line patterns
    glColor3f(0.7,0.7,0.8);
    glBegin(GL_LINES);
        glLineWidth(0.8);
        glVertex2f(x+0.01,y+0.1);
        glVertex2f(x+0.08,y+0.24);
        glVertex2f(x+0.05,y+0.1);
        glVertex2f(x+0.1,y+0.24);
        glLineWidth(1.0);
    glEnd();
    
    // Mast flag - red flag
    glColor3f(0.9,0.15,0.1);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.008,y+0.24);
        glVertex2f(x+0.05,y+0.235);
        glVertex2f(x+0.048,y+0.265);
        glVertex2f(x+0.01,y+0.27);
    glEnd();
    
    // Anchor point detail
    glColor3f(0.5,0.5,0.5);
    circle(x-0.15,y+0.001,0.008);
    circle(x+0.15,y+0.001,0.008);
    
    // Wave splash under boat
    glColor4f(1,1,1,0.3);
    glBegin(GL_LINES);
        glLineWidth(1.0);
        glVertex2f(x-0.22,y);
        glVertex2f(x-0.25,y+0.01);
        glVertex2f(x+0.22,y);
        glVertex2f(x+0.25,y+0.01);
        glLineWidth(1.0);
    glEnd();
}

// ================= Display =================
void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    sun();
    mountains();
    cloud(-0.5,0.7);
    cloud(0.1,0.8);
    cloud(0.6,0.68);

    land();

    tree(-0.8,-0.1);
    tree(-0.6,-0.1);
    tree(-0.4,-0.1);

    house(0.6,-0.05);

    river();

    boat(0.2,-0.75);

    bird(-0.2,0.6);
    bird(0.0,0.65);
    bird(0.2,0.6);

    glFlush();
}

// ================= Init =================
void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

// ================= Main =================
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,600);
    glutCreateWindow("Advanced River View - OpenGL Project");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
