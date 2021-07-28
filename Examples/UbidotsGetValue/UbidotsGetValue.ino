
#include <SPI.h>
#include <UbidotsUnoWifi.h>

#define ID  "Your_variable_ID_here"  // Put here your Ubidots variable ID
#define TOKEN  "Your_token_here"  // Put here your Ubidots TOKEN


char ssid[] = "yourNetwork"; //  your network SSID (name)
char pass[] = "secretPassword";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)



Ubidots client(TOKEN);

void setup(){
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}

	client.wifiConnect(ssid, pass); // connecting to the wifi
		
}
void loop(){
	float *responseArray;
	float value;
	responseArray = client.getValue(ID);
	// The library return a verify float in the first position, 0 when
	// it doesn't get the value and 1 when it get the value
	// in the second position is the value 
	if (responseArray[0] == 1) {
		value = responseArray[1];
	}
}


