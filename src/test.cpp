#include <ros/ros.h>
#include <std_msgs/UInt16.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rosserial_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::UInt16>("servo", 1);

    std_msgs::UInt16 msg;

    ros::Rate loop_rate(10);
    
    while(ros::ok())
    {
        for(int i=0; i<=180; i++)
        {
            msg.data = i;
            pub.publish(msg);
            loop_rate.sleep();
        }
    }

    return 0;
}

