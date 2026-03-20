#ifndef MLFQ_H
#define MLFQ_H
#include "rr.h"
#include "sjf.h"
#include "process.h"

class MLFQ{
    private:
    RR* rr1;
    RR* rr2;
    RR* rr3;
    int var;
    Proceso* ac;
    int wich;
    SJF* sjf;
    int quan;

    public:
    MLFQ();
    ~MLFQ();
    void addProcess(Proceso*);
    int run(int time);
    void next();
    void escogerCola(); 
};

#endif