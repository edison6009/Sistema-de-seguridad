#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* nombrered = "Red_sistema";
const char* contraseñared = "30433518";

int traslado1 = 10;
int traslado2= 11;
int traslado3;
int traslado4;

ESP8266WebServer server(80);

void handleRoot (){
  if (server.hasArg("variable")) {
    String variableName = server.arg("variable");
    if (variableName == "traslado1") {
      server.send(200, "text/plain", String(traslado1));
    } else if (variableName == "traslado2") {
      server.send(200, "text/plain", String(traslado2));
    } else {
      server.send(404, "text/plain", "Error: Variable no encontrada");
    }
  } else {
    String message = "traslado 1: " + String(traslado1) + "\ntraslado 2: " + String(traslado2);
    server.send(200, "text/plain", message);
  }

if (server.hasArg("var")){
  if(server.arg("var")){
    String var_str = server.arg("var");
    traslado3 = var_str.toInt();
    Serial.print("\nSe recibió: ");
    Serial.print(traslado3);
    }
  else if(server.arg("var2")){
    String var2_str = server.arg("var2");
    traslado4 = var2_str.toInt();
    Serial.print("\nSe recibió: ");
    Serial.print(traslado4);
   }
  else{
    server.send(400, "text/plain", "Error: no se proporcionó ninguna variable");
   }
  }

}

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);

  Serial.println("\n.....Configurando_Red_&_Servidor-HTTP.....");
  delay(1000);
  WiFi.softAP(nombrered, contraseñared);
  Serial.println("....Red_activa....");
  delay(1000);
  
  server.on("/", handleRoot);
  server.begin();
  Serial.println("...Servidor-HTTP_Activo...");
}

void loop(){
  server.handleClient();

  if (Serial.available()==0);
  char var = Serial.read();

    if (var == '1'){
      Serial.print("IP: ");
      Serial.println(WiFi.softAPIP());
  }
      if (var == '2'){ 
   Serial.printf("Señal DB: %d\n", WiFi.RSSI());
  }
   if (var == '3'){ 
      Serial.println(traslado3);
   }
}

