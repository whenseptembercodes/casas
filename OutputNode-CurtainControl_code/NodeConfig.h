/*
#define PWMA D5
#define AIN1 D7
#define AIN2 D6
//#define BIN1 51
/*
#define BIN2 50
#define PWMB 3
#define STBY D1
#define motor_A 0
#define motor_B 1
*/
#define FORWARD 1
#define REVERSE 0
// #define RIGHT 1
// #define LEFT 0


// Motor direction
#define dir1PinL  D1  
#define dir2PinL  D2   

String blindsState;
bool motorDirection = REVERSE;

// Credentials for authentication when connecting to MQTT Broker
// running on Raspberry Pi to send/receive data from/to input/output nodes
const char *HA_USER = "";
const char *HA_PASS = "";

// Connecting nodes to central hub through MQTT Protocol

char ID[20] = "windowblindsNode";  // Unique name for specific node in the system
const char *CONFIG_TOPIC = "homeassistant/cover/blindsNode/config";
const char *STATE_TOPIC = "homeassistant/cover/windowBlinds/state";
const char *COMMAND_TOPIC = "homeassistant/cover/windowsBlinds/set";
// const char *STATUS_TOPIC = "blindsNode/status"; // optional, for debugging when node is not transmitting/responding 

unsigned long currentMillis;
unsigned long previousMillis = 0; 

// Uptime (in milliseconds) of the Access Point if node can't connect to WiFi
unsigned long interval_AP = 120000; 

// Node will restart if the amount of time reaches this threshold while there is no network connection 
unsigned long interval_restart = 60000;

// Interval before each attempt to connect to WiFi
unsigned long interval_reconnect; 

// Following lines are for the Network Manager webpage that automatically opens
// with CASAS Node Access Point

// Search for parameter in HTTP POST request
const char* PARAM_INPUT_1 = "ssid";
const char* PARAM_INPUT_2 = "pass";
const char* PARAM_INPUT_3 = "ip";
const char* PARAM_INPUT_4 = "gateway";

//Variables to save values from HTML form
String ssid;
String pass;
String ip;
String gateway;

// File paths to save input values permanently
const char* ssidPath = "/ssid.txt";
const char* passPath = "/pass.txt";
const char* ipPath = "/ip.txt";
const char* gatewayPath = "/gateway.txt";