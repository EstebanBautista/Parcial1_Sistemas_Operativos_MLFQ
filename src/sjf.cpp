#include "../include/SJF.h"

SJF :: SJF(){}

void SJF::addProcess(Proceso* proc) {
    ready.push(proc);
}

bool SJF::hasProcesos() const {
    return !ready.empty();
}

Proceso* SJF::peek(){
    Proceso* ac = ready.top();
    ready.pop();
    return ac;
}

void SJF::updWT(){
    queue< Proceso*> q;
    Proceso* p;
    while (!ready.empty()) {
        p = ready.top();
        ready.pop();
        p->incrementWT();
        q.push(p);
    }
    while(!q.empty()){
        p = q.front();
        q.pop();
        ready.push(p);
    }
}

