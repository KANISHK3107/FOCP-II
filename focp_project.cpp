#include <iostream>
#include <vector>
using namespace std;

class Person
{
    int age, id;
    long long contactN;
    string name;

public:
    Person(int a, int b, long long c, string d)
    {
        setage(a);
        id = b;
        contactN = c;
        setname(d);
    }

    void setage(int a)
    {
        if (a > 0 && a < 80)
            age = a;
        else
            cout << "entered invalid Age";
    }

    void setname(string d)
    {
        if (d.empty())
            cout << "Entered invalid Name";
        else
            name = d;
    }

    virtual void displayDetail()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "ID:" << id << endl;
        cout << "Contact NO.:" << contactN << endl;
    }

    virtual float calculatePayment()
    {
        
        return 0.0;
    }

    };

class Student : public Person
{
    string enrol_date, program;
    
    public:
    float gpa;
    Student(int age, int id, long long contactN, string name, string a, string b, float c)
        : Person(age, id, contactN, name), enrol_date(a), program(b)
    {
        setgpa(c);
    }

    void setgpa(float c)
    {
        if (c > 0.0 && c < 4.0)
            gpa = c;
        else
            cout << "Entered invalid GPA";
    }

     void displayDetail() override
    {
        Person::displayDetail();
        cout << "Enrollment Date: " << enrol_date << endl;
        cout << "Program: " << program << endl;
        cout << "GPA: " << gpa << endl;
    }
    float calculatePayment() override
    {
        float baseFee = 20000;
        float scholarship = gpa * 1000;
        return baseFee - scholarship;
    }
};

class UndergraduateStudent: public Student
{
    private:
    string major, minor, expected_graduation_date;

public:
    UndergraduateStudent(int age, int id, long long contactN, string name, string a, string b, float c, string m, string mi, string e)
        : Student(age, id, contactN, name, a, b, c) {
        major = m;
        minor = mi;
        expected_graduation_date = e;
    }

    void displayDetail() override {
        Student::displayDetail();
        cout << "Major: " << major << endl;
        cout << "Minor: " << minor << endl;
        cout << "Expected Graduation Date: " << expected_graduation_date << endl;
    }

    float calculatePayment() override {
        float baseFee = 20000;
        float scholarship = gpa * 1200; 
        return baseFee - scholarship;
    }
};

class GraduateStudent : public Student
{
    private:
    string research_topic, advisor, thesis_title;

public:
    GraduateStudent(int age, int id, long long contactN, string name, string a, string b, float c, string r, string adv, string t)
        : Student(age, id, contactN, name, a, b, c) {
        research_topic = r;
        advisor = adv;
        thesis_title = t;
    }

    void displayDetail() override {
        Student::displayDetail();
        cout << "Research Topic: " << research_topic << endl;
        cout << "Advisor: " << advisor << endl;
        cout << "Thesis Title: " << thesis_title << endl;
    }

    float calculatePayment() override {
        float baseFee = 25000; 
        float scholarship = gpa * 1500; 
        return baseFee - scholarship;
    }

};

class Professor : public Person
{
    string department, specialization, hire_date;

public:
    Professor(int age, int id, long long contactN, string name, string a, string b, string c)
    : Person(age, id, contactN, name), department(a), specialization(b), hire_date(c)
    {
    }

    void displayDetail() override
    {
        Person::displayDetail();
        cout << "Department: " << department << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Hire Date: " << hire_date << endl;
    }

    float calculatePayment() override
    {
        float baseSalary = 50000;

        if (department == "CSE") baseSalary += 10000;
        else if (department == "ECE") baseSalary += 8000;

        return baseSalary;
    }
};

class AssistantProfessor:public Professor
{
    private:
    int tenureTrackYears;

public:
    AssistantProfessor(int age, int id, long long contactN, string name, string a, string b, string c, int t)
        : Professor(age, id, contactN, name, a, b, c) {
        tenureTrackYears = t;
    }

    void displayDetail() override {
        Professor::displayDetail();
        cout << "Tenure Track Years: " << tenureTrackYears << endl;
    }

    float calculatePayment() override {
        float baseSalary = 55000;
        if (tenureTrackYears > 5) baseSalary += 5000;  
        return baseSalary;
    }

};

class AssociateProfessor: public Professor
{
    private:
    bool hasPublished;

    public:
    AssociateProfessor(int age, int id, long long contactN, string name, string a, string b, string c, bool p)
        : Professor(age, id, contactN, name, a, b, c) {
        hasPublished = p;
    }

    void displayDetail() override {
        Professor::displayDetail();
        cout << "Has Published: " << (hasPublished ? "Yes" : "No") << endl;
    }

    float calculatePayment() override {
        float baseSalary = 60000;
        if (hasPublished) baseSalary += 7000;  
        return baseSalary;
    }
};
class FullProfessor: public Professor
{
    private:
    int yearsatrank;

public:
    FullProfessor(int age, int id, long long contactN, string name, string a, string b, string c, int years)
        : Professor(age, id, contactN, name, a, b, c) {
        yearsatrank = years;
    }

    void displayDetail() override {
        Professor::displayDetail();
        cout << "Years at Rank: " << yearsatrank << endl;
    }

    float calculatePayment() override {
        float baseSalary = 70000;
        if (yearsatrank > 10) baseSalary += 10000;  
        return baseSalary;
    }

};

class Course
{
    string code, title, description;
    int credits;

public:
    Course(string a, string b, string c, int d)
    {
        code = a;
        title = b;
        description = c;
        setcredit(d);
    }

    void setcredit(int d)
    {
        if (d > 0)
            credits = d;
        else
            cout << "Entered invalid Credits";
    }
};

class Department
{
    string name, location;
    int budget;

public:
    Department(string a, string b, int c)
    {
        setname(a);
        location = b;
        budget = c;
    }

    void setname(string d)
    {
        if (d.empty())
            cout << "Entered invalid Name";
        else
            name = d;
    }
};

class Gradebook
{
    vector<int> studentIDs;
    vector<float> grades;
    int count;

public:
    void addGrade(int studentID, float grade)
    {
        if (grade < 0.0 || grade > 4.0)
        {
            cout << "Invalid grade. cpg should be between 0.0 and 4.0\n";
            return;
        }

        studentIDs.push_back(studentID);
        grades.push_back(grade);
    }

    float calculateAverageGrade()
    {
        if (grades.empty())
        {
            cout << "No grades available to calculate average." << endl;
            return 0.0;
        }

        float sum = 0.0;
        for (float grade : grades)
        {
            sum += grade;
        }

        return sum / grades.size();
    }

    float getHighestGrade()
    {
        if (grades.empty())
        {
            cout << " No grades available o get highest of." << endl;
            return 0.0;
        }
        float max = 0;
        for (float grade : grades)
        {
            if (max < grade)
                max = grade;
        }

        return max;
    }

    void getFailingStudents()
    {
        if (grades.empty())
            cout << "No student to check for failing.";
        for (int i = 0; i < grades.size(); i++)
        {
            if (grades[i] < 1.0)
            {
                cout << "Student wiht student id:" << studentIDs[i] << " is failing." << endl;
            }
        }
    }
};

class Enrollment_Manager
{
    vector<string> coursecodes;
    vector<vector<int>> estudentids;

private:
    int findCourseIndex(const string &code)
    {
        for (int i = 0; i < coursecodes.size(); i++)
        {
            if (coursecodes[i] == code)
                return i;
        }
        return -1;
    }

public:
    void enrollStudent(string coursecode, int studentid)
    {
        int index = findCourseIndex(coursecode);

        if (index == -1)
        {
            coursecodes.push_back(coursecode);
            estudentids.push_back(vector<int>());
            index = coursecodes.size() - 1;
        }

        estudentids[index].push_back(studentid);
    }

    void dropstudent(string coursecode, int studentid)
    {
        int index = findCourseIndex(coursecode);

        if (index == -1)
        {
            cout << "course does not exit to drop the student." << endl;
        }

        for (int i = 0; i < estudentids[index].size(); i++)
        {
            if (studentid == estudentids[index][i])
            {
                estudentids[index].erase(estudentids[index].begin() + i);
                cout << "Student with id:" << studentid << " has been droped from the course." << endl;
            }
            return;
        }
        cout << "Student with id:" << studentid << " is not enrolled in the course" << endl;
    }

    void getEnrollmentCount(string coursecode)
    {
        int index = findCourseIndex(coursecode);

        if (index == -1)
        {
            cout << "course does not exit." << endl;
            return;
        }

        cout << "Number of students enrolled in " << coursecode << ": " << estudentids[index].size() << endl;
    }
};
testperson(Person* P){
P->displayDetail();
}

int main()
{
    Person P1(26, 3114, 9643247444, "Kanishk");
    Person *P2 = new Student(24, 2222, 9876543210, "Ravi", "24/4/2025", "MBA", 3.67);
    Student S1(21, 3333, 9876543211, "Anuj", "31/1/2024", "Btech", 3.63);
    testperson(&P1);
    testperson(P2);
    Gradebook g;
    g.addGrade(3114, 3.6);
    g.addGrade(3312, 2.2);
    g.addGrade(4321, 0.6);
    float avg = g.calculateAverageGrade();
    cout << avg << endl;
    g.getFailingStudents();
    float high = g.getHighestGrade();
    cout << high << endl;

    cout << "\n--- Polymorphism via Person* Array ---\n";

    Person* persons[3];
    persons[0] = new Student(20, 1001, 9876543210, "Amit", "01/01/2023", "BCA", 3.5);
    persons[1] = new Professor(45, 1002, 9123456789, "Dr. Sharma", "CSE", "AI", "15/08/2010");
    persons[2] = new Student(22, 1003, 9988776655, "Neha", "12/12/2022", "MBA", 3.8);

    for (int i = 0; i < 3; ++i)
    {
        persons[i]->displayDetail();
        cout << "Calculated Payment: " << persons[i]->calculatePayment() << endl;
        cout << "------------------------" << endl;
    }

    for (int i = 0; i < 3; ++i)
    {
        delete persons[i];
    }

    UndergraduateStudent U1(22, 4444, 9876543233, "Vikram", "01/01/2024", "Btech", 3.75, "CS", "Mathematics", "05/2027");
    GraduateStudent G1(25, 5555, 9876543234, "Sneha", "01/01/2022", "Mtech", 3.9, "AI Research", "Prof. Gupta", "Deep Learning");
    AssistantProfessor A1(40, 6666, 9876543235, "Prof. Mehta", "ECE", "Communication Systems", "12/08/2015", 6);
    AssociateProfessor Ap1(50, 7777, 9876543236, "Prof. Sharma", "CSE", "Machine Learning", "15/05/2010", true);
    FullProfessor F1(55, 8888, 9876543237, "Prof. Gupta", "ECE", "Signal Processing", "20/02/2005", 12);

    cout << "\n--- Testing GraduateStudent, UndergraduateStudent, AssistantProfessor, AssociateProfessor, FullProfessor ---\n";
    U1.displayDetail();
    cout << "Calculated Payment: " << U1.calculatePayment() << endl;
    cout << "------------------------" << endl;

    G1.displayDetail();
    cout << "Calculated Payment: " << G1.calculatePayment() << endl;
    cout << "------------------------" << endl;

    A1.displayDetail();
    cout << "Calculated Payment: " << A1.calculatePayment() << endl;
    cout << "------------------------" << endl;

    Ap1.displayDetail();
    cout << "Calculated Payment: " << Ap1.calculatePayment() << endl;
    cout << "------------------------" << endl;

    F1.displayDetail();
    cout << "Calculated Payment: " << F1.calculatePayment() << endl;
    cout << "------------------------" << endl;

    // Testing Course and Department classes
    Course C1("CS101", "Intro to CS", "Basic Programming Concepts", 4);
    Department D1("Computer Science", "Building A", 500000);

    // Testing Enrollment_Manager
    Enrollment_Manager em;
    em.enrollStudent("CS101", 1001);
    em.enrollStudent("CS101", 1003);
    em.getEnrollmentCount("CS101");

    em.dropstudent("CS101", 1003);
    em.getEnrollmentCount("CS101");

    // Cleanup dynamically allocated memory
    delete P2;
    
    return 0;
}
