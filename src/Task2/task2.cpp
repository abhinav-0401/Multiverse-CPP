#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
        int n; // n is size that user inputs
        vector<unsigned int> v, ans1, ans2, ans3; // v is the vector that user inputs

        void solve_task1() {
            // solve task1 and save the answer in ans1
            std::set<unsigned int> s;

            for (const auto& val : v) {
                s.insert(val);
            }

            for (auto val : s) {
                this->ans1.push_back(val);
            }
        }

        void solve_task2() {
            // solve task2 and save the answer in ans2
            std::vector<unsigned int> v_temp = this->v;
            std::vector<std::vector<unsigned int>> container;

            // Group the vector's elements into groups of two
            for (int i{}; i < std::size(v_temp); i += 2) {            // std::size needs C++17
                std::vector<unsigned int> temp = {v_temp[i], v_temp[i+1]};
                container.push_back(temp);
            }

            // Store the second elements in an array of their own, sort them, then use a map for referencing group
            std::map<unsigned int, std::vector<unsigned int>> el_map;
            std::vector<unsigned int> seconds;

            // Mapping the second elements to the ref of their groups
            for (std::vector<unsigned int>& val : container) {
                seconds.push_back(val[1]);
                el_map[val[1]] = val;
            }

            // Sort the seconds and then use the map to access the first members
            std::sort(seconds.begin(), seconds.end(), greater<>());
            for (auto& val : seconds) {
                this->ans2.push_back(el_map[val][0]);
            }
        }
        void solve_task3() {
            // solve task3 and save the answer in ans3
            std::vector<unsigned int> v_temp = v;
            std::vector<std::vector<unsigned int>> container;
            std::queue<unsigned int> q;

            // Group the vector's elements into groups of two
            for (int i{}; i < std::size(v_temp); i += 2) {            // std::size needs C++17
                std::vector<unsigned int> temp = {v_temp[i], v_temp[i+1]};
                container.push_back(temp);
            }

            // Loop through the first elements of the groups
            for (const auto& val : container) {
                if (val[0] % 2 != 0) {
                    q.push(val[1]);
                } 
                else {
                    q.push(val[1]);
                    q.pop();                        
                }
            }

            // Now loop through the queue and assign the values to ans3
            int q_init_len = q.size();
            for (int i = 0; i < q_init_len; ++i) {
                this->ans3.push_back(q.front());
                q.pop();
            }
        }
    
    public:
    // create a constructor to take input
        Solution(int n, std::vector<unsigned int> v) {
            this->n = n;
            this->v = v;
            this->solve_task1();
            this->solve_task2();
            this->solve_task3();
        }

    string FINDMATCH(string path) {
        // complete this function to read file, compare with ans1, ans2, ans3
        // and return the answer
        ifstream file;
        file.open(path, ios::binary);

        if (!file.is_open()){
            cout<<"The file can't be opened.\n";
            return "ERROR";
        }

        file.seekg(0, ios::end);
        int file_size = file.tellg();
        file.seekg(0, ios::beg);

        unsigned int read_data;
        int size_int = sizeof(int);
        vector<unsigned int> answer;

        while(file.tellg() != file_size){
            file.read((char *) &read_data, size_int);
            answer.push_back(read_data);
        }

        if (ans1==answer) return "TASK1";
        else if (ans2==answer) return "TASK2";
        else if (ans3==answer) return "TASK3";
        else return "NOTFOUND";

    }
};



// int main() {
//     vector<unsigned int> a{5, 7, 6, 5, 2, 1, 4, 0, 1, 3};
//     string paths[] = {
//         "missing_files/missing1.bin",
//         "missing_files/missing2.bin",
//         "missing_files/missing3.bin",
//         "missing_files/missing4.bin",
//     };
//     // Intialize your solution object here
//     Solution sol(10, a);

//     // Make a for loop to go through paths array and call FINDMATCH function
//     for (auto& s : paths) {
//         sol.FINDMATCH(s);
//     }

//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test2_cases.h"