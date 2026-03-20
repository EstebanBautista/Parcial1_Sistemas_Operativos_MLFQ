#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <vector>
#include "process.h"
#include "mlfq.h"

class Simulador{
    private:
    int time;
    int pr;
    int terminados;
    int numProcesos;
    vector<double> Promedios;
    MLFQ colas;
    vector<Proceso*> order;
    vector<Proceso*> procesos;
    
    public: 
    Simulador(vector<Proceso*> order, vector<Proceso*> procesos);

    void printReport();

    void calculatePromedios();

    void printPromedios();

    void run();

    void check();
};

#endif