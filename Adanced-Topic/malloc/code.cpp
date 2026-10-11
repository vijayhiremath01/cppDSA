#include <iostream>
using namespace std ; 

//learning about vector and struct in Cpp
struct Job {
    int id ;  
    string status ;
} ; 

int main(){

    vector<Job> jobs ; 

    jobs.push_back({1, "pending"});
    jobs.push_back({2, "in progress"});
    jobs.push_back({3, "completed"});

    for(const auto& job : jobs){
        cout << "Job ID: " << job.id << " , Status: " << job.status << endl ; 
    }
    return 0 ; 
    
}