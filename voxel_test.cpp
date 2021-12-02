#include <pcl/io/pcd_io.h>

#include <vector>

#include "VoxelMap.h"
#include "Voxel.h"

int main() {
    // // load pcl point cloud
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    // if (pcl::io::loadPCDFile<pcl::PointXYZ>("../pointclouds/office1_keypoints.pcd", *cloud) == -1) {//* load the file 
    //     PCL_ERROR("Couldn't read file test_pcd.pcd \n");
    //     return (-1);
    // }
    // std::cout << "Total number of points: " << cloud->points.size() << std::endl;
    // // initialize map
    // VoxelMap vxMap(2.0f);
    // for (int i = 0; i < cloud->points.size(); i++) {
    //     pcl::PointXYZ curPt = cloud->points[i];
    //     Point rawPt{curPt.x, curPt.y, curPt.z};
    //     vxMap.insert_point(rawPt);
    // }
    // std::cout << "Voxel num after insertion: " << vxMap.size() << std::endl;

    // // remove first half of the points
    // for (int i = 0; i < cloud->points.size() / 2; i++) {
    //     pcl::PointXYZ curPt = cloud->points[i];
    //     Point rawPt{curPt.x, curPt.y, curPt.z};
    //     vxMap.delete_point(rawPt);
    // }
    // std::cout << "Voxel num after deletion: " << vxMap.size() << std::endl;

    // Voxel* queriedVoxel = nullptr;
    // pcl::PointXYZ rawPcl = cloud->points[cloud->points.size() / 2 + 1];
    // Point rawPt{rawPcl.x, rawPcl.y, rawPcl.z};
    // std::cout << "Should return true: " << vxMap.query_point(rawPt, queriedVoxel) << std::endl;
    // std::cout << "Raw point: " << rawPcl << std::endl;
    // std::cout << "Voxel: " << queriedVoxel->xc << ", " << queriedVoxel->yc << ", " << queriedVoxel->zc << std::endl;
    // pcl::PointXYZ rawPcl2 = cloud->points[0];

    VoxelMap vxMap(2.0f);

    std::vector<Point> pc1;
    pc1.emplace_back( 1.59,  2.03,  3.31);
    pc1.emplace_back( 6.39, -8.56, -1.29);
    pc1.emplace_back(-4.87,  5.12,  2.65);
    pc1.emplace_back(-9.99, -4.44, -6.17);
    for (int i = 0; i < pc1.size(); i++) {
        vxMap.insert_point(pc1[i]);
    }

    std::vector<Point> pc2;
    pc2.emplace_back( 1.59,  2.03,  3.31);
    pc2.emplace_back( 6.39, -8.56, -1.29);
    pc2.emplace_back( 4.85, -7.57, -0.26);
    pc2.emplace_back( 1.23,  6.98,  4.44);
    for (int i = 0; i < pc2.size(); i++) {
        std::cout << "Querying: " << pc2[i] << std::endl;
        Voxel* qVox = nullptr;
        if (!vxMap.query_point(pc2[i], qVox)) {
            std::cout << "Query failed\n";
        } else {
            std::cout << qVox->xc << ", " << qVox->yc << ", " << qVox->zc << std::endl;
        }
    }


    return 0;
}
