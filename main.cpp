#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
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

void input_from_file(vector<string> &course_codes, vector<double> &credit_hourss, vector<double> &grades){
    string course_code;
    double credit_hours;
    double grade;

    string default_file = "data.txt";
    cout << "Enter the file name " << "[" << default_file << "]: ";
    string file_name;
    getline(cin, file_name);
    if (file_name.empty()){
        file_name = default_file;
    }
    
    ifstream file(file_name);
    if (file.is_open()){
        while (file >> course_code >> credit_hours >> grade){
            course_codes.push_back(course_code);
            credit_hourss.push_back(credit_hours);
            grades.push_back(grade);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void input_by_hand(vector<string> &course_codes, vector<double> &credit_hourss, vector<double> &grades){
    string course_code;
    double credit_hours;
    double grade;
    cout << "Enter course code, credit hours and grade (q/quit to exit): " << endl;
    while (cin >> course_code){
        if (course_code == "q" || course_code == "quit"){
            break;
        }
        cin >> credit_hours >> grade;
        course_codes.push_back(course_code);
        credit_hourss.push_back(credit_hours);
        grades.push_back(grade);
    }

    cin.ignore(); // remove the newline character from the input buffer
}

int main(){



    vector<string> course_codes;
    vector<double> credit_hourss;
    vector<double> grades;

    string welcome_msg = "\U0001F970 Hello, World!\n"
                         "Do you want to input from file? (y/[n]): ";
    cout << welcome_msg;

    string from_file;
    getline(cin, from_file);

    if (from_file == "y" || from_file == "Y"){
        input_from_file(course_codes, credit_hourss, grades);

        cout << "Do you want to input more courses? (y/[n]): ";
        string more_courses;
        getline(cin, more_courses);

        if (more_courses == "y" || more_courses == "Y"){
            input_by_hand(course_codes, credit_hourss, grades);
        }
    }
    else{
        input_by_hand(course_codes, credit_hourss, grades);
    }

     
    cout << "You have input " << course_codes.size() << " courses:" << endl;

    for (int i = 0; i < course_codes.size(); i++){
        cout << left << setw(10) << course_codes[i] << 
                fixed << setprecision(1) << setw(4) << credit_hourss[i] <<
                fixed << setprecision(2) << setw(5) << grades[i] << endl;
    }

    double cgpa = calculate_cgpa(credit_hourss, grades);

    cout << "Your CGPA is: " << fixed << setprecision(2) << "\033[32m"  << cgpa << "\033[0m" << endl;

    cout << "Do you want save the record to a file? ([y]/n): ";

    string save;
    getline(cin, save);

    if (save.empty() || save == "y" || save == "Y"){
        cout << "Enter the file name: ";
        string file_name;
        cin >> file_name;
        ofstream file(file_name);
        if (file.is_open()){
            for (int i = 0; i < course_codes.size(); i++){
                file << course_codes[i] << " " << credit_hourss[i] << " " << grades[i] << "\n";
            }
            file.close();
            cout << "Record saved to " << file_name << endl;
        } else {
            cout << "Unable to open file" << endl;
        }
    }


    return 0;
}