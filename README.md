# GPS Data Parser

This project demonstrates a simple GPS data parser implemented in C language. The parser is designed to extract information from NMEA sentences, a common format for GPS data. The parsed data includes time, latitude, longitude, altitude, fix quality, number of satellites, horizontal dilution of position, and height of geoid.


## Prerequisites
Before using the GPS data parser, ensure that you have the following:

- ESP-IDF v5.0 or later
- C compiler (e.g., GCC)
- Standard C library
- `stdio.h`, `stdlib.h`, and `string.h` header files
## Usage
Follow the steps below to use the GPS data parser in your ESP-IDF project:

1. Create a new component in your ESP-IDF project for the GPS data parser. You can name it `myLibrary` or any other suitable name.

2. Copy the following files into the component's directory:
   - `components/myLibrary/imp.c`
   - `components/myLibrary/my_library.h`

3. Include the `my_library.h` header file in your source file.
4. Call the `parse_data` function, passing an NMEA sentence and a `GpsData` structure as arguments.

   ```c
   #include "my_library.h"

   const char nmea_sentence[] = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
   GpsData gps_data;

   if (parse_data(nmea_sentence, &gps_data) == 0) {
       // Use the parsed GPS data as needed
   } else {
       printf("Failed to parse NMEA sentence.\n");
   }
5. Access the individual fields of the GpsData structure to retrieve the parsed GPS data.

6. Build and run your ESP-IDF project, ensuring that the necessary dependencies and libraries are properly linked.
## File Structure
The project consists of the following files:

main/main.c: Contains the example usage of the GPS data parser.

components/myLibrary/imp.c: Implements the GPS data parsing functions.

components/myLibrary/my_library.h: Defines the GpsData structure and function prototypes.
## Explanation
The code provided is a GPS data parser implemented in C using the ESP-IDF framework. It parses NMEA sentences, which are standard sentences used by GPS receivers to transmit essential positioning and timing data.

The code is organized into three files: main.c, imp.c, and my_library.h.


## main.c
The main.c file contains the entry point of the program (app_main function) and demonstrates the usage of the GPS data parser. Here's a breakdown of the code:

1-Include the necessary header files

2-Define the main function app_main

3-Declare an NMEA sentence and a GpsData structure:

`char nmea_sentence[] = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
GpsData gps_data;`

4- Call the parse_data function to parse the NMEA sentence and populate the GpsData structure:

`if (parse_data(nmea_sentence, &gps_data) == 0) {
    // Print the parsed GPS data
    printf("Time: %s, Latitude: %.4f, Longitude: %.4f, Altitude: %.1f\n, Fix Quality: %.1f, Number of Satellites: %d, Dilution: %.1f, Height: %.1f",
           gps_data.time, gps_data.latitude, gps_data.longitude, gps_data.altitude, gps_data.quality, gps_data.NoOfSatt, gps_data.horPos, gps_data.HoG);
} else {
    printf("Failed to parse NMEA sentence.\n");
}
`


## imp.c
The imp.c file contains additional functions required by the GPS data parser.

nmea_checksum function:

This function calculates the checksum of an NMEA sentence.
It takes a pointer to the NMEA sentence as input and returns the calculated checksum as an unsigned char.

parse_data function:

This function parses the NMEA sentence and populates the GpsData structure with the extracted data.
It takes the NMEA sentence as input (nmea_seq) and a pointer to the GpsData structure (Gps_data).
The function returns 0 on successful parsing and -1 if there was an error.
Here's a breakdown of the parse_data function:

First, the function checks for a null sequence or empty NMEA sentence.
It then calculates the checksum of the NMEA sentence using the nmea_checksum function and verifies it against the checksum provided in the sentence.
The NMEA sentence is tokenized using the strtok function to extract the individual data parameters.
The tokenized parameters are assigned to their respective fields in the GpsData structure based on their position (check variable).
The latitude and longitude values are adjusted based on the direction indicators 'N', 'S', 'E', or 'W'.
Finally, the function returns 0 to indicate successful parsing.
## my_library.h
The my_library.h file defines the GpsData structure and declares the function prototypes for the GPS data parser. Here's an explanation of the structure and function declarations:

GpsData structure:

This structure represents the parsed GPS data.
It contains the following fields:
char time[10]: Holds the time in the format "hh:mm:ss".
float latitude: Represents the latitude value.
float longitude: Represents the longitude value.
float altitude: Represents the altitude value.
float quality: Represents the fix quality.
int NoOfSatt: Stores the number of satellites used in the fix.
float horPos: Represents the horizontal position.
float HoG: Represents the height of geoid above WGS84 ellipsoid.

parse_data function declaration:

This function parses the NMEA sentence and populates the GpsData structure.
It takes the NMEA sentence and a pointer to the GpsData structure as input.
The function returns 0 on successful parsing and -1 if there was an error.

nmea_checksum function declaration:

This function calculates the checksum of an NMEA sentence.
It takes a pointer to the NMEA sentence as input and returns the calculated checksum as an unsigned char.
