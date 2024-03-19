//Interface for calibration to be inherited by each measurable component
#pragma once
#include <vector>
namespace common{
    template <typename Collected_Data>
    class calibrationHandler{
        private:
            //Shouldn't have any of these since this is an interface that is realized by every sensor
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
        bool isCalibrated;
        virtual void initSensor(){};
        //Make sure this works
        virtual void calibrate(){};
        virtual Collected_Data getReading(){
            Collected_Data data;
            return(data);
        };
        Collected_Data average;
        Collected_Data lowerDeviation;
        Collected_Data upperDeviation;
        virtual void getChauvenetCriteria(){};
        
    };
}