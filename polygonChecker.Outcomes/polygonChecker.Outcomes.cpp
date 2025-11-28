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

		//Testing side lengths with values (0, 0, 0)
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_NotATriangleResult) 
		{
			//Decleration
			int side1 = 0;
			int side2 = 0;
			int side3 = 0;
			char* result;

			//Calculations and Comparison
			result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a Triangle", result);

		}//(1)

		//Testing side lengths with values (10, 10, 10)
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_EquilateralTriangleResult)
		{
		    //Decleration
			int side1 = 10;
			int side2 = 10;
			int side3 = 10;
			char* result;

			//Calculations and Comparison
			result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Equilateral triangle", result);

		}//(2)

		//Testing side lengths with values (10, 10, 8)
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_IsoscelesTriangleResult)
		{
			//Decleration
			int side1 = 10;
			int side2 = 10;
			int side3 = 8;
			char* result;

			//Calculations and Comparison
			result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);	 

		}//(3)

		//Testing side lengths with values (24, 10, 8)
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_ScaleneTriangleResult)
		{
			//Decleration
			int side1 = 25;
			int side2 = 10;
			int side3 = 8;
			char* result;

			//Calculations and Comparison
			result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Scalene triangle", result);

		}//(4)

		//Testing side lengths with values (24, 10, 8)
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_NotATriangleNegativeSidesResult)
		{
			//Decleration
			int side1 = -5;
			int side2 = -10;
			int side3 = 8;
			char* result;

			//Calculations and Comparison
			result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a Triangle", result);

		}//(5)

		//Testing side lengths with values (9999, 1, 9999)
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_NotATriangleBoundarySidesResult)
		{
			//Decleration
			int side1 = 9999;
			int side2 = 1;
			int side3 = 9999;
			char* result;

			//Calculations and Comparison
			result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);

		}//(6)

		//Testing side lengths with values (-0, -0, -0)
		TEST_METHOD(AnalyzeTriangleFunction_AnalyzeTriangleType_NotATriangleUndefinedSidesResult)
		{
			//Decleration
			int side1 = -0;
			int side2 = -0;
			int side3 = -0;
			char* result;

			//Calculations and Comparison
			result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a Triangle", result);

		}//(7)

		//The following 6 test methods test the calculateTriangle() function=----------------------------=
		
		//Testing side lengths with values (10, 10, 10) for an equilateral triangle
		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_EquilateralCase)
		{
			//Decleration
			double side1 = 10.0;
			double side2 = 10.0;
			double side3 = 10.0;
			double angle1 = 0.0;
			double angle2 = 0.0;
			double angle3 = 0.0;

			//Calculations and Comparison
			calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);
			Assert::AreEqual(60.0, angle1, 0.01);
			Assert::AreEqual(60.0, angle2, 0.01);
			Assert::AreEqual(60.0, angle1, 0.01);

		}//(8)

		//Testing side lengths with values (10, 15, 10) for an Isosceles triangle
		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_IsoscelesCase)
		{
			//Decleration
			double side1 = 10.0;
			double side2 = 15.0;
			double side3 = 10.0;
			double angle1 = 0.0;
			double angle2 = 0.0;
			double angle3 = 0.0;

			//Calculations and Comparison
			calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);
			Assert::AreEqual(41.4096, angle1, 0.01);
			Assert::AreEqual(97.1808, angle2, 0.01);
			Assert::AreEqual(41.4096, angle3, 0.01);

		}//(9)

		//Testing side lengths with values (10, 15, 8) for an Isosceles triangle
		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_AnglesScaleneCase)
		{
			//Decleration
			double side1 = 10.0;
			double side2 = 16.0;
			double side3 = 8.0;
			double angle1 = 0.0;
			double angle2 = 0.0;
			double angle3 = 0.0;

			//Calculations and Comparison
			calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);
			Assert::AreEqual(30.7535, angle1, 0.01);
			Assert::AreEqual(125.1, angle2, 0.01);
			Assert::AreEqual(24.1468, angle3, 0.01);

		}//(10)

		//Testing side lengths with values (1, 9999, 9999) for an Isosceles triangle
		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_BoundaryCase)
		{
			//Decleration
			double side1 = 1.0;
			double side2 = 9999.0;
			double side3 = 9999.0;
			double angle1 = 0.0;
			double angle2 = 0.0;
			double angle3 = 0.0;

			//Calculations and Comparison
			calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);
			Assert::AreEqual(0.0057301, angle1, 0.01);
			Assert::AreEqual(89.9971, angle2, 0.01);
			Assert::AreEqual(89.9971, angle3, 0.01);
		
		}//(11)

		//Testing side lengths with values (9.4732, 12.43, 4.2) for an Isosceles triangle
		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_AnglesFromFractionalSides)
		{
			//Decleration
			double side1 = 9.4732;
			double side2 = 12.43;
			double side3 = 4.2;
			double angle1 = 0.0;
			double angle2 = 0.0;
			double angle3 = 0.0;

			//Calculations and Comparison
			calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);
			Assert::AreEqual(34.6222, angle1, 0.01);
			Assert::AreEqual(130.751, angle2, 0.01);
			Assert::AreEqual(14.6265, angle3, 0.01);

		}//(12)

		//The following 6 test methods test the classifyTriangleByAngles() function=----------------------------=
		
		//Testing angles (60, 60, 60) Equilateral triangle
		TEST_METHOD(ClassifyTrianglesByAnglesFunction_DetermineTriangleByAngles_AcuteTriangle)
		{
			//Decleration
			double angle1 = 60.0;
			double angle2 = 60.0;
			double angle3 = 60.0;
			char* result;

			//Calculations and Comparison
			result = classifyTriangleByAngles(angle1, angle2, angle3);
			Assert::AreEqual("Acute", result);

		}//(13)

		//Testing angles (120, 30, 30) Equilateral triangle
		TEST_METHOD(ClassifyTrianglesByAnglesFunction_TriangleAnglesDetermination_Greater90ObtuseTriangle)
		{

			//Decleration
			double angle1 = 120.0;
			double angle2 = 30.0;
			double angle3 = 30.0;
			char* result;

			//Calculations and Comparison
			result = classifyTriangleByAngles(angle1, angle2, angle3);
			Assert::AreEqual("Obtuse", result);

		}//(14)

		TEST_METHOD(ClassifyTrianglesByAnglesFunction_TriangleAnglesDetermination_Equal90RightTriangle)
		{
			//Decleration
			double angle1 = 90.0;
			double angle2 = 50.0;
			double angle3 = 40.0;
			char* result;

			//Calculations and Comparison
			result = classifyTriangleByAngles(angle1, angle2, angle3);
			Assert::AreEqual("Right-angled", result);

		}//(15)

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_AllZeroAnglesNoTriangle)
		{
			
			//Decleration
			double angle1 = 180;
			double angle2 = 1;
			double angle3 = 1;
			char* result;

			//Calculations and Comparison
			result = classifyTriangleByAngles(angle1, angle2, angle3);
			Assert::AreEqual("No Triangle", result);

		}//(16)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_UndefinedAnglesNoTriangle)
		//{
		//}//(17)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegativeAnglesNoTriangle)
		//{
		//}//(18)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegativeZeroAnglesNoTriangle)
		//{
		//}//(19)

	};

	TEST_CLASS(rectangleFeatures)
	{
	public:

		//TEST_METHOD(TestMethod)
		//{
		//}

	};
}
