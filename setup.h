void setup() {
    // debug related stuff
#ifdef KDEBUG
   // Start debug serial with 9600 bauds
    DEBUGSERIAL.begin(9600);
    while (!DEBUGSERIAL)
    // make debug serial port known to debug class
    // Means: KONNEKTING will sue the same serial port for console debugging
    Debug.setPrintStream(&DEBUGSERIAL);
#endif

    Wire.begin();
    Konnekting.setMemoryReadFunc(&readMemory);
    Konnekting.setMemoryWriteFunc(&writeMemory);
    Konnekting.setMemoryUpdateFunc(&updateMemory);
    Konnekting.setMemoryCommitFunc(&commitMemory);
    
    // Initialize KNX enabled Arduino Board
    Konnekting.init(KNX_SERIAL, PROG_BUTTON_PIN, PROG_LED_PIN, MANUFACTURER_ID, DEVICE_ID, REVISION);

    if (!Konnekting.isFactorySetting()){
        int startDelay = (int) Konnekting.getUINT16Param(PARAM_initialDelay);
        if (startDelay > 0) {
#ifdef KDEBUG  
     Debug.println(F("delay for %d ms"),startDelay);
#endif
     delay(startDelay);
#ifdef KDEBUG  
     Debug.println(F("ready!"));
#endif
    }
    //set i2c clock to 400kHz
    Wire.setClock(400000L);
    
    // Set I2C to 3.4 MHz
    //Wire.setClock(3400000L);
   
//    //htu sensor start
//    htu.begin();
//  mySensor.settings.I2CAddress = 0x76;
//  if (mySensor.beginI2C() == false) //Begin communication over I2C
//  {
//    Serial.println("The chip did not respond. Please check wiring.");
//    while(1); //Freeze
//  }

  if (!bme.begin(0x76)) {
    Debug.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms

    typeTemp = (int) Konnekting.getUINT8Param(PARAM_tempSendUpdate);
    
    //temperature polling interval (ms)
    intervalTempUser = (long) Konnekting.getUINT32Param(PARAM_tempPollingTime)*1000; 
    //intervalTempUser = 30000;
    
    //minimal difference between previous and current temperature [°C]
    diffTempUser = (float) Konnekting.getUINT8Param(PARAM_tempDiff)*0.1; 
    valueTempMin = Konnekting.getUINT8Param(PARAM_tempMinValue);
    limitTempMin = Konnekting.getINT16Param(PARAM_tempMinLimit);
    valueTempMax = Konnekting.getUINT8Param(PARAM_tempMaxValue);
    limitTempMax = Konnekting.getINT16Param(PARAM_tempMaxLimit);
    Debug.println(F("Temp parameters gelezen"));

    typeHumd = Konnekting.getUINT8Param(PARAM_rhSendUpdate);
    intervalHumdUser = (long) Konnekting.getUINT32Param(PARAM_rhPollingTime)*1000; //humidity polling interval (ms)
    //intervalHumdUser = 30000;
    diffHumdUser = (float) Konnekting.getUINT8Param(PARAM_rhDiff)*0.1;
    valueHumdMin = Konnekting.getUINT8Param(PARAM_rhMinValue);
    limitHumdMin = Konnekting.getINT16Param(PARAM_rhMinLimit);
    valueHumdMax = Konnekting.getUINT8Param(PARAM_rhMaxValue);
    limitHumdMax = Konnekting.getINT16Param(PARAM_rhMaxLimit);
    Debug.println(F("Hum parameters gelezen"));
    
    typePress = Konnekting.getUINT8Param(PARAM_pressSendUpdate);
    intervalPressUser = (long) Konnekting.getUINT32Param(PARAM_pressPollingTime)*1000; //humidity polling interval (ms)
    //intervalPressUser = 30000;
    diffPressUser = (float) Konnekting.getUINT8Param(PARAM_pressDiff)*0.1;
    valuePressMin = Konnekting.getUINT8Param(PARAM_pressMinValue);
    limitPressMin = Konnekting.getINT16Param(PARAM_pressMinLimit);
    valuePressMax = Konnekting.getUINT8Param(PARAM_pressMaxValue);
    limitPressMax = Konnekting.getINT16Param(PARAM_pressMaxLimit);
    Debug.println(F("Press parameters gelezen"));
    
    typeGas = Konnekting.getUINT8Param(PARAM_gasSendUpdate);
    intervalGasUser = (long) Konnekting.getUINT32Param(PARAM_gasPollingTime)*1000; //humidity polling interval (ms)
    //intervalGasUser = 30000;
    diffGasUser = (float) Konnekting.getUINT8Param(PARAM_gasDiff)*0.1;
    valueGasMin = Konnekting.getUINT8Param(PARAM_gasMinValue);
    limitGasMin = Konnekting.getINT16Param(PARAM_gasMinLimit);
    valueGasMax = Konnekting.getUINT8Param(PARAM_gasMaxValue);
    limitGasMax = Konnekting.getINT16Param(PARAM_gasMaxLimit);
    Debug.println(F("Gas parameters gelezen"));
    }
    Debug.println(F("Setup is ready. go to loop..."));
}
