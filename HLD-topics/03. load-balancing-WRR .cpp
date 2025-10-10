// Servers have different capacities.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
// 1.2 Weighted Round Robin Load Balancing

// Logic:
// Each server has a weight.
// Servers with higher weights handle more requests.

// Use case:

class Server {
public:
    std::string name;
    int weight;
    Server(std::string name, int weight) : name(name), weight(weight) {}
};

class WeightedRoundRobinBalancer {
private:
    std::vector<Server> servers;
    std::vector<int> cumulativeWeights;
    int totalWeight;

public:
    WeightedRoundRobinBalancer(std::vector<Server> servers) {
        this->servers = servers;
        totalWeight = 0;
        cumulativeWeights.resize(servers.size());
        for (size_t i = 0; i < servers.size(); i++) {
            totalWeight += servers[i].weight;
            cumulativeWeights[i] = totalWeight;
        }
        srand(time(0));
    }

    Server getNextServer() {
        int randomValue = rand() % totalWeight;
        for (size_t i = 0; i < cumulativeWeights.size(); i++) {
            if (randomValue < cumulativeWeights[i]) return servers[i];
        }
        return servers[0]; // fallback
    }
};

int main() {
    std::vector<Server> serverList = {
        Server("Server1", 3),
        Server("Server2", 2),
        Server("Server3", 1)
    };

    WeightedRoundRobinBalancer balancer(serverList);

    for (int i = 0; i < 10; i++) {
        Server s = balancer.getNextServer();
        std::cout << "Request " << (i + 1) << " routed to " << s.name << std::endl;
    }
    return 0;
}
