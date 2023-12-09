#include <stdio.h>
#include <stdarg.h>
#include<string.h>


typedef enum {
    LIGHT,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER
} DeviceType;

typedef enum {
    ON,
    OFF,
    SET_TEMPERATURE,
    SET_MODE,
    UNLOCK,
    LOCK,
    INCREASE_VOLUME,
    DECREASE_VOLUME,
    CHANGE_TRACK
} CommandType;

int controlDevice(DeviceType type, ...) {
    va_list args;
    va_start(args, type);

    switch (type) {
// case den
    case LIGHT: {
        switch (va_arg(args, CommandType)) {
        case ON: {
            printf("Light turned ON\n");
            break;
        }
            
        case OFF: {
            printf("Light turned OFF\n");
            break;
        }

        default:
            break;
        }
    }
      
// case dieu hoa
    case AIR_CONDITIONER: {
        switch (va_arg(args, CommandType)) {
        case ON: {
            printf("Air Conditioner turned ON\n");
            break;
        }
            

        case OFF: {
            printf("Air Conditioner turned OFF\n");
            break;
        }
        

        case SET_TEMPERATURE: {
            printf("Air Conditioner temperature set to %d degrees\n", va_arg(args, int));
            break;
        }
            

        case SET_MODE: {
            int m = va_arg(args, int);
            switch (m) {
            case 1: {
                printf("Air Conditioner set to cooler mode \n");
                break;
            }

            case 2: {
                printf("Air Conditioner set to fan mode\n");
                break;
            }

            default:
                break;
            }
        }
        default:
            break;
        }
    }
 
      
//case khoa van tay
    case FINGERPRINT_LOCK: {
        switch (va_arg(args, CommandType)) {
        case ON: {
            printf("open Lock \n");
            break;
        }

        case OFF: {
            printf("Locked\n");
            break;
        }

        default:
            break;
        }
    }

//case may phat nhac
    case MUSIC_PLAYER: {
            switch (va_arg(args, CommandType)) {
            case INCREASE_VOLUME: {
                printf("Increase volume to %d\n", va_arg(args, int));
                break;
            }

            case DECREASE_VOLUME:{
                printf("Decrease volume to %d\n", va_arg(args, int));
                break;
            }

            case CHANGE_TRACK: {
                printf("Change track\n");
                break;
            }

            default:
                break;
            }
        }
    default:
        break;
    }

    va_end(args);
    return(0);
}

int main() {
    controlDevice(LIGHT, ON);
    controlDevice(MUSIC_PLAYER, INCREASE_VOLUME,45);
    controlDevice(AIR_CONDITIONER, SET_MODE,2);


	return(0);
}