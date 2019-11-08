void loop() {
    Knx.task();
    unsigned long currentTime = millis();
    
    // only do measurements and other sketch related stuff if not in programming mode
    if (Konnekting.isReadyForApplication()) {
        // Get temperature
        if ((currentTime - previousTimeTemp) >= intervalTempUser) {
           
            unsigned long start = millis();
            //currentTemp = htu.readTemperature();
            //currentTemp = mySensor.readTempC();

            Debug.println(F("Start reading BME680"));
            // Potentially a blocking event
            if (! bme.performReading()) {
              Debug.println("Failed to perform reading :(");
              return;
            }
            Debug.println(F("Finished reading BME680"));

            currentTemp = bme.temperature;
            Debug.println(F("currentTemp from BME read"));
            unsigned long end = millis();
#ifdef KDEBUG              
            Debug.println(F("currentTemp: %3.2f %C time: %d ms"), currentTemp, 0x00B0, (end-start));
#endif
            if (currentTemp < 900) {
                switch (typeTemp) {
                    case 0:
                        Knx.write(COMOBJ_tempValue, currentTemp);
                        break;
                    case 1:
                        if (abs(currentTemp * 100 - previousTemp * 100) >= diffTempUser * 100) {//"*100" => "float to int"
                            Knx.write(COMOBJ_tempValue, currentTemp);
                            previousTemp = currentTemp;
                        }
                        break;
                    default:
                        break;
                }
                limitReached(currentTemp, limitTempMin, limitTempMax, COMOBJ_tempMin, COMOBJ_tempMax, valueTempMin, valueTempMax);
                
            }else{
#ifdef KDEBUG              
            Debug.println(F("Sensor error!"));
#endif 
            }
            previousTimeTemp = currentTime;
        }
        
        // Get humidity
        if ((currentTime - previousTimeHumd) >= intervalHumdUser) {
            unsigned long start = millis();
            //currentHumd = htu.readHumidity();
            //currentHumd = mySensor.readFloatHumidity();
            currentHumd = bme.humidity;
            Debug.println(F("currentHumd from BME read"));
            unsigned long end = millis();
#ifdef KDEBUG              
            Debug.println(F("currentHumd: %3.2f %% time: %d ms"), currentHumd, (end-start));
#endif
            if (currentHumd < 900) {
                
                switch (typeHumd) {
                    case 0:
                        Knx.write(COMOBJ_rhValue, currentHumd);
                        break;
                    case 1:
                        if (abs(currentHumd * 100 - previousHumd * 100) >= diffHumdUser * 100) {
                            Knx.write(COMOBJ_rhValue, currentHumd);
                            previousHumd = currentHumd;
                        }
                    default:
                        break;
                }
                limitReached(currentHumd, limitHumdMin, limitHumdMax, COMOBJ_rhMin, COMOBJ_rhMax, valueHumdMin, valueHumdMax);
                
            }else{
#ifdef KDEBUG              
            Debug.println(F("Sensor error!"));
#endif 
            }
            previousTimeHumd = currentTime;
        }
        
// /* niet gebruiken
        // Get pressure
        if ((currentTime - previousTimePress) >= intervalPressUser) {
            unsigned long start = millis();
            //currentHumd = htu.readHumidity();
            //currentHumd = mySensor.readFloatHumidity();
            currentPress = (bme.pressure/100);
            Debug.println(F("currentPress from BME read"));
            unsigned long end = millis();
#ifdef KDEBUG              
            Debug.println(F("currentPress: %3.2f %hhPa time: %d ms"), currentPress, (end-start));
#endif
            if (currentPress < 1090) {
                
                switch (typePress) {
                    case 0:
                        Knx.write(COMOBJ_pressValue, currentPress);
                        break;
                    case 1:
                        if (abs(currentPress * 100 - previousPress * 100) >= diffPressUser * 100) {
                            Knx.write(COMOBJ_pressValue, currentPress);
                            previousPress = currentPress;
                        }
                    default:
                        break;
                }
                limitReached(currentPress, limitPressMin, limitPressMax, COMOBJ_pressMin, COMOBJ_pressMax, valuePressMin, valuePressMax);
                
            }else{
#ifdef KDEBUG              
            Debug.println(F("Sensor error!"));
#endif 
            }
            previousTimePress = currentTime;
        }

        // Get gas resistance
        if ((currentTime - previousTimeGas) >= intervalGasUser) {
            unsigned long start = millis();
            //currentHumd = htu.readHumidity();
            //currentHumd = mySensor.readFloatHumidity();
            currentGas = (bme.gas_resistance/1000);
            Debug.println(F("currentGas from BME read"));
            unsigned long end = millis();
#ifdef KDEBUG              
            Debug.println(F("currentGas: %3.2f %kOhm time: %d ms"), currentGas, (end-start));
#endif
            if (currentGas < 1000) {
                
                switch (typeGas) {
                    case 0:
                        Knx.write(COMOBJ_gasValue, currentGas);
                        break;
                    case 1:
                        if (abs(currentGas * 100 - previousGas * 100) >= diffGasUser * 100) {
                            Knx.write(COMOBJ_gasValue, currentGas);
                            previousGas = currentGas;
                        }
                    default:
                        break;
                }
                limitReached(currentGas, limitGasMin, limitGasMax, COMOBJ_gasMin, COMOBJ_gasMax, valueGasMin, valueGasMax);
                
            }else{
#ifdef KDEBUG              
            Debug.println(F("Sensor error!"));
#endif 
            }
            previousTimeGas = currentTime;
        }
// niet gebruiken */        
    }
}
