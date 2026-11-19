
const int leds[7] = {2, 3, 4, 5, 6, 7, 8};
const int button = 9;
const int buzzer = 10;

// Dice LED patterns: A, B, C, D, E, F, G
const byte dice[6][7] = {
  {0,0,0,0,0,0,1}, // 1
  {1,0,0,0,0,0,0}, // 2
  {1,0,0,0,0,0,1}, // 3
  {1,1,0,0,0,0,0}, // 4
  {1,1,0,0,0,0,1}, // 5
  {1,1,1,1,0,0,0}  // 6
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  randomSeed(analogRead(A0));
}

void loop() {
  if (digitalRead(button) == LOW) {

    tone(buzzer, 1000, 150);

    int number = random(1, 7);

    for (int i = 0; i < 7; i++) {
      digitalWrite(leds[i], dice[number - 1][i]);
    }

    delay(300);

    while (digitalRead(button) == LOW) {
      delay(10);
    }
  }
}
