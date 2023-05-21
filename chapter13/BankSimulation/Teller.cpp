#include "./CommonTypes.cpp"
#include <string>
class Teller {
private: 
    TellerStatus status; // status of teller. It can process the customer if it's available.
public:
    Teller();
    void process(EventType eventType, std::string events[]);
    /// @brief Gets the status of teller.
    /// @return Available or busy.
    TellerStatus getStatus() const;
    /// @brief Changes the status of teller;
    void setStatus(TellerStatus newStatus);
};

Teller::Teller():status(TellerStatus::Available) {

}

void Teller::process(EventType EventType, std::string events[]) {
    // do nothing
}

void Teller::setStatus(TellerStatus newStatus) {
    status = newStatus;
}

TellerStatus Teller::getStatus() const {
    return status;
}