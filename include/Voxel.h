#pragma once

#include <vector>
#include <functional>
#include <ostream>

// placeholder Point definition
typedef int FrameId;
struct Point {
    float x;
    float y;
    float z;
    FrameId frameID;

    Point(float xIn, float yIn, float zIn) : x(xIn), y(yIn), z(zIn) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& pt) {
        os << "x: " << pt.x << ", y: " << pt.y << ", z: " << pt.z;
        return os;
    }
};

// used as hash key in voxelMap
struct VoxelCoord {
    float xc;
    float yc;
    float zc;

    bool operator==(const VoxelCoord& other) const {
        return (xc == other.xc && yc == other.yc && zc == other.zc);
    }

    friend std::ostream& operator<<(std::ostream& os, const VoxelCoord& vc) {
        os << "x: " << vc.xc << ", y: " << vc.yc << ", z: " << vc.zc;
        return os;
    }
};

template <>
struct std::hash<VoxelCoord> {
    std::size_t operator()(VoxelCoord const& vc) const {
        // Here we assume the voxel resolution is upto 2 digits after decimal (e.g. voxelSize = 0.01), we multiply by 100 to get a integer
        int p1 = 204803, p2 = 618637, p3 = 779189;
        return (static_cast<int>(vc.xc * 100 * p1) ^ static_cast<int>(vc.yc * 100 * p2) ^ static_cast<int>(vc.zc * 100 * p3));
    }
};

class Voxel {
public:
    Voxel() {}

    Voxel(float x, float y, float z) : xc(x), yc(y), zc(z) {}

public:
    // voxel center coordinates
    float xc;
    float yc;
    float zc;
    // points in the voxel
    std::vector<Point> voxPoints;
};