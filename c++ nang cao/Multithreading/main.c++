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

using namespace std;

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

mutex mtx_sensor_outside, mtx_sensor_inside, mtx_cout, mtx_sensor_wind, mtx_key_input;
double sensor_outside;
double sensor_inside = 16;
int sensor_wind;
double temp_display = 20;
int wind_display;

Air_condition_status air_status = OFF;
Air_mode air_mode = AIR_MODE_OFF;
