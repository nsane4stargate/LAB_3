#pragma config(Motor,  motorB,          LEFT,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RIGHT,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//GLOBAL VARIABLES

const float diameter = 58.0, tolerance = .5, trackWidth = 120.0;
const float circumference = (PI * diameter), desiredDistanceMM = 1800, k = 2; //angleIncrease is the equivalent of 1 degree in radians

const int motorControlTaskDelay = 1000, slewRate = 10, maxMotorPower = 80,kDegree = 2, minMotorPower = 0;

float degreesTurned, currentDistance = 0, desiredAngleU = (2*PI) * (180/PI), angleIncrease = PI/180, currentAnglePsi = 0, psiIncrement = 0;
int currentPower = 0, desiredPower, error;


void positive60degrees(){

	desiredPower = 0;

	while(currentAnglePsi < ((60/desiredAngleU) * desiredAngleU)){

		error = (((60/desiredAngleU) * desiredAngleU) - currentAnglePsi);

		if(abs(error) > tolerance){
			desiredPower = kDegree*(((60/desiredAngleU) * desiredAngleU) - currentAnglePsi);

			if(currentPower < desiredPower){

					if(currentPower + slewRate < desiredPower){
							currentPower +=slewRate;
					}else{
							currentPower = desiredPower;
							if(currentPower > maxMotorPower)
								currentPower = maxMotorPower;
						}

			}else{

						if(currentPower - slewRate > desiredPower){
				   			currentPower -= slewRate;
				 		}else{
				 				currentPower = desiredPower;
				 				if(currentPower < minMotorPower)
				 						currentPower =  minMotorPower;
						}
			}// end of INNER IF-ELSE
		}// end of OUTTER IF

		if(currentAnglePsi < ((60/desiredAngleU) * desiredAngleU)){
				//	psiIncrement will increase by the equivalent of 1 degree but in radians
				psiIncrement += (slewRate* angleIncrease);
				// caluculate new current angle based of psiIncrement and then convert it to degrees
				currentAnglePsi = ((trackWidth/2 * psiIncrement)* (2/diameter))*(180/PI);
		}else
			if(currentAnglePsi > ((60/desiredAngleU) * desiredAngleU)){
				//	psiIncrement will decrease by the equivalent of 1 degree but in radians
					psiIncrement -= (slewRate* angleIncrease);
				// caluculate new current angle based of psiIncrement and then convert it to degrees
					currentAnglePsi = ((trackWidth/2 * psiIncrement)* (2/diameter))*(180/PI);
				}
	/*displayTextLine(1,"%s: %f","currentPower",currentPower);
		displayTextLine(2,"%s: %f","desiredPower",desiredPower);
			*/
		displayTextLine(3,"%s: %f","currentAnglePsi",currentAnglePsi);
		displayTextLine(4,"%s: %f","desiredAngleU",((60/desiredAngleU) * desiredAngleU));
		setMotorSync(RIGHT,LEFT,-100,currentPower);

		sleep(motorControlTaskDelay * .25);
	}// end of WHILE
}// end of turnRightSpeedControl



void distance500(){
resetMotorEncoder(RIGHT);

	desiredPower = 0;

	while(currentDistance < (desiredDistanceMM * .2777)){

		error = ((desiredDistanceMM * .2777) - currentDistance);


		if(abs(error) > tolerance){
			desiredPower = k*((desiredDistanceMM * .2777)- currentDistance);

			if(currentDistance <  (.5 * (desiredDistanceMM * .2777))){
							currentPower += slewRate;
			}else if(currentDistance > (.5 * (desiredDistanceMM * .2777))){
							 currentPower -= slewRate;
			}// end of INNER IF-ELSE
		}// end of OUTTER IF

		displayTextLine(1,"%s: %i","desiredDistanceINCHES", (desiredDistanceMM * .2777));
		displayTextLine(2,"%s: %i","current distance",currentDistance);
		displayTextLine(3,"%s: %f","currentPower",currentPower);
		displayTextLine(4,"%s: %f","desiredPower",desiredPower);
		setMotorSync(RIGHT,LEFT,0,currentPower);
		degreesTurned = getMotorEncoder(RIGHT);
		currentDistance += ((degreesTurned/360) * circumference);
		sleep(motorControlTaskDelay * .80);
	}// end of WHILE
}// end of turnRightSpeedControl TASK


void negative90degrees(){

	desiredPower = 0;

	while(currentAnglePsi < ((90/desiredAngleU) * desiredAngleU)){

		error = (((90/desiredAngleU) * desiredAngleU) - currentAnglePsi);

		if(abs(error) > tolerance){
			desiredPower = k*(((90/desiredAngleU) * desiredAngleU) - currentAnglePsi);

			if(currentPower < desiredPower){

					if(currentPower + slewRate < desiredPower){
							currentPower +=slewRate;
					}else{
							currentPower = desiredPower;
							if(currentPower > maxMotorPower)
								currentPower = maxMotorPower;
						}

			}else{

						if(currentPower - slewRate > desiredPower){
				   			currentPower -= slewRate;
				 		}else{
				 				currentPower = desiredPower;
				 				if(currentPower < minMotorPower)
				 						currentPower =  minMotorPower;
						}
			}// end of INNER IF-ELSE
		}// end of OUTTER IF

		if(currentAnglePsi < ((90/desiredAngleU) * desiredAngleU)){
				//	psiIncrement will increase by the equivalent of 1 degree but in radians
				psiIncrement += (slewRate* angleIncrease);
				// caluculate new current angle based of psiIncrement and then convert it to degrees
				currentAnglePsi = ((trackWidth/2 * psiIncrement)* (2/diameter))*(180/PI);
		}else
			if(currentAnglePsi > ((90/desiredAngleU) * desiredAngleU)){
				//	psiIncrement will decrease by the equivalent of 1 degree but in radians
					psiIncrement -= (slewRate* angleIncrease);
				// caluculate new current angle based of psiIncrement and then convert it to degrees
					currentAnglePsi = ((trackWidth/2 * psiIncrement)* (2/diameter))*(180/PI);
				}
		displayTextLine(1,"%s: %f","currentPower",currentPower);
		displayTextLine(2,"%s: %f","desiredPower",desiredPower);
		displayTextLine(3,"%s: %f","currentAnglePsi",currentAnglePsi);
		displayTextLine(4,"%s: %f","desiredAngleU",((90/desiredAngleU) * desiredAngleU));
		setMotorSync(RIGHT,LEFT,100,currentPower);
		sleep(motorControlTaskDelay * .22);

	}// end of WHILE
}// end of turnRightSpeedControl


void distance1000(){
	resetMotorEncoder(RIGHT);

	desiredPower = 0;

	while(currentDistance < (desiredDistanceMM * .555)){

		error = ((desiredDistanceMM * .555) - currentDistance);


		if(abs(error) > tolerance){
			desiredPower = k*((desiredDistanceMM * .555) - currentDistance);

			if(currentDistance <  (.80 * (desiredDistanceMM * .555))){
							currentPower += slewRate;
			}else if(currentDistance > (.80 * (desiredDistanceMM * .555))){
							 currentPower -= slewRate;
			}// end of INNER IF-ELSE
		}// end of OUTTER IF

		displayTextLine(1,"%s: %i","desiredDistanceINCHES", (desiredDistanceMM * .555));
		displayTextLine(2,"%s: %i","current distance",currentDistance);
		displayTextLine(3,"%s: %f","currentPower",currentPower);
		displayTextLine(4,"%s: %f","desiredPower",desiredPower);

		setMotorSync(RIGHT,LEFT,0,currentPower);
		degreesTurned = getMotorEncoder(RIGHT);
		currentDistance += ((degreesTurned/360) * circumference);
		sleep(motorControlTaskDelay);
	}// end of WHILE
}// end of turnRightSpeedControl TASK

void positive150degrees(){

	desiredPower = 0;

	while(currentAnglePsi < ((150/desiredAngleU) * desiredAngleU)){

		error = (((150/desiredAngleU) * desiredAngleU) - currentAnglePsi);

		if(abs(error) > tolerance){
			desiredPower = k*(((150/desiredAngleU) * desiredAngleU) - currentAnglePsi);

			if(currentPower < desiredPower){

					if(currentPower + slewRate < desiredPower){
							currentPower +=slewRate;
					}else{
							currentPower = desiredPower;
							if(currentPower > maxMotorPower)
								currentPower = maxMotorPower;
						}

			}else{

						if(currentPower - slewRate > desiredPower){
				   			currentPower -= slewRate;
				 		}else{
				 				currentPower = desiredPower;
				 				if(currentPower < minMotorPower)
				 						currentPower =  minMotorPower;
						}
			}// end of INNER IF-ELSE
		}// end of OUTTER IF

		if(currentAnglePsi < ((150/desiredAngleU) * desiredAngleU)){
				//	psiIncrement will increase by the equivalent of 1 degree but in radians
				psiIncrement += (slewRate* angleIncrease);
				// caluculate new current angle based of psiIncrement and then convert it to degrees
				currentAnglePsi = ((trackWidth/2 * psiIncrement)* (2/diameter))*(180/PI);
		}else
			if(currentAnglePsi > ((150/desiredAngleU) * desiredAngleU)){
				//	psiIncrement will decrease by the equivalent of 1 degree but in radians
					psiIncrement -= (slewRate* angleIncrease);
				// caluculate new current angle based of psiIncrement and then convert it to degrees
					currentAnglePsi = ((trackWidth/2 * psiIncrement)* (2/diameter))*(180/PI);
				}

		displayTextLine(1,"%s: %f","currentPower",currentPower);
		displayTextLine(2,"%s: %f","desiredPower",desiredPower);
		displayTextLine(3,"%s: %f","currentAnglePsi",currentAnglePsi);
		displayTextLine(4,"%s: %f","desiredAngleU",(150/desiredAngleU) * desiredAngleU);
		setMotorSync(RIGHT,LEFT,-100,currentPower);

		sleep(motorControlTaskDelay * .13);
	}// end of WHILE
}// end of turnRightSpeedControl



void distance300(){
	resetMotorEncoder(RIGHT);

	desiredPower = 0;

	while(currentDistance < desiredDistanceMM){

		error = (desiredDistanceMM - currentDistance);


		if(abs(error) > tolerance){
			desiredPower = k*(desiredDistanceMM - currentDistance);

			if(currentDistance <  (.85 * (desiredDistanceMM * .1666))){
							currentPower += slewRate;
			}else if(currentDistance > (.85 * desiredDistanceMM)){
							 currentPower -= slewRate;
			}// end of INNER IF-ELSE
		}// end of OUTTER IF

		displayTextLine(1,"%s: %i","desiredDistanceINCHES",desiredDistanceMM);
		displayTextLine(2,"%s: %i","current distance",currentDistance);
		displayTextLine(3,"%s: %f","currentPower",currentPower);
		displayTextLine(4,"%s: %f","desiredPower",desiredPower);

		setMotorSync(RIGHT,LEFT,0,currentPower);
		degreesTurned = getMotorEncoder(RIGHT);
		currentDistance += ((degreesTurned/360) * circumference);
		sleep(motorControlTaskDelay * .6);
	}// end of WHILE
}// end of turnRightSpeedControl TASK




task main()
{
	positive60degrees();
	distance500();
	negative90degrees();
	distance1000();
	positive150degrees();
	distance300();
}
