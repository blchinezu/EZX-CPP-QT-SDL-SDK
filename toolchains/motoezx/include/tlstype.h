/*+
Release: SSL Plus 1.1.2b

Certicom, the Certicom logo, SSL Plus, and Security Builder are trademarks of
Certicom Corp.  Copyright (c) 1997-2002 Certicom Corp.  All rights reserved.
Protected by U.S. patents 5,787,028; 4,745,568;
5,761,305.  Patents pending.
-*/

/*+
 * tlstype.h - TLS datatypes.
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
/* $Id: tlstype.h,v 2.4 2002/04/18 20:55:54 amartin Exp $ */

#ifndef __TLSTYPE_H__
#define __TLSTYPE_H__ 1

#include "cdglobal.h"

struct TLSContext;
typedef struct TLSContext TLSContext;

typedef struct {
    uint32  length;
    uint8   *data;
} TLSBuffer;

typedef enum {
    TLSFatalAlert       = 2,
    TLSWarningAlert     = 1
} TLSAlertLevel;

typedef enum {
    TLSCloseNotifyAlert                 = 0,
    TLSUnexpectedMessageAlert           = 10,
    TLSBadRecordMacAlert                = 20,
    TLSDecryptionFailedAlert            = 21,
    TLSRecordOverflowAlert              = 22,
    TLSDecompressionFailureAlert        = 30,
    TLSHandshakeFailureAlert            = 40,
    TLSNoCertificateAlert               = 41, /* SSL3-only */
    TLSBadCertificateAlert              = 42,
    TLSUnsupportedCertificateAlert      = 43,
    TLSCertificateRevokedAlert          = 44,
    TLSCertificateExpiredAlert          = 45,
    TLSCertificateUnknownAlert          = 46,
    TLSIllegalParameterAlert            = 47,
    TLSUnknownCaAlert                   = 48,
    TLSAccessDeniedAlert                = 49,
    TLSDecodeErrorAlert                 = 50,
    TLSDecryptErrorAlert                = 51,
    TLSExportRestrictionAlert           = 60,
    TLSProtocolVersionAlert             = 70,
    TLSInsufficientSecurityAlert        = 71,
    TLSInternalErrorAlert               = 80,
    TLSUserCanceledAlert                = 90,
    TLSNoRenegotiationAlert             = 100
} TLSAlertCode;

typedef enum {
    TLSCertCommonName,
    TLSCertOrganization,
    TLSCertOrganizationalUnit,
    TLSCertLocality,
    TLSCertStateProvince,
    TLSCertCountry
} TLSCertificateNameItem;

typedef uint16 TLSErr;

/*
@section Assigning Callbacks 
@desc <B>SSL Plus for Embedded Systems</B> uses callback functions to accomplish tasks such
      as transferring data on the network connection and generating random data.
	  Each of these callback functions must conform to a template provided by the
	  library. This section describes these templates and the behavior expected of
	  each function.
      
      
*/

/*--------------------------------- TLSRandomFunc --------------------------------------*/
/**Template for a callback function which the library uses to generate random data.
Set this callback function with TLSSetRandomFunc().


@param buf       [Output] Random data generated by the function. 
                          
@param randomRef [Input] Reference parameter that the library passes to your function.
                         It is up to your function to determine how to use this 
						 parameter.

@returndesc Any error codes that your callback function generates will cause the SSL Plus
            API function that called your function to fail.

@version TLS 1.0
*/

typedef 
SSL_EXPORT 
TLSErr (SSL_CALLCONV *TLSRandomFunc) (
    TLSBuffer data, 
    void *randomRef
    );


/*----------------------------------- TLSIOFunc ------------------------------------------*/
/**Template for a read()/write() callback function. The library uses these callback functions to
transfer data over the network connection. Set these functions with TLSSetWriteFunc() and
TLSSetReadFunc().


@param data      [Input/Output] Data to be read/written.
                                
@param processed [Output] Must contain the number of bytes read/written.
                          
@param connRef   [Input] Reference parameter that the library passes to your function. It is up
                         to your function to determine how to use this parameter. It could 
						 represent an identifier for the network connection, such as the 
						 socket number.

@returndesc If your read() callback function cannot fulfill a request, it should return 
            TLSWouldBlockErr. A write() callback function cannot return TLSWouldBlockErr.
			If a network error (or an error other than TLSWouldBlockErr) occurs, your
			callback function should return TLSIOErr.
		   
@version TLS 1.0
*/
 
typedef 
SSL_EXPORT 
TLSErr (SSL_CALLCONV *TLSIOFunc) (
    TLSBuffer data, 
    uint32 *processed, 
    void *connRef
    );


/*----------------------------------------- TLSAlertFunc ------------------------------------*/
/**Template for a callback function which the library uses to send alert messages to your application.
Your function can then determine how to handle the alert message. Set this function with 
TLSSetAlertFunc().


@param ctx      [Input] Pointer to the TLS context.
@param level    [Input] Contains the level (type) of the alert.
@param code     [Input] Contains a description of the alert.
@param alertRef [Input] Reference parameter that the library passes to your function. Is it up to
                        your function to determine how to use this parameter.

@returndesc Any error codes that your callback function generates will cause the SSL Plus
            API function that called your function to fail.
		   
@version TLS 1.0
*/
 
typedef 
SSL_EXPORT 
TLSErr (SSL_CALLCONV *TLSAlertFunc) (
    TLSContext *ctx, 
    TLSAlertLevel level, 
    TLSAlertCode code, 
    void *alertRef
    );

/*----------------------------------- TLSAddSessionFunc -----------------------------------*/
/**Template for a callback function which the library uses to add a session entry to the 
session database. The session key identifies the entry in the database. If the database
already contains an entry with this session key, it should be overwritten.


@param sessionKey  [Input] Identifies the new session entry.
@param sessionData [Input] Contains information that the library will use to resume this
                           session. The library retains ownership of this buffer. Your function
						   must make a copy of the data.

@param sessionRef  [Input] Reference parameter that the library passes to your function. It is up
                           your function to determine how to use this parameter.

@returndesc Any error codes that your callback function generates are ignored by the library.
		   
@version TLS 1.0
*/

typedef 
SSL_EXPORT 
TLSErr (SSL_CALLCONV *TLSAddSessionFunc) (
    TLSBuffer sessionKey, 
    TLSBuffer sessionData, 
    void *sessionRef
    );

/*------------------------------------- TLSGetSessionFunc ----------------------------------*/
/**Template for a callback function which the library uses to get a session entry from the 
session database. The session key identifies the entry in the database.

@param sessionKey  [Input] Identifies the session entry to be retrieved.
@param sessionData [Output] Contains the session data. This buffer is allocated by the 
                            library.

@param sessionRef  [Input] Reference parameter that the library passes to your function. It is up 
                           to you function to determine how to use this parameter.
                        
@return TLSSessionNotFoundErr -- No entry with this session key was found.
@return TLSNoErr              -- Success.
		   
@version TLS 1.0
*/

typedef 
SSL_EXPORT 
TLSErr (SSL_CALLCONV *TLSGetSessionFunc) (
    TLSBuffer sessionKey, 
    TLSBuffer *sessionData, 
    void *sessionRef
    );


/*---------------------------------- TLSDeleteSessionFunc --------------------------------*/
/**Template for a callback function which the library uses to remove a session entry from the
session database. The session key identifies the session to be removed. 

The library removes a session from the database if the security of the session has been
compromised. It also removes a session if it is more than one week old or older than the
time set in TLSSetSessionExpiryTime(). 


@param sessionKey [Input] Identifies the session entry to be deleted.
                      
@param sessionRef [Input] Reference parameter that the library passes to your function. It is up
                          to your function to determine how to use this parameter.

@returndesc Any error codes that your callback function generates are ignored by the library.

@version TLS 1.0
*/

typedef 
SSL_EXPORT 
TLSErr (SSL_CALLCONV *TLSDeleteSessionFunc) (
    TLSBuffer sessionKey, 
    void *sessionRef
    );

/*-------------------------------- TLSCheckCertificateChainFunc ----------------------------*/
/**Template for a callback function which the library calls after it has
evaluated a certificate chain. If one or more of the certificates is rejected, the library
gives the reason why it was rejected in the parameter chainResult (see below). You
can then determine whether you want the handshake to continue by returning an error
code: <C>TLSErrNone</C> if you want to override the error and allow the handshake to
continue, or <C>chainResult</C> if you want the handshake to be aborted.

<B>Note</B>: If more than one error occurred while the certificates were being evaluated, the
      library will only return the most serious error in <C>chainResult</C>.

@param ctx          [Input] Pointer to the TLS context.
@param certChain    [Input] An array of DER encoded X.509 certificates,
                            server certificate first.
@param chainLen     [Input] The number of entries in the <C>certChain</C> array.

@param chainResult  [Input] The library uses this parameter to pass the result
                            of evaluating the <C>certChain</C> array. The following is a 
							list of possible error values, ranging from least to most 
							serious.
                           
TLSInvalidCertDatesErr     -- One or more of the certificates is no longer valid.
                              Either a certificate has expired or the current date
                              is earlier than the start date.

TLSCertNotTrustedErr       -- No certificate in the chain is trusted.

TLSBasicConstraintErr      -- One or more of the certificates has an extension which
                              is marked as critical, but has invalid basic constraints.

TLSCertKeyUsageErr         -- One or more of the certificates has a key usage
                              extension which prevents the library from
                              completing an operation on the chain.

TLSCertSignatureInvalid    -- One or more of the certificates contained a
                              signature which failed verification.

TLSNonMatchingCertChainErr -- There are one or more certificates in the chain
                              which contain a mismatch between the issuer name
                              and the subject name, i.e. the the issuer name of
                              a certificate is different from the subject name
                              of the certificate which follows this certificate
                              in the chain.


<B>Note</B>: The library treats all other error codes as fatal and terminates the
             handshake. These error codes will not be passed to the callback
             function. They include TLSBadCertificateErr,
             TLSUnknownCriticalExtensionErr and TLSCertificateChainLengthErr. 
				  
@param chainTrusted The chainTrusted parameter contains 1 if a trusted certificate,
                    either CA or server, was found in the path. If no trusted
                    certificate is found, a zero is returned. If <C>chainResult</C> is
                    equal to <C>TLSCertNotTrustedErr</C>, it will always return zero.
@param certChainRef A reference parameter passed by the library. This parameter
                    can be set by calling TLSSetCheckCertificateChainRef(). The library 
					does not manipulate this data. It is up your callback function to
					determine how it is used.

@version TLS 1.0
*/

typedef 
SSL_EXPORT 
TLSErr (SSL_CALLCONV *TLSCheckCertificateChainFunc) (
    TLSContext *ctx, 
    TLSBuffer certChain[], 
    uint32 chainLen, 
    TLSErr chainResult, 
    uint8 chainTrusted, 
    void *certChainRef
    );

#endif /* __TLSTYPE_H__ */
