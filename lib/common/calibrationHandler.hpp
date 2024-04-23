//Interface for calibration to be inherited by each measurable component
#pragma once
#include <vector>
namespace common{
    template <typename Collected_Data>//General type for any kind of implementation
    class calibrationHandler{
        private:
        public:
        //vector to be the calibration sensor data
        std::vector<Collected_Data> basis_data;
        //Integer for how large the calibration set should be 
        int calibrationDataSize;
        //Time for when the sensor was last pulled
        unsigned long previousMillis = 0;
        //Frequency in hertz for how often a sensor should be pulled
        double frequency;
        //Constructor takes the size and frequency and assigns it to the respective members
        calibrationHandler<Collected_Data>(double freq,int calibSize){
            frequency = freq;
            calibrationDataSize = calibSize;
        };
        //Default destructor
        ~calibrationHandler() = default;
        //Function definition for initializing the hardware interface
        virtual void initSensor(){};
        //Function definition for getting the current reading of a sensor
        virtual Collected_Data getReading(){
            Collected_Data data;
            return(data);
        };
        //Unused Currently
        bool isCalibrated;
        virtual void calibrate(){};
        
        Collected_Data average;
        Collected_Data lowerDeviation;
        Collected_Data upperDeviation;        
    };
}