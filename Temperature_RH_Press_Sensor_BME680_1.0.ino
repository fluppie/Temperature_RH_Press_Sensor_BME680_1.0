/* ---------------------------------------------------------------------------------------------
Temperature and relative humidty Sensor (HTU21D, SHT21...)
Hardware/Firmware/Sketch/kdevice.xml by E.Burkowski / e.burkowski@konnekting.de, GPL Licensed
Compatible with: KONNEKTING Device Library 1.0.0 beta 4
------------------------------------------------------------------------------------------------*/

#include <KonnektingDevice.h>
#include "mi.h"

// include device related configuration code, created by "KONNEKTING CodeGenerator"
#include "kdevice_Temp_RH.h"

// ################################################
// ### DEBUG CONFIGURATION
// ################################################
// #define KDEBUG // comment this line to disable DEBUG mode
#ifdef KDEBUG
#include <DebugUtil.h>
#define DEBUGSERIAL SerialUSB
#endif

//#include "SparkFunHTU21D.h" //https://github.com/sparkfun/SparkFun_HTU21D_Breakout_Arduino_Library
//
//// Create an instance for HTU21D sensor
//HTU21D htu;
//#include "SparkFunBME280.h"
//BME280 mySensor; //Global sensor object

#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
Adafruit_BME680 bme; // I2C

// ################################################
// ### Global variables, sketch related
// ################################################

unsigned long previousTimeTemp = 0;
unsigned long previousTimeHumd = 0;
unsigned long previousTimePress = 0;
unsigned long previousTimeGas = 0;

float previousTemp = 0;
float previousHumd = 0;
float previousPress = 0;
float previousGas = 0;
float currentTemp = 0;
float currentHumd = 0;
float currentPress = 0;
float currentGas = 0;

int typeTemp;
long intervalTempUser; //typical temperatur polling interval (ms)
float diffTempUser; //minimal difference between previous and current temperature [°C]
uint8_t valueTempMin;
int16_t limitTempMin;
bool lastStateTempMin = false;
uint8_t valueTempMax;
int16_t limitTempMax;
bool lastStateTempMax = false;

uint8_t typeHumd;
long intervalHumdUser; //typical temperatur polling interval (ms)
float diffHumdUser;
uint8_t valueHumdMin;
int16_t limitHumdMin;
bool lastStateHumdMin = false;
uint8_t valueHumdMax;
int16_t limitHumdMax;
bool lastStateHumdMax = false;

int typePress;
long intervalPressUser; //typical Pressure polling interval (ms)
float diffPressUser; //minimal difference between previous and current pressure [Pa/hPa]
uint8_t valuePressMin;
int16_t limitPressMin;
bool lastStatePressMin = false;
uint8_t valuePressMax;
int16_t limitPressMax;
bool lastStatePressMax = false;

uint8_t typeGas;
long intervalGasUser; //typical gas polling interval (ms)
float diffGasUser;
uint8_t valueGasMin;
int16_t limitGasMin;
bool lastStateGasMin = false;
uint8_t valueGasMax;
int16_t limitGasMax;
bool lastStateGasMax = false;

// Callback function to handle com objects updates

void knxEvents(byte index) {
    // nothing to do in this sketch
};

void limitReached(float comVal, float comValMin, float comValMax, int minObj, int maxObj, int minVal, int maxVal) {
    if (minVal != 255) {
        if (comVal <= comValMin) {
            
            Knx.write(minObj, minVal);
        }
    }
    if (maxVal != 255) {
        if (comVal >= comValMax) {
            Knx.write(maxObj, maxVal);
        }
    }
};

#include "setup.h"
#include "loop.h"
