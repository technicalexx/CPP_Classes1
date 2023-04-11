/*
Author: Alexandra R
Created: 03/15/2023
Last Updated: 04/11/2023
Project: Program that defines and tests the class called Programming
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//class definition for our Programming class
class Programming
{
private:  //private members declaration:
	string student_number;
	string first_name;
	string last_name;
	int quiz1_grade;
	int quiz2_grade;
	int quiz3_grade;
	int midterm_grade;
	int final_grade;
	double total_grade;
	char final_letter_grade;

public:  //public members declaration:
	Programming(); //default constructor, will be used to initialize students' grades to 100 later

	//declaration of additional constructor, all values can be passed manually in main function:
	Programming(string number, string f_name, string l_name, int q1_grade, int q2_grade,
		int q3_grade, int mid_grade, int fin_grade, double tot_grade, char letter_grade);

	//setter functions declaration for all members
	//sets specific values for each member if needed in main function later:
	void set_student_number(string student_number);
	void set_first_name(string updated_first_name);
	void set_last_name(string updated_last_name);
	void set_quiz1_grade(int updated_quiz1_grade);
	void set_quiz2_grade(int updated_quiz2_grade);
	void set_quiz3_grade(int updated_quiz3_grade);
	void set_midterm_grade(int updated_midterm_grade);
	void set_final_grade(int updated_final_grade);
	void set_total_grade(double updated_total_grade);
	void set_final_letter_grade(char updated_letter_grade);

	//declaration of getter functions (for each member):
	string get_student_number();
	string get_first_name();
	string get_last_name();
	int get_quiz1_grade();
	int get_quiz2_grade();
	int get_quiz3_grade();
	int get_midterm_grade();
	int get_final_grade();
	double get_total_grade();
	char get_final_letter_grade();

	//declaration of "total grades" function
	//a function that computes a student's total grade
	double student_total_grade(int quiz1, int quiz2, int quiz3, int midterm, int final);

	//declaration of a function that assigns a letter grade based on the total grade
	char student_letter_grade(double total_grade);

	//additional function that checks if a student missed a midterm or a final
	//if midterm/final is 0, the student gets F automatically
	bool check_missed_exams(int midterm, int final);

	//declaration of an output function that displays a student's name, student number and all the grades
	void display_output(ostream& display);
};

int main()
{
	//declaration of objects
	Programming student0, student1, student2, student3;

	//testing default constructor, all the grades were initialized to 100:
	cout << "---------------------------------------------------------------------------";
	cout << "\nTest Case 1 - Using Default Constructor:\n";
	cout << "---------------------------------------------------------------------------";
	student0 = Programming();
	student0.display_output(cout);
	cout << "---------------------------------------------------------------------------";

	//passing specific values for another object, using second constructor:
	cout << "\nTest Case 2 - Using Additional Constructor:\n";
	cout << "---------------------------------------------------------------------------";
	student1 = Programming("33333333", "Sam", "Samuel", 30, 30, 30, 60, 80, 88.00, 'B');
	student1.display_output(cout);
	cout << "---------------------------------------------------------------------------";

	//setting each value separately to test "Fan Fankous":
	cout << "\nTest Case 3 - setting each value separately to test Fan Fankous example:\n";
	cout << "---------------------------------------------------------------------------";
	student2.set_student_number("12345678");
	student2.set_first_name("Fan");
	student2.set_last_name("Fankous");
	student2.set_quiz1_grade(20);
	student2.set_quiz2_grade(20);
	student2.set_quiz3_grade(10);
	student2.set_midterm_grade(0);
	student2.set_final_grade(100);
	//total grade and missed exams will be checked inside the output function before displaying the results
	student2.display_output(cout);
	cout << "---------------------------------------------------------------------------";

	//setting each value separately to test "Gim Gimous":
	cout << "\nTest Case 4 - setting each value separately to test Gim Gimous example:\n";
	cout << "---------------------------------------------------------------------------";
	student3.set_student_number("98765432");
	student3.set_first_name("Gim");
	student3.set_last_name("Gimous");
	student3.set_quiz1_grade(20);
	student3.set_quiz2_grade(20);
	student3.set_quiz3_grade(20);
	student3.set_midterm_grade(98);
	student3.set_final_grade(95);
	//total grade and missed exams will be checked inside the output function before displaying the results
	student3.display_output(cout);
	cout << "---------------------------------------------------------------------------";

	return 0;
}

//default constructor - initialization of all the member variables in our class (grades set to 100)
Programming::Programming()
{
	student_number = "00000000";
	first_name = "Test";
	last_name = "Test";
	quiz1_grade = 100;
	quiz2_grade = 100;
	quiz3_grade = 100;
	midterm_grade = 100;
	final_grade = 100;
	total_grade = 100;
	final_letter_grade = 'A';
}

//additional constructor that was declared earlier - specific values were passed in main
Programming::Programming(string number, string f_name, string l_name, int q1_grade, int q2_grade,
	int q3_grade, int mid_grade, int fin_grade, double tot_grade, char letter_grade)
{
	student_number = number;
	first_name = f_name;
	last_name = l_name;
	quiz1_grade = q1_grade;
	quiz2_grade = q2_grade;
	quiz3_grade = q3_grade;
	midterm_grade = mid_grade;
	final_grade = fin_grade;
	total_grade = tot_grade;
	final_letter_grade = letter_grade;
}

//setter functions - allow us to set each value separately if needed in main function:
void Programming::set_student_number(string updated_znumber)
{
	student_number = updated_znumber;
}
void Programming::set_first_name(string updated_first_name)
{
	first_name = updated_first_name;
}
void Programming::set_last_name(string updated_last_name)
{
	last_name = updated_last_name;
}
void Programming::set_quiz1_grade(int updated_quiz1_grade)
{
	//first checking whether negative grade or grade above 100 wasn't passed
	if ((updated_quiz1_grade < 0) || (updated_quiz1_grade > 100))
	{
		cout << "Inappropriate values entered. \n";
		exit(1);
	}
	quiz1_grade = updated_quiz1_grade;
}
void Programming::set_quiz2_grade(int updated_quiz2_grade)
{
	//first checking whether negative grade or grade above 100 wasn't passed
	if ((updated_quiz2_grade < 0) || (updated_quiz2_grade > 100))
	{
		cout << "Inappropriate values entered. \n";
		exit(1);
	}
	quiz2_grade = updated_quiz2_grade;
}
void Programming::set_quiz3_grade(int updated_quiz3_grade)
{
	//first checking whether negative grade or grade above 100 wasn't passed
	if ((updated_quiz3_grade < 0) || (updated_quiz3_grade > 100))
	{
		cout << "Inappropriate values entered. \n";
		exit(1);
	}
	quiz3_grade = updated_quiz3_grade;
}
void Programming::set_midterm_grade(int updated_midterm_grade)
{
	//first checking whether negative grade or grade above 100 wasn't passed
	if ((updated_midterm_grade < 0) || (updated_midterm_grade > 100))
	{
		cout << "Inappropriate values entered. \n";
		exit(1);
	}
	midterm_grade = updated_midterm_grade;
}
void Programming::set_final_grade(int updated_final_grade)
{
	//first checking whether negative grade or grade above 100 wasn't passed
	if ((updated_final_grade < 0) || (updated_final_grade > 100))
	{
		cout << "Inappropriate values entered. \n";
		exit(1);
	}
	final_grade = updated_final_grade;
}
void Programming::set_total_grade(double updated_total_grade)
{
	total_grade = updated_total_grade;
}
void Programming::set_final_letter_grade(char updated_letter_grade)
{
	final_letter_grade = updated_letter_grade;
}

//getter functions:
string Programming::get_student_number()
{
	return student_number;
}
string Programming::get_first_name()
{
	return first_name;
}
string Programming::get_last_name()
{
	return last_name;
}
int Programming::get_quiz1_grade()
{
	return quiz1_grade;
}
int Programming::get_quiz2_grade()
{
	return quiz2_grade;
}
int Programming::get_quiz3_grade()
{
	return quiz3_grade;
}
int Programming::get_midterm_grade()
{
	return midterm_grade;
}
int Programming::get_final_grade()
{
	return final_grade;
}
double Programming::get_total_grade()
{
	return total_grade;
}
char Programming::get_final_letter_grade()
{
	return final_letter_grade;
}

//calculating student total grade based on 3 quizes, midterm, and final:
double Programming::student_total_grade(int quiz1, int quiz2, int quiz3, int midterm, int final)
{
	double total_grade = 0.00;
	return total_grade = (quiz1 + quiz2 + quiz3) / 3.0 + midterm * 0.3 + final * 0.5;
}

//assigning a final letter grade based on the result of the total grade
//there will be another function to check for absence below this one
char Programming::student_letter_grade(double total_grade)
{
	if (total_grade >= 90)
		return 'A';
	if ((total_grade >= 80) && (total_grade < 90))
		return 'B';
	if ((total_grade >= 70) && (total_grade < 80))
		return 'C';
	if ((total_grade >= 60) && (total_grade < 70))
		return 'D';
	if (total_grade < 60)
		return 'F';
}

//checking whether a student missed midterm or final
//if midterm or final grade is zero, the student is automatically assigned letter grade 'F' (in output)
bool Programming::check_missed_exams(int midterm, int final)
{
	if (midterm == 0 || final == 0)
		return 0;
}

//displaying all the results
//in addition, calling "total_grade" function to calculate student's total grade before displaying it
//and calling "check_missed_exams" func. to check if a student was absent to assign & display letter 'F'
//otherwise an appropriate letter grade is assigned & displayed instead (if wasn't absent)
void Programming::display_output(ostream& display)
{
	bool result;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "\n" << first_name << " " << last_name << " - Student# " << student_number << endl;
	cout << endl;
	cout << setw(20) << "Quiz 1: " << quiz1_grade << endl;
	cout << setw(20) << "Quiz 2: " << quiz2_grade << endl;
	cout << setw(20) << "Quiz 3: " << quiz3_grade << endl;
	cout << setw(21) << "Midterm: " << midterm_grade << endl;
	cout << setw(19) << "Final: " << final_grade << endl;

	//calling function to calculate student's total
	total_grade = student_total_grade(quiz1_grade, quiz2_grade, quiz3_grade, midterm_grade, final_grade);
	//displaying student's total
	cout << setw(25) << "Total grade: " << total_grade << endl;

	//calling function to check if midterm or final grade is missing 
	//and displaying letter grade based on the result
	result = check_missed_exams(midterm_grade, final_grade);
	if (result == 0)
	{
		final_letter_grade = 'F';
		cout << setw(25) << "Final grade: " << final_letter_grade << endl;
	}
	else if (result != 0)
	{
		final_letter_grade = student_letter_grade(total_grade);
		cout << setw(25) << "Final grade: " << final_letter_grade << endl;
	}
	cout << endl;
}