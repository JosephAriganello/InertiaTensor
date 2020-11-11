#include "Matrix.h"
#include "InertiaTensor.h"
#include <iostream>

using namespace std;

namespace MATH {

	int main() {

		InertiaTensor cubeoidWE1(250.0f, 50.0f, 50.0f, 150000.0f, Vec3(150.0f, 75.0f, 100.0f));
		InertiaTensor cubeoidWE2(250.0f, 50.0f, 50.0f, 150000.0f, Vec3(-150.0f, 75.0f, 100.0f));
		InertiaTensor cubeoidER(150.0f, 50.0f, 100.0f, 400000.0f, Vec3(0.0f, 0.0f, 0.0f));
		InertiaTensor cylinderBridge(300000.0f, 150.0f, 50.0f, Vec3(0.0f, 50.0f, -300.0f));
		InertiaTensor sumOfAllIT;
		InertiaTensor inverseTensor;

		cubeoidWE1.generateCubeiodIT();
		cubeoidWE2.generateCubeiodIT();
		cubeoidER.generateCubeiodIT();
		cylinderBridge.generateCylinderIT();

		sumOfAllIT += cubeoidWE1 + cubeoidWE2 + cubeoidER + cylinderBridge;

		cout << sumOfAllIT[0] << "          " << sumOfAllIT[1] << "          " << sumOfAllIT[2] << endl;
		cout << sumOfAllIT[3] << "          " << sumOfAllIT[4] << "          " << sumOfAllIT[5] << endl;
		cout << sumOfAllIT[6] << "          " << sumOfAllIT[7] << "          " << sumOfAllIT[8] << endl;
	}
}