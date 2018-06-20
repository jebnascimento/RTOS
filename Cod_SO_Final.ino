#include <Arduino_FreeRTOS.h>


void TaskCounter( void *pvParameters );
void TaskAnalogRead( void *pvParameters );
void TaskRedLed( void *pvParameters );
void TaskYellowLed( void *pvParameters );
void TaskGreenLed( void *pvParameters );

void setup() 
{
  xTaskCreate(TaskCounter, (const portCHAR *)"Counter", 128, NULL,  1,  NULL ); //TAREFA 1
  xTaskCreate(TaskAnalogRead, (const portCHAR *) "AnalogRead", 128, NULL, 1, NULL );//TAREFA 2
  xTaskCreate(TaskRedLed, (const portCHAR *) "red", 128, NULL, 6, NULL ); //TAREFA 3
  xTaskCreate(TaskYellowLed, (const portCHAR *) "yellow", 128, NULL, 5, NULL ); //TAREFA 4
  xTaskCreate(TaskGreenLed, (const portCHAR *) "green", 128, NULL, 4, NULL ); //TAREFA 5
  
  
  
  while (!Serial) {
    ; 
  }
}

void loop()
{}

void TaskCounter(void *pvParameters)  
{
  (void) pvParameters;
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);   
  unsigned int counter = 0;
  for (;;)
  {
    Serial.println("aqui");
    if(counter == 3)
    {
      counter = 0;
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
    }
      
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    counter++;
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    counter++;
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    counter++;
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
  vTaskDelete(NULL);
}

void TaskAnalogRead(void *pvParameters)
{
  (void) pvParameters;
  Serial.begin(9600);
  
  for (;;)
  {
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    vTaskDelay(1);  //equivalent a 1 ms
  }
  vTaskDelete(NULL);
}

void TaskGreenLed(void *pvParameters)
{
  (void) pvParameters;
  pinMode(2, INPUT);
  pinMode(5, OUTPUT);
  
  
  for (;;)
  {
    if(digitalRead(2) == HIGH)
      digitalWrite(5, HIGH);
    else
      digitalWrite(5, LOW);  
    vTaskDelay( 100 / portTICK_PERIOD_MS);  
  }
  vTaskDelete(NULL);
}


void TaskYellowLed(void *pvParameters)
{
  (void) pvParameters;
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
  
  
  for (;;)
  {
    if(digitalRead(3) == HIGH)
      digitalWrite(6, HIGH);
    else
      digitalWrite(6, LOW);  
    vTaskDelay(1);  
  }
  vTaskDelete(NULL);
}


void TaskRedLed(void *pvParameters)
{
  (void) pvParameters;
  pinMode(4, INPUT);
  pinMode(7, OUTPUT);
  
  
  for (;;)
  {
    if(digitalRead(4) == HIGH)
      digitalWrite(7, HIGH);
    else
      digitalWrite(7, LOW);  
    vTaskDelay(1);
    while(digitalRead(4) == HIGH)
    {
      digitalWrite(7, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
    }
  }
  vTaskDelete(NULL);
  
}

