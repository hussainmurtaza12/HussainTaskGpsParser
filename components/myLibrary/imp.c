#include"my_library.h"

unsigned char nmea_checksum(const char *sentence) 
{
    unsigned char checksum = 0;
    if (*sentence == '$') sentence++;
    while (*sentence && *sentence != '*') {
        checksum ^= *sentence++; // XOR each character of the sentence
    }
    return checksum;
}
int parse_data(const char* nmea_seq, GpsData *Gps_data)
{
    // First check for null sequence
    if (nmea_seq == NULL || Gps_data == NULL || nmea_seq[0] == '\0') {
        printf("Empty NMEA sentence.\n");
        return -1;
    }
    // Calculate the checksum and compare it with the checksum in the NMEA sentence
     unsigned char calculated_checksum = nmea_checksum(nmea_seq);
    char *star = strrchr(nmea_seq, '*');
    if (star == NULL || strlen(star) != 3 || strtol(star + 1, NULL, 16) != calculated_checksum) {
        printf("Invalid NMEA checksum.\n");
        return -1;
    }
    // Tokenize the NMEA sentence
    char *token = strtok(nmea_seq,",");
    int check=0;
  
    
  
    // In this while loop, we check the value of 'check' variable
    //According to that value, the consecutive switch statement is executed and thus each parameter of GpsData is updated
    while (token!=NULL)
    {
        switch(check){
            case 1:
            strncpy(Gps_data->time,token,sizeof(Gps_data->time));
            break;
            
            case 2:
            Gps_data->latitude = atof(token);
            break;
            
            case 3:
            if(token[0]=='S'||token[0]=='s') //If the parameter next to it is South, then latitude should be a negative value
            {
                Gps_data->latitude=(-1)*Gps_data->latitude;
            }
            break;
            
            case 4:
            Gps_data->longitude = atof(token);
            break;
            
            case 5:
            if(token[0]=='E'||token[0]=='e')
            {
                Gps_data->longitude=(-1)*Gps_data->longitude;
            }
            break;
            
            case 6:
            Gps_data->quality=atof(token); //the atof function is used for conversion from string to double
            break;
            
            case 7:
            Gps_data->NoOfSatt=atoi(token);
            break;
            
            case 8:
            Gps_data->horPos=atof(token);
            break;
            
            case 9:
            Gps_data->altitude=atof(token);
            break;
            
            case 11:
            Gps_data->HoG=atof(token);
            break;
            
            
        }
        token = strtok(NULL, ",");
        check++;
    }

    return 0;
}
