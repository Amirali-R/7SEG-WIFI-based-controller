// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid     = "";
const char* password = "";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output0 = "off";
String output1 = "off";
String output2 = "off";
String output3 = "off";
String output4 = "off";
String output5 = "off";
String output6 = "off";
String output7 = "off";
String output8 = "off";
String output9 = "off";

const int a = 16;
const int b = 5;
const int c = 4;
const int d = 0;
const int e = 2;
const int f = 14;
const int g = 12;
const int dp = 13;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(a, OUTPUT);
  digitalWrite(a,HIGH);
  pinMode(b, OUTPUT);
  digitalWrite(b,HIGH);
  pinMode(c, OUTPUT);
  digitalWrite(c,HIGH);
  pinMode(d, OUTPUT);
  digitalWrite(d,HIGH);
  pinMode(e, OUTPUT);
  digitalWrite(e,HIGH);
  pinMode(f, OUTPUT);
  digitalWrite(f,HIGH);
  pinMode(g, OUTPUT);
  digitalWrite(g,HIGH);
  pinMode(dp, OUTPUT);
  digitalWrite(dp,HIGH);

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
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /0/on") >= 0) {
              Serial.println("0 on");
              zero();
            } else if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("1 on");
              one();
            } else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("2 on");
              two();
            } else if (header.indexOf("GET /3/on") >= 0) {
              Serial.println("3 on");
              three();
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("4 on");
              four();
            } else if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("5 on");
              five();
            } else if (header.indexOf("GET /6/on") >= 0) {
              Serial.println("6 on");
              six();
            } else if (header.indexOf("GET /7/on") >= 0) {
              Serial.println("7 on");
              seven();
            } else if (header.indexOf("GET /8/on") >= 0) {
              Serial.println("8 on");
              eight();
            } else if (header.indexOf("GET /9/on") >= 0) {
              Serial.println("9 on");
              nine();
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>7-SEG Control Web Page</h1>");

            client.println("<p>0 - State " + output0 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output0=="off") {
              client.println("<p><a href=\"/0/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/0/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>1 - State " + output1 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output1=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>2 - State " + output2 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output2=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>3 - State " + output3 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output3=="off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>4 - State " + output4 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output4=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>5 - State " + output5 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output5=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>6 - State " + output6 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output6=="off") {
              client.println("<p><a href=\"/6/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/6/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>7 - State " + output7 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output7=="off") {
              client.println("<p><a href=\"/7/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/7/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>8 - State " + output8 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output8=="off") {
              client.println("<p><a href=\"/8/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/8/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

            client.println("<p>9 - State " + output9 + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output9=="off") {
              client.println("<p><a href=\"/9/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/9/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

void zero() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
  output0 = "on";
  output1 = "off";
  output2 = "off";
  output3 = "off";
  output4 = "off";
  output5 = "off";
  output6 = "off";
  output7 = "off";
  output8 = "off";
  output9 = "off";
}

void one() {
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "on";
  output2 = "off";
  output3 = "off";
  output4 = "off";
  output5 = "off";
  output6 = "off";
  output7 = "off";
  output8 = "off";
  output9 = "off";
}

void two() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "on";
  output3 = "off";
  output4 = "off";
  output5 = "off";
  output6 = "off";
  output7 = "off";
  output8 = "off";
  output9 = "off";
}

void three() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "off";
  output3 = "on";
  output4 = "off";
  output5 = "off";
  output6 = "off";
  output7 = "off";
  output8 = "off";
  output9 = "off";
}

void four() {
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "off";
  output3 = "off";
  output4 = "on";
  output5 = "off";
  output6 = "off";
  output7 = "off";
  output8 = "off";
  output9 = "off";
}

void five() {
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "off";
  output3 = "off";
  output4 = "off";
  output5 = "on";
  output6 = "off";
  output7 = "off";
  output8 = "off";
  output9 = "off";
}

void six() {
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "off";
  output3 = "off";
  output4 = "off";
  output5 = "off";
  output6 = "on";
  output7 = "off";
  output8 = "off";
  output9 = "off";
}

void seven() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "off";
  output3 = "off";
  output4 = "off";
  output5 = "off";
  output6 = "off";
  output7 = "on";
  output8 = "off";
  output9 = "off";
}

void eight() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "off";
  output3 = "off";
  output4 = "off";
  output5 = "off";
  output6 = "off";
  output7 = "off";
  output8 = "on";
  output9 = "off";
}

void nine() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  output0 = "off";
  output1 = "off";
  output2 = "off";
  output3 = "off";
  output4 = "off";
  output5 = "off";
  output6 = "off";
  output7 = "off";
  output8 = "off";
  output9 = "on";
}