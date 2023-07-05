//This code was compiled for Esp-IDF v5.0.2 using VS Code
#include<stdio.h>
#include "my_library.h" //the library containing struct and function implementation

void app_main(void)
{
    char nmea_sentence[] = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
    GpsData gps_data; // Declare an instance of the GpsData struct to store parsed GPS data
// Parse the NMEA sentence and store the parsed data in the gps_data struct
    if (parse_data(nmea_sentence, &gps_data) == 0) {
        printf("Time: %s, Latitude: %.4f, Longitude: %.4f, Altitude: %.1f\n, Fix Quality: %.1f,Number of Satellites: %d, Dilution: %.1f, Height: %.1f",
               gps_data.time, gps_data.latitude, gps_data.longitude, gps_data.altitude, gps_data.quality, gps_data.NoOfSatt,gps_data.horPos, gps_data.HoG);
    } else {
        printf("Failed to parse NMEA sentence.\n");
    }
}
