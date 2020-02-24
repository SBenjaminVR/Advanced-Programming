//
//  main.c
//  First Hour of Code 
//
//  Created by Benjamin Valdez on 2/24/20.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

long generateRandom(long seed) {
    long int random;
    
    if (seed <= 0) {
        seed = seed *-1;
        seed = seed+11;
    }
    
    sleep(1);
    time_t seconds;
    seconds = time(NULL);

    random = seconds * seed;
    
    return random % 100;
};

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 10; i++) {
        printf("%ld\n", generateRandom(i));
    }
    
    
    return 0;
}
