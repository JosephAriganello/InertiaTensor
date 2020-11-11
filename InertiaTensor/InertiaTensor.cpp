#include "InertiaTensor.h"
#include <iostream>

using namespace std;

namespace MATH {

	InertiaTensor::InertiaTensor(){

		length = 0.0f;
		width = 0.0f;
		height = 0.0f;
		mass = 0.0f;
		radius = 0.0f;
		centerOfMass = Vec3(0.0f, 0.0f, 0.0f);
		iX = 0.0f;
		iY = 0.0f;
		iZ = 0.0f;
	}

	InertiaTensor::InertiaTensor(float l, float w, float h, float m, Vec3 cOM){

		length = l;
		width = w;
		height = h;
		mass = m;
		radius = 0.0f;
		centerOfMass = cOM;
		iX = 0.0f;
		iY = 0.0f;
		iZ = 0.0f;
	}

	InertiaTensor::InertiaTensor(float m, float r, float h, Vec3 cOM){

		length = 0.0f;
		width = 0.0f;
		height = h;
		mass = m;
		radius = r;
		centerOfMass = cOM;
		iX = 0.0f;
		iY = 0.0f;
		iZ = 0.0f;
	}

	InertiaTensor::~InertiaTensor(){

		delete this;
	}

	Matrix3 InertiaTensor::generateCubeiodIT(){

		Matrix3 cubeoidIT;

		cubeoidIT[0] = (1.0f / 12.0f) * mass * ((height * height) + (length * length));
		
		cubeoidIT[4] = (1.0f / 12.0f) * mass * ((width * width) + (length * length));

		cubeoidIT[8] = (1.0f / 12.0f) * mass * ((width * width) + (height * height));

		cout << cubeoidIT[0] << "          " << cubeoidIT[1] << "          " << cubeoidIT[2] << endl;
		cout << cubeoidIT[3] << "          " << cubeoidIT[4] << "          " << cubeoidIT[5] << endl;
		cout << cubeoidIT[6] << "          " << cubeoidIT[7] << "          " << cubeoidIT[8] << endl;

		return cubeoidIT;
	}

	Matrix3 InertiaTensor::generateCylinderIT(){

		Matrix3 cylinderIT;

		cylinderIT[0] = (1.0f / 12.0f) * mass * ((3 * (radius * radius)) + (height * height));

		cylinderIT[4] = (1.0f / 12.0f) * mass * ((3 *(radius * radius)) + (height * height));

		cylinderIT[8] = (1.0f / 2.0f) * mass * (radius * radius);

		cout << cylinderIT[0] << "          " << cylinderIT[1] << "          " << cylinderIT[2] << endl;
		cout << cylinderIT[3] << "          " << cylinderIT[4] << "          " << cylinderIT[5] << endl;
		cout << cylinderIT[6] << "          " << cylinderIT[7] << "          " << cylinderIT[8] << endl;

		return cylinderIT;
	}

	void InertiaTensor::print(InertiaTensor iT){

		cout << iT[0] << "          " << iT[1] << "          " << iT[2] << endl;
		cout << iT[3] << "          " << iT[4] << "          " << iT[5] << endl;
		cout << iT[6] << "          " << iT[7] << "          " << iT[8] << endl;
	}
}