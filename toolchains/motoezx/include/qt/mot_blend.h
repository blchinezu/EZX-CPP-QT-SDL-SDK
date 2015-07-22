#ifndef MOT_BLEND_H
#define MOT_BLEND_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//---------------------------------------------------------------------------
//                                                                    
//   Header Name: mot_blend.h
//
//   General Description: blending functions used by Qt and applications to 
//                        blend pixmaps and colors with wallpaper, etc.
//
//   This file is included by qpaintdevice.h.  It's better to 
//
//   #include <qpaintdevice.h>, not #include <mot_blend.h>
//
//   Note: These functions have been put in this separate file to make merging 
//   with future qt versions easier.
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
//
// Peter McDermott (w20027)      01/19/2004    
//
//---------------------------------------------------------------------------
//                              INCLUDE FILES
//---------------------------------------------------------------------------

#include <qpaintdevice.h>
#include <qpoint.h>
#include <qsize.h>
#include <qcolor.h>

//
// dst = (src1 * src1Percent) + (src2 * src2Percent)
//

void blendBlt(QPaintDevice* dst, const QPoint& dstp,
              const QPaintDevice *src1, const QPoint& src1p, int src1Percent,
              const QPaintDevice *src2, const QPoint& src2p, int src2Percent,
              const QSize& size, bool ignoreMask = false);

void blendBlt(QPaintDevice* dst, int dstx, int dsty, 
              const QPaintDevice *src1, int src1x, int src1y, int src1Percent,
              const QPaintDevice *src2, int src2x, int src2y, int src2Percent,
              int w, int h, bool ignoreMask = false);

//
// dst = (src * srcPercent) + (fillColor * fillColorPercent)
//

void blendFill(QPaintDevice* dst, const QRect& dstRegion,
               const QPaintDevice *src, const QPoint& srcp, int srcPercent,
               const QColor& fillColor, int fillColorPercent,
               bool ignoreMask = false);

void blendFill(QPaintDevice* dst, int dstx, int dsty,  int w, int h,
               const QPaintDevice *src1, int srcx, int srcy, int srcPercent,
               const QColor& fillColor, int fillColorPercent,
               bool ignoreMask = false);

#endif // MOT_BLEND_H
