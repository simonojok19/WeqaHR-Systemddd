#ifndef COMMCONTROL_H
#define COMMCONTROL_H


#pragma once

#include <vector>
#include <string>
#include "BS_API.h"


enum RS485_HOST_CHANNEL
{
    RS485_HOST_CH_ALL = 0xFF,
    RS485_HOST_CH_0 = 0x00,
    RS485_HOST_CH_1 = 0x01,
    RS485_HOST_CH_2 = 0x02,
    RS485_HOST_CH_3 = 0x03,
    RS485_HOST_CH_MAX,
};


class CommControl
{
public:
    CommControl(void* sdkContext);
    virtual ~CommControl();


public:
    int searchDevices(std::vector<BS2SimpleDeviceInfo>& devices);
    int connectDevice(BS2_DEVICE_ID id);
    int connectDevice(BS2_DEVICE_ID& id, std::string ip, BS2_PORT port = BS2_TCP_DEVICE_PORT_DEFAULT);
    int disconnectDevice(BS2_DEVICE_ID id);

    // Slave
    int searchSlaveDevice(BS2_DEVICE_ID id, std::vector<BS2Rs485SlaveDevice>& slaveList);
    int addSlaveDevice(BS2_DEVICE_ID id, BS2_DEVICE_ID slaveID);
    int deleteSlaveDevice(BS2_DEVICE_ID id, BS2_DEVICE_ID slaveID);
    // Slave (CST)
    int searchCSTSlaveDevice(BS2_DEVICE_ID id, uint32_t channelPort, std::vector<BS2Rs485SlaveDeviceEX>& slaveList);
    int addCSTSlaveDevice(BS2_DEVICE_ID id, uint32_t channelPort, BS2_DEVICE_ID slaveID);
    int deleteCSTSlaveDevice(BS2_DEVICE_ID id, uint32_t channelPort, BS2_DEVICE_ID slaveID);

    // Wiegand
    int searchWiegandDevice(BS2_DEVICE_ID id, std::vector<BS2_DEVICE_ID>& wiegandList);
    int addWiegandDevice(BS2_DEVICE_ID id, BS2_DEVICE_ID wiegandID);
    int getWiegandDevice(BS2_DEVICE_ID id, std::vector<BS2_DEVICE_ID>& wiegandList);
    int deleteWiegandDevice(BS2_DEVICE_ID id, BS2_DEVICE_ID wiegandID);

    int setKeepAliveTimeout();
    int getServerPort();
    int setServerPort();
    int getSSLServerPort();
    int setSSLServerPort();
    int isConnected(BS2_DEVICE_ID id);
    int isAutoConnection();
    int setAutoConnection();
    int getEnableIPV4();
    int setEnableIPV4();
    int getEnableIPV6();
    int setEnableIPV6();
    int getServerPortIPV6();
    int setServerPortIPV6();
    int getSSLServerPortIPV6();
    int setSSLServerPortIPV6();
    int getDefaultResponseTimeout();
    int setDefaultResponseTimeout();


private:
    void* context_;
};

#endif // COMMCONTROL_H
