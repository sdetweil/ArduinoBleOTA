#pragma once
#ifdef ESP32
#include "BleOtaStorage.h"
#include "BleOtaVersion.h"
#include "BleOtaSecurityCallbacks.h"
#include "BleOtaUploadCallbacks.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLECharacteristic.h>

class BleOtaUploader;

#define NIMBLE_PROPERTY BLECharacteristic

class ArduinoBleOTAClass: public BLECharacteristicCallbacks
{
public:
    ArduinoBleOTAClass();

    bool begin(const std::string& deviceName,
               OTAStorage& storage,
               const std::string& hwName = " ",
               BleOtaVersion hwVersion = {},
               const std::string& swName = " ",
               BleOtaVersion swVersion = {},
               bool enableUpload = true, bool advertise = true);
    bool begin(OTAStorage &storage,
               const std::string &hwName = " ",
               BleOtaVersion hwVersion = {},
               const std::string &swName = " ",
               BleOtaVersion swVersion = {},
               bool enableUpload = true, bool advertise = true);
    BLEService *begin(BLEServer *server, OTAStorage &storage,
                      const std::string &hwName = " ",
                      BleOtaVersion hwVersion = {},
                      const std::string &swName = " ",
                      BleOtaVersion swVersion = {},
                      bool enableUpload = true, bool advertise = true);
    void pull();

    void enableUpload();
    void disableUpload();
    void setSecurityCallbacks(BleOtaSecurityCallbacks &);
    void setUploadCallbacks(BleOtaUploadCallbacks &);

private:
    friend BleOtaUploader;
    void begin(BLEService& service,
               const std::string& hwName, BleOtaVersion hwVersion,
               const std::string& swName, BleOtaVersion swVersion);
    void onWrite(BLECharacteristic* characteristic) override;
    void send(const uint8_t* data, size_t length);

    BLECharacteristic* txCharacteristic;
    BleOtaSecurityCallbacks *securityCallbacks;
    BleOtaUploadCallbacks *uploadCallbacks;
};

extern ArduinoBleOTAClass ArduinoBleOTA;
#endif
