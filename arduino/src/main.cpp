#include <Arduino.h>
#include <cube.cpp>

String solution;

RubiksCube cube;


/*
clockwise   counterclockwise
R   r
L   l
U   u
D   d
F   f
B   b
*/

void rotate(int face , int direction){
  int* p = cube.get_position(face);
  int x=p[0],y=p[1];
  //TODO: servo_rotate(x*90); angle as input
  if (x<0){
    cube.rotate_anticlockwise();
  }
  else {
    for (int i = 0; i < x; i++) {
      cube.rotate_clockwise();
    }
  }
  for (int i = 0; i < y; i++) {
    cube.flip();
    //TODO: servo_flip();
  }

  Serial.println(cube.faces[5].color);

  //servo_covercube();

  //servo_rotate(direction*90); angle as input
}


void turn(char move) {
  switch (move) {
    case 'R':
      rotate(3, -1);
      Serial.println("R");
      break;
    case 'r':
      rotate(3, 1);
      Serial.println("r");
      break;
    case 'L':
      rotate(1, -1);
      Serial.println("L");
      break;
    case 'l':
      rotate(1, 1);
      Serial.println("l");
      break;
    case 'U':
      rotate(0, -1);
      Serial.println("U");
      break;
    case 'u':
      rotate(0, 1);
      Serial.println("u");
      break;
    case 'D':
      rotate(5, -1);
      Serial.println("D");
      break;
    case 'd':
      rotate(5, 1);
      Serial.println("d");
      break;
    case 'F':
      rotate(2, -1);
      Serial.println("F");
      break;
    case 'f':
      rotate(2, 1);
      Serial.println("f");
      break;
    case 'B':
      rotate(4, -1);
      Serial.println("B");
      break;
    case 'b':
      rotate(4, 1);
      Serial.println("b");
      break;
  }
  delay(1000);
  Serial.println("010");
}


void setup() {
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  if (Serial.available()){
    delay(100);
    solution = Serial.readString();
    Serial.println(solution);
  }
  if (solution != "") {
    for (int i = 0; i < solution.length(); i++) {
    turn(solution[i]);
  }
  solution = "";
  Serial.println("Done");
  }
  
}