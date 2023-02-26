#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#include <UniversalTelegramBot.h>
#define BOTtoken "5707309716:AAG6g4clWMPhC6EOX2w15gEolnXxQiTk6KI"
#define CHAT_ID "2022257787"
// DHT sensor
DHT dht(D5 , DHT11);
// END DHT 


// Telegram bot 
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOTtoken, secured_client);
//END Telegram bot 

//Serail Send 
SoftwareSerial NodeMCU(D2,D3);
// END Serail 
IPAddress local_IP(192 , 168 , 113 , 25);
IPAddress gateway(192 , 168 , 113 , 174);
IPAddress subnet(255 , 255 , 255 , 0);

// Enter your wifi network name and Wifi Password
const char* ssid = "USSR";
const char* password = "osama@2244";
// END WIFI NETWORK

// PORT OF WEB SERVER 
WiFiServer server(80);
//END 


// VARIABLE AND CONSTS

const long interval = 1000;
String header;
int temp ;
int temp_web;
int Humidity;
String r1 = "off";
String r2 = "off";
String r3 = "off";
String r4 = "off";
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
long lastTime = 0;
//

void setup() {

  dht.begin();
  NodeMCU.begin(4800);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  Serial.begin(115200);

  
//  if(!WiFi.config(local_IP , gateway ,subnet )){
//    Serial.println("Faild config IP");
//    }
configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

// Connect to Wi-Fi network with SSID and password
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
// Print local IP address and start web server
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin();
NodeMCU.write(11);
delay(30);
NodeMCU.write(22);
delay(30);
NodeMCU.write(33);
delay(30);
NodeMCU.write(44);
delay(30);   
}



//void telegram

void handleNewMessages(int numNewMessages) {

  for (int i = 0; i < numNewMessages; i++)
  {
    String text = bot.messages[i].text;
    
    if (text == "/on1")
    {
            NodeMCU.write(1);
      bot.sendMessage(CHAT_ID, "Relay ON 1", "");
    }

    if (text == "/off1")
    {
           NodeMCU.write(11);

      bot.sendMessage(CHAT_ID, "Relay OFF 1", "");
    }

    if (text == "/on2")
    {
           NodeMCU.write(2);

      bot.sendMessage(CHAT_ID, "Relay ON 2", "");
    }

    if (text == "/off2")
    {
           NodeMCU.write(22);

      bot.sendMessage(CHAT_ID, "Relay OFF 2 ", "");
    }

    if (text == "/on3")
    {
           NodeMCU.write(3);

      bot.sendMessage(CHAT_ID, "Relay ON 3", "");
    }

    if (text == "/off3")
    {
           NodeMCU.write(33);

      bot.sendMessage(CHAT_ID, "Relay OFF 3 ", "");
    }

    if (text == "/on4")
    {
           NodeMCU.write(4);

      bot.sendMessage(CHAT_ID, "Relay ON 4 ", "");
    }

    if (text == "/off4")
    {
           NodeMCU.write(44);

      bot.sendMessage(CHAT_ID, "Relay OFF 4", "");
    }
    if (text == "/temp")
    {
      Serial.print(String(dht.readTemperature()));
      Serial.print("temp");
      bot.sendMessage(CHAT_ID,String(dht.readTemperature()), "");
    }
    
  }
}



// END void
void loop(){

temp_web = (int) dht.readTemperature();

//telegram

 if (millis() - lastTime > interval)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTime = millis();
  }
//END







  
WiFiClient client = server.available(); 

if (client) { 
Serial.println("New Client."); 
String currentLine = ""; 
currentTime = millis();
previousTime = currentTime;
while (client.connected() && currentTime - previousTime <= timeoutTime) { 
  // loop while the client's connected
  
currentTime = millis(); 
if (client.available()) { 
char c = client.read(); 
Serial.write(c); 
header += c;
if (c == '\n') { 
if (currentLine.length() == 0) {

client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();

if (header.indexOf("GET /ON1") >= 0) {
      NodeMCU.write(1);
      delay(30);
      r1 = "on";
      temp = 0;
} else if (header.indexOf("GET /OFF1") >= 0) {
      NodeMCU.write(11);
      delay(30);
      r1 = "off";
      temp = 0;

} else if (header.indexOf("GET /ON2") >= 0) {
      NodeMCU.write(2);
      delay(30);
      r2 = "on";
      temp = 0;

} else if (header.indexOf("GET /OFF2") >= 0) {
      NodeMCU.write(22);
      delay(30);
      r2 = "off";
} else if (header.indexOf("GET /ON3") >= 0) {
      NodeMCU.write(3);
      delay(30);
      r3 = "on";
            temp = 0;

} else if (header.indexOf("GET /OFF3") >= 0) {
      NodeMCU.write(33);
      delay(30);
      r3 = "off";
}else if(header.indexOf("GET /ON4") >= 0){
      NodeMCU.write(4);
      delay(30);
      r4 = "on";
        temp = 0;

  }else if(header.indexOf("GET /OFF4") >= 0){
          NodeMCU.write(44);
      delay(30);
      r4 = "off";
            temp = 0;

    }else if(header.indexOf("GET /Humidity") >= 0){
          NodeMCU.write(44);
         delay(30);
         temp = 2;
         Humidity = 1;
    }else if(header.indexOf("GET /temp") >= 0){
          NodeMCU.write(44);
         delay(30);
         temp = 1;
         Humidity = 0;
    }


// HTML web page
if(temp == 0){
client.println("<!DOCTYPE html><html>");
client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
client.println("<link rel=\"icon\" href=\"data:,\">");
// CSS to style the on/off buttons 
client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
client.println(".buttonRed { background-color: #ff0000; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".buttonGreen { background-color: #00ff00; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".buttonYellow { background-color: #feeb36; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".buttonOff { background-color: #77878A; border: none; color: white; padding: 16px 40px; border-radius: 70%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");

// Web Page Heading
client.println("<body><h1>My LED Control Server</h1>");

client.println("<p>Relay  1 is " + r1 + "</p>");

if (r1=="off") {
client.println("<p><a href=\"/ON1\"><button class=\"button buttonOff\">OFF</button></a></p>");
} else {
client.println("<p><a href=\"/OFF1\"><button class=\"button buttonRed\">ON</button></a></p>");
} 


client.println("<p>Relay  3 is " + r2 + "</p>");

if (r2 =="off") {
client.println("<p><a href=\"/ON2\"><button class=\"button buttonOff\">OFF</button></a></p>");
} else {
client.println("<p><a href=\"/OFF2\"><button class=\"button buttonRed\">ON</button></a></p>");
}
client.println("</body></html>");

client.println("<p>Relay  3 is" + r3 + "</p>");

if (r3 =="off") {
client.println("<p><a href=\"/ON3\"><button class=\"button buttonOff\">OFF</button></a></p>");
} else {
client.println("<p><a href=\"/OFF3\"><button class=\"button buttonRed\">ON</button></a></p>");
}
client.println("<p>Relay  4 is " + r4 + "</p>");

if (r4 =="off") {
client.println("<p><a href=\"/ON4\"><button class=\"button buttonOff\">OFF</button></a></p>");
} else {
client.println("<p><a href=\"/OFF4\"><button class=\"button buttonRed\">ON</button></a></p>");
}
client.println("<center> <h2> Developed by <a  href=\"http://osamaelkassaby.com\" style=\"text-decoration:none;color:#ff0044\"> osamaelkassaby </a> </h2></center>");

client.println("</body></html>");

}else if (temp == 1){

  client.print(temp_web);
  
  }else if (Humidity == 1){
    client.print(int(dht.readHumidity()));
    }
client.println();
break;
} else { 
currentLine = "";
}
} else if (c != '\r') { 
currentLine += c; 
}
}
}
// Clear the header variable
header = "";

client.stop();
Serial.println("Client disconnected.");
Serial.println("");
}
}
