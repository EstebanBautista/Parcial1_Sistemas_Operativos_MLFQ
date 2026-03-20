#include "../include/simulador.h" 

Simulador:: Simulador(vector<Proceso*> ord, vector<Proceso*> prcs)
    :order(ord),
    time(0),
    pr(0),
    numProcesos(ord.size()),
    terminados(0),
    procesos(prcs)
{
    for(int i = 0; i < 4; i++){
        Promedios.push_back(0);
    }
}

void Simulador:: check(){
    while (pr < numProcesos && time == order[pr]->getArrival()) {
        colas.addProcess(order[pr]);
        pr++;
    }
}

void Simulador::printReport() {
    cout << "P\tAT\tBT\tQ\tCT\tTAT\tWT\tRT\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < numProcesos; i++) {
        cout << procesos[i]->getLabel()   << "\t"
             << procesos[i]->getArrival()  << "\t"
             << procesos[i]->getBurst()  << "\t"
             << procesos[i]->getInitialQueue()  << "\t"
             << procesos[i]->getCompletionTime()  << "\t"
             << procesos[i]->getTurnAroundTime() << "\t"
             << procesos[i]->getWaitingTime()  << "\t"
             << procesos[i]->getResponseTime()  << "\n";
    }
}

void Simulador:: calculatePromedios(){
    for (int i = 0; i < numProcesos; i++) {
        Promedios[0] += procesos[i]->getCompletionTime();
        Promedios[1] += procesos[i]->getTurnAroundTime();
        Promedios[2] += procesos[i]->getWaitingTime();
        Promedios[3] += procesos[i]->getResponseTime();
    }
      for (int i = 0; i < 4; i++) {
        Promedios[i] /= numProcesos;
    }
}

void Simulador:: printPromedios(){
    cout<<"-----PROMEDIOS----- "<<endl;
    cout << "Completion Time: "<< Promedios[0]<<endl;
    cout << "Turn Around Time: "<< Promedios[1]<<endl;
    cout << "Waiting Time: "<< Promedios[2]<<endl;
    cout << "Response Time: "<< Promedios[3]<<endl;
}


void Simulador:: run(){
    while(terminados < numProcesos){
        check();
        terminados += colas.run(time);
        time++;
    }

}