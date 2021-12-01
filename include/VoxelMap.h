#pragma once

#include <unordered_map>
#include <iostream>
#include <vector>
#include <math.h>

#include <Voxel.h>


class VoxelMap {
public:
    VoxelMap(float voxelSize);

    /**
     * @brief insert a 3D point into the voxel map
     * @param pt: a 3D point
     * @return true if insertion is successful; False if point already exists
     */
    bool insert_point(Point pt);


    /**
     * @brief remove a 3D point from the voxel map
     * @param pt: a 3D point
     * @return true if deletion is successful; False if point doesn't exist in map
     */
    bool delete_point(Point pt);

    /**
     * @brief query a 3D point to find the voxel containing it in the voxel map
     * @param pt: a 3D point
     * @param contained_voxel: the query result
     * @return true if query finds a valid voxel, false if such voxel doesn't exist in map
     */
    bool query_point(Point pt, Voxel*& contained_voxel);

    /**
     * @brief obtain the frameIds that have seen this voxel
     * @param q_vox: queried voxel
     * @return a vector of frameIds
     */
    std::vector<FrameId> voxel_seen_frames(VoxelCoord q_vox);

    size_t size();

private:
    /**
     * @brief finds the voxel center coordinate that contains a given point
     * @param pt: a 3D point
     * @return the coordinate of the voxel center
     */
    VoxelCoord point_to_voxel_center(Point pt);

private:
    float voxelSize_;                               // Edge length of a single voxel cubic
    std::unordered_map<VoxelCoord, Voxel> vmap_;    // Hash map that stores the full voxel map

};