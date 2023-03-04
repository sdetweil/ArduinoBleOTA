#pragma once
#include "BleOtaStorage.h"
#include "BleOtaVersion.h"
#include "BleOtaSecurity.h"
#include <NimBLEDevice.h>

class BleOtaUploader;

class ArduinoBleOTAClass: public BLECharacteristicCallbacks
{
public:
    ArduinoBleOTAClass();

    bool begin(const std::string& deviceName,
               OTAStorage& storage,
               const std::string& hwName = {},
               BleOtaVersion hwVersion = {},
               const std::string& swName = {},
               BleOtaVersion swVersion = {});
    bool begin(OTAStorage& storage,
               const std::string& hwName = {},
               BleOtaVersion hwVersion = {},
               const std::string& swName = {},
               BleOtaVersion swVersion = {});
    void setSecurity(BleOtaSecurity& callbacks);
    void pull();

private:
    friend BleOtaUploader;
    void begin(BLEService& service,
               const std::string& hwName, BleOtaVersion hwVersion,
               const std::string& swName, BleOtaVersion swVersion);
    void onWrite(BLECharacteristic* characteristic) override;
    void send(const uint8_t* data, size_t length);

    BLECharacteristic* txCharacteristic;
    BleOtaSecurity* security;
};

extern ArduinoBleOTAClass ArduinoBleOTA;