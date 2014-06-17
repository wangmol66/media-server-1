#ifndef MCU_ASSERTIONS_H
#define	MCU_ASSERTIONS_H


/**
 * If the macro ENABLE_MCU_ASSERTIONS is set (by calling the compiler with -DENABLE_MCU_ASSERTIONS
 * or by uncommenting the line below) then custom assertions will be performed.
 */
#define ENABLE_MCU_ASSERTIONS


#include "log.h"
#include <cstdlib>  // _Exit(), abort()
#include <cassert>  // assert()


#ifdef ENABLE_MCU_ASSERTIONS
#define MCU_CLOSE(fd)  \
	({ do {  \
		if (fd <= 2) {  \
			::Error("close(fd) called with fd == %d, aborting!\n", fd);  \
			assert(fd > 2);  \
			abort();  \
		}  \
	} while(0); close(fd); })
#else
#define MCU_CLOSE(fd)  close(fd)
#endif


#endif