#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define SUBE 4
#define BAJA 3
#define RESET 5
#define UNIDAD A4
#define DECENA A5
#define APAGADOS 0
#define TIMEDISPLAYON 10
#define SENSOR A0
#define MOTOR 2


int contador = 0;
int sube = 1;
int subePrevia = 1;
int baja = 1;
int bajaPrevia = 1;
int reset = 1;
int resetPrevia = 1;

const float umbralTemperatura = 30.0;




void setup()
{ 
  pinMode(13 , OUTPUT);
  pinMode(12 , OUTPUT);
  pinMode(11 , OUTPUT);
  pinMode(10 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(8 , OUTPUT);
  pinMode(7 , OUTPUT);
  pinMode(UNIDAD , OUTPUT);
  pinMode(DECENA , OUTPUT);
  pinMode(2, OUTPUT);
  
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(SUBE, INPUT_PULLUP);
  pinMode(BAJA, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);
  
  printDigit(0);
  
  
}



void loop()
{
    	
  
  int presiono = keypressed();
  if(presiono == SUBE)
  {
    contador ++;
    if(contador>99)
      contador = 0;
  }
  else if (presiono == BAJA)
  {
    contador --;
    if(contador < 0)
      contador = 99;
    
  }
  else if(presiono == RESET)
  {
    contador = 0;
  }
  
  float lectura;
  float temperatura;
  lectura = analogRead(SENSOR);
  temperatura = map(lectura, 20, 358, -5, 125);
  Serial.println("Temperatura: " + String(temperatura) + "°C");
  printCount(contador);
  
  if(temperatura> umbralTemperatura){
     digitalWrite(2, HIGH);
  }else{
  	
    digitalWrite(2, LOW);	
  }
}


void printDigit(int digit)
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  switch(digit)
  {
  	case 1:
    {
    	digitalWrite(B, HIGH);
    	digitalWrite(C, HIGH);
      	break;
    }
    case 2:
    {	
      	digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
      	digitalWrite(E, HIGH);
      	digitalWrite(G, HIGH);
      	break;
    }
  	case 3:
    {
    	digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      	digitalWrite(G, HIGH);
      	break;
    }
    case 4:
    {
      	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
      	digitalWrite(F, HIGH);
      	digitalWrite(G, HIGH);
      	break;
    }  	
    case 5:
    {
    	digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      	digitalWrite(F, HIGH);
      	digitalWrite(G, HIGH);
      	break;
    }
    case 6:
    {
    	digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      	digitalWrite(E, HIGH);
      	digitalWrite(F, HIGH);
      	digitalWrite(G, HIGH);
      	break;
    }
    case 7:
    {
    	digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
      	break;
    }
    case 8:
    {
    	digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      	digitalWrite(E, HIGH);
      	digitalWrite(F, HIGH);
      	digitalWrite(G, HIGH);
      	break;
    }
    case 9:
    {
    	digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      	digitalWrite(F, HIGH);
      	digitalWrite(G, HIGH);
      	break;
    }
  	case 0:
    {
      	digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      	digitalWrite(E, HIGH);
      	digitalWrite(F, HIGH);
    	break;
    }
  }//switch
  	
  
  
}


    
int keypressed(void)
{
  
  sube = digitalRead(SUBE);
  baja = digitalRead(BAJA);
  reset = digitalRead(RESET);
  if(sube)
    subePrevia = 1;
  if(baja)
    bajaPrevia = 1;
  if(reset)
    resetPrevia = 1;
  
  	if(sube == 0 && sube != subePrevia)
    {
      subePrevia = sube;
      return SUBE;
    }
  
  	if(baja == 0 && baja != bajaPrevia)
    {
    	bajaPrevia = baja;
      return BAJA;
    
    }
  
  	if(reset == 0 && reset != resetPrevia)
    {
    	resetPrevia = reset;
      	return RESET;
    
    }
    
return 0;
}


void prendeDigito(int digito)
{
  if(digito == UNIDAD)
  {
  	digitalWrite(UNIDAD, LOW);
  	digitalWrite(DECENA, HIGH);
    delay(TIMEDISPLAYON);
  }
  else if(digito == DECENA)
  {
  	digitalWrite(UNIDAD, HIGH);
  	digitalWrite(DECENA, LOW);
    delay(TIMEDISPLAYON);
  
  }
  else
  {
  	digitalWrite(UNIDAD, HIGH);
  	digitalWrite(DECENA, HIGH);
  }

}


void printCount(int contador)
{
  prendeDigito(APAGADOS);
  printDigit(contador/10);
  prendeDigito(DECENA);
  prendeDigito(APAGADOS);
  printDigit(contador - 10*((int)contador /10));
  prendeDigito(UNIDAD);

}




