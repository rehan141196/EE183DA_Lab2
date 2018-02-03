#include <ESP8266WiFi.h>

WiFiServer server(80);
const short int DO = D0; // GPIO16
const short int RE = D4; // GPIO2
/*const short int MI = ; // GPIO
const short int FA = ; // GPIO
const short int SO = ; // GPIO
const short int LA = ; // GPIO
const short int TI = ; // GPIO*/

void setup() {

WiFi.mode(WIFI_AP);
WiFi.softAP("ESP8266", "laafakhaayega");
server.begin();


Serial.begin(115200); // Start communication between the ESP8266-12E and the monitor window
IPAddress HTTPS_ServerIP= WiFi.softAPIP(); // Obtain the IP of the Server 
Serial.print("Server IP is: ");
Serial.println(HTTPS_ServerIP);

pinMode(DO, OUTPUT);
digitalWrite(DO, LOW); //Initial state is OFF
pinMode(RE, OUTPUT);
digitalWrite(RE, LOW); //Initial state is OFF
/*
pinMode(MI, OUTPUT);
digitalWrite(MI, LOW); //Initial state is OFF
pinMode(FA, OUTPUT);
digitalWrite(FA, LOW); //Initial state is OFF
pinMode(SO, OUTPUT);
digitalWrite(SO, LOW); //Initial state is OFF
pinMode(LA, OUTPUT);
digitalWrite(LA, LOW); //Initial state is OFF
pinMode(TI, OUTPUT);
digitalWrite(TI, LOW); //Initial state is OFF
pinMode(TI, OUTPUT);
*/
}

void loop() {
  
WiFiClient client = server.available();
if (!client) { 
return; 
} 

Serial.println("Somebody has connected :)");

//Read what the browser has sent into a String class and print the request to the monitor
String request = client.readStringUntil('\r'); 
Serial.println(request);

// Handle the Request


if (request.indexOf("/DO") != -1)
  { 
    digitalWrite(DO, HIGH);
    delay(1000);
    digitalWrite(DO, LOW);
  }
else if (request.indexOf("/RE") != -1)
  { 
    digitalWrite(RE, HIGH);
    delay(1000);
    digitalWrite(RE, LOW);
  }/*
else if (request.indexOf("/MI") != -1)
  { 
    digitalWrite(MI, HIGH);
    delay(1000);
    digitalWrite(MI, LOW);
  }
else if (request.indexOf("/FA") != -1)
  { 
    digitalWrite(FA, HIGH);
    delay(1000);
    digitalWrite(FA, LOW);
  }
else if (request.indexOf("/SO") != -1)
  { 
    digitalWrite(SO, HIGH);
    delay(1000);
    digitalWrite(SO, LOW);
  }
else if (request.indexOf("/LA") != -1)
  { 
    digitalWrite(LA, HIGH);
    delay(1000);
    digitalWrite(LA, LOW);
  }
else if (request.indexOf("/TI") != -1)
  { 
    digitalWrite(TI, HIGH);
    delay(1000);
    digitalWrite(TI, LOW);
  }
  */


  // Prepare the HTML document to respond and add buttons:
  String s = "HTTP/1/1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  s += "<br><input = type=\"button\" name\"b1\" value=\"DO\" onclick=\"location.href='/DO'\">";
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"RE\" onclick=\"location.href='/RE'\">";
  /*
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"MI\" onclick=\"location.href='/MI'\">";
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"FA\" onclick=\"location.href='/FA'\">";
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"SO\" onclick=\"location.href='/SO'\">";
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"LA\" onclick=\"location.href='/LA'\">";
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"TI\" onclick=\"location.href='/TI'\">";
  */
  s += "</html>\n";

//Serve the HTML document to the browser.

client.flush(); //clear previous info in the stream 
client.print(s); // Send the response to the client 
delay(1); 
Serial.println("Client disonnected"); //Looking under the hood
}





// To play pre-recorded songs we need to create buttons for the songs and then depending on the button pressed call a function that has the notes for that song

/*
void HappyBirthday()
{
  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(RE, HIGH);
  delay(500);
  digitalWrite(RE, LOW);
  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(FA, HIGH);
  delay(500);
  digitalWrite(FA, LOW);
  digitalWrite(MI, HIGH);
  delay(500);
  digitalWrite(MI, LOW);

  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(RE, HIGH);
  delay(500);
  digitalWrite(RE, LOW);
  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(SO, HIGH);
  delay(500);
  digitalWrite(SO, LOW);
  digitalWrite(FA, HIGH);
  delay(500);
  digitalWrite(FA, LOW);

  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(DO, HIGH);
  delay(500);
  digitalWrite(DO, LOW);
  digitalWrite(LA, HIGH);
  delay(500);
  digitalWrite(LA, LOW);
  digitalWrite(FA, HIGH);
  delay(500);
  digitalWrite(FA, LOW);
  digitalWrite(MIA, HIGH);
  delay(500);
  digitalWrite(MI, LOW);
  digitalWrite(RE, HIGH);
  delay(500);
  digitalWrite(RE, LOW);

  digitalWrite(TI, HIGH);
  delay(500);
  digitalWrite(TI, LOW);
  digitalWrite(TI, HIGH);
  delay(500);
  digitalWrite(TI, LOW);
  digitalWrite(LA, HIGH);
  delay(500);
  digitalWrite(LA, LOW);
  digitalWrite(FA, HIGH);
  delay(500);
  digitalWrite(FA, LOW);
  digitalWrite(SO, HIGH);
  delay(500);
  digitalWrite(SO, LOW);
  digitalWrite(FA, HIGH);
  delay(500);
  digitalWrite(FA, LOW); 
}
*/