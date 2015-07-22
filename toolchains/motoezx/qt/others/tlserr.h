/*+
Release: SSL Plus 1.1.2b

Certicom, the Certicom logo, SSL Plus, and Security Builder are trademarks of
Certicom Corp.  Copyright (c) 1997-2002 Certicom Corp.  All rights reserved.
Protected by U.S. patents 5,787,028; 4,745,568;
5,761,305.  Patents pending.
-*/

/*+
 * tlserr.h - TLS errors.
 *
 * Description: 
 *
 *-------------------------------------------------------------
 * Conditional compilations:
 *
 *
 *-------------------------------------------------------------
 * Notes:
 *
 *-------------------------------------------------------------
 * This software contains trade secrets and confidential information of Certicom Corp.
 * (c) Copyright Certicom Corp. 1997-1999
-*/
/* $Id: tlserr.h,v 2.3 2001/05/31 17:15:17 rdugal Exp $ */

#ifndef __TLSERR_H__
#define __TLSERR_H__ 1

#include "tlstype.h"

enum {
    TLSNoErr = 0,
    TLSMemoryErr=1,
    TLSIOClosedOverrideGoodbyeKiss=2,
    TLSIOErr=3,
    TLSWouldBlockErr=4,
    TLSNullContext=5,
    TLSUnknownState=6,
    TLSNullCallback=7,
    TLSOverflowErr=8,
    TLSVersionErr=9,
    TLSStateErr=10,
    TLSNegotiationErr=11,
    TLSCryptoErr=12,
    TLSUnknownRecord=13,
    TLSBadFinishedMessage=14,
    TLSBadMacErr=15,
    TLSUnknownErr=16,
    TLSFatalAlertErr=17,
    TLSBadParameterErr=18,
    TLSSessionNotFoundErr=19,
    TLSResumableSessionErr=20,
    TLSBadCertificateErr=21,
    TLSCertificateChainLengthErr=22,
    TLSInvalidCertDatesErr=23,
    TLSCertNotTrustedErr=24,
    TLSBasicConstraintsErr=25,
    TLSCertKeyUsageErr=26,
    TLSUnknownCriticalExtensionErr=27,
    TLSCertSignatureInvalid=28,
    TLSNonMatchingCertChainErr=29,
    TLSConnectionClosedGraceful=30,
    TLSIncompleteCertChainErr=31,

/* PALM O/S SHARED LIBRARY SPECIFIC ERRORS */
    TLSSharedLibNotOpenErr=32,                         /* Shared TLS library is not open */
    TLSSharedLibFailOpenErr=33,                        /* Unable to open shared library (TLS, ESB, etc) */ 
    TLSSharedLibStillOpenErr=34                        /* Shared library still in use by other clients */
};

#endif /* __TLSERR_H__ */

