/*
*  Attempt at propertly controlling 
*  This program shows how to control a blinkm
*  from an arduino using RosSerial
*/

#include <stdlib.h>


#include <ros.h>
#include <std_msgs/String.h>

void setLED( bool on,  char color)
{
  if (on) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
}

void light_cb( const std_msgs::String& light_cmd){
        bool solid =false;
        char color; 
        /*
        if (strlen( (const char* ) light_cmd.data) ==2 ){
          solid  = (light_cmd.data[0] == '1');
          color = light_cmd.data[1];
        }
        else{
          solid=  false;
          color = light_cmd.data[0];
        }
        */
        solid = (light_cmd.data[0] == 't');
        
  setLED(solid, color);
}



ros::NodeHandle  nh;
ros::Subscriber<std_msgs::String> sub("lightControl" , light_cb);


void setup()
{
   
  pinMode(13, OUTPUT); //set up the LED
  delay(100);
  nh.initNode();
  nh.subscribe(sub);

}

void loop()
{
 nh.spinOnce();
 delay(1);
}
