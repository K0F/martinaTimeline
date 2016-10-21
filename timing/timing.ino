
int pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ins[] = {0, 16, 21, 65, 68, 69, 70, 118, 125, 145, 157};
int outs[] = {67, 60, 54, 71, 122, 121, 120, 127, 165, 166, 200};

boolean ons[12];
int T = 0;

void setup() {
  for (int i = 0 ; i < 13; i++) {
    ons[i] = false;
    pinMode(pins[i], OUTPUT);
  }
  T = 0;
}

void loop() {

  for (int i = 0 ; i < 12; i++) {
    if (ins[i] <= T && outs[i] > T) {
      ons[i] = true;
    } else {
      ons[i] = false;
    }
  }

  for (int i = 0 ; i < 12; i++) {
    if (ons[i]) {
      digitalWrite(pins[i], HIGH);
    } else {
      digitalWrite(pins[i], LOW);
    }
  }


  delay(900);
  digitalWrite(pins[13], HIGH);
  delay(100);
  digitalWrite(pins[13], LOW);


  T += 1;
  if (T > 200) {
    T = 0;
  }

}


