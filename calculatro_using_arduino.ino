#include <Keypad.h>

int num1=0, num2=0, result=0;
char opr=0;
String number1;
String number2;

char num=0;

bool take_num2 = true;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'=','0','C','/'}
};

byte rowPins[ROWS] = {A0,A1,A2,A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A4,A5,3,2};   //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
   Serial.begin(9600);
   
  Serial.println("Calculator");
  
   ///  Serial.println("Enter number 1");
}
  
void loop()
{
  
    num = keypad.getKey();
    if(num != NO_KEY)
       {
       if((num == '0' || num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7' || num == '8' || num == '9') & (take_num2 == true))
       {
         number1 =  number1+num;
         Serial.print(num);
       }
       else if((num == '0' || num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7' || num == '8' || num == '9') & (take_num2 == false))
       {
         number2 = number2+num;
         Serial.print(num);
          take_num2 == false;
       }
       else if(num == '+' || num == '-' || num == '*' || num == '/')
       {
         opr = num;
         Serial.print(num);
         take_num2 = false;
       }
       else if(num == '=')
       {
         take_num2 == true;
         print_result();
       }
       
    }
}

void print_result()
{
    Serial.println("");
    Serial.println(number1);
    Serial.println(opr);
    Serial.println(number2);

    num1 = number1.toInt();
    num2 = number2.toInt();
    switch(opr)
    {
       case '+':  result = num1+num2; break;
       case '-':  result = num1-num2; break;
       case '*':  result = num1*num2; break;
       case '/':  result = num1/num2; break;
    }
    number1="";
    number2="";
    Serial.println("Your Result=");
    Serial.println(result);
    take_num2 = true;
    num=0;
    num1 = 0;
    num2 = 0;
    result=0;
    opr=0;
   
}
