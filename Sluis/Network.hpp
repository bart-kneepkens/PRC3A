#ifndef SLUIS_NETWORK_HPP
#define SLUIS_NETWORK_HPP

#include <string>

class Network {
private:
    int port;
public:
    Network();
    ~Network();

    void SendData(std::string data);
    void OnDataReceived(std::string data);
};

#endif  // SLUIS_NETWORK_HPP