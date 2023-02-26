#include "ros/ros.h"
#include<thread>
#include "line_detection14.h"

void threadFunction(void)
{
    line_detection14();
    ros::shutdown();
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "line_detection14_test");
    ros::NodeHandlePtr MLROSNodePtr = ros::NodeHandlePtr(new ros::NodeHandle);
    std::thread threadObj(threadFunction);

    ros::spin();
    threadObj.join();

    return 0;
}
