#ifndef DRAGONGAME_TIMER_H
#define DRAGONGAME_TIMER_H

#include "SDL.h"

class Timer {
public:

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    Uint32 getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();
    static Timer* Instance()
    {
        if(s_pInstance == nullptr)
        {
            s_pInstance = new Timer();
            return s_pInstance;
        }
        return s_pInstance;
    }
private:
    static Timer* s_pInstance;
    Timer();
    //The clock time when the timer started
    Uint32 mStartTicks;
    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;
    Uint32 rem_time;
    //The timer status
    bool mPaused;
    bool mStarted;
};


#endif //DRAGONGAME_TIMER_H
