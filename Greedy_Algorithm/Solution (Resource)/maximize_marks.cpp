#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Question
{
    int id;
    int marks;
    int time;
    double ratio;
};

bool compareRatio(Question a, Question b)
{
    return a.ratio > b.ratio;
}

pair<double, vector<pair<int, double>>> solveAlone(vector<Question> &questions, int totalTime)
{
    double maxMarks = 0;
    vector<pair<int, double>> answered;
    int remainingTime = totalTime;

    for (const Question &q : questions)
    {
        if (remainingTime <= 0)
            break;

        double timeCanSpend = min(q.time, remainingTime);
        double percentage = (timeCanSpend / q.time) * 100.0;
        double marksGot = (percentage / 100.0) * q.marks;

        if (percentage > 0)
        {
            maxMarks += marksGot;
            answered.push_back({q.id, percentage});
            remainingTime -= timeCanSpend;
        }
    }

    return {maxMarks, answered};
}

double solveWithFriend(vector<Question> &questions, int totalTime)
{
    double maxMarks = 0;
    int remainingTime1 = totalTime;
    int remainingTime2 = totalTime;

    for (const Question &q : questions)
    {
        if (remainingTime1 >= remainingTime2 && remainingTime1 >= q.time)
        {
            maxMarks += q.marks;
            remainingTime1 -= q.time;
        }
        else if (remainingTime2 >= q.time)
        {
            maxMarks += q.marks;
            remainingTime2 -= q.time;
        }
        else
        {
            // Try to complete remaining part with available time
            if (remainingTime1 > 0)
            {
                double percentage = (double)remainingTime1 / q.time;
                maxMarks += percentage * q.marks;
                remainingTime1 = 0;
            }
            else if (remainingTime2 > 0)
            {
                double percentage = (double)remainingTime2 / q.time;
                maxMarks += percentage * q.marks;
                remainingTime2 = 0;
            }
        }
    }

    return maxMarks;
}

int main()
{
    int M, T, N;
    cin >> M >> T >> N;

    vector<Question> questions(N);
    for (int i = 0; i < N; i++)
    {
        questions[i].id = i + 1;
        cin >> questions[i].marks >> questions[i].time;
        questions[i].ratio = (double)questions[i].marks / questions[i].time;
    }

    sort(questions.begin(), questions.end(), compareRatio);

    auto result = solveAlone(questions, T);
    double maxMarksAlone = result.first;
    vector<pair<int, double>> answered = result.second;

    double maxMarksWithFriend = solveWithFriend(questions, T);

    cout << fixed << setprecision(0);
    cout << "Maximum " << maxMarksAlone << " marks answering alone\n";

    for (const auto &ans : answered)
    {
        cout << "ques " << ans.first << " "
             << ans.second << "% done -- "
             << (ans.second / 100.0) * questions[ans.first - 1].marks << " marks\n";
    }

    cout << "Maximum " << maxMarksWithFriend << " marks answering with a friend\n";

    return 0;
}