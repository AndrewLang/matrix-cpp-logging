#pragma once
#include "Shape.h"

namespace Tests
{
	class Circle : public Shape
	{
	public:
		Circle();
		Circle(std::string shapeName, double circleRadius);

		double radius;
		double area() override;
	};
}