#include"Vec3d.h"
#include"STL.h"

int main() {
    CAD c;
    c.add(new Cube(0,0,0,5));
    c.add(new Cylinder(100,0,0, 3, 10, 10));
    c.write("test.stl");
}