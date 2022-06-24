//including necessary message types
#include <cstdio>
#include <ignition/msgs/twist.pb.h>
#include <ignition/msgs/laserscan.pb.h>
#include <ignition/transport/Node.hh>

#include <string>

ignition::transport::Node node; //Initialising node
  std::string topic_pub = "/cmd_vel";   //publish to this topic
  ignition::msgs::Twist data; //msg type
  auto pub = node.Advertise<ignition::msgs::Twist>(topic_pub); //publishing on cmd_vel topic


//Callback function
void cb(const ignition::msgs::LaserScan &_msg)
{
  ignition::msgs::Twist data;

  bool allMore = true;

  //Checking for obstacles 
  for (int i = 0; i < _msg.ranges_size(); i++)
  {
    if (_msg.ranges(i) < 1.0) 
    {
      allMore = false;
      break;
    }
  }
  //For object farther than threshold distance 1 meter
  //Keep going straight  

  printf("Lidar Node is running\n");

  if (allMore)   {
    data.mutable_linear()->set_x(0.5); //move forward
    data.mutable_angular()->set_z(0.0); 
  }
  else
  //For object distance less than 1 meter start changing direction
  {
    data.mutable_linear()->set_x(-0.5); //move back
    data.mutable_angular()->set_z(-0.5); //steer left
  }
  pub.Publish(data);

}


//Main function
int main(int argc, char **argv)
{

  std::string topic_sub = "/lidar";   // subscribe to lidar topic
  
  if (!node.Subscribe(topic_sub, cb))   // Subscribe to a topic by registering a callback.

  {
    std::cerr << "Error subscribing to topic [" << topic_sub << "]" << std::endl; //Return error msg if topic can't be subscribed
    return -1;
  }

  // Zzzzzz.
  ignition::transport::waitForShutdown();

  return 0;
}