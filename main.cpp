#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

double calculate_cgpa(vector<double> credit_hours, vector<double> grades){
    double total_credit_hours = 0;
    double total_grade_points = 0;

    if (credit_hours.empty() || grades.empty()){
        return 0;
    }
    
    for (int i = 0; i < credit_hours.size(); i++){
        total_credit_hours += credit_hours[i];
        total_grade_points += credit_hours[i] * grades[i];
    }
    return total_grade_points / total_credit_hours;
}

int main(){

    string welcome_msg = "\U0001F970 Hello, World!\n"
                         "Please input your course code, credit hours and grade.\n"
                         "example: CSE1001 3 95\n"
                            "Enter EOF to end input\n";
    cout << welcome_msg;

    string course_code;
    double credit_hours;
    double grade;

    vector<string> course_codes;
    vector<double> credit_hourss;
    vector<double> grades;


    while (cin >> course_code >> credit_hours >> grade){
        course_codes.push_back(course_code);
        credit_hourss.push_back(credit_hours);
        grades.push_back(grade);
    }
     
    cout << "You have input " << course_codes.size() << " courses:\n";

    for (int i = 0; i < course_codes.size(); i++){
        cout << left << setw(10) << course_codes[i] << 
                fixed << setprecision(1) << setw(4) << credit_hourss[i] <<
                fixed << setprecision(2) << setw(5) << grades[i] << endl;
    }

    double cgpa = calculate_cgpa(credit_hourss, grades);

    cout << "Your CGPA is: " << fixed << setprecision(2) << cgpa << endl;


    return 0;
}