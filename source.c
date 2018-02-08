#include <SPI.h>
#include <WiFi101.h>

char ssid[] = "Apt_4126";
char pass[] = "TheGlendon4126";
int keyIndex = 0;

bool first = true;
String s = "";
String favicon = "HTTP/1/1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<head><title>Not Found</title></head><body>Sorry</body></html>\n";

const short int DO = 22;
const short int RE = 24;
const short int MI = 26;
const short int FA = 28;
const short int SO = 30;
const short int LA = 32;
const short int TI = 34;
const short int SERVO = 36;

void HappyBirthday();
void printWifiStatus();

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  pinMode(DO, OUTPUT);
  digitalWrite(DO, HIGH); //Initial state is OFF
  pinMode(RE, OUTPUT);
  digitalWrite(RE, HIGH);
  pinMode(MI, OUTPUT);
  digitalWrite(MI, HIGH);
  pinMode(FA, OUTPUT);
  digitalWrite(FA, HIGH);
  pinMode(SO, OUTPUT);
  digitalWrite(SO, HIGH);
  pinMode(LA, OUTPUT);
  digitalWrite(LA, HIGH);
  pinMode(TI, OUTPUT);
  digitalWrite(TI, HIGH);
  pinMode(SERVO, OUTPUT);
  digitalWrite(SERVO, LOW);
  

  s = "HTTP/1/1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  s += "<br><input = type=\"button\" name\"b1\" value=\"DO\" onclick=\"location.href='/DO'\">";
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"RE\" onclick=\"location.href='/RE'\">";
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
  s += "<br><br><br>";
  s += "<br><input = type=\"button\" name\"b1\" value=\"Happy Birthday\" onclick=\"location.href='/HappyBirthday'\">";
  s += "</html>\n";

  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");
    while (true);
  }

  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10);
  }
  server.begin();
  printWifiStatus();
}


void loop()
{
  WiFiClient client = server.available();

  if (!client)
  {
    return;
  }

  String request = client.readString();
  if (request == "")
  {
    return;
  }
  Serial.println(request);
  if (request.indexOf("/favicon.ico") != -1)
  {
    client.flush();
    client.print(favicon);
    delay(10);
    client.stop();
    return;
  }
  if (first)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    Serial.println(s);
    delay(10);
    first = false;
    client.stop();
    return;
  }

  if (request.indexOf(" /DO") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    digitalWrite(DO, LOW);
    delay(1000);
    digitalWrite(DO, HIGH);
  }
  else if (request.indexOf(" /RE") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    digitalWrite(RE, LOW);
    delay(1000);
    digitalWrite(RE, HIGH);
  }
  else if (request.indexOf(" /MI") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    digitalWrite(MI, LOW);
    delay(1000);
    digitalWrite(MI, HIGH);
  }
  else if (request.indexOf(" /FA") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    digitalWrite(FA, LOW);
    delay(1000);
    digitalWrite(FA, HIGH);
  }
  else if (request.indexOf(" /SO") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    digitalWrite(SO, LOW);
    delay(1000);
    digitalWrite(SO, HIGH);
  }
  else if (request.indexOf(" /LA") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    digitalWrite(LA, LOW);
    delay(1000);
    digitalWrite(LA, HIGH);
  }
  else if (request.indexOf(" /TI") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    digitalWrite(TI, LOW);
    delay(1000);
    digitalWrite(TI, HIGH);
  }
  else if (request.indexOf(" /HappyBirthday") != -1)
  {
    client.flush(); //clear previous info in the stream
    client.print(s); // Send the response to the client
    delay(10);
    client.stop();
    Serial.println(s);
    HappyBirthday();
  }
  else
  {
    client.stop();
    return;
  }
}

void printWifiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void HappyBirthday()
{
  digitalWrite(SERVO, HIGH);
  digitalWrite(DO, LOW);
  delay(200);
  digitalWrite(DO, HIGH);
  delay(100);
  digitalWrite(DO, LOW);
  delay(200);
  digitalWrite(DO, HIGH);
  delay(200);
  digitalWrite(RE, LOW);
  delay(300);
  digitalWrite(RE, HIGH);
  delay(200);
  digitalWrite(DO, LOW);
  delay(250);
  digitalWrite(DO, HIGH);
  delay(200);
  digitalWrite(FA, LOW);
  delay(300);
  digitalWrite(FA, HIGH);
  delay(200);
  digitalWrite(MI, LOW);
  delay(500);
  digitalWrite(MI, HIGH);
  delay(1000);

  digitalWrite(DO, LOW);
  delay(200);
  digitalWrite(DO, HIGH);
  delay(100);
  digitalWrite(DO, LOW);
  delay(200);
  digitalWrite(DO, HIGH);
  delay(200);
  digitalWrite(RE, LOW);
  delay(300);
  digitalWrite(RE, HIGH);
  delay(200);
  digitalWrite(DO, LOW);
  delay(250);
  digitalWrite(DO, HIGH);
  delay(200);
  digitalWrite(SO, LOW);
  delay(300);
  digitalWrite(SO, HIGH);
  delay(200);
  digitalWrite(FA, LOW);
  delay(500);
  digitalWrite(FA, HIGH);
  delay(1000);

  digitalWrite(DO, LOW);
  delay(250);
  digitalWrite(DO, HIGH);
  delay(200);
  digitalWrite(DO, LOW);
  delay(250);
  digitalWrite(DO, HIGH);
  delay(200);
  digitalWrite(DO, LOW);
  delay(250);
  digitalWrite(DO, HIGH);
  delay(200);
  digitalWrite(LA, LOW);
  delay(250);
  digitalWrite(LA, HIGH);
  delay(200);
  digitalWrite(FA, LOW);
  delay(250);
  digitalWrite(FA, HIGH);
  delay(200);
  digitalWrite(MI, LOW);
  delay(250);
  digitalWrite(MI, HIGH);
  delay(200);
  digitalWrite(RE, LOW);
  delay(250);
  digitalWrite(RE, HIGH);
  delay(200);

  digitalWrite(TI, LOW);
  delay(250);
  digitalWrite(TI, HIGH);
  delay(200);
  digitalWrite(TI, LOW);
  delay(250);
  digitalWrite(TI, HIGH);
  delay(200);
  digitalWrite(LA, LOW);
  delay(250);
  digitalWrite(LA, HIGH);
  delay(200);
  digitalWrite(FA, LOW);
  delay(250);
  digitalWrite(FA, HIGH);
  delay(200);
  digitalWrite(SO, LOW);
  delay(250);
  digitalWrite(SO, HIGH);
  delay(200);
  digitalWrite(FA, LOW);
  delay(250);
  digitalWrite(FA, HIGH);
  delay(200);
  digitalWrite(SERVO, LOW);
}