#ifndef my_library.h
#define my_library.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Define a struct for the parameters of the NMEA Sentence
typedef struct{
    double latitude; //Latitude value
    double longitude; // Longitude value
    double altitude; // Altitude value
    double quality; //Fix quality value
    int NoOfSatt; // Number of satellites
    double horPos; // Horizontal dilution of position
    double HoG; // Height of Geoid
    char checkSum[3]; // Checksum string
    char time[11]; //Time string
} GpsData;
/**
 * Calculate the checksum of an NMEA sentence.
 * 
 * @param sentence The NMEA sentence string.
 * @return The calculated checksum.
 */
unsigned char nmea_checksum(const char *sentence);
/**
 * Parse the NMEA sentence and extract the GPS data.
 * @param nmea_seq The NMEA sentence string.
 * @param Gps_data Pointer to the GpsData struct to store the parsed data.
 * @return 0 if parsing is successful, -1 if an error occurred.
 */
int parse_data(const char* nmea_seq, GpsData *Gps_data);
#endif
