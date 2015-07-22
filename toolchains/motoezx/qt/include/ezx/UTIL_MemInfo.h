#ifndef UTIL_MEMINFO_H
#define UTIL_MEMINFO_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//---------------------------------------------------------------------------
//                                                                    
//   Header Name: UTIL_MemInfo.h
//
//   General Description: C++ interface to the /proc/meminfo system memory
//                        statistics
//
//---------------------------------------------------------------------------
//
//                   Motorola Confidential Proprietary
//        Template ID and version: IL93-TMP-01-0107  Version 1.10
//         (c) Copyright Motorola 2002-2003, All Rights Reserved
//   
//
// Revision History:
//                             Modification     Tracking
//---------------------------------------------------------------------------
// Author (core ID)                Date          Number     Changes
// Peter McDermott/w20027       05/20/2003     LIBdd04622   created
//
//---------------------------------------------------------------------------
//                              INCLUDE FILES
//---------------------------------------------------------------------------

class UTIL_MemInfo
{
public:

    // constructor

    UTIL_MemInfo(); 

    // refresh memory statistics
    
    void refresh();

    // get memory statistics
    //
    // Note: these values are accurate as of the first time any of the below
    // functions are called.  They are not initialized when the constructor
    // is called!
    //
    // If you would like to refresh the statistics, call refresh();
    //
    
    long memTotal() const;         // RAM available for apps
    long memFree() const;          // RAM not allocated
    long memShared() const;        // RAM shared between apps
    long buffers() const;
    long cached() const;           // RAM used by cached filesystem pages
    long swapCached() const;
    long active() const;           // RAM allocated by apps
    long inactDirty() const;
    long inactClean() const;
    long inactTarget() const;
    long highTotal() const;
    long highFree() const;
    long lowTotal() const; 
    long lowFree() const;          
    long swapTotal() const;
    long swapFree() const;
    long nrSwapPages() const;
  
    // 
    // mallocable()
    //
    // mallocable = memFree() + cached()
    //
    // This is the amount of RAM that can be allocaed by your application.
    //
    // If you allocate all of this memory, then:
    //
    //      1. Other applications can't allocate any memeory
    //      2. Other applications can't grow their stack
    //      3. Your application can't allocate any memory
    //      4. Your application can't grow its stack
    //      5. The system will almost certainly crash.
    //
    // So be smart!  Only allocate a max of some percentage of the number
    // returned by mallocable()
    //

    long mallocable() const;       // RAM that can be allocated   
    
    // 
    // debug methods to print memory stats to STDOUT
    //

    void print() const;
    static void printCurrent();

private:

    void doRefresh() const;
    void init() const; 

    mutable bool isInitialized;

    mutable long m_memTotal;
    mutable long m_memFree;
    mutable long m_memShared;
    mutable long m_buffers;
    mutable long m_cached;
    mutable long m_swapCached;
    mutable long m_active;
    mutable long m_inactDirty;
    mutable long m_inactClean;
    mutable long m_inactTarget;
    mutable long m_highTotal;
    mutable long m_highFree;
    mutable long m_lowTotal;
    mutable long m_lowFree;
    mutable long m_swapTotal;
    mutable long m_swapFree;
    mutable long m_nrSwapPages;
   
};

#endif // #ifndef UTIL_MEMINFO_H
