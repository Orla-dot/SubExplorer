#include "Arduino.h"

struct data_package
{
    byte  selfAdress;
    byte  receiver;
    float longitude;
    float latitude;
    int   roll;
    int   pitch;
    int   yaw;
    int   lidarMap[120];
    
};
