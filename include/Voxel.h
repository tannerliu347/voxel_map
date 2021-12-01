#pragma once

#include <vector>
#include <functional>

// placeholder Point definition
typedef int FrameId;
struct Point {
    float x;
    float y;
    float z;
    FrameId frameID;
};

// used as hash key in voxelMap
struct VoxelCoord {
    float xc;
    float yc;
    float zc;

    bool operator==(const VoxelCoord& other) const {
        return (xc == other.xc && yc == other.yc && zc == other.zc);
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