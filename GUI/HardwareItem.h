/***
 * HardwareItem.h
*/
#ifndef HARDWAREITEM_H
#define HARDWAREITEM_H

#include<string>

class HardwareItem{
    
    private:
        std::string name;
        std::string type;

    public:
        HardwareItem();
        ~HardwareItem();

        bool connectionOK();
        std::string getDeviceName();
        std::string getDeviceType();
        void setDeviceName(std::string name);
        void setDeviceType(std::string type);

};
#endif