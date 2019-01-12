/*
* Library : https://github.com/bmegli/wifi-scan
* To use it you need :
* apt-get install build-essential 
* apt-get install libmnl0 libmnl-dev
* apt-get install linux-headers-$(uname -r)
*/

#include "wifi_scan.h"
#include <stdio.h>
#include <unistd.h>

#define AMPLIFIER 120 // To round the value around 100

void help(char **argv);
int finalize(int);

int main(int argc, char **argv)
{
    // This'll store all the wifi scan library
	struct wifi_scan *wifi=NULL;
    // this is where we are going to keep information about AP (Access Point) we are connected to
	struct station_info hotspot;
	int status;

    // If not enough args print the help and return
	if(argc != 2)
	{
		help(argv);
		return 0;
	}

    // Initialize the library with network interface in argv[1] (e.g. wlo1)
	wifi=wifi_scan_init(argv[1]);

        // Get information from the hotspot we are associated with
		status=wifi_scan_station(wifi, &hotspot);

		if(status==0)
			printf("Not connected to any hotspot\n");
		else if(status==-1)
			perror("Network card or OS is not compatible\n");
		else
			printf("%d\n", finalize(hotspot.signal_dbm));


	// Free the memory resources
	wifi_scan_close(wifi);

	return 0;
}

void help(char **argv)
{
	printf("Usage:\n");
	printf("%s wireless_interface\n\n", argv[0]);
	printf("Examples: (you can get your interface w/ ifconfig)\n");
	printf("%s wlo1\n", argv[0]);
}

// Signal range from experimentation
// -75 => 0
// -20 => 100
int finalize(int signaldbm) {
    int strength;
    // Rounding the signal
    if (signaldbm > -20)
        strength = 100;
    else if (signaldbm < -80)
        strength = 0;
    else
        strength = signaldbm + AMPLIFIER;

    return strength;
}