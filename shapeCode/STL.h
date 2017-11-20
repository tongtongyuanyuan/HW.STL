//
// Created by Tong Xue on 11/8/17.
//

#ifndef STL_STL_H
#define STL_STL_H
#include<iostream>
#include<vector>
//#include"Vec3d.h"
using namespace std;
class Shape {
private:
    double x, y, z;
public:
    Shape(double x = 0, double y = 0, double z = 0);
    double getX() const;
    double getY() const;
    double getZ() const;
    virtual void write(ofstream& file) const = 0;
    //virtual ofstream& connectTriangle(Vec3d a, Vec3d b, Vec3d c);
    virtual ~Shape();
};

class Cylinder : public Shape {
private:
    double r,h;
    int facets;
    //vector<Vec3d> v;
public:
    Cylinder(double x,double y,double z,double r,double h,int facets);
    ~Cylinder();
    void write(ofstream& file)const;
};
 class Cube : public Shape {
 private:
     double r,h,size;
     //vector<Vec3d> v;
 public:
     Cube(double x,double y,double z,double size);
     void write(ofstream& file) const;
     ~Cube();
 };

class CAD {
private:
    vector<Shape*> shapes;
public:
    void write(string filename);
    CAD(const CAD&c) {}
    CAD() {}
    void add(Shape *s);
    ~CAD();
};
#endif //STL_STL_H
