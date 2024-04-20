//Interface for calibration to be inherited by each measurable component
#pragma once
#include <vector>
namespace common{
    template <typename Collected_Data>
    class calibrationHandler{
        private:
    
        public:
        std::vector<Collected_Data> basis_data;
        int calibrationDataSize;
        unsigned long previousMillis = 0;
        double frequency;
        calibrationHandler<Collected_Data>(double freq,int calibSize){
            frequency = freq;
            calibrationDataSize = calibSize;
        };
        ~calibrationHandler() = default;
        virtual void initSensor(){};
        virtual Collected_Data getReading(){
            Collected_Data data;
            return(data);
        };
        bool isCalibrated;
        virtual void calibrate(){};
        
        Collected_Data average;
        Collected_Data lowerDeviation;
        Collected_Data upperDeviation;        
    };
}