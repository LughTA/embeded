#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "thread.hpp"

using namespace std;



int main()
{
    Air_condition_status air_status = OFF;
    Air_mode air_mode = AIR_MODE_OFF;

    thread thread_input_key(inputKey);
    thread thread_sensor_outside(display_sensor_outside);
    thread thread_sensor_inside(display_sensor_inside);
    thread thread_fan(display_fan);
    thread thread_air_condition(display_air_condition);
    thread thread_display(display);

    cout << "-------------BUTTON------------------" << endl;
    cout << "1. Increase temperature " << endl;
    cout << "2. Decrease temperature " << endl;
    cout << "3. Increase wind level " << endl;
    cout << "4. Decrease wind level " << endl;
    cout << "5. Turn on air mode " << endl;
    cout << "6. Turn off air mode " << endl;

    while (1)
    {
        mtx_key_input.lock();
        mtx_sensor_outside.lock();
        mtx_sensor_inside.lock();
        if (air_mode == AIR_MODE_ON)
        {
            if (temp_display * 2 - (sensor_inside + sensor_outside) > 1)
            {
                sensor_inside = (sensor_inside + sensor_outside) / 2;
                air_status = INCREASE;
            }
            else if (temp_display * 2 - (sensor_inside + sensor_outside) < -1)
            {
                sensor_inside = (sensor_inside + sensor_outside) / 2;
                air_status = DECREASE;
            }
            else
            {
                air_status = OFF;
            }
        }
        else if (air_mode == AIR_MODE_OFF)
        {
            if (temp_display - sensor_inside > 1)
            {
                air_status = INCREASE;
            }
            else if (temp_display - sensor_inside < -1)
            {
                air_status = DECREASE;
            }
            else
            {
                air_status = OFF;
            }
        }

        mtx_key_input.unlock();
        mtx_sensor_outside.unlock();
        mtx_sensor_inside.unlock();

    }

    thread_input_key.join();
    thread_display.join();
    thread_air_condition.join();
    thread_fan.join();
    thread_sensor_inside.join();
    thread_sensor_outside.join();

    return 0;
}