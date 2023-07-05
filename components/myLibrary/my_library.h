#ifndef my_library.h
#define my_library.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Define a struct for the parameters of the NMEA Sentence
typedef struct{
    double latitude;
    double longitude;
    double altitude;
    double quality;
    int NoOfSatt; // Number of satellites
    double horPos; // Horizontal dilution of position
    double HoG; // Height of Geoid
    char checkSum[3]; // Checksum string
    char time[11];
} GpsData;
unsigned char nmea_checksum(const char *sentence);
int parse_data(const char* nmea_seq, GpsData *Gps_data);
#endif