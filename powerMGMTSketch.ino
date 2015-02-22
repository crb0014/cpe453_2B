#include <Ethernet.h>
#include <SPI.h>
#include <string.h>

// Global Variables
boolean reading = false;
boolean entireSys = false;
#define delimiter "-"

////////////////////////////////////////////////////////////////////////
//CONFIGURE
////////////////////////////////////////////////////////////////////////
  //byte ip[] = { 192, 168, 0, 199 };   //Manual setup only
  //byte gateway[] = { 192, 168, 0, 1 }; //Manual setup only
  //byte subnet[] = { 255, 255, 255, 0 }; //Manual setup only

  // if need to change the MAC address (Very Rare)
  // The two seperate ethernet shields must have different values
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  IPAddress ip(192, 168, 137, 2);

  EthernetServer server = EthernetServer(80); //port 80
////////////////////////////////////////////////////////////////////////

void setup(){
  Serial.begin(57600);

  // Configure pins for output
  // Pins 10,11,12 & 13 are used by the ethernet shield
  for (int i = 1; i < 54; i++)
	  pinMode(i, OUTPUT);

  // Configure Analog Pins for digital use
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A6,OUTPUT);
  pinMode(A7,OUTPUT);
  pinMode(A8,OUTPUT);
  pinMode(A9,OUTPUT);
  pinMode(A10,OUTPUT);
  pinMode(A11,OUTPUT);
  pinMode(A12,OUTPUT);
  pinMode(A13,OUTPUT);
  pinMode(A14,OUTPUT);
  pinMode(A15,OUTPUT);

  // Configure ethernet connection for use
  Ethernet.begin(mac,ip);
  //Ethernet.begin(mac, ip, gateway, subnet); //for manual setup

  server.begin();
  Serial.println(Ethernet.localIP());
}

void loop(){

  // listen for incoming clients, and process qequest.
  checkForClient();

}

void checkForClient(){

  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    boolean sentHeader = false;

    while (client.connected()) {
      if (client.available()) {

        if(!sentHeader){
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          sentHeader = true;
        }

        char c = client.read();

		if(reading && c == ' ') reading = false;
        if(c == '?') reading = true; //found the ?, begin reading the info
		if(c == '%') entireSys = true; //found the &, begin reading the info
		if(reading) individualPinSet(client); // This calls for the system to power individual pins up/down

		if(entireSys) {				// This calls for the system to power fully up/down
			powerSet(client);
			entireSys = false;
		}

        if (c == '\n' && currentLineIsBlank)  break;
        if (c == '\n') {
          currentLineIsBlank = true;
        }else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1); // give the web browser time to receive the data
    client.stop(); // close the connection:
  } 
}

// This function manipulates individual pins to set their output
void triggerPin(int pin, EthernetClient client, String mode){
//blink a pin - Client needed just for HTML output purposes.  
  if (mode == "on")
	if (pin <= 53) 
		digitalWrite(pin, 1);
	else 
		powerIndividualAnalog(pin,mode);
  else
	if (pin <= 53)
	  digitalWrite(pin, 0);
	else 
		powerIndividualAnalog(pin,mode);
  delay(250);
}

// Function sets digital pin values appropriately
void individualPinSet(EthernetClient client) {
	// Parse the input for pin number && state
	String line = client.readStringUntil(' ');
	int pinNumber = line.substring(0,line.indexOf(delimiter,0)).toInt();
	String state = line.substring(line.indexOf(delimiter,0)+1);

	// Change the state of the wanted pin			
	triggerPin(pinNumber,client,state);
	reading = false;
	client.print("Toggling ");
	client.print(pinNumber);
	client.print(" ");
	client.println(state);
	client.print("<br>");
}

// Function for powering on/off the entire system
void powerSet(EthernetClient client) { 
	String line = client.readStringUntil(' ');
	if (line == "on") {
		for (int i = 1; i < 54; i++) {
			triggerPin(i,client,"on");
		}
		for (int i = 54; i < 70; i++) {
			powerIndividualAnalog(i,"on");
		}
		client.println("Power System On");
		client.print("<br>");
	} else {
		for (int i = 1; i < 54; i++) {
			triggerPin(i,client,"off");
		}
		for (int i = 54; i < 70; i++) {
			powerIndividualAnalog(i,"off");
		}
		client.println("Power System Off");
		client.print("<br>");
	}
}

// Sets the individual analog pins appropriately
void powerIndividualAnalog(int pin, String state) {
	int setState = 0;
	if (state == "on") setState = 1;
	if (pin == 54) digitalWrite(A0,setState);
	else if (pin == 55) digitalWrite(A1,setState);
	else if (pin == 56) digitalWrite(A2,setState);
	else if (pin == 57) digitalWrite(A3,setState);
	else if (pin == 58) digitalWrite(A4,setState);
	else if (pin == 59) digitalWrite(A5,setState);
	else if (pin == 60) digitalWrite(A6,setState);
	else if (pin == 61) digitalWrite(A7,setState);
	else if (pin == 62) digitalWrite(A8,setState);
	else if (pin == 63) digitalWrite(A9,setState);
	else if (pin == 64) digitalWrite(A10,setState);
	else if (pin == 65) digitalWrite(A11,setState);
	else if (pin == 66) digitalWrite(A12,setState);
	else if (pin == 67) digitalWrite(A13,setState);
	else if (pin == 68) digitalWrite(A14,setState);
	else if (pin == 69) digitalWrite(A15,setState);
}
