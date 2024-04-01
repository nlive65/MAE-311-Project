#pragma once
#include <stdint.h>
#include "../common/voltageDivider.hpp"
namespace THERM{
    class THERMHandler :public common::voltageDivider{
        int r25 = 1050;
        public:
        THERMHandler(uint8_t pinNum, double vReference, int resistance, int frequency,int size) : common::voltageDivider(pinNum,vReference,resistance,r25,frequency,size){}
        double getReading() override;
        void initSensor(){common::voltageDivider::initSensor();};
        void calibrate() override{};
        void getChauvenetCriteria() override;
    };
}