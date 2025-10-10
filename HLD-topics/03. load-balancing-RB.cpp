#include <bits/stdc++.h>
using namespace std;

// 2.3 Resource-Based Load Balancing

// Logic:
// Assign requests based on real-time resources (CPU, memory, bandwidth).
// Choose the server with the most available resources.

// Use case:
// CPU/memory-intensive applications.

class Server {
public:
    string name;
    double cpuLoad;
    Server(string name) : name(name), cpuLoad(0.0) {}
    void updateCpuLoad(double load) { cpuLoad = load; }
};

class ResourceBasedLoadBalancer {
private:
    map<string, Server> servers;

public:
    void addServer(Server s) { servers[s.name] = s; }

    Server getServerWithMostResources() {
        Server bestServer("");
        double lowestLoad = numeric_limits<double>::max();
        for (auto &pair : servers) {
            if (pair.second.cpuLoad < lowestLoad) {
                lowestLoad = pair.second.cpuLoad;
                bestServer = pair.second;
            }
        }
        return bestServer;
    }

    void handleRequest() {
        Server s = getServerWithMostResources();
        cout << "Routing request to server: " << s.name << " with CPU load: " << s.cpuLoad << "%\n";
    }
};

int main() {
    ResourceBasedLoadBalancer lb;
    Server s1("Server1"), s2("Server2"), s3("Server3");

    s1.updateCpuLoad(30.0);
    s2.updateCpuLoad(50.0);
    s3.updateCpuLoad(20.0);

    lb.addServer(s1);
    lb.addServer(s2);
    lb.addServer(s3);

    lb.handleRequest(); // Should route to Server3
    return 0;
}