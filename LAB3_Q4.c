#pragma config(Motor,  motorB,          LEFT,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RIGHT,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//GLOBAL VARIABLES

const float diameter = 58.0, tolerance = .5;
const float circumference = (PI * diameter), desiredDistanceMM = 500, k = 2; 

const int motorControlTaskDelay = 1000, slewRate = 10;

float degreesTurned, currentDistance = 0;
int currentPower = 0, desiredPower, error;




void distance(){


 	resetMotorEncoder(RIGHT);

	desiredPower = 0;

	while(currentDistance < desiredDistanceMM){

		error = (desiredDistanceMM - currentDistance);


		if(abs(error) > tolerance){
			desiredPower = k*(desiredDistanceMM - currentDistance);

			if(currentDistance <  (.5 *desiredDistanceMM)){
							currentPower += slewRate;
			}else if(currentDistance > (.5 *desiredDistanceMM)){
							 currentPower -= slewRate;
			}// end of INNER IF-ELSE
		}// end of OUTTER IF

		displayTextLine(1,"%s: %i","desiredDistanceINCHES", desiredDistanceMM);
		displayTextLine(2,"%s: %i","current distance",currentDistance);
		displayTextLine(3,"%s: %f","currentPower",currentPower);
		displayTextLine(4,"%s: %f","desiredPower",desiredPower);
		
		/* The code below calculate the current distance travelled of the right 
		 * motor and recalculates the sum of the currentDistance variable
		 */
		setMotorSync(RIGHT,LEFT,0,currentPower);
		degreesTurned = getMotorEncoder(RIGHT);
		currentDistance += ((degreesTurned/360) * circumference);
		sleep(motorControlTaskDelay);
	}// end of WHILE
}// end of turnRightSpeedControl TASK


task main()
{
	distance();
}
