#include "../include/MLFQ.h"

MLFQ :: MLFQ(){
    rr1 = new RR(1);
    rr2 = new RR(3);
    rr3 = new RR(4);
    ac = NULL;
    wich = 1;
    sjf = new SJF();
    var = 0;
    quan = 1;
}

MLFQ::~MLFQ(){
    delete rr1;
    delete rr2;
    delete rr3;
    delete sjf;
}

void MLFQ::addProcess(Proceso* p){
    rr1->addProcess(p);
}

int MLFQ::run(int time) {
    int ans = 0;
    if (ac == NULL) {
        escogerCola();
        if (wich == 1) {
            ac = rr1->peek();
            quan = rr1->getQuantum();
        } else if (wich == 2) {
            ac = rr2->peek();
            quan = rr2->getQuantum();
        } else if (wich == 3) {
            ac = rr3->peek();
            quan = rr3->getQuantum();
        } else {
            ac = sjf->peek();
            quan = ac->getRemaining();
        }
        var = 0;
    }

    ac->run(time);
    rr1->updWT(ac->getPid());
    rr2->updWT(ac->getPid());
    rr3->updWT(ac->getPid());
    sjf->updWT();

    var++;

    if (ac->isFinished()) {
        ans = 1;
        if (wich == 1) rr1->deleteProcess();
        else if (wich == 2) rr2->deleteProcess();
        else if (wich == 3) rr3->deleteProcess();
        // si es wich == 4 (SJF) no hace falta moverlo
        ac = NULL;
    } else if (var == quan) {
        next();
        var = 0;
        if (wich == 1) rr1->deleteProcess();
        else if (wich == 2) rr2->deleteProcess();
        else if (wich == 3) rr3->deleteProcess();
        ac = NULL;
    }
    return ans;
}


void MLFQ::escogerCola(){
    if(rr1->hasProcesos())
        wich = 1;
    else if(rr2->hasProcesos())
        wich = 2;
    else if(rr3->hasProcesos())
        wich = 3;
    else wich = 4;
}

void MLFQ::next(){
    if(wich == 1)
        rr2->addProcess(ac);
    else if(wich == 2)
        rr3->addProcess(ac);
    else if(wich == 3)
        sjf->addProcess(ac);
}