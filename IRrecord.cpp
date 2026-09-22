#include <IRremote.hpp>

#define IR_RECEIVE_PIN 10
#define OUTPUT_PIN 13

void setup() {
  Serial.begin(9600);

  pinMode(OUTPUT_PIN, OUTPUT);
  digitalWrite(OUTPUT_PIN, LOW);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {

    Serial.print("Received: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, DEC);

    if (IrReceiver.decodedIRData.decodedRawData == 16580863) {
      digitalWrite(OUTPUT_PIN, HIGH);
    }

    IrReceiver.resume();
  }
}

