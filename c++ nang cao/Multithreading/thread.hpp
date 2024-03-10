#ifndef _THREAD_HPP_
#define _THREAD_HPP_

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>

#define INCREASE_TEMP 1
#define DECREASE_TEMP 2
#define INCREASE_WIND 3
#define DECREASE_WIND 4
#define TURN_ON_AIR  5
#define TURN_OFF_AIR 6

extern mutex mtx_sensor_outside, mtx_sensor_inside, mtx_cout, mtx_sensor_wind, mtx_key_input;
extern double sensor_outside ;
extern double sensor_inside  ;
extern int sensor_wind ;
extern double temp_display;
extern int wind_display;
extern Air_condition_status air_status;
extern Air_mode air_mode;

typedef enum
{
    INCREASE,
    DECREASE,
    OFF
} Air_condition_status;

typedef enum
{
    AIR_MODE_ON,
    AIR_MODE_OFF
} Air_mode;

double generateRandomTemperature();

double getTemperatureInside();

void display_sensor_outside();

void display_sensor_inside();

void display_air_condition();

void display();

void display_fan();

void inputKey();

#endif  _THREAD_HPP_