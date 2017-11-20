//
// Created by Tong Xue on 11/8/17.
//

#ifndef STL_VEC3D_H
#define STL_VEC3D_H
#include <iostream>
#include <cmath>
using namespace std;
class Vec3d {
private:
    double x, y, z;
public:
    Vec3d(double x = 0, double y = 0, double z = 0);

    double getX() const;

    double getY() const;

    double getZ() const;

    Vec3d(const Vec3d &d);

    ~Vec3d();

    friend ostream& operator <<(ostream& s, const Vec3d& v);

    friend Vec3d operator - (const Vec3d& v1, const Vec3d& v2);

    friend Vec3d facetnormal(const Vec3d &d_v1, const Vec3d &d_v2);
};

#endif //STL_VEC3D_H
