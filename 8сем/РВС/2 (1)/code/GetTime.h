#ifndef GETTIME_H
#define GETTIME_H

double getTime(clock_t start, clock_t end){
	double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
	return seconds;
}

#endif GETTIME_H