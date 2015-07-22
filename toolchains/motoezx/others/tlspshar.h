/*+
Release: SSL Plus 1.1.2b

Certicom, the Certicom logo, SSL Plus, and Security Builder are trademarks of
Certicom Corp.  Copyright (c) 1997-2002 Certicom Corp.  All rights reserved.
Protected by U.S. patents 5,787,028; 4,745,568;
5,761,305.  Patents pending.
-*/

/*+
 * tlspshar.h - SSLPlus Palm shared library interfaces.
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
 * (c) Copyright Certicom Corp. 1996-2001.  All rights reserved
 *
 * This software contains trade secrets and confidential information
 * of Certicom Corp. This software cannot be reproduced or distributed,
 * in whole or in part by any means without the explicit prior consent
 * of Certicom Corp.
 *
 * Warning: Federal law provides severe civil and criminal penalties
 *          for the unauthorized reproduction in any form of these copyrighted
 *          materials.
 *          Criminal copyright infringement constitutes a felony and is
 *          punishable for up to 5 years in prison and $250,000 fine.
 *          This software is licensed strictly for use as outlined in the
 *          license agreement.
 *          Security Builder (TM) is a registered trademark of Certicom Corp.
-*/
/* $Id: tlspshar.h,v 2.7 2001/12/14 22:09:58 amartin Exp $ */

#ifndef __TLSPSHAR_H__
#define __TLSPSHAR_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

/*=== Module Preconditions ==================================================*/
/* None */


/*===============includes====================================*/
#include "cdglobal.h"
#include "tlstype.h"
#define SSLPLUS_API_DECLARED
#include "tls.h"

/*===============constants===================================*/
/*
 * Type and creator of TLS Library database
 */
#define     PalmSSLPLUSLibCreatorID     'CICS'              // Library database creator
#define     PalmSSLPLUSLibTypeID        'libr'              // Standard library database type

/*
 * Internal library name which can be passed to SysLibFind()
 */
#define     PalmSSLPLUSLibName          "Certicom Shared SSLPLUS"      


/*-----------------------------------------------------------------------------
// TLS shared library function trap ID's. Each library call gets a trap number:
//   PTLSTrapXXXX which serves as an index into the library's dispatch table.
//   The constant sysLibTrapCustom is the first available trap number after
//   the system predefined library traps Open,Close,Sleep & Wake.
//
// WARNING!!! The order of these traps MUST match the order of the dispatch
//  table in psl_dispatch.c!!!
//----------------------------------------------------------------------------*/

typedef enum {
    PTLSTrapTLSContextSize = sysLibTrapCustom,
    PTLSTrapTLSInitContext,
    PTLSTrapTLSDeleteContext,
    PTLSTrapTLSSetCipherSuites,
    PTLSTrapTLSSetRandomFunc,
    PTLSTrapTLSSetRandomRef,
    PTLSTrapTLSSetIORef,
    PTLSTrapTLSSetReadFunc,
    PTLSTrapTLSSetWriteFunc,
    PTLSTrapTLSSetPeerID,
    PTLSTrapTLSSetSessionRef,
    PTLSTrapTLSSetAddSessionFunc,
    PTLSTrapTLSSetGetSessionFunc,
    PTLSTrapTLSSetDeleteSessionFunc,
    PTLSTrapTLSSetSessionExpiryTime,
    PTLSTrapTLSSetAlertFunc,
    PTLSTrapTLSSetAlertRef,
    PTLSTrapTLSSetCheckCertificateChainFunc,
    PTLSTrapTLSSetCheckCertificateChainRef,
    PTLSTrapTLSGenerateKeyAgreementParams,
    PTLSTrapTLSAddTrustedCertificate,
    PTLSTrapTLSHandshake,
    PTLSTrapTLSClose,
    PTLSTrapTLSWrite,
    PTLSTrapTLSRead,
    PTLSTrapTLSWriteNoCopy,
    PTLSTrapTLSReadNoCopy,
    PTLSTrapTLSPeekNextReadLength,
    PTLSTrapTLSExtractCertificateNameItem,
    PTLSTrapTLSNoCopyBufferSize,
    PTLSTrapTLSAddECDSACertificate,
    PTLSTrapTLSAddRSACertificate,
    PTLSTrapTLSDeriveARC4Key,
    PTLSTrapTLSSetECDSAPrivateKey,
    PTLSTrapTLSSetRSAPrivateKey,
    PTLSTrapTLSSetPwdECDSAPrivateKey,
    PTLSTrapTLSSetPwdRSAPrivateKey,
    PTLSTrapTLSGetNegotiatedCipher,
    PTLSTrapTLSSetProtocolVersion,
    PTLSTrapTLSGetProtocolVersion,
    PTLSTrapTLSEnableNonBlocking,
    PTLSTrapTLSSetCryptographicStrength,
    PTLSTrapTLSLibVersion,
    PTLSTrapTLSAddTrustedCertificateNoCopy,
    PTLSTrapTLSSetOption,
    PTLSTrapTLSGenerateRandom,
    PTLSTrapTLSGetMasterSecret,
    PTLSTrapLast
} PTLSTrapNumberEnum;

/*=============function prototypes===========================*/

#ifndef TLS_DONOT_DECLARE_PALM_SHARED_API


/*-------PalmTLSLibOpen()
 *  Opens the TLS Shared library, creates and initializes the globals.
 *
 * Notes: 
 *       This function must be called before any other TLS Shared Library functions,
 *       with the exception of PalmTLSGetLibAPIVersion.
 *
 *       If SYS_TRAPOpen fails, do not call any other TLS library API functions.
 *       If SYS_TRAPOpen succeeds, call SYS_TRAPClose when you are done using
 *       the library to enable it to release critical system resources.
 *
 *       The library's "open" and "close" functions should *not* take an excessive
 *       amount of time to complete.  If the processing time for either of these
 *       is lengthy, consider creating additional library API function(s) to handle
 *       the time-consuming chores.
 *
 * Returns:
 *      TLSNoErr            -- no error
 *      TLSMemoryErr        -- Memory error
 *      TLSBadParameterErr  -- Bad parameters
 *
*/ 
TLSErr PalmTLSLibOpen (
    uint16 refNum, 
    /* [input]
     * Library reference #
     */
    CD_mallocFunc mallocFunc,
    /* [input]
     * CD_malloc() fcn ptr.
     */
    CD_freeFunc freeFunc,   
    /* [input]
     * CD_free() fcn ptr.
     */
    CD_reallocFunc reallocFunc, 
    /* [input]
     * CD_realloc() fcn ptr.
     */
    CD_memsetFunc memsetFunc,
    /* [input]
     * CD_memset() fcn ptr.
     */
    CD_memcpyFunc memcpyFunc,
    /* [input]
     * CD_memcpy() fcn ptr.
     */
    CD_memcmpFunc memcmpFunc,
    /* [input]
     * CD_memcmp() fcn ptr.
     */
    CD_timeFunc timeFunc,
    /* [input]
     * CD_time() fcn ptr.
     */
    CD_yieldFunc yieldFunc,
    /* [input]
     * CD_yield() fcn ptr.
     */
    uint32 *clientContext
    /* [output]
     * Pointer to a variable to return the client context
     */
    ) SYS_TRAP(sysLibTrapOpen);
    

/*-------PalmTLSLibClose()
 *  Closes the TLS Shared libary, frees client context and globals.
 *
 * Notes: 
 *       ***IMPORTANT***
 *       May be called only if PalmOpen succeeded.
 *
 *       If other applications still have the library open, decrements
 *       the reference count and returns TLSSharedLibStillOpenErr.
 *
 *       The library's "open" and "close" functions should *not* take an excessive
 *       amount of time to complete.  If the processing time for either of these
 *       is lengthy, consider creating additional library API function(s) to handle
 *       the time-consuming chores.
 *
 * Returns:
 *      TLSNoErr                    -- no error
 *      TLSSharedLibStillOpenErr    -- Library is still open by other clients
 *
*/ 
TLSErr PalmTLSLibClose (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext
    /* [input]
     * Client context.
     */
    ) SYS_TRAP(sysLibTrapClose);

/*-------PalmTLSLibSleep()
 *  Handles system sleep notification.
 *
 * Notes: 
 *      ***IMPORTANT***
 *      This notification function is called from a system interrupt.
 *      It is only allowed to use system services which are interrupt-
 *      safe.  Presently, this is limited to EvtEnqueueKey, SysDisableInts,
 *      SysRestoreStatus.  Because it is called from an interrupt,
 *      it must *not* take a long time to complete to preserve system
 *      integrity.  The intention is to allow system-level libraries
 *      to enable hardware components which were disabled when the system
 *      went to sleep.
 *
 * Returns:
 *      TLSNoErr            -- no error
 *
*/ 
TLSErr PalmTLSLibSleep (
    uint16 refNum
    /* [input]
     * Library reference #
     */
    ) SYS_TRAP(sysLibTrapSleep);

/*-------TLSLibWake()
 *  Handles system wake notification.
 *
 * Notes: 
 *      ***IMPORTANT***
 *      This notification function is called from a system interrupt.
 *      It is only allowed to use system services which are interrupt-
 *      safe.  Presently, this is limited to EvtEnqueueKey, SysDisableInts,
 *      SysRestoreStatus.  Because it is called from an interrupt,
 *      it must *not* take a long time to complete to preserve system
 *      integrity.  The intention is to allow system-level libraries
 *      to enable hardware components which were disabled when the system
 *      went to sleep.
 *
 * Returns:
 *      TLSNoErr            -- no error
 *
*/ 
TLSErr PalmTLSLibWake (
    uint16 refNum
    /* [input]
     * Library reference #
     */
    ) SYS_TRAP(sysLibTrapWake);

/*---PalmTLSContextSize()
 * This function returns the size of an TLSContext structure. 
 *
 * Notes: 
 * You should call this function to determine how much memory to 
 * allocate for an TLSContext before initializing it.
 *
 * ****IMPORTANT****
 * This API is slightly different than non-shared API because of error return.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSBadParameterErr      -- the contextSize parameter is null
 */
TLSErr PalmTLSContextSize (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    uint16 readBufferSize,
    /* [input]
     * The read buffer size in bytes.
     */
    uint32 *contextSize
    /* [output]
     * Buffer to return context size in bytes.
     */
    ) SYS_TRAP(PTLSTrapTLSContextSize);
    
/*---PalmTLSInitContext()
 * This function initializes the internal values of the TLSContext structure.
 *
 * Notes: 
 * TLSInitContext() must be called before any other TLS functions are called
 * on this context.
 * The internal values of ctx are initialized to their default values. 
 * The documentation for individual TLS calls that change the configuration 
 * of a context will indicate what the default value for that setting is. 
 * If ctx points to an TLSContext currently in use, its values will be 
 * initialized without regard to its associated SSL connection.
 *
 * Returns (checked in the order indicated):
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 */
TLSErr PalmTLSInitContext (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to a memory buffer to be initialized as a TLSContext with 
     * default values.
     */
    uint16 readBufferSize,
    /* [input]
     * The read buffer size in bytes.
     */
    void *cbRef
    /* [input]
     * Optional user reference parameter which will be passed to memory 
     * allocation callbacks.
     */
    ) SYS_TRAP(PTLSTrapTLSInitContext);
    
/*---PalmTLSDeleteContext()
 * This function releases all resources held by a TLSContext structure. 
 *
 * Notes: 
 * The TLSContext structure itself is not deallocated; you should deallocate 
 * it using the same method you used to allocate the memory.
 * Heap memory and other resources of ctx are released.
 * If the TLS connection has not been closed, it should be closed by calling 
 * TLSClose() before deleting the TLSContext.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 */
TLSErr PalmTLSDeleteContext (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context to be released. This context must have been 
     * initialized with TLSInitContext() and must not have been already deleted.
     */
    ) SYS_TRAP(PTLSTrapTLSDeleteContext);

/*---PalmTLSSetProtocolVersion()
 * This function sets the version of the TLS/SSL protocol to be negotiated
 * with the server.
 *
 * Notes: The protocol parameter has the following meaning:
 *
 *  SSLVersion2             SSL version 2 or higher
 *  SSLVersion3             SSL version 3 or higher
 *  TLSVersion1             TLS version 1 only
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the version parameter is invalid
 */
TLSErr PalmTLSSetProtocolVersion (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx,
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSProtocolVersion version
    /* [input]
     * The desired version of the protocol
     */
    ) SYS_TRAP(PTLSTrapTLSSetProtocolVersion);

/*---PalmTLSGetProtocolVersion()
 * Returns the actual protocol version negotiated with the remote host.
 *
 * Notes: None.
 *
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the version parameter is null
 */
TLSErr PalmTLSGetProtocolVersion (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx,
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSProtocolVersion *version
    /* [output]
     * The negotiated version of the protocol
     */
    ) SYS_TRAP(PTLSTrapTLSGetProtocolVersion);

/*---PalmTLSSetPeerID()
 * Describes to the TLS library which TLS server you are communicating with; 
 * the library uses this information to retrieve information about past 
 * connections with this server to enable TLS session resumption.
 *
 * Notes: 
 * The library uses callback functions to retrieve existing peer information 
 * to resume the TLS session. If the peer is a server and is not in the 
 * resumable connection database, the library uses this value as a key when 
 * adding the resumption data for this session. If implementing a TLS client, 
 * but this function is not called for an TLSContext, the library will not 
 * attempt to resume a session with this peer, nor will the library attempt to
 * store any session data.
 * This function need only be called by clients; TLS servers use information 
 * provided to them by the client to store resumable session records. 
 * On servers, therefore, simply setting the database callbacks is sufficient 
 * to enable TLS session resumption.
 *
 * The peerID.length must be less than or equal to 32 bytes because the 
 * peerID.data value is copied into the ctx->peerID buffer which is 32 bytes.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the peerID parameter is null, peerID.length or 
 *                                                     peerID.data is invalid.
 */
TLSErr PalmTLSSetPeerID (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer peerID
    /* [input]
     * Is an opaque buffer. The library passes it to the session database 
     * callback functions as the key and without regard for its contents; 
     * it should be a representation of the peer's network address and port, 
     * or some other uniquely identifying value. 
     * The library makes a copy of this buffer, leaving the caller responsible 
     * for deallocating it, if necessary.
     */
    ) SYS_TRAP(PTLSTrapTLSSetPeerID);

/*---PalmTLSSetIORef()
 * This function specifies the reference parameter passed by the library 
 * to the I/O callback functions and configures the TLSContext structure 
 * for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the randomRef parameter is null.
 */
TLSErr PalmTLSSetIORef (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    void *ioRef
    /* [input]
     * Passed through to the I/O callback function. 
     * It is shared by TLSReadFunc and TLSWriteFunc. 
     * ioRef is not used by the library. 
     * It is up to the callback functions to determine how ioRef is used.
     */
    ) SYS_TRAP(PTLSTrapTLSSetIORef);
    
/*---PalmTLSSetSessionRef()
 * This function specifies the reference parameter passed by the library to 
 * the session database callback functions and configures the TLSContext 
 * structure for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the sessRef parameter is null.
 */
TLSErr PalmTLSSetSessionRef (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    void *sessRef
    /* [input]
     * sessRef is passed through to the session database callback functions. 
     * It is shared by TLSAddSessionFunc, TLSGetSessionFunc, and
     * TLSDeleteSessionFunc. sessRef is not used by the library. It is up
     * to the callback functions to determine how sessRef is used.
     */
    ) SYS_TRAP(PTLSTrapTLSSetSessionRef);
    
/*---PalmTLSAddTrustedCertificate()
 * Adds a DER-encoded X.509 certificate to the list of trusted certificates. 
 * A copy of the certificate is made, and the caller retains ownership of 
 * the certificate data. The cert can either be a server or CA certificate. 
 * Calling this with a server certificate will prevent any certificate signature 
 * verifies from occurring, calling it with a CA cert will prevent one or more 
 * ECDSA verifies from occurring.

 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the certificate parameter is null, has 0 length, or null data.
 *      TLSBadCertificateErr    -- the certificate is bad.
 *      TLSMemoryErr            -- memory allocation error.
 */
TLSErr PalmTLSAddTrustedCertificate (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *certificate
    /* [input]
     * Points to a DER-encoded X.509 certificate.
     */
    ) SYS_TRAP(PTLSTrapTLSAddTrustedCertificate);
    
/*---PalmTLSGenerateKeyAgreementParams()
 * Pre-generates an the TLS handshake key agrement parameters which are 
 * normally generated during TLSHandshake(). 
 * Call before calling TLSHandshake()
 *
 * Notes: 
 * This function assumes that the curve will be ec163a02.
 * This function will allocate memory for the SB global data using CD_malloc().
 * The memory is released on exit from the function.
 * This function will execute the callback identified with TLSSetRandomFunc().
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNegotiationErr       -- error generating the Key Agrement parameters.
 *      TLSMemoryErr            -- memory allocation error.
 *      ??????                  -- the TLSRandomFunc callback may return other user 
 *                                                     defined errors.
 */
TLSErr PalmTLSGenerateKeyAgreementParams (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure for which the Key Agrement parameters
     * are to be generated.
     */
    ) SYS_TRAP(PTLSTrapTLSGenerateKeyAgreementParams);

/*---PalmTLSSetCipherSuites()
 * This function specifies and prioritizes the cipher suites the 
 * TLS connection should support.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- ciphers parameter is null or invalid.
 */
TLSErr PalmTLSSetCipherSuites ( 
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx,
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    TLSBuffer *ciphers 
    /* [input]
     * Specifies the array of cipher suite values which you wish to 
     * support in this TLS context.
     * The data field should point to an array of 16-bit values and the 
     * length parameter should indicate the length of this array in bytes. 
     * This data block can be allocated in any fashion; the library makes 
     a copy of the data during the call, so the caller is responsible for 
     * deallocating the ciphers buffer, if necessary.
     */
    ) SYS_TRAP(PTLSTrapTLSSetCipherSuites);

/*---PalmTLSSetSessionExpiryTime()
 * Configure the session expiry time length in seconds.
 * If this callback is not set, the toolkit will use the default session expiry
 * period of 1 week.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 */
TLSErr PalmTLSSetSessionExpiryTime ( 
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    uint32 sessionExpiryTime
    /* [input]
     * The session expiry time length in seconds.
     */
    ) SYS_TRAP(PTLSTrapTLSSetSessionExpiryTime);

/*---PalmTLSSetRandomFunc()
 * Configures the TLSContext structure to identify the function used by the 
 * library to obtain a random number.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the random parameter is null.
 */
TLSErr PalmTLSSetRandomFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSRandomFunc random
    /* [input]
     * Points to a callback of type TLSRandomFunc.
     */
    ) SYS_TRAP(PTLSTrapTLSSetRandomFunc);
    
/*---PalmTLSSetRandomRef()
 * This function specifies the reference parameter passed by the library
 * to the random callback function and configures the TLSContext structure 
 * for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the randomRef parameter is null.
 */
TLSErr PalmTLSSetRandomRef (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    void* randomRef
    /* [input]
     * Passed through to the random callback function. 
     * randomRef is not used by the library. It is up to the TLSRandomFunc 
     * callback function to determine how randomRef is used.
     */
    ) SYS_TRAP(PTLSTrapTLSSetRandomRef);
    
/*---PalmTLSSetReadFunc()
 * This function is used by the library to retrieve data from the 
 * physical connection and configures the TLSContext structure for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the read parameter is null.
 */
TLSErr PalmTLSSetReadFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSIOFunc read
    /* [input]
     * Points to a TLSIOFunc callback.
     */
    ) SYS_TRAP(PTLSTrapTLSSetReadFunc);
    
/*---PalmTLSSetWriteFunc()
 * This function is used by the library to write data to the 
 * physical connection and configures the TLSContext structure for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the write parameter is null.
 */
TLSErr PalmTLSSetWriteFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSIOFunc write
    /* [input]
     * Points to a TLSIOFunc callback.
     */
    ) SYS_TRAP(PTLSTrapTLSSetWriteFunc);
    
/*---PalmTLSSetAlertFunc()
 * This function performs any additional alert procedures desired by the user
 * and configures the TLSContext structure for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the alertFunc parameter is null.
 */
TLSErr PalmTLSSetAlertFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSAlertFunc alertFunc
    /* [input]
     * Points to a callback of type TLSAlertFunc.
     */
    ) SYS_TRAP(PTLSTrapTLSSetAlertFunc);

/*---PalmTLSSetAlertRef()
 * This function specifies the reference parameter passed by the library
 * to the alert callback function and configures the TLSContext structure
 * for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the alertRef parameter is null.
 */
TLSErr PalmTLSSetAlertRef (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx,
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    void *alertRef
    /* [input]
     * Passed through to the Alert callback function.
     * alertRef is not used by the library.  It is up to the TLSAlertFunc
     * callback function to determine how alertRef is used.
     */
    ) SYS_TRAP(PTLSTrapTLSSetAlertRef);

/*---PalmTLSSetAddSessionFunc()
 * This function is used by the library to add a session's resumption 
 * information to the database of resumable sessions and configures the 
 * TLSContext structure for later use.
 * If this callback is not set, the toolkit will not attempt to use the 
 * session database and will proceed without the benefits of session caching.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the addFunc parameter is null.
 */
TLSErr PalmTLSSetAddSessionFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSAddSessionFunc addFunc
    /* [input]
     * Points to a callback of type TLSAddSessionFunc.
     */
    ) SYS_TRAP(PTLSTrapTLSSetAddSessionFunc);
    
/*---PalmTLSSetGetSessionFunc()
 * This function is used by the library to retrieve a session's resumption 
 * information from the database of resumable sessions and configures the 
 * TLSContext structure for later use. If this callback is not set, the toolkit 
 * will not attempt to use the session database and will proceed without the 
 * benefits of session caching.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the getFunc parameter is null.
 */
TLSErr PalmTLSSetGetSessionFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSGetSessionFunc getFunc
    /* [input]
     * Points to a callback of type TLSGetSessionFunc.
     */
    ) SYS_TRAP(PTLSTrapTLSSetGetSessionFunc);
    
/*---PalmTLSSetDeleteSessionFunc()
 * This function is used by the library to remove a session's resume 
 * information from the database of resumable sessions and configures 
 * the TLSContext structure for later use.
 * If this callback is not set, the toolkit will not attempt to use the 
 * session database and will proceed without the benefits of session caching.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the deleteFunc parameter is null.
 */
TLSErr PalmTLSSetDeleteSessionFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSDeleteSessionFunc deleteFunc
    /* [input]
     * Points to a callback of type TLSDeleteSessionFunc.
     */
    ) SYS_TRAP(PTLSTrapTLSSetDeleteSessionFunc);
    
/*---PalmTLSSetCheckCertificateChainFunc()
 * This function is used by the library to check the validity of a certificate 
 * chain during negotiation of the TLS connection. Setting such a function is 
 * optional; certificates can be examined after the TLS handshake is complete, 
 * but if you wish to override certificate validation errors during the handshake, 
 * you must add a certificate callback.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSNullCallback         -- the chainFunc parameter is null.
 */
TLSErr PalmTLSSetCheckCertificateChainFunc (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSCheckCertificateChainFunc chainFunc
    /* [input]
     * Points to a callback of type TLSCheckCertificateChainFunc.
     */
    ) SYS_TRAP(PTLSTrapTLSSetCheckCertificateChainFunc);

/*---PalmTLSSetCheckCertificateChainRef()
 * This function specifies the reference paremeter passed by the library
 * to the certificate chain callback function and configures the TLSContext
 * structure for later use.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the certChainRef parameter is null.
 */
TLSErr PalmTLSSetCheckCertificateChainRef (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx,
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    void* certChainRef
    /* [input]
     * Passed through to the certificate chain callback function.
     * certChainRef is not used by the library.  It is up to the
     * TLSCheckCertificateChainFunc callback function to determine how
     * certChainRef is used.
     */
     ) SYS_TRAP(PTLSTrapTLSSetCheckCertificateChainRef);

/*---PalmTLSHandshake()
 * This function completes a TLS handshake. This function can be called for a newly
 * initialized connection. When the handshake is complete, the connection will be
 * complete and it can be used to transfer data.
 * TLSHandshake() initiates the handshake process with the peer. In the absence of any
 * errors, TLSHandshake() will not return until the handshake process is complete.
 *
 * Notes: 
 * The handshake process generally will cause data to be written to the connection
 * as well as read using the I/O callbacks.
 * Calls to all the TLS callbacks can occur during the TLS handshake; error codes returned
 * by these callbacks will be bubbled up and returned to the caller.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      ?????                   -- some TLSErr
 *                                 Most of the TLSErr errors can be returned by this function.
 */
TLSErr PalmTLSHandshake (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    ) SYS_TRAP(PTLSTrapTLSHandshake);

/*---PalmTLSClose()
 * This function attempts to close the TLS connection with the peer by 
 * sending a "goodbye kiss" message. If the connection is not properly 
 * closed, it cannot be resumed. A "finished" message is sent to the peer, 
 * indicating that no further communications should be expected. This should 
 * be done whenever the connection is to be closed if no error has yet 
 * occurred on the TLS connection. If the peer closes the connection first,
 * TLSConnectionClosedGraceful will be returned from TLSRead(); in this
 * case, calling TLSClose() is usually not necessary because the peer will 
 * close its connection after sending the "goodbye kiss" without waiting to 
 * receive one from your end. TLSClose() has no affect on the underlying 
 * network connection; it must still be closed manually with its native API. 
 * If the network connection is closed without first calling TLSClose() 
 * the peer to the TLS connection may treat this connection as unreliable, 
 * including refusing to cache the keys from this connection and invalidating 
 * the session.
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSIOErr                -- I/O error.
 */
TLSErr PalmTLSClose (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    ) SYS_TRAP(PTLSTrapTLSClose);
    
/*---PalmTLSWrite()
 * This function writes data to an TLS connection.
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSIOErr                -- I/O error.
 */
TLSErr PalmTLSWrite (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    void *data, 
    /* [input]
     * Points to the block of data to be written. 
     * The user is responsible for freeing the buffer passed to TLSWrite.
     */
    uint32 *length, 
    /* [input/output]
     * Points to the number of bytes to be written. 
     * *length will be replaced with the number of bytes actually written.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    ) SYS_TRAP(PTLSTrapTLSWrite);
    
/*---PalmTLSRead()
 * This function reads data from an TLS connection.
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSIOErr                -- I/O error.
 */
TLSErr PalmTLSRead (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    void *data, 
    /* [input]
     * Points to the buffer where the read data will be stored.
     */
    uint32 *length, 
    /* [input/output]
     * Points to the size of the buffer in bytes.
     * *length will be replaced with the number of bytes actually read.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    ) SYS_TRAP(PTLSTrapTLSRead);
    
/*---PalmTLSWriteNoCopy()
 * This function writes data to a TLS connection but the buffer must be 
 * longer than the data being written. The number of extra bytes required
 * can be determined with TLSNoCopyBufferSize().
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSIOErr                -- I/O error.
 *      TLSBadParameterErr      -- a parameter is invalid.
 *      TLSOverflowErr          -- the totalLength parameter is too small.
 */
TLSErr PalmTLSWriteNoCopy (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    void *data, 
    /* [input]
     * Points to the block of data to be written. 
     * The user is responsible for freeing the buffer passed to TLSWrite.
     */
    uint32 *length, 
    /* [input/output]
     * Points to the number of bytes to be written. 
     * *length will be replaced with the number of bytes actually written.
     */
    uint32 totalLength, 
    /* [input]
     * The total length of the data buffer.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    ) SYS_TRAP(PTLSTrapTLSWriteNoCopy);
    
/*---PalmTLSReadNoCopy()
 * This function reads data to a TLS connection but the buffer must be 
 * longer than the data being read. The number of extra bytes required
 * can be determined with TLSNoCopyBufferSize().
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSIOErr                -- I/O error.
 *      TLSBadParameterErr      -- a parameter is invalid.
 *      TLSOverflowErr          -- the totalLength parameter is too small.
 */
TLSErr PalmTLSReadNoCopy (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    void *data, 
    /* [input]
     * Points to the buffer where the read data will be stored.
     */
    uint32 *length, 
    /* [input/output]
     * Points to the size of the buffer in bytes.
     * *length will be replaced with the number of bytes actually read.
     */
    uint32 totalLength, 
    /* [input]
     * The total length of the data buffer.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    ) SYS_TRAP(PTLSTrapTLSReadNoCopy);
    
/*---PalmTLSPeekNextReadLength()
 * This function is used to obtain the size of the next record available for reading. length
 * will specify the size of the next record to be read. Calling TLSRead () or
 * TLSReadNoCopy () with a buffer of this length plus N bytes will allow the next
 * record to be read.
 * N, the number of extra bytes required can be determined with TLSNoCopyBufferSize().
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSIOErr                -- I/O error.
 *      TLSBadParameterErr      -- a parameter is invalid.
 *      TLSOverflowErr          -- the totalLength parameter is too small.
 */
TLSErr PalmTLSPeekNextReadLength (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure defining the TLS connection. 
     * The library updates it as necessary for its internal use.
     */
    uint32 *length
    /* [output]
     * Points to a container into which the number of bytes of application 
     * data in the read buffer will be copied.
     */
    ) SYS_TRAP(PTLSTrapTLSPeekNextReadLength);

/*---PalmTLSExtractCertificateNameItem()
 * Extracts from a DER-encoded certificate (usually provided by the cert 
 * callback) an subject RDN denoted by the which param, the legal values 
 * of which are TLSCommonName, et. al.. defined in tlstype.h. 
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadCertificateErr    -- bad certificate.
 *      TLSBadParameterErr      -- a parameter is invalid.
 *      TLSOverflowErr          -- buffer overflow.
 */
TLSErr PalmTLSExtractCertificateNameItem (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSBuffer *certificate, 
    /* [input]
     * Points to a DER-encoded X.509 certificate.
     */
    TLSCertificateNameItem which, 
    /* [input]
     * Defines which RDN to extract. May be one of:
     *      TLSCertCommonName
     *      TLSCertCountry
     *      TLSCertLocality
     *      TLSCertStateProvince
     *      TLSCertOrganization
     *      TLSCertOrganizationalUnit
     */
    TLSBuffer *result
    /* [output]
     * Points to a buffer into which the RDN will be copied.
     */
    ) SYS_TRAP(PTLSTrapTLSExtractCertificateNameItem);



/*---PalmTLSAddECDSACertificate()
 * Adds a DER-encoded X.509 ECDSA certificate to the list of local certificates. 
 *
 * Notes: None.
 *
 * Returns (checked in the order indicated):
 *  TLSSharedLibNotOpenErr  -- Library is not open
 *  TLSNullContext      -- the ctx parameter is null.
 *  TLSBadParameterErr  -- the certificate parameter is null, has 0 length, or null data.
 *  TLSBadCertificateErr-- the certificate is bad.
 *  TLSMemoryErr        -- memory allocation error.
 *  TLSNoErr            -- success.
 */
TLSErr PalmTLSAddECDSACertificate(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *certificate,
    /* [input]
     * Points to a DER-encoded X.509 certificate.
     */
    uint16 parent,
    /* [input]
     * Flag to indicate if this certificate is a parent to certs previously added.
     * Non-zero to indicate it is a parent.
     */
    uint16 noCopy
    /* [input]
     * Flag to indicate if we should copy the data (noCopy == 0) or reuse the 
     * certificate data pointer (noCopy == 1)
     */
    ) SYS_TRAP(PTLSTrapTLSAddECDSACertificate);

/*---PalmTLSAddRSACertificate()
 * Adds a DER-encoded X.509 RSA certificate to the list of local certificates. 
 *
 * Notes: None.
 *
 * Returns (checked in the order indicated):
 *  TLSSharedLibNotOpenErr  -- Library is not open
 *  TLSNullContext      -- the ctx parameter is null.
 *  TLSBadParameterErr  -- the certificate parameter is null, has 0 length, or null data.
 *  TLSBadCertificateErr-- the certificate is bad.
 *  TLSMemoryErr        -- memory allocation error.
 *  TLSNoErr            -- success.
 */
TLSErr PalmTLSAddRSACertificate(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *certificate,
    /* [input]
     * Points to a DER-encoded X.509 certificate.
     */
    uint16 parent,
    /* [input]
     * Flag to indicate if this certificate is a parent to certs previously added.
     * Non-zero to indicate it is a parent.
     */
    uint16 noCopy
    /* [input]
     * Flag to indicate if we should copy the data (noCopy == 0) or reuse the 
     * certificate data pointer (noCopy == 1)
     */
    ) SYS_TRAP(PTLSTrapTLSAddRSACertificate);

/*---PalmTLSSetECDSAPrivateKey()
 * Copies the ECDSA private key for the local identity.
 * The private key must match the public key in the certificate for the local identity
 * set with TLSAddECDSACertificate(). 
 *
 * Notes: None.
 *
 * Returns (checked in the order indicated):
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the parameter is null, has 0 length, or null data.
 */
TLSErr PalmTLSSetECDSAPrivateKey (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *privateKey
    /* [input]
     * Points to the local private key.
     */
    ) SYS_TRAP(PTLSTrapTLSSetECDSAPrivateKey);

/*---PalmTLSSetRSAPrivateKey()
 * Copies the RSA private key for the local identity.
 * The private key must match the public key in the certificate for the local identity
 * set with TLSAddRSACertificate(). 
 *
 * Notes: None.
 *
 * Returns (checked in the order indicated):
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the parameter is null, has 0 length, or null data.
 */
TLSErr PalmTLSSetRSAPrivateKey (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
	TLSBuffer *n,
    /* [input]
     * n
     */
	TLSBuffer *e,
    /* [input]
     * e
     */
	TLSBuffer *d,
    /* [input]
     * d
     */
	TLSBuffer *p,
    /* [input]
     * p
     */
	TLSBuffer *q,
    /* [input]
     * q
     */
	TLSBuffer *dp,
    /* [input]
     * dp
     */
	TLSBuffer *dq,
    /* [input]
     * dq
     */
	TLSBuffer *qinv
    /* [input]
     * qinv
     */
    ) SYS_TRAP(PTLSTrapTLSSetRSAPrivateKey);

/*---PalmTLSDeriveARC4Key()
 * Generates ARC4 key material from a passphrase.
 * The key derivation algorithm is as follows:
 *    1. Pad the passphrase out to 128 bytes with 0xaa.
 *    2. Compute the SHA-1 message digest of the padded 
 *       passphrase from Step 1.
 *    3. Use the SHA-1 message digest from Step 2 as the first 
 *       20 bytes of key material.
 *    4. Pad the passphrase out to 128 bytes with 0x55.
 *    5. Compute the SHA-1 message digest of the padded 
 *       passphrase from Step 4.
 *    6. Use the SHA-1 message digest from Step 5 as the next 
 *       20 bytes of key material.
 *
 * Notes: 
 * This function can generate at most 40 bytes if key material.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- a parameter is invalid (null, invalid length or data).
 */
TLSErr PalmTLSDeriveARC4Key (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx,
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    const TLSBuffer *passphrase,
    /* [input]
     * Points to the password used to decrypt the private key.
     */
    TLSBuffer *derivedKey
    /* [input/output]
     * Points to the buffer for the derived key.
     * On input derivedKey->length will specify the # bytes of key material 
     * to generate (MAX = 2 * 20).
     * On output derivedKey->length will contain the # bytes generated and
     * derivedKey->data will contain the derived key. 
     */
    ) SYS_TRAP(PTLSTrapTLSDeriveARC4Key);

/*---PalmTLSSetPwdECDSAPrivateKey()
 * Copies the ECDSA private key for the local identity.
 * The private key is password protected using ARC4 encryption.
 * The password protected private key is decrypted and a copy is stored in the context.
 * The private key must match the public key in the certificate for the local identity
 * set with TLSAddECDSACertificate(). 
 *
 * Notes: None.
 *
 * Returns (checked in the order indicated):
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- a parameter is invalid (null, invalid length or data).
 */
TLSErr PalmTLSSetPwdECDSAPrivateKey (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *protectedPrivateKey,
    /* [input]
     * Points to the local private key.
     */
    TLSBuffer *password
    /* [input]
     * Points to the password used to decrypt the private key.
     */
    ) SYS_TRAP(PTLSTrapTLSSetPwdECDSAPrivateKey);

/*---PalmTLSSetPwdRSAPrivateKey()
 * Copies the RSA private key for the local identity.
 * The private key is password protected using ARC4 encryption.
 * The password protected private key is decrypted and a copy is stored in the context.
 * The private key must match the public key in the certificate for the local identity
 * set with TLSAddRSACertificate(). 
 *
 * Notes: 
 * Before encryption the RSA components are assembled into a buffer as following : 
 * [n.length>>8]    [n.length]      [n.data ............]
 * [e.length>>8]    [e.length]      [e.data ............]
 * [d.length>>8]    [d.length]      [d.data ............]
 * [p.length>>8]    [p.length]      [p.data ............]
 * [q.length>>8]    [q.length]      [q.data ............]
 * [dp.length>>8]   [dp.length]     [dp.data ...........]
 * [dq.length>>8]   [dq.length]     [dq.data ...........]
 * [qinv.length>>8] [qinv.length]   [qinv.data .........]
 *
 * Returns (checked in the order indicated):
 *      TLSNoErr        -- no error
 *  TLSNullContext      -- the ctx parameter is null.
 *  TLSBadParameterErr  -- the parameter is null, has 0 length, or null data.
 */
TLSErr PalmTLSSetPwdRSAPrivateKey(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *protectedPrivateKey,
    /* [input]
     * Points to the local private key.
     */
    TLSBuffer *password
    /* [input]
     * Points to the password used to decrypt the private key.
     */
    ) SYS_TRAP(PTLSTrapTLSSetPwdRSAPrivateKey);

/*---PalmTLSNoCopyBufferSize()
 * This function returns the number of additional bytes required to use 
 * TLSReadNoCopy() and TLSWriteNoCopy() functions.
 *
 * Notes: 
 * You should call this function to determine how much extra memory to 
 * allocate in using TLSReadNoCopy() and TLSWriteNoCopy().
 *
 * ****IMPORTANT****
 * This API is slightly different than non-shared API because of error return.
 *
 * Returns :
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSBadParameterErr      -- the noCopySize parameter is null
 */
TLSErr PalmTLSNoCopyBufferSize (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    uint32 *noCopySize
    /* [output]
     * The number of additional bytes required.
     */
    ) SYS_TRAP(PTLSTrapTLSNoCopyBufferSize);

/*---PalmTLSEnableNonBlocking()
 * This function allocates the necessary data structures to perform
 * non-blocking I/O.
 *
 * Notes: None.
 *
 * Returns (checked in the order indicated):
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSMemoryErr            -- no memory available to allocate data structures
 */
TLSErr PalmTLSEnableNonBlocking (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx
    /* [input/output]
     * Points to the context structure which will have non-blocking enabled.
     */
    ) SYS_TRAP(PTLSTrapTLSEnableNonBlocking);

/*---PalmTLSGetNegotiatedCipher()
 * This function returns the negotiated cipher.
 *
 * Notes: None.
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSSharedLibNotOpenErr  -- Library is not open
 *      TLSNullContext          -- the ctx parameter is null.
 *      TLSBadParameterErr      -- the cipherSuite parameter is null or the
 *                                                     negotiated cipher parameter in the context is null.
 */
TLSErr PalmTLSGetNegotiatedCipher(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx,
    /* [input]
     * Points to the context structure which contains the negotiated cipher.
     */
    uint16 *cipherSuite
    /* [input/output]
     * Points to the negotiated cipher suite.
     */
    ) SYS_TRAP(PTLSTrapTLSGetNegotiatedCipher);

/*---PalmTLSSetCryptographicStrength()
 * This function sets the supported crypto strength in the TLSContext structure. 
 *
 * Notes: 
 *
 * Returns :
 *  TLSSharedLibNotOpenErr  -- Library is not open
 *  TLSNullContext          -- the ctx parameter is null.
 *  TLSBadParameterErr      -- a parameter is invalid.
 *  TLSNoErr                -- success.
 */
TLSErr PalmTLSSetCryptographicStrength (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSCryptoStrength strength
    /* [input]
     * Strength to install in context.
     */
    ) SYS_TRAP(PTLSTrapTLSSetCryptographicStrength);

/*-------PalmTLSLibVersion()
 *  Return the Embedded SSLPlus library version.
 *
 * Notes: 
 *
 * Returns:
 *      TLSNoErr                -- no error
 *      TLSBadParameterErr      -- null major or minor parameters.
 *      TLSOverflowErr          -- The buffer length is too small.
 *      TLSSharedLibNotOpenErr  -- Shared library was not opened correctly.
 *
*/ 
TLSErr PalmTLSLibVersion (
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    uint16 *bufferLen,
    /* [output]
     * On input contains the max size of the versionString buffer. 
     * On output contains the number of bytes copied into the versionString buffer. 
     * On failure due to TLSOverflowErr, the min size of the versionString buffer 
     * is returned. 
     */
    char *versionString
    /* [output]
     * Points to the buffer for the version string. Restricted to non-NULL values.
     */
    ) SYS_TRAP(PTLSTrapTLSLibVersion);

/*---PalmTLSAddTrustedCertificateNoCopy()
 * Adds a DER-encoded X.509 certificate to the list of trusted certificates. 
 * A copy of the certificate is NOT made, and the caller retains ownership of 
 * the certificate data. The cert can either be a server or CA certificate. 
 * Calling this with a server certificate will prevent any certificate signature 
 * verifies from occurring, calling it with a CA cert will prevent one or more 
 * ECDSA verifies from occurring.

 *
 * Notes: None.
 *
 * Returns:
 *  TLSNullContext      -- the ctx parameter is null.
 *  TLSBadParameterErr  -- the certificate parameter is null, has 0 length, or null data.
 *  TLSBadCertificateErr-- the certificate is bad.
 *  TLSMemoryErr        -- memory allocation error.
 *  TLSNoErr            -- success.
 */
TLSErr PalmTLSAddTrustedCertificateNoCopy(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *certificate
    /* [input]
     * Points to a DER-encoded X.509 certificate. 
     */
    ) SYS_TRAP(PTLSTrapTLSAddTrustedCertificateNoCopy);


/*---PalmTLSGenerateRandom()
 * Generates pseudo-random data from an input seed.
 *
 * Notes:
 *
 * Returns:
 *  TLSCryptoErr        -- crypto error.
 *  TLSBadParameterErr  -- a parameter is invalid (null, invalid length or data).
 *  TLSNoErr            -- success.
 */
TLSErr PalmTLSGenerateRandom(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    const TLSBuffer *seed,
    /* [input]
     * Points to the seed used for the PRNG.
     */
    TLSBuffer *random,
    /* [input/output]
     * Points to the buffer for the generated pseudo-random data.
     * On input random->length will specify the # bytes of pseudo-random
     * data to generate.
     * On output random->length will contain the # bytes generated.
     */
    void *cbRef
    /* [input]
     * Optional user reference parameter which will be passed to memory 
     * allocation callbacks.
     */
    ) SYS_TRAP(PTLSTrapTLSGenerateRandom);

/*---PalmTLSSetOption()
 * This function sets options which affect the internal processing of the library. 
 *
 * Notes: 
 *
 * Returns :
 *  TLSBadParameterErr  -- a parameter is invalid.
 *  TLSNoErr            -- success.
 */
TLSErr PalmTLSSetOption(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSOption option
    /* [input]
     * Option to enable.
     */
    ) SYS_TRAP(PTLSTrapTLSSetOption);


/*---PalmTLSGetMasterSecret()
 * Gets the Master Secret used in the key generation process.
 *
 * Notes: 
 *
 * Returns :
 *  TLSStateErr         -- Handshake not finished 
 *  TLSBadParameterErr  -- A NULL buffer is provided
 *  TLSNullContext      -- A NULL Context.
 *  TLSNoErr            -- success.
 */ 

TLSErr PalmTLSGetMasterSecret(
    uint16 refNum,
    /* [input]
     * Library reference #
     */
    uint32 clientContext,
    /* [input]
     * Client context.
     */
    TLSContext *ctx, 
    /* [input/output]
     * Points to the context structure into which this parameter is installed.
     */
    TLSBuffer *buf
    /* [output]
     * Pointer to a TLSBuffer that will contain the Master_Secret in buf->data.
     */
    ) SYS_TRAP(PTLSTrapTLSGetMasterSecret);

#endif

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __TLSPSHAR_H__ */
