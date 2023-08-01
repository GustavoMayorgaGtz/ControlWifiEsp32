AsyncWebServer server(80);
extern byte IsOpen;
//-----------------------------------------------------------------
void conectarWiFi() {
  const char* nombreRed = "CyberSphere2.4";
  const char* passwordRed = "KD6JVB8kmCRe";
  IPAddress ipEstatica(192, 168, 100, 254);  
  IPAddress gateway(192, 168, 100, 1);  
  IPAddress subnet(255, 255, 255, 0);       

  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(nombreRed);

  WiFi.config(ipEstatica, gateway, subnet);
  WiFi.begin(nombreRed, passwordRed);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conexión WiFi establecida");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
}
//-----------------------------------------------------------------
void configurarServidor() {
 server.on("/open", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Abriendo puerta....");
    IsOpen = 1;
  request->send(200, "text/plain", "Puerta abierta...");
  });
  server.begin();
  Serial.println("Servidor iniciado");
}
//-----------------------------------------------------------------