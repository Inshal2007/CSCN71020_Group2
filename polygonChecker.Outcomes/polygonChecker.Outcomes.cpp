#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" void calculateTriangleAngles(int side1, int side2, int side3, double* angle1, double* angle2, double* angle3);
extern "C" char* classifyTriangleByAngles(double angle1, double angle2, double angle3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace polygonCheckerOutcomes
{
	TEST_CLASS(triangleFeatures)
	{
	public:
		
		//The following 6 test methods test the analyzeTriangle() function=----------------------------=
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_NotATriangleResult)
		{
		}

		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_EquilateralTriangleResult)
		{
		}

		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_IsoscelesTriangleResult)
		{
		}

		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_ScaleneTriangleResult)
		{
		}

		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_NotATriangleNegativeSidesResult)
		{
		}

		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_NotATriangleBoundarySidesResult)
		{
		}

		//The following 6 test methods test the calculateTriangle() function=----------------------------=
		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_606060AnglesEquilateralCase)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_806060AnglesIsoscelesCase)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_1050120AnglesScaleneCase)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_000AnglesCase)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegtaiveAnglesCase)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_UndefinedAnglesCase)
		{
		}

		//The following 6 test methods test the classifyTriangleByAngles() function=----------------------------=
		TEST_METHOD(ClasifyTriangleByAnglesFunction_TriangleByAngles_Less90AcuteTriangle)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_Greater90ObtuseTriangle)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_Equal90RightTriangle)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_AllZeroAnglesNoTriangle)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_UndefinedAnglesNoTriangle)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegativeAnglesNoTriangle)
		{
		}

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegativeZeroAnglesNoTriangle)
		{
		}

	};

	TEST_CLASS(rectangleFeatures)
	{
	public:

		//TEST_METHOD(TestMethod)
		//{
		//}

	};
}
