#ifndef SJF_H
#define SJF_H
#include <queue>
#include <vector>
#include "process.h"

/// Comparador para la cola de prioridad:
/// Ordena primero por BurstTime restante, y en caso de empate por ArrivalTime y por ultimo, por la etiqueta.
struct SJFCompare {
    bool operator()(const Proceso* a, const Proceso* b) const {
        bool ans;
        if (a->getBurst() == b->getBurst()) {
            if(a->getArrival() == b->getArrival())
                ans = a->getPid() > b->getPid();
            else ans = a->getArrival() > b->getArrival();
        }
        else ans = a->getBurst() > b->getBurst();
        return ans;
    }
};

/// Implementación de Shortest Job First (SJF).
class SJF{
private:
    priority_queue< Proceso*, vector<Proceso*>, SJFCompare> ready;

public:
    SJF();
    //~SJF() ovesrride = default;
    void updWT();
    void addProcess(Proceso* proc);
    bool hasProcesos() const;
    Proceso* peek();
    const char* name() const { return "SJF"; }
};

#endif