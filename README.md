
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
