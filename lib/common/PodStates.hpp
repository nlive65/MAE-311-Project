//All master level states of the SW

#pragma once
//Defines each state of the POD to an integer to make it more readable
namespace common{
 enum POD_STATES{
    INIT =0,//Initialization stage
    CALIB = 1,//Calibration (debug) stage
    ACQUISITION = 2//Data collection stage
 };   
}