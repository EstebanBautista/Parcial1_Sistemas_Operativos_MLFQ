#ifndef RR_H
#define RR_H
#include <queue>
#include <list>
#include "process.h"

using namespace std;

/// Implementación de Round Robin como hijo de Scheduler.
class RR{
private:
    int quantum;  ///< Quantum de RR
    list<Proceso*> ready; ///< cola de listos
    list<Proceso*>::iterator current;

public:
    RR(){};
    RR(int q);

    void addProcess(Proceso* proc);
    bool hasProcesos() const;
    Proceso* peek() const;
    void deleteProcess();
    void increaseIT();
    /// Devuelve el quantum configurado.
    int getQuantum() const;

    void updWT( int pid);
};

#endif