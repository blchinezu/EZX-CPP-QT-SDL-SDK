#ifndef UTIL_SKINFILE_H
#define UTIL_SKINFILE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//----------------------------------------------------------------------------
//                                                                        
//   Module Name: UTIL_SkinFile.h
//
//   General Description: Helper class for UTIL_SkinFileWriter and 
//                        UTIL_SkinFileReader
//
//----------------------------------------------------------------------------
//
//                     Motorola Confidential Proprietary
//          Template ID and version: IL93-TMP-01-0108  Version 1.10
//           (c) Copyright Motorola 2002-2003, All Rights Reserved
//   
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description
// -------------------------   ------------    ----------   ----------------
// Yingbo Hu / w4765c           07/06/2004                  created 
//
// Portability: should be portable to any compliant C++ compiler
//----------------------------------------------------------------------------
//                                INCLUDE FILES
//----------------------------------------------------------------------------

#include <qstring.h>

#include "UTIL_Res.h"

//----------------------------------------------------------------------------
//                             CLASS UTIL_SkinFile
//----------------------------------------------------------------------------

class UTIL_SkinFile {

    friend class UTIL_SkinFileReader;
    friend class UTIL_SkinFileWriter;

private:

    struct skinData
    {

        unsigned x;
        unsigned y;
        unsigned width;
        unsigned height;
    };

    struct hashTableEntry
    {
        unsigned hashedID;
        unsigned IDOffset;
        struct skinData data;
    }; 

    struct startBlock
    {
        unsigned check;                 // 0xABCDDCBA
        unsigned IDTableOffset;
        unsigned hashTableSize;
        unsigned hashTableOffset;
        unsigned dataOffset;
    };

    static const unsigned startBlockCheck;
    static const unsigned dataBlockCheck;
    static const char* headerText;
};

#endif // #ifndef UTIL_SKINFILE_H
