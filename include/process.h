#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>
using namespace std;

/// Estado del proceso en la simulación
enum class Estado {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

/// Clase que representa un proceso de la simulación
class Proceso {
private:
    int pid;                // identificador interno
    std::string label;      // nombre/etiqueta del proceso
    int arrival;            // tiempo de llegada (AT)
    int burst;              // burst time original (BT)
    int remaining;          // tiempo restante por ejecutar
    int initialQueue;       // cola inicial indicada en archivo (Q)
    int priority;           // prioridad (P)
    int ResponseTime;          // primer instante de ejecución (para RT)
    int CompletionTime;         // tiempo de finalización (CT)
    int waitingTime;        // tiempo total de espera (WT)
    int TurnAroundTime;       // tiempo de respuesta (RT)
    Estado state;           // estado actual

public:
    /// Constructor

    Proceso(int pid,
            const std::string& label,
            int arrival,
            int burst,
            int initialQueue,
            int priority);

    // --- Getters ---
    int getPid() const;
    const std::string& getLabel() const;
    int getArrival() const;
    int getBurst() const;
    int getRemaining() const;
    int getInitialQueue() const;
    int getPriority() const;
    int getResponseTime() const;
    int getCompletionTime() const;
    int getWaitingTime() const;
    int getTurnAroundTime() const;
    Estado getState() const;

    // --- Setters ---
    void setLabel(const std::string& l);
    void setArrival(int a);
    void setBurst(int b);
    void setRemaining(int r);
    void setInitialQueue(int q);
    void setPriority(int p);
    void setResponseTime(int t);
    void setCompletionTime(int t);
    void setWaitingTime(int t);
    void setTurnAroundTime(int t);
    void setState(Estado s);

    /// Indica si el proceso ya terminó
    bool isFinished() const;

    void incrementWT();

    void run(int time);
};

#endif