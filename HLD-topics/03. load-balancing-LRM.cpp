#include <bits/stdc++.h>
using namespace std;


// 2.2 Least Response Time Method

// Logic:
// Assign requests to the server with the lowest response time.

// Use case:
// Optimize for faster responses in high-traffic apps.

class LeastResponseLoadBalancer {
private:
    map<string, long long> serverResponseTimes;

public:
    void addServer(const string& serverName) { serverResponseTimes[serverName] = 0; }

    string getServerWithLeastResponseTime() {
        long long minTime = numeric_limits<long long>::max();
        string selectedServer;
        for (auto &entry : serverResponseTimes) {
            if (entry.second < minTime) {
                minTime = entry.second;
                selectedServer = entry.first;
            }
        }
        serverResponseTimes[selectedServer]++;
        return selectedServer;
    }
};

int main() {
    LeastResponseLoadBalancer lb;
    lb.addServer("Server1");
    lb.addServer("Server2");
    lb.addServer("Server3");

    for (int i = 0; i < 10; i++)
        cout << "Request " << i+1 << " routed to " << lb.getServerWithLeastResponseTime() << endl;

    return 0;
}