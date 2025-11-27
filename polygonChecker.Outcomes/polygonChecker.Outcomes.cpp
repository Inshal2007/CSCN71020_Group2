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
			Assert::AreEqual(41.4096, angle1, 0.01);

		}//(9)

		TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_1050120AnglesScaleneCase)
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
			Assert::AreEqual(130.0, angle1, 0.01);
			Assert::AreEqual(20, angle2, 0.01);
			Assert::AreEqual(30, angle1, 0.01);

		}//(10)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_000AnglesCase)
		//{
		//}//(11)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegtaiveAnglesCase)
		//{
		//}//(12)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_UndefinedAnglesCase)
		//{
		//}//(13)

		//The following 6 test methods test the classifyTriangleByAngles() function=----------------------------=
		//TEST_METHOD(ClasifyTriangleByAnglesFunction_TriangleByAngles_Less90AcuteTriangle)
		//{
		//}//(14)

		///TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_Greater90ObtuseTriangle)
		//{
		//}//(15)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_Equal90RightTriangle)
		//{
		//}//(16)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_AllZeroAnglesNoTriangle)
		//{
		//}//(17)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_UndefinedAnglesNoTriangle)
		//{
		//}//(18)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegativeAnglesNoTriangle)
		//{
		//}//(19)

		//TEST_METHOD(CalculateTriangleAnglesFunction_TriangleAnglesDetermination_NegativeZeroAnglesNoTriangle)
		//{
		//}//(20)

	};

	TEST_CLASS(rectangleFeatures)
	{
	public:

		//TEST_METHOD(TestMethod)
		//{
		//}

	};
}
