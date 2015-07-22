
//------------------------------------------------------------------------
//
// Header Name: ZGlobal.h
//
// General Description: EZX Global defines
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_GLOBAL_H
#define Z_GLOBAL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

/**
 * ZGlobal is the only header file of all global declarations and definitions for EzX.
 *
 * All global definitions in the ZGlobal namespace.
 *
 * This header inlcudes other header files, which consist of global definitions 
 * (@see ZDef), layout methods and definitions (@see ZLayout), hardkey related Macros 
 * (@see ZHKey), methods to inactivate with input widgets (@see ZIMethod) and specific 
 * LRS (Layout Requirements Specification) that regulate application layout (@see ZLRS).
 *
 * Almost all the included headers are symbolically linked to model dependent header 
 * files.
 *
 * For example, the portfolio A760 is actually defined by the following global header 
 * files:
 *
 * ZHKey.h ---> Z760HKey.h
 * ZIMethod.h ---> Z760IMethod.h
 * ZLRS.h ---> Z760LRS.h
 * ZDefs.h and ZLayout.h are common for all products for now.
 *
 * As new products come out, new linkages will be made.
 */
#include "ZDefs.h"
#include "ZLayout.h"
#include "ZHKey.h"
#include "ZIMethod.h"
#include "ZLRS.h"

#endif //ZGlobal_H
