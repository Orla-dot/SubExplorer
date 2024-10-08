#include <SPI.h>
#include <Wire.h>
#include <LoRa.h>
#include <iostream>
#include <list>

using namespace std;

byte selfAddress  = 0xAA;
byte destination = 0x77;

String senderMessage = "";
int errorCount = 0;
int messageCount = 0;

double currentTime  = 0;
double previousTime = 0;
int waitingTime = 6000;
list<String> messageList;

void sendMessage(String outGoing);
void onReceiveLoRa(int packetSize);
void onReceiveWire(int packerSize);

void setup() {
  if (!LoRa.begin(915E6)) {
    while (1);
  }

  LoRa.onReceive(onReceiveLoRa);

  LoRa.receive();
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();

  if ((currentTime - previousTime) >= waitingTime) {
    sendMessageLoRa(messageList.back());
    messageList.pop_back();
  }

}


void sendMessageLoRa(String outGoing) {
  LoRa.beginPacket();
  LoRa.write(destination);
  LoRa.write(selfAddress);
  LoRa.write(messageCount);
  LoRa.write(outGoing.length());
  LoRa.print(outGoing);
  LoRa.endPacket();
  messageCount++;

}
void onReceiveLoRa(int packerSize) {
  if (packerSize == 0) return;

  // riding the header part
  int  recipient     = LoRa.read(); // recipient address
  char senderAddrs   = LoRa.read(); // sender address
  char messageType   = LoRa.read(); // type of the message
  char messageID     = LoRa.read(); // message ID
  char messageLength = LoRa.read(); // message length

  String message = ""; // packet of data

  // reading the message
  while (LoRa.available()) {
    message += char(LoRa.read()); // adding byte per byte of the message
  }

  // checking the currect length
  if (messageLength != message.length()) return;
  // chacking the currect address
  if (recipient != selfAddress && recipient != 0xFF) return;

  // ...
}
void onReceiveWire(int packerSize) {
  if (packerSize == 0) return;

  string message = "";
  while (Wire.available()) {
    message += char(Wire.read());
  }
  
  messageList.push_back(message.c_str());
}