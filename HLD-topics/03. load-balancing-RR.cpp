#include <bits/stdc++.h>
using namespace std;

// 1.1 Round Robin Load Balancing

// Logic:
// Requests are assigned sequentially to servers in a circular manner.
// Simple, fair distribution but ignores server capacity.

// Use case:
// All servers have similar capacity and performance.
class RoundRobinLoadBalancer {
private:
    vector<string> servers;
    int currentIndex;

public:
    RoundRobinLoadBalancer(const vector<string>& servers) {
        this->servers = servers;
        currentIndex = 0;
    }

    string getNextServer() {
        if (servers.empty()) {
            throw runtime_error("No servers available");
        }
        string server = servers[currentIndex];
        currentIndex = (currentIndex + 1) % servers.size();
        return server;
    }
};
int main()
{
    vector<string> servers = {"Server1", "Server2", "Server3"};
    RoundRobinLoadBalancer lb(servers);

    for (int i = 0; i < 10; ++i) {
        cout << "Request " << i + 1 << " assigned to " << lb.getNextServer() << endl;
    }
    return 0;
}