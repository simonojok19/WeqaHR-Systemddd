#ifndef LOGCONTROL_H
#define LOGCONTROL_H


#pragma once

#include <vector>
#include <string>
#include "BS_API.h"


class LogControl
{
public:
    LogControl(void* sdkContext);
    virtual ~LogControl();


public:
    int getLogSmallBlob(BS2_DEVICE_ID id);


private:
    void print(const BS2EventSmallBlob* logs, uint32_t numLog);
    void print(const BS2EventExtInfo& info);


private:
    static void* context_;
};


#endif // LOGCONTROL_H
