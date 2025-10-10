#include <bits/stdc++.h>
using namespace std;


// 1.3 Source IP Hash Load Balancing

// Logic:
// Hash the source IP to consistently route the same client to the same server.

// Use case:
// Session persistence is required.
class SourceIpHashLoadBalancer {
private:
    vector<string> servers;

public:
    void addServer(const string& serverName) {
        servers.push_back(serverName);
    }

    string getServerForIp(const string& sourceIp) {
        if (servers.empty()) {
            throw runtime_error("No servers available");
        }
        hash<string> hashFn;
        size_t hashValue = hashFn(sourceIp);
        size_t serverIndex = hashValue % servers.size();
        return servers[serverIndex];
    }
};

int main() {
    SourceIpHashLoadBalancer lb;
    lb.addServer("Server1");
    lb.addServer("Server2");
    lb.addServer("Server3");

    vector<string> sourceIps = {"192.168.1.1", "10.0.0.1", "172.16.0.1"};
    for (auto ip : sourceIps) {
        cout << "Request from " << ip << " routed to " << lb.getServerForIp(ip) << endl;
    }
    return 0;
}
