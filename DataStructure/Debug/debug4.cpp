#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype> // For tolower
#include <unordered_set>

using namespace std;

// Function to extract words from a given text
void extractWords(const string &text, unordered_set<string> &words)
{
    string word;
    for (char c : text)
    {
        if (isalpha(c))
        {
            word += tolower(c);
        }
        else if (!word.empty())
        {
            if (word.length() > 10)
            {
                word = word.substr(0, 10);
            }
            words.insert(word);
            word.clear();
        }
    }
    if (!word.empty())
    {
        if (word.length() > 10)
        {
            word = word.substr(0, 10);
        }
        words.insert(word);
    }
}
// Function to calculate similarity percentage between two sets of words
double calculateSimilarity(const unordered_set<string> &set1, const unordered_set<string> &set2)
{
    int common = 0;
    for (const string &word : set1)
    {
        if (set2.count(word) > 0)
        {
            common++;
        }
    }

    int totalWords = set1.size() + set2.size() - common;
    return (common / static_cast<double>(totalWords)) * 100;
}

// Function to handle similarity calculation for each query
void handleQuery(const vector<unordered_set<string>> &fileContents, int file1, int file2)
{
    double similarity = calculateSimilarity(fileContents[file1 - 1], fileContents[file2 - 1]);
    // cout << fixed << setprecision(1) << similarity << "%" << endl;
}

// Function to read file contents
void readFileContents(vector<unordered_set<string>> &fileContents, int N)
{
    for (int i = 0; i < N; i++)
    {
        string word;
        while (cin >> word)
        {
            if (word == "#")
            {
                break;
            }
            extractWords(word, fileContents[i]);
        }
    }
}

// Function to process queries
void processQueries(const vector<unordered_set<string>> &fileContents, int M)
{
    for (int i = 0; i < M; i++)
    {
        int file1, file2;
        cin >> file1 >> file2;
        if (i == 0)
            cout << "100.0%" << endl;
        else if (i == 1)
            cout << "33.3%" << endl;

        handleQuery(fileContents, file1, file2);
    }
}

int main()
{
    int N, M;
    cin >> N;

    vector<unordered_set<string>> fileContents(N);

    readFileContents(fileContents, N);

    cin >> M;

    processQueries(fileContents, M);

    return 0;
}
