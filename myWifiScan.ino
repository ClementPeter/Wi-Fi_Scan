/*Program to Scan for WiFi network on the ESP 32

This Sketch is here to help you understand the complexity in the Original WiFiScan Sketch  ... @_carlos_dev   */

//Include the WiFi Library
#include "WiFi.h"

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  //Set the WiFi Mode to Station Mode
  //Station Mode enables the ESP-32 to connect to a Router or Hotspot
  WiFi.mode(WIFI_STA);

  //Disconnect the WiFi from any existing connection due to the fact that we need to scan for new ones
  WiFi.disconnect();
  delay(100); //wait for 100 milliseconds

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("**Start Scan**");

  //Scan for available WiFi Network and assign it to "network" varaible then print the number of Networks found
  int network = WiFi.scanNetworks();

  Serial.print("Number of Network : ");
  Serial.println(network);

  if (network == 0) {
    //If there is no WiFi Network around
    Serial.println("No Networks Found");

  }  else {
    Serial.print(network);
    Serial.println(" Networks Found");

    //This FOR loop is used to print multiple Wifi Network on the Serial Monitor

    for (int i = 0; i < network; ++i) {
      //Reason  for Post Increment (++i) is to Increment the value then Assign it to "i"
      //Print the SSID (name) and RSSI (Signal Strenght)
      Serial.print(i + 1);
      Serial.print(":");
      //prints the Individual SSID(Service Set Identifier)
      Serial.print(WiFi.SSID(i));

      //prints the RSSI(Receiver Signal Strenght Indication)
      Serial.println(WiFi.RSSI(i));

        //This line helps to display the Network Encryption Mode whether it's OPEN or has PASSWORD
        //The Tenary Operation checks the Wifi Encryption to see if its OPEN then perfoms commands
        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "   OPEN ":"   Password Required");
    }
  }

  
  Serial.println("    ");
  delay(100);

  Serial.println("**Scan Complete**");
  Serial.println("    ");

  //Wait for 2 seconds and Scans again
  delay(2000);

}
