#include "student_records.hpp"
#include <iostream>

using namespace std;

bool isValidStudentId(string id) {
    // TODO:
    // A valid ID should have at least 3 characters.
    // A valid ID should start with an uppercase letter.
    // Hint: You may compare characters directly, such as id[0] >= 'A'.
    
    if (id.length() >= 3)
    {
        if (id[0] >= 'A' && id[0] <= 'Z')
        {
            return true;
        }
    }
    return false;

}

bool isValidScore(double score) {
    // TODO: Return true when score is between 0 and 100, inclusive.
    if (score >= 0 && score <= 100)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void printStudent(const Student& student) {
    cout << student.id << " "
         << student.name << " "
         << student.score << " "
         << determineLetterGrade(student.score)
         << endl;
}

void printStudents(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        cout << "No students to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        printStudent(students[i]);
    }
}

double calculateAverageScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the average score.
    if(size <= 0)
    {
        return 0.0;
    }
    else if (students == nullptr)
    {
        return 0.0;
    }
    else
    {
        double total = 0.0;

        for (int i = 0; i < size; i++)
        {
            total += students[i].score;
        }

        return (total/size);
    }
    
}

double findHighestScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the highest score.
    if(size <= 0)
    {
        return 0.0;
    }
    else if (students == nullptr)
    {
        return 0;
    }
    else
    {
        double largest = students[0].score;

        for (int i = 1; i < size; i++)
        {
            if(students[i].score > largest)
            {
                largest = students[i].score;
            }
        }

        return largest;
    }
}

int findStudentById(const Student students[], int size, string targetId) {
    // TODO:
    // Search by comparing students[i].id to targetId.
    // Return the index of the matching student.
    // Return -1 if no student is found.
    if(size <= 0)
    {
        return -1;
    }
    else if (students == nullptr)
    {
        return -1;
    }
    int dex = -1;
    for(int i = 0; i < size; i++)
    {
        if(students[i].id == targetId)
        {
            dex = i;
            break;
        }

    }
    
    return dex;
}

char determineLetterGrade(double score) {
    // TODO:
    // Return 'A' for scores 90 or higher.
    // Return 'B' for scores 80 or higher.
    // Return 'C' for scores 70 or higher.
    // Return 'D' for scores 60 or higher.
    // Return 'F' otherwise.
    if (score >= 60)
    {
        if (score >= 70)
        {
            if (score >= 80)
            {
                if (score >= 90)
                {
                    return 'A';
                }
                else
                {
                    return 'B';
                }
                
            }
            else
            {
                return 'C';
            }
            
        }
        else
        {
            return 'D';
        }
        
    }
    else
    {
        return 'F';
    }
}
