/***************************************************************************
* PALM++/palm library
*
* palm/os.h
*
* $Id$
*
* Copyright (C) 1994-2003 by Matthias Troyer <troyer@itp.phys.ethz.ch>,
*                            Synge Todo <wistaria@comp-phys.org>,
*
* Permission is hereby granted, free of charge, to any person or organization 
* obtaining a copy of the software covered by this license (the "Software") 
* to use, reproduce, display, distribute, execute, and transmit the Software, 
* and to prepare derivative works of the Software, and to permit others
* to do so for non-commerical academic use, all subject to the following:
*
* The copyright notice in the Software and this entire statement, including 
* the above license grant, this restriction and the following disclaimer, 
* must be included in all copies of the Software, in whole or in part, and 
* all derivative works of the Software, unless such copies or derivative 
* works are solely in the form of machine-executable object code generated by 
* a source language processor.

* In any scientific publication based in part or wholly on the Software, the
* use of the Software has to be acknowledged and the publications quoted
* on the web page http://www.alps.org/license/ have to be referenced.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT 
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, 
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
* DEALINGS IN THE SOFTWARE.
*
**************************************************************************/

#ifndef PALM_OS_H
#define PALM_OS_H

//=======================================================================
// This file includes low level functions which depend on the OS used
//=======================================================================

#include <alps/config.h>
#include <string>

namespace alps {

/// set the string to contain the name of the host
std::string hostname();

/** the clock in seconds.
    A fast system call to obtain a clock. Depending on the
    system this can be either wallclock time or CPU time. 
    The rationale for this function is that on some MPP systems the
    clock() function is synchronized over all nodes, making it
    a very resource intensive call. The function also
    handles overflows of the clock, as long as it is
    called at least once during the period of the clock. */
double dclock();

/// the resolution of the dclock() function
double dclock_resolution();

} // end namespace

#endif // PALM_OS_H
