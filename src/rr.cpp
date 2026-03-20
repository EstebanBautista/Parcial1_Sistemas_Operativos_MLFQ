#include "../include/rr.h"

RR::RR(int q) : quantum(q){
    current = ready.begin();
}

void RR::addProcess(Proceso* proc) {
    proc->setState(Estado::READY);
    ready.push_back(proc);
    if( ready.size() == 1 || current == ready.end())
        current = ready.begin();
}

bool RR::hasProcesos() const {
    bool prue = !ready.empty();
    return !ready.empty();

}

Proceso* RR::peek() const{
    Proceso* p = *current;
    return p;   
}

void RR::increaseIT(){
    current++;
    if(current == ready.end())
        current = ready.begin();
}

void RR::deleteProcess(){
    current = ready.erase(current);
    if(current == ready.end())
        current = ready.begin();
}

void RR::updWT(int pid){
    for (list<Proceso*>::iterator it = ready.begin(); it != ready.end(); ++it) {
        if ((*it)-> getPid() != pid){
            (*it)->incrementWT();
        }
    }
    
}

int RR::getQuantum() const { return quantum; }