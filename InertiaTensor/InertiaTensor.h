#ifndef INERTIATENSOR_H
#define INERTIATENSOR_H

#include "Matrix.h"

namespace MATH {

	struct InertiaTensor : public Matrix3 {

		float length;
		float width;
		float height;
		float radius;
		float mass;
		float iX, iY, iZ;
		Vec3 centerOfMass;

		inline InertiaTensor();
		inline InertiaTensor(float l, float w, float h, float m, Vec3 cOM);
		inline InertiaTensor(float m, float r, float h, Vec3 cOM);
		~InertiaTensor();

		Matrix3 generateCubeiodIT();
		Matrix3 generateCylinderIT();

		void print(InertiaTensor iT);

	};
}
#endif