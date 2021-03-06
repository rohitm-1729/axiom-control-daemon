#ifndef CMVADAPTER_H
#define CMVADAPTER_H

#include <memory>
#include <functional>
#include <unordered_map>
#include <utility>

//#include "MemoryAdapter.h"
#include "IDaemonModule.h"

class MemoryAdapter;

class CMV12000Adapter : public IDaemonModule
{
    uint32_t address;
    uint32_t memorySize;

    std::shared_ptr<MemoryAdapter> _memoryAdapter;
    //uint32_t* mappedAddress;

    // Analog gain
    unsigned int _analogGainValue;
    //unsigned int _gainPGA[8] = {0, 1, 0, 3, 7, 1, 3, 7};
    //unsigned int _divPGA[8] = {8, 8, 0, 8, 8, 0, 0, 0};
    unsigned int _gainPGA[8] = {8, 9, 0, 11, 15, 1, 3, 7};
    std::string _analogGainTextValues[8] = {"1/3", "2/3", "1", "3/3", "4/3", "2", "3", "4"};

    bool SetAnalogGain(std::string gainValue, std::string, std::string& message);
    bool GetAnalogGain(std::string& gainValue, std::string& message);

    // Digital gain
    unsigned int _digitalGainValue;
    unsigned int _digitalGainValues[10] = {1, 2, 3, 4, 6, 8, 10, 12, 14, 16};
    std::string _digitalGainTextValues[10] = {"1", "2", "3", "4", "6", "8", "10", "12", "14", "16"};

    bool SetDigitalGain(std::string gainValue, std::string, std::string& message);
    bool GetDigitalGain(std::string& gainValue, std::string& message);

    // Configuration register
    bool SetConfigRegister(const std::string registerIndex, std::string value, std::string &message);
    // NOTE: On request value contains register index, on reply current value is returned
    bool GetConfigRegister(std::string& value, std::string& message);


    virtual void SetCMVConfigRegister(u_int8_t registerIndex, unsigned int value);

public:
    CMV12000Adapter();

    ~CMV12000Adapter();

    void Execute();

    //bool SetParameter(std::string parameterName, std::string parameterValue);
    //std::string GetParameter(std::string parameterName);

protected:
    void RegisterAvailableMethods();
};

#endif // CMVADAPTER_H
