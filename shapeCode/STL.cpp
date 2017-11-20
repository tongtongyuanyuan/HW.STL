
//
// Created by Tong Xue on 11/8/17.
//
#include"Vec3d.h"
#include"STL.h"
#include<fstream>
#include<vector>
using namespace std;

Shape::Shape(double x,double y,double z) :x(x),y(y),z(z){}
double Shape::getX() const{return x;}
double Shape::getY() const{return y;}
double Shape::getZ() const{return z;}
Shape::~Shape(){}

Cylinder::Cylinder(double x, double y, double z, double r, double h, int facets):Shape(x,y,z), r(r),h(h),facets(facets){

}

constexpr double pi = 3.1415926535;

void Cylinder::write(ofstream& file) const {
    if (file) {
        double angel = 2 * pi;
        double m = angel / facets;
        Vec3d v1(getX() + cos(0), getY() + sin(0), getZ() + h);
        Vec3d v2(getX(), getY(), getZ() + h);
        Vec3d d_v1 = v1 - Vec3d(0, 0, h);
        Vec3d d_v2 = v1 - Vec3d(0, 0, h);
        Vec3d v3;
        Vec3d d_v3;
        for (int i = 0;i <= facets; i++) {
            Vec3d v3(getX() + r * cos((i + 1) * m), getY() + r * sin((i + 1) * m), getZ() + h);
            //up circle
            Vec3d f1 = facetnormal(v1 - v2, v2 - v3);
            file << " " << "facet normal" << ' ' << f1 << "\n";
            file << " outer loop " << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << v1 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << v2 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << v3 << "\n";
            file << "endloop" << "\n";
            file << "endfacet" << "\n";
            //down circle
            Vec3d d_v3 = v3 - Vec3d(0, 0, h);
            Vec3d f2 = facetnormal(d_v2 - d_v1, d_v3 - d_v2);
            file << "facet normal" << ' ' << f2 << "\n";
            file << " outer loop " << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << d_v1 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << d_v2 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << d_v3 << "\n";
            file << "endloop" << "\n";
            file << "endfacet" << "\n";
            //triangle v3,v1,d_v3
            Vec3d f3 = facetnormal(v1 - v3, d_v3 - v1);
            file << " " << "facet normal" << ' ' << f3 << "\n";
            file << " outer loop " << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << v3 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << v1 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << d_v3 << "\n";
            file << "endloop" << "\n";
            file << "endfacet" << "\n";
            //triangle v3,v1,d_v3
            Vec3d f4 = facetnormal(d_v1 - v1, v1 - d_v3);
            file << " " << "facet normal" << ' ' << f4 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << v1 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << d_v1 << "\n";
            file << ' ' << ' ' << ' ' << " vertex " << d_v3 << "\n";
            file << "endloop" << "\n";
            file << "endfacet" << "\n";

            v1 = v3;
            d_v1 = d_v3;
        }
        file.close();
    }
}

Cylinder::~Cylinder() {}

Cube::Cube(double x, double y, double z, double size = 50) : Shape(x,y,z),size(size) {}
void Cube::write(ofstream& file) const{
       double x1,x2,x3;
       double y1,y2,y3;
       double z1,z2,z3;
       for (int i = 1; i <= 12; i++) {
           switch (i) {
               case 1:
                   x1 = size;
                   x2 = size;
                   x3 = size;
                   y1 = 0;
                   y2 = 0;
                   y3 = size;
                   z1 = size;
                   z2 = 0;
                   z3 = 0;
                   break;
               case 2:
                   x1 = size;
                   x2 = size;
                   x3 = size;
                   y1 = 0;
                   y2 = size;
                   y3 = size;
                   z1 = size;
                   z2 = 0;
                   z3 = size;
                   break;
               case 3:
                   x1 = size;
                   x2 = size;
                   x3 = 0;
                   y1 = size;
                   y2 = size;
                   y3 = size;
                   z1 = size;
                   z2 = 0;
                   z3 = 0;
                   break;
               case 4:
                   x1 = size;
                   x2 = 0;
                   x3 = 0;
                   y1 = size;
                   y2 = size;
                   y3 = size;
                   z1 = size;
                   z2 = 0;
                   z3 = size;
                   break;
               case 5:
                   x1 = 0;
                   x2 = 0;
                   x3 = 0;
                   y1 = 0;
                   y2 = size;
                   y3 = size;
                   z1 = size;
                   z2 = 0;
                   z3 = size;
                   break;
               case 6:
                   x1 = 0;
                   x2 = 0;
                   x3 = 0;
                   y1 = 0;
                   y2 = 0;
                   y3 = size;
                   z1 = 0;
                   z2 = size;
                   z3 = 0;
                   break;
               case 7:
                   x1 = size;
                   x2 = 0;
                   x3 = 0;
                   y1 = 0;
                   y2 = 0;
                   y3 = 0;
                   z1 = size;
                   z2 = size;
                   z3 = 0;
                   break;
               case 8:
                   x1 = size;
                   x2 = 0;
                   x3 = size;
                   y1 = 0;
                   y2 = 0;
                   y3 = 0;
                   z1 = size;
                   z2 = 0;
                   z3 = 0;
                   break;
               case 9:
                   x1 = 0;
                   x2 = size;
                   x3 = size;
                   y1 = 0;
                   y2 = 0;
                   y3 = size;
                   z1 = size;
                   z2 = size;
                   z3 = size;
                   break;
               case 10:
                   x1 = 0;
                   x2 = size;
                   x3 = 0;
                   y1 = 0;
                   y2 = size;
                   y3 = size;
                   z1 = size;
                   z2 = size;
                   z3 = size;
                   break;
               case 11:
                   x1 = size;
                   x2 = 0;
                   x3 = size;
                   y1 = 0;
                   y2 = 0;
                   y3 = size;
                   z1 = 0;
                   z2 = 0;
                   z3 = 0;
                   break;
               case 12:
                   x1 = 0;
                   x2 = 0;
                   x3 = size;
                   y1 = 0;
                   y2 = size;
                   y3 = size;
                   z1 = 0;
                   z2 = 0;
                   z3 = 0;
                   break;
           }
           Vec3d c1 = (x2 - x1, y2 - y1, z2 - z1);
           Vec3d c2 = (x3 - x2, y3 - y2, z3 - z2);
           Vec3d normal = facetnormal(c1, c2);
           file << "facet normal " << normal.getX() << ' ' << normal.getY() << ' ' << normal.getZ() << "\n";
           file << "outer loop " << "\n";
           file << "vertex " << x1 << ' ' << y1 << ' ' << z1 << "\n";
           file << "vertex " << x2 << ' ' << y2 << ' ' << z2 << "\n";
           file << "vertex " << x3 << ' ' << y3 << ' ' << z3 << "\n";
           file << "endloop" << "\n";
           file << "endfacet" << "\n";
   }
}

Cube::~Cube(){}


CAD:: ~CAD() {
    for(int i = 0;i < shapes.size();i++)
        delete shapes[i];
    }
void CAD::add(Shape *s) {
    shapes.push_back(s);
}
void CAD::write(string fileName) {
    ofstream file(fileName);
    if(file) {
        auto n = fileName.find('.');
        string s = fileName.substr(0, n);
        file << "solid " << s << endl;
        for( int i = 0; i < shapes.size(); ++i) {
            shapes[i]->write(file);
        }
        file << "endsolid " << s;
        file.close();
    }
}
