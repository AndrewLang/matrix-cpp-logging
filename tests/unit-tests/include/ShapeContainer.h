#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

namespace Tests
{
	class ShapeContainer : public Shape
	{
	public:
		std::vector<std::shared_ptr<Shape>> shapes;

		ShapeContainer();

		double area() override;
	};
}