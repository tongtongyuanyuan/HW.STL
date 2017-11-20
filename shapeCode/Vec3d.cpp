//
// Created by Tong Xue on 11/8/17.
//

#include "Vec3d.h"
using namespace std;

    Vec3d::Vec3d(double x, double y, double z) : x(x), y(y), z(z) {}

    double Vec3d::getX() const { return x; };

    double Vec3d::getY() const { return y; };

    double Vec3d::getZ() const { return z; };

    Vec3d::Vec3d(const Vec3d &d) {}

    Vec3d::~Vec3d() {}

    ostream& operator <<(ostream& s, const Vec3d& v) {
    s << v.x << " " << v.y << " " << v.z;
    return s;
    }


   Vec3d operator - (const Vec3d& v1, const Vec3d& v2) {
    Vec3d ans;
    ans.x = v1.x - v2.x;
    ans.y = v1.y - v2.y;
    ans.z = v1.z - v2.z;
    return ans;
   }

    Vec3d facetnormal(const Vec3d &d_v1, const Vec3d &d_v2) {
        Vec3d normal;
        normal.x = d_v1.y * d_v2.z - d_v2.y * d_v1.z;
        normal.y = d_v1.z * d_v2.x - d_v2.z * d_v1.x;
        normal.z = d_v1.x * d_v2.y - d_v2.x * d_v1.y;
        return normal;
    }