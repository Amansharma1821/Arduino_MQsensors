float RS_gas = 0;
float ratio = 0;
float sensorValue = 0;
float sensor_volt = 0;
float R0 = 19300.0;

void setup() {
 Serial.begin(9600);
}

void loop() {

   //FOR CARBON DIOXIDE
   sensorValue = analogRead(A0);
   sensor_volt = sensorValue/1024*5.0;
   RS_gas = (5.0-sensor_volt)/sensor_volt;
   ratio = RS_gas/R0; //Replace R0 with the value found using the sketch above
   float x = 250 * ratio;
   float ppm = pow(x,-2.832);
   Serial.print("PPM OF CO2: ");
   Serial.println(ppm);
   delay(1000);
}
