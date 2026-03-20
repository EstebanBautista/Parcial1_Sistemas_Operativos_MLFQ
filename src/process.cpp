#include "../include/process.h"

// ---------- Constructor ----------
Proceso::Proceso(int pid_,
                 const std::string& label_,
                 int arrival_,
                 int burst_,
                 int initialQueue_,
                 int priority_)
    : pid(pid_),
      label(label_),
      arrival(arrival_),
      burst(burst_),
      remaining(burst_),
      initialQueue(initialQueue_),
      priority(priority_),
      ResponseTime(-1),
      CompletionTime(-1),
      waitingTime(0),
      TurnAroundTime(-1),
      state(Estado::NEW)
{}

// ---------- Getters ----------
int Proceso::getPid() const { return pid; }
const std::string& Proceso::getLabel() const { return label; }
int Proceso::getArrival() const { return arrival; }
int Proceso::getBurst() const { return burst; }
int Proceso::getRemaining() const { return remaining; }
int Proceso::getInitialQueue() const { return initialQueue; }
int Proceso::getPriority() const { return priority; }
int Proceso::getResponseTime() const { return ResponseTime; }
int Proceso::getCompletionTime() const { return CompletionTime; }
int Proceso::getWaitingTime() const { return waitingTime; }
int Proceso::getTurnAroundTime() const { return TurnAroundTime; }
Estado Proceso::getState() const { return state; }

// ---------- Setters ----------
void Proceso::setLabel(const std::string& l) { label = l; }
void Proceso::setArrival(int a) { arrival = a; }
void Proceso::setBurst(int b) { burst = b; }
void Proceso::setRemaining(int r) { remaining = r; }
void Proceso::setInitialQueue(int q) { initialQueue = q; }
void Proceso::setPriority(int p) { priority = p; }
void Proceso::setResponseTime(int t) { ResponseTime = t; }
void Proceso::setCompletionTime(int t) { CompletionTime = t; }
void Proceso::setWaitingTime(int t) { waitingTime = t; }
void Proceso::setTurnAroundTime(int t) { TurnAroundTime = t; }
void Proceso::setState(Estado s) { state = s; }

// ---------- Otros métodos ----------
void Proceso::run(int time) {
    remaining--;
    if(ResponseTime == -1)
        ResponseTime = time;
    if(remaining == 0){
        CompletionTime = time + 1;
        TurnAroundTime = CompletionTime - arrival;
        setState(Estado(4));
    }
}

void Proceso::incrementWT(){
    waitingTime++;
}

bool Proceso::isFinished() const {
    return state == Estado(4);
}
