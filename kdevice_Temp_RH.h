#define MANUFACTURER_ID 7070
#define DEVICE_ID 2
#define REVISION 1

#define COMOBJ_tempValue 0
#define COMOBJ_tempMin 1
#define COMOBJ_tempMax 2
#define COMOBJ_rhValue 3
#define COMOBJ_rhMin 4
#define COMOBJ_rhMax 5
#define COMOBJ_pressValue 6
#define COMOBJ_pressMin 7
#define COMOBJ_pressMax 8
#define COMOBJ_gasValue 9
#define COMOBJ_gasMin 10
#define COMOBJ_gasMax 11
#define PARAM_initialDelay 0
#define PARAM_tempSendUpdate 1
#define PARAM_tempPollingTime 2
#define PARAM_tempDiff 3
#define PARAM_tempMinValue 4
#define PARAM_tempMinLimit 5
#define PARAM_tempMaxValue 6
#define PARAM_tempMaxLimit 7
#define PARAM_rhSendUpdate 8
#define PARAM_rhPollingTime 9
#define PARAM_rhDiff 10
#define PARAM_rhMinValue 11
#define PARAM_rhMinLimit 12
#define PARAM_rhMaxValue 13
#define PARAM_rhMaxLimit 14
#define PARAM_pressSendUpdate 15
#define PARAM_pressPollingTime 16
#define PARAM_pressDiff 17
#define PARAM_pressMinValue 18
#define PARAM_pressMinLimit 19
#define PARAM_pressMaxValue 20
#define PARAM_pressMaxLimit 21
#define PARAM_gasSendUpdate 22
#define PARAM_gasPollingTime 23
#define PARAM_gasDiff 24
#define PARAM_gasMinValue 25
#define PARAM_gasMinLimit 26
#define PARAM_gasMaxValue 27
#define PARAM_gasMaxLimit 28
        
KnxComObject KnxDevice::_comObjectsList[] = {
    /* Index 0 - tempValue */ KnxComObject(KNX_DPT_9_001, 0x34),
    /* Index 1 - tempMin */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 2 - tempMax */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 3 - rhValue */ KnxComObject(KNX_DPT_9_007, 0x34),
    /* Index 4 - rhMin */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 5 - rhMax */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 6 - pressValue */ KnxComObject(KNX_DPT_9_006, 0x34),
    /* Index 7 - pressMin */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 8 - pressMax */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 9 - gasValue */ KnxComObject(KNX_DPT_9_008, 0x34),
    /* Index 10 - gasMin */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 11 - gasMax */ KnxComObject(KNX_DPT_1_001, 0x34)
};
const byte KnxDevice::_numberOfComObjects = sizeof (_comObjectsList) / sizeof (KnxComObject); // do not change this code
       
byte KonnektingDevice::_paramSizeList[] = {
    /* Index 0 - initialDelay */ PARAM_UINT16,
    /* Index 1 - tempSendUpdate */ PARAM_UINT8,
    /* Index 2 - tempPollingTime */ PARAM_UINT32,
    /* Index 3 - tempDiff */ PARAM_UINT8,
    /* Index 4 - tempMinValue */ PARAM_UINT8,
    /* Index 5 - tempMinLimit */ PARAM_INT16,
    /* Index 6 - tempMaxValue */ PARAM_UINT8,
    /* Index 7 - tempMaxLimit */ PARAM_INT16,
    /* Index 8 - rhSendUpdate */ PARAM_UINT8,
    /* Index 9 - rhPollingTime */ PARAM_UINT32,
    /* Index 10 - rhDiff */ PARAM_UINT8,
    /* Index 11 - rhMinValue */ PARAM_UINT8,
    /* Index 12 - rhMinLimit */ PARAM_INT16,
    /* Index 13 - rhMaxValue */ PARAM_UINT8,
    /* Index 14 - rhMaxLimit */ PARAM_INT16,
    /* Index 15 - pressSendUpdate */ PARAM_UINT8,
    /* Index 16 - pressPollingTime */ PARAM_UINT32,
    /* Index 17 - pressDiff */ PARAM_UINT8,
    /* Index 18 - pressMinValue */ PARAM_UINT8,
    /* Index 19 - pressMinLimit */ PARAM_INT16,
    /* Index 20 - pressMaxValue */ PARAM_UINT8,
    /* Index 21 - pressMaxLimit */ PARAM_INT16,
    /* Index 22 - gasSendUpdate */ PARAM_UINT8,
    /* Index 23 - gasPollingTime */ PARAM_UINT32,
    /* Index 24 - gasDiff */ PARAM_UINT8,
    /* Index 25 - gasMinValue */ PARAM_UINT8,
    /* Index 26 - gasMinLimit */ PARAM_INT16,
    /* Index 27 - gasMaxValue */ PARAM_UINT8,
    /* Index 28 - gasMaxLimit */ PARAM_INT16
};
//const byte KonnektingDevice::_numberOfParams = sizeof (_paramSizeList); // do not change this code
const int KonnektingDevice::_numberOfParams = sizeof (_paramSizeList); // BETA4b do not change this code
