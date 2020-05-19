#include <Servo.h> 
//importer la bibliotheque du servo moteur
char ser[8]; //declarer une tableau de 8
int x, y; 
String txt;
int val1,val2;
Servo myservo1;
Servo myservo2;

void setup() {   
 Serial.begin(9600);  
 myservo1.attach(6);
 myservo2.attach(5);
 myservo1.write(90);
 myservo2.write(90);
}



void loop() {   // put your main code here, to run repeatedly:  
if(Serial.available()>0)    //verfie si il y'a des information dans le port-serie
{   
    for(int i=0;i<8;i++)   //cet boucle va repeter pour chaque chartar dans le tableaiu
    { char inchar=Serial.read();
      ser[i]=inchar; // mettre tout les character dans un tableau
      delay(3);  //defini un temp pour lire chaque de charcter
      }    
  
  txt=String(ser); //mettre le tabbleau lisé dans un autre chaine de character declarer
  
  

for (int i = 0; i < txt.length(); i++) {
  //suparer les valeurs lisées en deux valeurs défrentes
  if (txt.substring(i, i+1) == ",") {
    x = txt.substring(0, i).toInt();
    y = txt.substring(i+1).toInt();
    val1=map(x,0,600,0,180);  //changer l'interval de variation de x et y
    val2=map(y,0,600,90,180);
    Serial.print(val1); 
 //ecrice la valeur 1 dans le port serie pour verfie que l'arduino recoit l'information
    Serial.print("_");
    Serial.println(val2);
    myservo1.write(val1);  //dérige l'angle le servo en fonction de x
    myservo2.write(val2);  //dérige l'angle le servo en fonction de y
    delay(15); //la dirée entre chaque operation
  }
}

  
  } 
  }
