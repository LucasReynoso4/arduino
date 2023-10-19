# arduino
Reynoso Lucas | Mamani Santino | Rama Franco


PARTE UNO DEL PROYECTO
![Captura de pantalla (487)](https://github.com/LucasReynoso4/arduino/assets/111331322/a0d9dbdc-7a6d-4218-997c-dca66fbaab6a)

Descripcion:
La primera parte del proyecto se encarga de contar hasta 99 o de 99 hasta 0 en los visualizadores

# FUNCIONES PRINCIPAL 

si se preciono un boton que no se preciono con anterioridad devuelve el valor de ese boton si ya se habia precionado no hace nada 


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

 si el digito es unidad se prende unidad , si es decena se prende decena , y si no es ninguno de los dos no prende 

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
    

PARTE DOS DEL PROYECTO
![Captura de pantalla (489) - copia](https://github.com/LucasReynoso4/arduino/assets/111331322/5be7555d-47fe-455c-92e8-bc6eb61cae37)

Descripcion:
La segunda parte del proyecto se encarga de lo mismo que la primera pero ademas contiene un motor y un sensor de temperatura que al llegar a determinada temperatura el motor se prende

# FUNCIONES PRINCIPAL
Si el senor determina una temperatura asignada activa el motor


const float umbralTemperatura = 30.0;
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


