 #include <Arduino.h>
 #include "Dynamic_Indication_time.h"
 #include "TimerOne.h"

 const int zaderjka = 2; // ms

  Indicator::Indicator(uint8_t pinA,uint8_t pinB,uint8_t pinC,uint8_t pinD,uint8_t pinE,uint8_t pinF,uint8_t pinG,uint8_t pinDP,
  uint8_t pinSEG1,uint8_t pinSEG2,uint8_t pinSEG3,uint8_t pinSEG4,uint8_t pinSEG5,uint8_t pinSEG6,bool comPIN)
  {
    this->A = pinA;
    this->B = pinB;
    this->C = pinC;
    this->E = pinE;
    this->D = pinD;
    this->F = pinF;
    this->G = pinG;
    this->DP = pinDP;

    this->SEG1 = pinSEG1;
    this->SEG2 = pinSEG2;
    this->SEG3 = pinSEG3;
    this->SEG4 = pinSEG4;
    this->SEG5 = pinSEG5;
    this->SEG6 = pinSEG6;

    this->commonPIN = comPIN;

    if (commonPIN == 1)
    {
      this->HIGH_Level = 1;
      this->LOW_Level = 0;
    }
    else 
    {
      this-> HIGH_Level = 0;
      this->LOW_Level = 1;
    }

    this->flag_of_on = true;
  }
  //----------------------------------------------- 
  bool Indicator::display (uint8_t hour, uint8_t min, uint8_t sec)
  {
    display_segment(1, calculate_zifra(hour, 2));
    display_tochka();
    display_segment(2, calculate_zifra(hour, 1));
    display_segment(3, calculate_zifra(min, 2));
    display_tochka();
    display_segment(4, calculate_zifra(min, 1));
    display_segment(5, calculate_zifra(sec, 2));
    display_segment(6, calculate_zifra(sec, 1));
  }

    bool Indicator::display_blink (uint8_t hour, uint8_t min, uint8_t sec, uint8_t segment)
  {
    if (flag_of_on == 1)
    {  
      display_segment(1, calculate_zifra(hour, 2));
      display_tochka();
      display_segment(2, calculate_zifra(hour, 1));
      display_segment(3, calculate_zifra(min, 2));
      display_tochka();
      display_segment(4, calculate_zifra(min, 1));
      display_segment(5, calculate_zifra(sec, 2));
      display_segment(6, calculate_zifra(sec, 1));  
    }
    else 
    {
      switch (segment)
      {
        case 1: 
        {
          display_segment(3, calculate_zifra(min, 2));
          display_tochka();
          display_segment(4, calculate_zifra(min, 1));
          display_segment(5, calculate_zifra(sec, 2));
          display_segment(6, calculate_zifra(sec, 1));
        }
        case 2: 
        {
          display_segment(1, calculate_zifra(hour, 2));
          display_tochka();
          display_segment(2, calculate_zifra(hour, 1));
          display_segment(5, calculate_zifra(sec, 2));
          display_segment(6, calculate_zifra(sec, 1)); 
        }
        case 3: 
        {
          display_segment(1, calculate_zifra(hour, 2));
          display_tochka();
          display_segment(2, calculate_zifra(hour, 1));
          display_segment(3, calculate_zifra(min, 2));
          display_tochka();
          display_segment(4, calculate_zifra(min, 1)); 
        }
      }
    }
  }

 void Indicator::display_segment(uint8_t segment, uint8_t zifra)
{
    set_segment(segment, true);
    display_zifra(zifra);
    delay(zaderjka);
    set_segment(segment, false);
    zifra_off();
}

  uint8_t Indicator::calculate_zifra(uint32_t number, int position)
  {
      uint32_t temp = 1;
      for (int i = 1; i < position; i++)
      {
        temp *= 10;
      }
      return (number / temp) % 10;
  }
  //---------------------------------------------------------------------
 void Indicator::set_segment(uint8_t segment, bool on)
{
    uint8_t level = on ? LOW_Level : HIGH_Level; //Поскольку у нас общий анод
    switch (segment)
    {
    case 1: digitalWrite(SEG1, level); break;
    case 2: digitalWrite(SEG2, level); break;    
    case 3: digitalWrite(SEG3, level); break;  
    case 4: digitalWrite(SEG4, level); break;  
    case 5: digitalWrite(SEG5, level); break;  
    case 6: digitalWrite(SEG6, level); break;   
    }
}
  //------------------------------------
void Indicator::display_zifra(uint8_t Zifra) 
 {
	 switch (Zifra) 
   {
		 case 0: display_zifra_0(); break;
		 case 1: display_zifra_1(); break;
		 case 2: display_zifra_2(); break;
		 case 3: display_zifra_3(); break;
		 case 4: display_zifra_4(); break;
		 case 5: display_zifra_5(); break;
		 case 6: display_zifra_6(); break;
		 case 7: display_zifra_7(); break;
		 case 8: display_zifra_8(); break;
		 case 9: display_zifra_9(); break;
	 }
 }

 void Indicator::display_zifra_1()
 {
    digitalWrite( A, LOW_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, LOW_Level);
    digitalWrite( E, LOW_Level);
    digitalWrite( F, LOW_Level);
    digitalWrite( G, LOW_Level);
 }

 void Indicator::display_zifra_2()
 {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, LOW_Level);
    digitalWrite( D, HIGH_Level);
    digitalWrite( E, HIGH_Level);
    digitalWrite( F, LOW_Level);
    digitalWrite( G, HIGH_Level);
 }
 
 void Indicator::display_zifra_3()
 {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, HIGH_Level);
    digitalWrite( E, LOW_Level);
    digitalWrite( F, LOW_Level);
    digitalWrite( G, HIGH_Level);
 }
 
 void Indicator::display_zifra_4()
 {
    digitalWrite( A, LOW_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, LOW_Level);
    digitalWrite( E, LOW_Level);
    digitalWrite( F, HIGH_Level);
    digitalWrite( G, HIGH_Level);
 }
 
 void Indicator::display_zifra_5()
 {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, LOW_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, HIGH_Level);
    digitalWrite( E, LOW_Level);
    digitalWrite( F, HIGH_Level);
    digitalWrite( G, HIGH_Level);
 }
 
  void Indicator::display_zifra_6()
  {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, LOW_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, HIGH_Level);
    digitalWrite( E, HIGH_Level);
    digitalWrite( F, HIGH_Level);
    digitalWrite( G, HIGH_Level);
  }
 
 void Indicator::display_zifra_7()
 {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, LOW_Level);
    digitalWrite( E, LOW_Level);
    digitalWrite( F, LOW_Level);
    digitalWrite( G, LOW_Level);
 }
 
 void Indicator::display_zifra_8()
 {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, HIGH_Level);
    digitalWrite( E, HIGH_Level);
    digitalWrite( F, HIGH_Level);
    digitalWrite( G, HIGH_Level);
 }
 
 void Indicator::display_zifra_9()
 {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, HIGH_Level);
    digitalWrite( E, LOW_Level);
    digitalWrite( F, HIGH_Level);
    digitalWrite( G, HIGH_Level);	
 }
 
 void Indicator::display_zifra_0()
 {
    digitalWrite( A, HIGH_Level);
    digitalWrite( B, HIGH_Level);
    digitalWrite( C, HIGH_Level);
    digitalWrite( D, HIGH_Level);
    digitalWrite( E, HIGH_Level);
    digitalWrite( F, HIGH_Level);
    digitalWrite( G, LOW_Level);
 }

 void Indicator::zifra_off()
 {
	 digitalWrite( A, LOW_Level);
	 digitalWrite( B, LOW_Level);
	 digitalWrite( C, LOW_Level);
	 digitalWrite( D, LOW_Level);
	 digitalWrite( E, LOW_Level);
	 digitalWrite( F, LOW_Level);
	 digitalWrite( G, LOW_Level);
   digitalWrite( DP, LOW_Level);	 
 }

 void Indicator::display_tochka()
 {
  digitalWrite( DP, HIGH_Level);
 }
 