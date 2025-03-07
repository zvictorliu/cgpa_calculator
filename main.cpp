#include <iostream>
#include <string>
#include <vector>

using namespace std;

double calculate_cgpa(vector<int> credit_hours, vector<int> grades){
    double total_credit_hours = 0;
    double total_grade_points = 0;
    for (int i = 0; i < credit_hours.size(); i++){
        total_credit_hours += credit_hours[i];
        total_grade_points += credit_hours[i] * grades[i];
    }
    return total_grade_points / total_credit_hours;
}

int main(){

    string welcome_msg = "Hello, World!\n"
                         "Please input your course code, credit hours and grade.\n"
                         "example: CSE1001 3 95\n"
                            "Enter EOF to end input\n";
    cout << welcome_msg;

    string course_code;
    int credit_hours;
    int grade;

    vector<string> course_codes;
    vector<int> credit_hourss;
    vector<int> grades;


    while (cin >> course_code >> credit_hours >> grade){
        course_codes.push_back(course_code);
        credit_hourss.push_back(credit_hours);
        grades.push_back(grade);
    }
     
    cout << "you have input " << course_codes.size() << " courses\n";

    for (int i = 0; i < course_codes.size(); i++){
        cout << course_codes[i] << " " << credit_hourss[i] << " " << grades[i] << endl;
    }

    cout << "Your CGPA is: " << calculate_cgpa(credit_hourss, grades) << endl;


    return 0;
}