#include <iostream>

using namespace std;

class Exam
{
private:
    string *sName;
    string *examDate;
    string *subject; //added myself so that it looks better when displaying Exam Details
    int *score;

public:
    void setSName(string name)
    {
        *sName = name;
    }
    void setExamDateAndSubject(string Date, string Subj)
    {
        *examDate = Date;
        *subject = Subj;
    }
    void setScore(int Score)
    {
        *score = Score;
    }
    void displayExamDetails()
    {
        cout << "Student Name: " << *sName << endl;
        cout << "Exam Date: " << *examDate << endl;
        cout << "Exam subject: " << *subject << endl;
        cout << "Score: " << *score << "/100" << endl;
        cout << endl;
    }
    Exam()
    {
        sName = new string;
        examDate = new string;
        subject = new string;
        score = new int;
    }
    ~Exam()
    {
        delete sName;
        delete examDate;
        delete subject;
        delete score;
    }
};

int main()
{
    Exam e1;
    e1.setSName("Ahmed");
    e1.setExamDateAndSubject("28th August'2025 ", "English");
    e1.setScore(90);
    e1.displayExamDetails();
    Exam e2(e1);
    e2.setSName("Kamran");
    e2.setExamDateAndSubject("24th September'2025 ", "Calculus");
    e2.setScore(87);
    e2.displayExamDetails();
    e1.displayExamDetails();

    /* Conclusion: We notice that when using DMA in a class, if we don't use a custom copy
    constructor, then when copying an object's attributes to another object, shallow copy
    is performed, meaning that when we edit object 2's attributes, then the original
    object's attributes are also changed which is an undesirable result. */

    return 0;
}
