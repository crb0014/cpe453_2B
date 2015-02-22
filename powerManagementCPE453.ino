#include <Ethernet.h>
#include <SPI.h>
#include <string.h>

// Global Variables
boolean reading = false;
boolean entireSys = false;
#define delimiter "-"
#define onVal 1
#define offVal 0

////////////////////////////////////////////////////////////////////////
//CONFIGURE
////////////////////////////////////////////////////////////////////////
  // if need to change the MAC address (Very Rare)
  // The two seperate ethernet shields must have different values
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  IPAddress ip(192, 168, 137, 2);

  EthernetServer server = EthernetServer(80); //port 80
////////////////////////////////////////////////////////////////////////

void setup(){

  // Configure ethernet connection for use
  Ethernet.begin(mac,ip);
  server.begin();

  // Configure pins for output
  for (int i = 0; i < 8; i++) {
	  pinMode(i, OUTPUT);
	  do {
		  digitalWrite(i,offVal);
	  } while(digitalRead(i) != offVal); 

  }

  for (int i = 14; i <= 69; i++) {
	  pinMode(i, OUTPUT);
	  if (i == 50 || i == 51 || i == 52) continue;
	  do {
		  digitalWrite(i,offVal);
	  } while(digitalRead(i) != offVal); 
  }
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
		if(c == '%') entireSys = true; //found the %, begin reading the info
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
	digitalWrite(pin, 1);
  else
	digitalWrite(pin, 0);
}

// Function sets digital pin values appropriately
void individualPinSet(EthernetClient client) {
	// Parse the input for pin number && state
	String line = client.readStringUntil(' ');
	uint8_t pinNumber = line.substring(0,line.indexOf(delimiter,0)).toInt();
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
		for (int i = 0; i < 8; i++) {
			triggerPin(i,client,"on");
		}
		for (int i = 14; i <= 69; i++) {
			triggerPin(i,client,"on");
		}
		client.println("Power System On");
		client.print("<br>");
	} else {
		for (int i = 0; i < 8; i++) {
			triggerPin(i,client,"off");
		}
		for (int i = 14; i <= 69; i++) {
			triggerPin(i,client,"off");
		}
		client.println("Power System Off");
		client.print("<br>");
	}
}
