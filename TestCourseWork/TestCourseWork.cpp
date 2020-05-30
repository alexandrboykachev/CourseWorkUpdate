#include "pch.h"
#include "CppUnitTest.h"
#include "../CourseWork/Flow.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCourseWork
{
	TEST_CLASS(TestCourseWork)
	{
	public:
		TEST_METHOD(TestMethod_Ñorrect_output_for_6_vertexes)
		{
			ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input1.txt");
			Flow flow(input);
			Assert::AreEqual(flow.max_flow(), 6);
		}
		TEST_METHOD(TestMethod_Exception_entering_the_first_character) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input2.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error entering the first character in the string or missing a space after it. Check the correctness of the input in the file and correct these errors in the line under the number: 2");
			}
		}
		TEST_METHOD(TestMethod_Exception_entering_the_second_character) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input3.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error entering the second character in the string or missing a space after it. Check the correctness of the input in the file and correct these errors in the line under the number: 2");
			}
		}
		TEST_METHOD(TestMethod_Exception_entering_the_third_number_flow) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input4.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error entering the third character (bandwidth) in the string or the presence of a space after it.Please note that the bandwidth cannot be negative. Check that you entered the file correctly and correct these errors in the line number: 4");
			}
		}
		TEST_METHOD(TestMethod_Exception_empty_string) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input5.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "A data-entry error. Check the correctness of the input in the file and correct these errors in the line under the number: 3");
			}
		}
		TEST_METHOD(TestMethod_Ñorrect_output_for_6_vertexes_and_edge_from_source_to_sink)
		{
			ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input6.txt");
			Flow flow(input);
			Assert::AreEqual(flow.max_flow(), 25);
		}
		TEST_METHOD(TestMethod_Ñorrect_output_for_2_vertexes_edges_from_source_to_sink)
		{
			ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input7.txt");
			Flow flow(input);
			Assert::AreEqual(flow.max_flow(), 20);
		}
		TEST_METHOD(TestMethod_Exception_there_is_a_path_from_the_vertex_to_itself) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input8.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "The path from the vertex to itself is impossible in the string under the number: 2");
			}
		}
		TEST_METHOD(TestMethod_Ñorrect_output_for_20_vertexes)
		{
			ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input9.txt");
			Flow flow(input);
			Assert::AreEqual(flow.max_flow(), 19);
		}
		TEST_METHOD(TestMethod_Exception_empty_file) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input10.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "A data-entry error. File is empty.");
			}
		}
		TEST_METHOD(TestMethod_Exception_source_missing) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input11.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Source is missing");
			}
		}
		TEST_METHOD(TestMethod_Exception_sink_missing) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input12.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Sink is missing");
			}
		}
		TEST_METHOD(TestMethod_Exception_no_way_from_source_to_sink) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input13.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "There is no way from the source to the sink");
			}
		}
		TEST_METHOD(TestMethod_Exception_extra_line) {
			try {
				ifstream input("C:\\Users\\Asus\\source\\repos\\CourseWork\\TestCourseWork\\input14.txt");
				Flow flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "A data-entry error. Check the correctness of the input in the file and correct these errors in the line under the number: 41");
			}
		}
	};
}
