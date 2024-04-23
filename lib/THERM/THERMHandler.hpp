#pragma once
#include <stdint.h>
#include "../common/voltageDivider.hpp"
namespace THERM{
    class THERMHandler :public common::voltageDivider{
        int r25 = 1050;//Resistance at 25 degrees celcius
        double prob = 1;//Unused
        public:
        //Uses the base constructor 
        THERMHandler(uint8_t pinNum, double vReference, int resistance, int frequency,int size) : common::voltageDivider(pinNum,vReference,resistance,r25,frequency,size){}
        //Definition of operation to get the temperature
        double getReading() override;
        //Uses the parent initSensor function
        void initSensor(){common::voltageDivider::initSensor();};

        //Unused
        void calibrate() override{};
        int distance(double reading);
        //double getDeviations(double reading);
        //void getChauvenetCriteria() override;
    };
}