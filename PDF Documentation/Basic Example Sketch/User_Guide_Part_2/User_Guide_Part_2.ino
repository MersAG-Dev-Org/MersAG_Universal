// Script to toggle 2 LEDs with push-button script
// Use in Part 2.3 of MersAG_Universal User Guide
#define BUTTON_PIN 16 // Button
#define LED_PIN1 17 // Green LED
#define LED_PIN2 18 // Red LED
int led_state = LOW;
int button_state, last_button_state;
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  last_button_state = digitalRead(BUTTON_PIN);
  Serial.begin(115200);
  delay(1000);
}
void loop() {
  button_state = digitalRead(BUTTON_PIN);
  if (last_button_state == HIGH && button_state == LOW) {
    led_state = !led_state;
    digitalWrite(LED_PIN1, led_state);
    digitalWrite(LED_PIN2, !led_state);
    Serial.println(led_state);
}
  last_button_state = button_state;
  delay(500);
}  