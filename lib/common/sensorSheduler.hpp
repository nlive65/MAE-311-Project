#pragma once

namespace common{
    class sensorScheduler{
        private:
        int state;
        public:
        sensorScheduler();
        ~sensorScheduler() = default;
        int getState(){return state;};
        void setState(int newState) {state=newState;};
        void runCalibration();
    };
}