/*
    Nathan Moore, 03-16-2018

    Simple program to read the input from a digital "morse" communication line.
    Code looks for risin or falling edges from a digital transmission.  Times
    that an edge are detected, as wells as R-rising or F-Falling are stored in 
    an array.  Mapping te delays to Morse would be the next task.
    */

int data_in = 13;
int d0, d1;
unsigned long t;

// This is a  PREPROCESSOR MACRO - think of it as a constant
#define ARRAY_SIZE 200

int i;
unsigned long edge_t[ARRAY_SIZE];
int rise[ARRAY_SIZE];
char line[40]; // used for printing to Serial

void setup() {
  Serial.begin(9600);
  pinMode(data_in, INPUT);
  d0 = digitalRead(data_in);
  i = 0;
}

void loop() {
  /* note, this code runs falt out with no delay.  This is not the optimal
    way to look for clock edges. */
  d1 = digitalRead(data_in);
  t = millis();
  // look for 01, rising
  if ( !d0 && d1 ) {
    //    Serial.print("R ");
    //    Serial.println(t);
    edge_t[i] = t;
    rise[i] = 1;
    i++;
  }
  // look for 10, falling
  if ( d0 && !d1 ) {
    //    Serial.print("F ");
    //    Serial.println(t);
    edge_t[i] = t;
    rise[i] = 0;
    i++;
  }
  // get ready for the next cycle
  d0 = d1;

  // is the array filled up?  If so, print to screen.
  if (i == ARRAY_SIZE) {
    for (i = 0; i < ARRAY_SIZE; i++) {
      if (rise[i]) {
        sprintf(line, "R,%ld\n", edge_t[i]);
      } else {
        sprintf(line, "F,%ld\n", edge_t[i]);
      }
      Serial.print(line);
    }
    Serial.println();
    i = 0;

    print_out_mathematica_format(edge_t, rise);

  }
}



// pass the array in
void print_out_mathematica_format(unsigned long edge_t[], int rise[]) {
  int j;
  char line[40];
  Serial.println("{");
  for (j = 0; j < ARRAY_SIZE; j++) {
    if (rise[j] == 0) {
      sprintf(line, "{%ld,1},{%ld,0},", edge_t[j], edge_t[j]);
    }
    else {
      if (rise[j] == 1) {
        sprintf(line, "{%ld,0},{%ld,1},", edge_t[j], edge_t[j]);
      }
      else {
        Serial.print("\nERROR IN RISE DATA!!!\n");
      }
    }
    Serial.print(line);
    if (j % 5 == 4) {
      Serial.println();
    }
  }

  Serial.println("}");
  return;
}

