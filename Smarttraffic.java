import processing.serial.*;
import cc.arduino.*;
import processing.core.PFont;

Arduino arduino;
PFont font;

// Pin assignments for 4 directions (adjust as needed)
int[] pirPins = {6, 7, 8, 9}; // PIR sensor pins
int[][] greenPins = {{10, 11, 12, 13}}; // Green LEDs
int[][] yellowPins = {{14, 15, 16, 17}}; // Yellow LEDs
int[][] redPins = {{18, 19, 20, 21}}; // Red LEDs

int[] vehicleCounts = new int[4];
int[] greenTimes = new int[4];
String[] statuses = new String[4];
int currentDirection = 0;
long startTime = 0;
int phase = 0; // 0: Green, 1: Yellow, 2: Red
int yellowDuration = 5000; // 5 seconds

void setup() {
  size(800, 600);
  font = createFont("Arial", 20);
  textFont(font);
  
  // Initialize Arduino (adjust port name as needed)
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600); // Change index/port if needed
  
  // Set pin modes
  for (int i = 0; i < 4; i++) {
    arduino.pinMode(pirPins[i], Arduino.INPUT);
    arduino.pinMode(greenPins[0][i], Arduino.OUTPUT);
    arduino.pinMode(yellowPins[0][i], Arduino.OUTPUT);
    arduino.pinMode(redPins[0][i], Arduino.OUTPUT);
    statuses[i] = "Red";
  }
  
  // Initialize first direction
  getVehicleCounts();
  calculateGreenTimes();
  startGreenPhase(0);
}

void draw() {
  background(255);
  displayStatus();
  
  long currentTime = millis();
  
  if (phase == 0 && currentTime - startTime >= greenTimes[currentDirection]) {
    startYellowPhase(currentDirection);
  } else if (phase == 1 && currentTime - startTime >= yellowDuration) {
    startRedPhase(currentDirection);
    currentDirection = (currentDirection + 1) % 4;
    getVehicleCounts();
    calculateGreenTimes();
    startGreenPhase(currentDirection);
  }
}

void getVehicleCounts() {
  for (int i = 0; i < 4; i++) {
    int pirState = arduino.digitalRead(pirPins[i]);
    if (pirState == Arduino.HIGH) {
      vehicleCounts[i] = 16; // High traffic detected
    } else {
      vehicleCounts[i] = 0; // No traffic detected
    }
  }
}

void calculateGreenTimes() {
  for (int i = 0; i < 4; i++) {
    if (vehicleCounts[i] > 15) {
      greenTimes[i] = 60000; // 60 seconds
    } else {
      greenTimes[i] = 30000; // 30 seconds
    }
  }
}

void startGreenPhase(int direction) {
  phase = 0;
  startTime = millis();
  statuses[direction] = "Green";
  
  // Set lights for current direction
  arduino.digitalWrite(greenPins[0][direction], Arduino.HIGH);
  arduino.digitalWrite(yellowPins[0][direction], Arduino.LOW);
  arduino.digitalWrite(redPins[0][direction], Arduino.LOW);
  
  // Set red for other directions
  for (int i = 0; i < 4; i++) {
    if (i != direction) {
      arduino.digitalWrite(greenPins[0][i], Arduino.LOW);
      arduino.digitalWrite(yellowPins[0][i], Arduino.LOW);
      arduino.digitalWrite(redPins[0][i], Arduino.HIGH);
      statuses[i] = "Red";
    }
  }
}

void startYellowPhase(int direction) {
  phase = 1;
  startTime = millis();
  statuses[direction] = "Yellow";
  
  arduino.digitalWrite(greenPins[0][direction], Arduino.LOW);
  arduino.digitalWrite(yellowPins[0][direction], Arduino.HIGH);
  arduino.digitalWrite(redPins[0][direction], Arduino.LOW);
}

void startRedPhase(int direction) {
  phase = 2;
  statuses[direction] = "Red";
  
  arduino.digitalWrite(greenPins[0][direction], Arduino.LOW);
  arduino.digitalWrite(yellowPins[0][direction], Arduino.LOW);
  arduino.digitalWrite(redPins[0][direction], Arduino.HIGH);
}

void displayStatus() {
  fill(0);
  textAlign(LEFT);
  text("Traffic Control System", 20, 50);
  
  for (int i = 0; i < 4; i++) {
    text("Direction " + (i + 1) + ": " + statuses[i] + ", Vehicles: " + vehicleCounts[i] + ", Green Time: " + (greenTimes[i] / 1000) + "s", 20, 100 + i * 50);
  }
}
