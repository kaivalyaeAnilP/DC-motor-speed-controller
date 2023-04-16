# include <reg51.h>
sbit motor = P2^0; //Output to drive the motor is supplied through port 2.0
sbit sw = P1^0; //Input is taken through port 1.0
void delay(unsigned int val);
int main(){
	int state = 0;
	motor = 0;
	while(1){
		if(sw == 0){
			state = (state==3) ? 0 : state+1; //Change state upon switch press
		}
		while(sw == 0); //wait for switch release
		switch(state){
			case 0: while(sw != 0){
						motor = 0;
					}
					break;
			case 1: while(sw != 0){
						motor = 0;
						delay(10);
						motor = 1;
						delay(5);
					}
					break;
			case 2: while(sw != 0){
						motor = 0;
						delay(10);
						motor = 1;
						delay(10);
					}
					break;
			case 3: while(sw != 0){
						motor = 0;
						delay(5);
						motor = 1;
						delay(10);
					}
					break;
		}
	}
}
void delay(unsigned int val){
	unsigned int j,i;
	for(i=0; i<val; i++)
		for(j=0; j<4000; j++);
}