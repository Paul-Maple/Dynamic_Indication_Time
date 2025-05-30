  /*/
  Библиотека предназначена для работы с индикаторами как с общим катодом (ОК), так и с общим анодом (ОА)
  Работает только с 6-ти разрядным индикатором!!!

  ВАЖНО!!!!!!!
  Внутри void loop() нельзя писать delay(). 
  НИКАКИХ delay!!!!!!! 
  Даже delay(1)!!!!!!!!!!!!
  Иначе РАБОТАТЬ НЕ БУДЕТ!!!!!!!!!!!!

  Это пример для отображения времени в формате чч:мм:сс
  чч - часы (от 0 до 23)
  мм - минуты (от 0 до 59)
  сс - секунды (от 0 до 59)
  /*/

  // Подключаем библиотеку
  #include "Dynamic_indication_time.h"

  // Определяем пины к которым подключёны сегменты индикатора (Слева - сегменты индикатора, справа - пины Arduino)
  #define A A5 // Сегмент А
  #define B A4 // Сегмент B
  #define C A3 // Сегмент C
  #define D A2 // Сегмент D
  #define E A1 // Сегмент E
  #define F A0 // Сегмент F
  #define G 13 // Сегмент G
  #define DP 4 // Сегмент точка
  
  #define  SEG1 9 // Общий катод сегмента 1
  #define  SEG2 10 // Общий катод сегмента 2
  #define  SEG3 11 // Общий катод сегмента 3
  #define  SEG4 2 // Общий катод сегмента 4
  #define  SEG5 1 // Общий катод сегмента 3
  #define  SEG6 0 // Общий катод сегмента 4

  #define  commonPIN 0 // Общий катод (ОК) - "1", общий анод (ОА) - "0"
  // Создаём объект "MyLED"
  Indicator MyTimeLED (A,B,C,D,E,F,G,DP,SEG1,SEG2,SEG3,SEG4,SEG5,SEG6,commonPIN); 

 // Все порты в режим "Вывода" 
void setup() 
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(SEG1, OUTPUT);
  pinMode(SEG2, OUTPUT);
  pinMode(SEG3, OUTPUT);
  pinMode(SEG4, OUTPUT);
  pinMode(SEG5, OUTPUT);
  pinMode(SEG6, OUTPUT);

  //Timer1.initialize(500000);
  //Timer1.attachInterrupt(switch_flag);
}

uint8_t h = 12; 
uint8_t m = 34;
uint8_t s = 56;
uint8_t nomer_knopki = 1;

void loop() 
{
 MyTimeLED.display(h,m,s); // Отображаем время (12 часов, 34 минуты, 56 секунд)
 // MyTimeLED.display_blink(h,m,s,nomer_knopki); // мигание не работает
}
  /*
  void switch_flag()
  {
  MyTimeLED.flag_of_on = !MyTimeLED.flag_of_on;
  }
  */
