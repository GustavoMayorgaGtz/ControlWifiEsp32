#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "server.h";

byte IsOpen = 0;

void setup() {
  Serial.begin(115200);

  // Conectar a la red WiFi
  conectarWiFi();  //serve.h
  configurarServidor(); //serve.h
}

void loop() {
  Serial.println(IsOpen);
  delay(500);
}
