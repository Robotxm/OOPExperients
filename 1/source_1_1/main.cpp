/**
 * Experiment 1
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-04-06
 */

#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    string input_str;
    // Use map as container to store each student's score
    // Structure:
    // Key   - student's name
    // Value - list of student's scores
    map<string, vector<double>> students_total_scores;
    // Store total score of all students
    double total_score = 0.0;
    // Store how many scores are given
    int total_item_count = 0;

    while (1)
    {
        // Input name and value
        string name;
        cin >> name;
        if (!cin)
            break;
        double value;
        cin >> value;
        if (!value)
            break;

        // Find student and append value
        students_total_scores[name].push_back(value);

        // Store total scores and count
        total_item_count++;
        total_score += value;
    }

    // Print each student's total scores and average
    cout << endl
         << "Statistics by name:" << endl;
    for (auto kv : students_total_scores)
    {
        double sum = accumulate(kv.second.begin(), kv.second.end(), 0.0);
        cout << kv.first << "\t"
             << "Sum=" << sum << ", Average=" << sum / kv.second.size() << endl;
    }

    // Print all students' total scores and average
    cout << endl
         << "Total:" << endl
         << "Sum=" << total_score << ", Average=" << total_score / total_item_count << endl;

    return 0;
}