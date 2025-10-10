#include <bits/stdc++.h>
using namespace std;


// 2.1 Least Connection Method

// Logic:

// Assign requests to the server with the fewest active connections.

// Use case:

// Traffic varies, some requests are long-running.

class LeastConnectionLoadBalancer {
private:
    map<string, int> serverConnections;

public:
    void addServer(const string& serverName) { serverConnections[serverName] = 0; }

    string getServerWithLeastConnections() {
        int minConnections = numeric_limits<int>::max();
        string selectedServer;
        for (auto &entry : serverConnections) {
            if (entry.second < minConnections) {
                minConnections = entry.second;
                selectedServer = entry.first;
            }
        }
        serverConnections[selectedServer]++;
        return selectedServer;
    }
};

int main() {
    LeastConnectionLoadBalancer lb;
    lb.addServer("Server1");
    lb.addServer("Server2");
    lb.addServer("Server3");

    for (int i = 0; i < 10; i++)
        cout << "Request " << i+1 << " routed to " << lb.getServerWithLeastConnections() << endl;

    return 0;
}