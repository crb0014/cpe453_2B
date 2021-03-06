#define CONFIG_FILE "/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/config.ini"
#define IMAX 2
#define JMAX 4
#define KMAX 16
#define MAX (IMAX * JMAX * KMAX)

// Global Variables
static QString IP_ADDRESS_ARDUINO_1;
static QString IP_ADDRESS_ARDUINO_2;
static QString dsArray[MAX][3] = {
     {"ds1_1_1","Black","54"},
     {"ds1_1_2","Black","55"},
     {"ds1_1_3","Black","56"},
     {"ds1_1_4","Black","57"},
     {"ds1_1_5","Black","58"},
     {"ds1_1_6","Black","59"},
     {"ds1_1_7","Black","60"},
     {"ds1_1_8","Black","61"},
     {"ds1_1_9","Black","62"},
     {"ds1_1_10","Black","63"},
     {"ds1_1_11","Black","64"},
     {"ds1_1_12","Black","65"},
     {"ds1_1_13","Black","66"},
     {"ds1_1_14","Black","67"},
     {"ds1_1_15","Black","68"},
     {"ds1_1_16","Black","69"},
     {"ds1_2_1","Black","22"},
     {"ds1_2_2","Black","23"},
     {"ds1_2_3","Black","24"},
     {"ds1_2_4","Black","25"},
     {"ds1_2_5","Black","26"},
     {"ds1_2_6","Black","27"},
     {"ds1_2_7","Black","28"},
     {"ds1_2_8","Black","29"},
     {"ds1_2_9","Black","30"},
     {"ds1_2_10","Black","31"},
     {"ds1_2_11","Black","32"},
     {"ds1_2_12","Black","33"},
     {"ds1_2_13","Black","34"},
     {"ds1_2_14","Black","35"},
     {"ds1_2_15","Black","36"},
     {"ds1_2_16","Black","37"},
     {"ds1_3_1","Black","38"},
     {"ds1_3_2","Black","39"},
     {"ds1_3_3","Black","40"},
     {"ds1_3_4","Black","41"},
     {"ds1_3_5","Black","42"},
     {"ds1_3_6","Black","43"},
     {"ds1_3_7","Black","44"},
     {"ds1_3_8","Black","45"},
     {"ds1_3_9","Black","46"},
     {"ds1_3_10","Black","47"},
     {"ds1_3_11","Black","48"},
     {"ds1_3_12","Black","49"},
     {"ds1_3_13","Black","53"},
     {"ds1_3_14","Black","11"},
     {"ds1_3_15","Black","12"},
     {"ds1_3_16","Black","13"},
     {"ds1_4_1","Black","0"},
     {"ds1_4_2","Black","1"},
     {"ds1_4_3","Black","2"},
     {"ds1_4_4","Black","3"},
     {"ds1_4_5","Black","4"},
     {"ds1_4_6","Black","5"},
     {"ds1_4_7","Black","6"},
     {"ds1_4_8","Black","7"},
     {"ds1_4_9","Black","14"},
     {"ds1_4_10","Black","15"},
     {"ds1_4_11","Black","16"},
     {"ds1_4_12","Black","17"},
     {"ds1_4_13","Black","18"},
     {"ds1_4_14","Black","19"},
     {"ds1_4_15","Black","20"},
     {"ds1_4_16","Black","21"},
     {"ds2_1_1","Black","54"},
     {"ds2_1_2","Black","55"},
     {"ds2_1_3","Black","56"},
     {"ds2_1_4","Black","57"},
     {"ds2_1_5","Black","58"},
     {"ds2_1_6","Black","59"},
     {"ds2_1_7","Black","60"},
     {"ds2_1_8","Black","61"},
     {"ds2_1_9","Black","62"},
     {"ds2_1_10","Black","63"},
     {"ds2_1_11","Black","64"},
     {"ds2_1_12","Black","65"},
     {"ds2_1_13","Black","66"},
     {"ds2_1_14","Black","67"},
     {"ds2_1_15","Black","68"},
     {"ds2_1_16","Black","69"},
     {"ds2_2_1","Black","22"},
     {"ds2_2_2","Black","23"},
     {"ds2_2_3","Black","24"},
     {"ds2_2_4","Black","25"},
     {"ds2_2_5","Black","26"},
     {"ds2_2_6","Black","27"},
     {"ds2_2_7","Black","28"},
     {"ds2_2_8","Black","29"},
     {"ds2_2_9","Black","30"},
     {"ds2_2_10","Black","31"},
     {"ds2_2_11","Black","32"},
     {"ds2_2_12","Black","33"},
     {"ds2_2_13","Black","34"},
     {"ds2_2_14","Black","35"},
     {"ds2_2_15","Black","36"},
     {"ds2_2_16","Black","37"},
     {"ds2_3_1","Black","38"},
     {"ds2_3_2","Black","39"},
     {"ds2_3_3","Black","40"},
     {"ds2_3_4","Black","41"},
     {"ds2_3_5","Black","42"},
     {"ds2_3_6","Black","43"},
     {"ds2_3_7","Black","44"},
     {"ds2_3_8","Black","45"},
     {"ds2_3_9","Black","46"},
     {"ds2_3_10","Black","47"},
     {"ds2_3_11","Black","48"},
     {"ds2_3_12","Black","49"},
     {"ds2_3_13","Black","53"},
     {"ds2_3_14","Black","11"},
     {"ds2_3_15","Black","12"},
     {"ds2_3_16","Black","13"},
     {"ds2_4_1","Black","0"},
     {"ds2_4_2","Black","1"},
     {"ds2_4_3","Black","2"},
     {"ds2_4_4","Black","3"},
     {"ds2_4_5","Black","4"},
     {"ds2_4_6","Black","5"},
     {"ds2_4_7","Black","6"},
     {"ds2_4_8","Black","7"},
     {"ds2_4_9","Black","14"},
     {"ds2_4_10","Black","15"},
     {"ds2_4_11","Black","16"},
     {"ds2_4_12","Black","17"},
     {"ds2_4_13","Black","18"},
     {"ds2_4_14","Black","19"},
     {"ds2_4_15","Black","20"},
     {"ds2_4_16","Black","21"}
};
