float RS_gas = 0;
float ratio = 0;
float sensorValue = 0;
float sensor_volt = 0;
float R0 = 13200.0;

void setup() {
 Serial.begin(9600);
}

void loop() {
   
   //FOR HYDROGEN
   sensorValue = analogRead(A1);
   sensor_volt = sensorValue/1024*5.0;
   RS_gas = (5.0-sensor_volt)/sensor_volt;
   ratio = RS_gas/R0; //Replace R0 with the value found using the sketch above
   float x = 2000 * ratio;
   float ppm = pow(x,-3.311);
   Serial.print("PPM OF H2: ");
   Serial.println(ppm);
   delay(1000);
}
