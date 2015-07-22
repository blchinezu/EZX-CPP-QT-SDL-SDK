/*+
Release: SSL Plus 1.1.2b

Certicom, the Certicom logo, SSL Plus, and Security Builder are trademarks of
Certicom Corp.  Copyright (c) 1997-2002 Certicom Corp.  All rights reserved.
Protected by U.S. patents 5,787,028; 4,745,568;
5,761,305.  Patents pending.
-*/

/*+
 * tls.h - TLS api definitions.
 *
 * Description: This header file holds the prototypes and interface
 *  definitions for the following functions.
 *
 *      TLSContextSize()
 *      TLSInitContext()
 *      TLSDeleteContext()
 *      TLSSetCipherSuites()
 *      TLSSetRandomFunc()
 *      TLSSetRandomRef()
 *      TLSSetIORef()
 *      TLSSetReadFunc()
 *      TLSSetWriteFunc()
 *      TLSSetPeerID()
 *      TLSSetSessionRef()
 *      TLSSetAddSessionFunc()
 *      TLSSetGetSessionFunc()
 *      TLSSetDeleteSessionFunc()
 *      TLSSetSessionExpiryTime()
 *      TLSSetAlertFunc()
 *      TLSSetAlertRef()
 *      TLSSetCheckCertificateChainFunc()
 *      TLSSetCheckCertificateChainRef()
 *      TLSGenerateKeyAgreementParams()
 *      TLSAddTrustedCertificate()
 *      TLSHandshake()
 *      TLSClose()
 *      TLSWrite()
 *      TLSRead()
 *      TLSWriteNoCopy()
 *      TLSReadNoCopy()
 *      TLSPeekNextReadLength()
 *      TLSExtractCertificateNameItem()
 *      TLSNoCopyBufferSize()
 *      TLSAddECDSACertificate()
 *      TLSAddRSACertificate()
 *      TLSDeriveARC4Key()
 *      TLSSetECDSAPrivateKey()
 *      TLSSetRSAPrivateKey
 *      TLSSetPwdECDSAPrivateKey()
 *      TLSSetPwdRSAPrivateKey()
 *      TLSGetNegotiatedCipher()
 *      TLSGenerateRandom()
 *      TLSSetOption()
 *
 *-------------------------------------------------------------
 * Conditional compilations:
 *  None.
 *-------------------------------------------------------------
 * Notes:
 *  1. None.
 *
 * This software contains trade secrets and confidential information of Certicom Corp.
 * (c) Copyright Certicom Corp. 1997-1999
-*/
/* $Id: tls.h,v 2.13 2001/11/16 21:11:42 amartin Exp $ */


#ifndef __TLS_H__
#define __TLS_H__ 1

#ifdef _MSC_VER
    #pragma warning( disable : 4180 ) /* qualifier applied to function type has no meaning */
    #pragma warning( disable : 4201 ) /* nonstandard extension used : nameless struct/union */
    #pragma warning( disable : 4214 ) /* nonstandard extension used : bit field types other than int */
    #pragma warning( disable : 4100 ) /* unreferenced formal parameter */
    #pragma warning( disable : 4514 ) /* unreferenced inline function has been removed */  
#endif

#include "cdglobal.h"
#include "tlscnfg.h"
#include "tlstype.h"
#include "tlserr.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Tls cipher suites */
#define TLS_NULL_WITH_NULL_NULL                     0x0000
#define TLS_RSA_WITH_NULL_MD5                       0x0001
#define TLS_RSA_WITH_NULL_SHA                       0x0002
#define TLS_RSA_EXPORT_WITH_RC4_40_MD5              0x0003
#define TLS_RSA_WITH_RC4_128_MD5                    0x0004
#define TLS_RSA_WITH_RC4_128_SHA                    0x0005
#define TLS_RSA_EXPORT_WITH_RC2_CBC_40_MD5          0x0006
#define TLS_RSA_WITH_IDEA_CBC_SHA                   0x0007
#define TLS_RSA_EXPORT_WITH_DES40_CBC_SHA           0x0008
#define TLS_RSA_WITH_DES_CBC_SHA                    0x0009
#define TLS_RSA_WITH_3DES_EDE_CBC_SHA               0x000A
#define TLS_DH_DSS_EXPORT_WITH_DES40_CBC_SHA        0x000B
#define TLS_DH_DSS_WITH_DES_CBC_SHA                 0x000C
#define TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA            0x000D
#define TLS_DH_RSA_EXPORT_WITH_DES40_CBC_SHA        0x000E
#define TLS_DH_RSA_WITH_DES_CBC_SHA                 0x000F
#define TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA            0x0010
#define TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA       0x0011
#define TLS_DHE_DSS_WITH_DES_CBC_SHA                0x0012
#define TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA           0x0013
#define TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA       0x0014
#define TLS_DHE_RSA_WITH_DES_CBC_SHA                0x0015
#define TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA           0x0016
#define TLS_DH_anon_EXPORT_WITH_RC4_40_MD5          0x0017
#define TLS_DH_anon_WITH_RC4_128_MD5                0x0018
#define TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA       0x0019
#define TLS_DH_anon_WITH_DES_CBC_SHA                0x001A
#define TLS_DH_anon_WITH_3DES_EDE_CBC_SHA           0x001B
#define TLS_FORTEZZA_DMS_WITH_NULL_SHA              0x001C
#define TLS_FORTEZZA_DMS_WITH_FORTEZZA_CBC_SHA      0x001D
#define TLS_ECES_ECDSA_NULL_SHA                     0x002C
#define TLS_ECES_ECDSA_WITH_RC4_128_SHA             0x002D
#define TLS_ECES_ECDSA_WITH_DES_CBC_SHA             0x002E
#define TLS_RSA_WITH_AES_128_CBC_SHA                0x002F
#define TLS_DH_DSS_WITH_AES_128_CBC_SHA             0x0030 
#define TLS_DH_RSA_WITH_AES_128_CBC_SHA             0x0031 
#define TLS_DHE_DSS_WITH_AES_128_CBC_SHA            0x0032 
#define TLS_DHE_RSA_WITH_AES_128_CBC_SHA            0x0033
#define TLS_DH_anon_WITH_AES_128_CBC_SHA            0x0034
  /*Unimplemented ciphers 
   *
#define TLS_ECES_ECDSA_WITH_3DES_EDE_CBC_SHA        0x002F
#define TLS_ECES_ECNRA_NULL_SHA                     0x0030
#define TLS_ECES_ECNRA_WITH_RC4_128_SHA             0x0031
#define TLS_ECES_ECNRA_WITH_DES_CBC_SHA             0x0032
#define TLS_ECES_ECNRA_WITH_3DES_EDE_CBC_SHA        0x0033
#define TLS_ECDHE_ECDSA_NULL_SHA                    0x0034
 *
 */
#define TLS_ECDHE_ECDSA_WITH_RC4_128_SHA            0x0036
#define TLS_ECDHE_ECDSA_WITH_DES_CBC_SHA            0x0037
#define TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA       0x0038
#define TLS_ECDHE_ECDSA_EXPORT_WITH_DES40_CBC_SHA   0x0039
#define TLS_ECDHE_ECDSA_EXPORT_WITH_RC4_40_SHA      0x0040
#define TLS_ECDHE_ECNRA_NULL_SHA                    0x0041
#define TLS_ECDHE_ECNRA_WITH_RC4_128_SHA            0x0042
#define TLS_ECDHE_ECNRA_WITH_DES_CBC_SHA            0x0043
#define TLS_ECDHE_ECNRA_WITH_3DES_EDE_CBC_SHA       0x0044
#define TLS_ECDHE_ECNRA_EXPORT_WITH_DES40_CBC_SHA   0x0045
#define TLS_ECDHE_ECNRA_EXPORT_WITH_RC4_40_SHA      0x0046
#define TLS_ECDH_ECDSA_NULL_SHA                     0x0047
#define TLS_ECDH_ECDSA_WITH_RC4_128_SHA             0x0048
#define TLS_ECDH_ECDSA_WITH_DES_CBC_SHA             0x0049
#define TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA        0x004A
#define TLS_ECDH_ECNRA_NULL_SHA                     0x004B
#define TLS_ECDH_ECNRA_WITH_RC4_128_SHA             0x004C
#define TLS_ECDH_ECNRA_WITH_DES_CBC_SHA             0x004D
#define TLS_ECDH_ECNRA_WITH_3DES_EDE_CBC_SHA        0x004E
#define TLS_ECMQV_ECDSA_NULL_SHA                    0x004F
#define TLS_ECMQV_ECDSA_WITH_RC4_128_SHA            0x0050
#define TLS_ECMQV_ECDSA_WITH_DES_CBC_SHA            0x0051
#define TLS_ECMQV_ECDSA_WITH_3DES_EDE_CBC_SHA       0x0052
#define TLS_ECMQV_ECNRA_NULL_SHA                    0x0053
#define TLS_ECMQV_ECNRA_WITH_RC4_128_SHA            0x0054
#define TLS_ECMQV_ECNRA_WITH_DES_CBC_SHA            0x0055
#define TLS_ECMQV_ECNRA_WITH_3DES_EDE_CBC_SHA       0x0056
#define TLS_ECDH_anon_NULL_WITH_SHA                 0x0057
#define TLS_ECDH_anon_WITH_RC4_128_SHA              0x0058
#define TLS_ECDH_anon_WITH_DES_CBC_SHA              0x0059
#define TLS_ECDH_anon_WITH_3DES_EDE_CBC_SHA         0x005A
#define TLS_ECDH_anon_EXPORT_WITH_DES40_CBC_SHA     0x005B
#define TLS_ECDH_anon_EXPORT_WITH_RC4_40_SHA        0x005C
#define TLS_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA       0xFF84
#define TLS_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA       0xFF85

/* TlS protocol versions */
typedef enum {
    SSL_Version_Undetermined = 0,
    SSL_Version_3_0_With_2_0_Hello = 100,
    SSL_Version_3_0_Only = 101,
    TLS_Version_1_0_Only = 102,
    TLS_Version_1_0_With_2_0_Hello = 103,
    SSL_Version_2_0 = 0x0002,
    SSL_Version_3_0 = 0x0300,
    TLS_Version_1_0 = 0x0301
} TLSProtocolVersion;

/* Old protocol options */
#define SSLVersion2 SSL_Version_2_0
#define SSLVersion3 SSL_Version_3_0
#define TLSVersion1 TLS_Version_1_0

typedef enum
{   
    TLS_AllCrypto,
    TLS_StrongCryptoOnly,
    TLS_ExportCryptoOnly,
    TLS_ServerGatedCrypto
} TLSCryptoStrength;

typedef enum {

    /* 
     * Options for handling critical basic constraints in CA certs.
     * Note: This option only applies when the negotiated protocol is TLS.
	 *
     * The PKIX standard requires that basic constraints be marked critical in CA
     * certificates (see <http://www.ietf.org/rfc/rfc2459.txt>, section 4.2.1.10).
     * However, some websites have CA certificates which don't have basic constraints
     * marked critical. The default behavior of SSLPlus is to fail handshake
     * when this error occurs. 
     * This option allows developers choose to have SSLPlus either ignore this
     * requirement or enforce the requirement. The default behavior is to enforce
     * the requirement.
    */
    option_tls_enforce_basic_constraints=0,     /* CA certs must have critical basic constraints  */
    option_tls_no_enforce_basic_constraints,    /* above requirement is relaxed */ 


    /* 
     * Options for handling expired CA Certificates.
     *
     * There are many websites that use expired CA certificates even though newer 
     * certificates have been issued. With this option SSLPlus will substitue an 
     * expired CA certificate with an identical CA certificate which is not expired
     * if one exists in the list of trusted certificates. 
     *
     * With this option disabled, a certificate chain which contains an expired
     * CA certificate will generate the error TLSInvalidCertDatesErr in the 
     * certificate chain callback, even if the CA certificate is trusted.
     *
    */
    option_enable_expired_ca_cert_replacement,   
    option_disable_expired_ca_cert_replacement,
    
    /*  Options for enabling/disabling yielding
     *	This will allow the developer to turn yielding on or off for a TLS context. 
     *  The  default behavior will always be to have the yield callback
     *  disabled (Except for the RIM devices which require that
     *  yielding be supported at all time.). 
     *
     */

    option_enable_yield_callback,   
    option_disable_yield_callback,

    /* 
     * Option for removing the embedded MobileTrust root Certificates.
     *
     * When the context is initialize the MobileTrust root certificates
     * are installed into the list of trusted certificates. 
     * This default behavior can be overridden using this option
     * which removes the MobileTrust certs from the list of trusted certificates. 
     *
    */
    option_disable_mobiletrust_rootcerts

}TLSOption;
  
   


#ifndef SSLPLUS_API_DECLARED


/*
@section TLS Context Functions
@desc SSL Plus represents the state of a connection in a TLS context structure.
	  Each time your client application connects to a server, you must create
	  and initialize a context structure. This structure stores information such
	  as your local certificates, your private key and your preferred cipher
	  suites. You do not have to set the information in the structure directly;
	  the library provides functions for this purpose.

      When you terminate a connection using <C>TLSClose()</C>, you must 
	  free the resources allocated in the context structure using <C>TLSDeleteContext()</C>.
      
      The functions described in this section perform the following tasks:
      
          1.  Initialize the internal values of a new context structure.

	  2.  Set non-blocking I/O on a network connection.

	  3.  Set the preferred cipher suites for an SSL session.

	  4.  Set the preferred SSL/TLS protocol for an SSL session.

	  5.  Set the strength of cryptography to be used in an SSL session.

	  6.  Generate key agreement parameters.

	  7.  Set an identifying certificate (chain) for your application.

	  8.  Set trusted certificates for your application.

	  9.  Set a private key.

	  10. Set the length of time before an active session expires.

	  11. Set the identity of a server application (for session resumption).
	  
	  12. Free the resources allocated to a context structure.
	

*/

/*----------------------------------- TLSContextSize() ------------------------------------*/
/**Returns the size (in bytes) of a TLS context structure. You should call this
function to determine how much memory to allocate for a new TLS context.


<B>Note</B>: If you are developing your application on the Palm platform and calling the shared
library version of this function, please note the differences in the parameters and return
values listed below. See the <I>User's Guide</I> for more information.

@param readBufferSize [Input] The size of the read buffer to use in the TLS context.
                              The read buffer must be at least the maximum size of a 
							  record sent by the server. You should pick a size which suits 
							  your environment.
							                                
The Palm shared library version takes an additional parameter:

@param contextSize [Output] The size of the context structure (in bytes).

@return TLSContextSize The size of the TLS context structure (static library version only).
                                                     
The Palm shared library version of this function has a return type of TLSErr. Here are
the possible values:

@return TLSNoErr               -- Success.
@return TLSSharedLibNotOpenErr -- The shared library is not open.
@return TLSBadParameterErr     -- The <C>contextSize</C> parameter is NULL.
		   
@version TLS 1.0
*/

extern
SSL_EXPORT
uint32 
SSL_CALLCONV
TLSContextSize(
    uint16 readBufferSize
    );
    
/*----------------------------------- TLSInitContext() ------------------------------------*/
/**Sets the internal variables in a TLS context structure to their default values.
TLSInitContext() must be called before any other functions are called
with this context.

If the context structure pointed to by ctx is already in use, its
internal variables will be set without regard to its associated SSL connection.
The read buffer must be at least the maximum size of a record sent by the server.
If the buffer is too small then a <C>TLSOverflowErr</C> is received during the handshake
or during a call to TLSRead()/TLSReadNoCopy().

@param ctx            [Input] Pointer to the TLS context.
                           
@param readBufferSize [Input] The size of the read buffer provided to the
                              TLSContext which must be the same value provided
                              to the TLSContextSize() function.

@param cbRef          [Input] Optional user reference parameter which will be 
                              passed to CD_malloc(), CD_free(), and CD_realloc().

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSOverflowErr -- The read buffer is too small.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSInitContext(
    TLSContext *ctx, 
    uint16 readBufferSize,
    void *cbRef
    );
    
/*--------------------------------- TLSEnableNonBlocking() ------------------------------*/
/**Sets the TLS context to work with non-blocking I/O on the network connection. 
This function must be called after TLSInitContext().
If you set the context to work with non-blocking I/O then functions which read from
the network connection could return <C>TLSWouldBlockErr</C>.

@param ctx [Input] Pointer to the TLS context.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSMemoryErr   -- Memory allocation failure.
@return TLSNoErr       -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSEnableNonBlocking(
    TLSContext *ctx
    );


/*--------------------------------- TLSDeleteContext() -----------------------------------*/
/**Frees all the resources held by a TLS context structure. The
TLS context structure itself is not de-allocated; you should de-allocate it using the
same method you used to allocate the memory.

<B>Note</B>: You should call TLSClose() to close the connection before calling this function.

@param ctx [Input] Pointer to the TLS context.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSDeleteContext(
    TLSContext *ctx
    );

/*------------------------------------ TLSSetCipherSuites() --------------------------------*/
/**Sets the cipher suites that your application negotiates with during the handshake. 

The ciphers buffer should contain a list of your preferred cipher suites (each cipher suite
is identified by a two-byte constant). The cipher suites should be listed in order of preference,
with the first one in the list being the preferred choice. The length field in ciphers should be
set to the size of the list (in bytes). You can only set a maximum of four cipher suites.
See the <B>README</B> for a list of all the cipher suites that are available to your application.

@param ctx     [Input] Pointer to the TLS context.
                 
@param ciphers [Input] Contains the list of cipher suites. Each cipher suite is identified by a 
					   two-byte constant. You can only specify a maximum of four cipher suites.
					   The length field should be set to the size of the list (in bytes). This 
					   function makes a copy of the list, so your application is responsible 
					   for freeing any memory that was allocated to create the list.

@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr -- The <C>ciphers</C> parameter contains a NULL pointer.
@return TLSNoErr           -- Success.

@version TLS 1.0 
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetCipherSuites( 
    TLSContext *ctx,
    TLSBuffer *ciphers 
    );


/*------------------------------- TLSSetProtocolVersion() --------------------------------*/
/**Specifies which version of the SSL/TLS protocol should be negotiated with the server.
The default version is <C>TLS_Version_1_0</C>.

Possible values are:

<C>SSL_Version_3_0_With_2_0_Hello</C>

<C>SSL_Version_3_0_Only</C>

<C>TLS_Version_1_0_Only</C>

<C>TLS_Version_1_0_With_2_0_Hello</C>

<C>SSL_Version_2_0</C>

<C>SSL_Version_3_0</C>

<C>TLS_Version_1_0</C>

<B>Note:</B> This version of <B>SSL Plus for Embedded Systems</B> uses a different scheme to
determine which version of the SSL protocol to use with a server. This could prevent
your application from connecting to a server which uses an older version of <B>SSL Plus
for Desktop Systems</B> (up to and including version 3.1.0).

If you intend your client application to use <C>SSL_Version_3_0</C> with an older server
application that is running either <C>TLS_Version_1_0</C>, <C>SSL_Version_3_0_Only</C> or
<C>SSL_Version_3_0</C>, then you will not be able to make a connection. This is because
<C>SSL_Version_3_0</C> now behaves as <C>SSL_Version_3_0_With_2_0_Hello</C>, not as
<C>SSL_Version_3_0_Only</C>. The solution is to use <C>SSL3_Version_3_0_Only</C> in
your client application instead of <C>SSL3_Version_3_0</C> when connecting to these
servers.

You do not have to make this change if your server application uses version 3.1.1 (or
above) of <B>SSL Plus for Desktop Systems</B>.


@param ctx     [Input] Pointer to the TLS context.
@param version [Input] The protocol version. 

@return TLSNoErr           -- Success.
@return TLSBadParameterErr -- The <C>version</C> parameter is invalid.
@return TLSNullContext     -- The context parameter contains a NULL pointer.

@version TLS 1.0  
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetProtocolVersion(
    TLSContext *ctx,
    TLSProtocolVersion version
    );


/*------------------------ TLSSetCryptographicStrength() -----------------------------------*/
/**Sets the cryptographic strength of a connection. 

<C>TLS_AllCrypto</C>:         Enable cryptography of all strengths.

<C>TLS_StrongCryptoOnly</C>:  Enable only cipher suites with strong cryptography
                       (RSA keys 512-bit or greater, and DES/EC keys 40-bit or greater).
                      
<C>TLS_ExportCryptoOnly</C>:  Enable only cipher suites with 512-bit or weaker
                       RSA keys or 40-bit or weaker DES/EC key encryption.
                      
<C>TLS_ServerGatedCrypto</C>: Enable only export cipher suites except when
                       communicating with servers that possess certificates
                       which certify them as having the legal ability to use
                       stronger cryptography.

Note that the cryptographic strength setting places restrictions on which cipher 
suites are available to your application.

<C>TLS_ServerGated</C> implies that the library can only support strong cryptography
when the server has a special certificate which allows this. If the server does
not have such a certificate then only exportable cipher suites are supported
(if any are enabled). A client which uses this option attempts to connect and
only turn on strong ciphers when it sees that the server has a certificate with
this option. A server which uses this option only turns on strong ciphers if
the local certificate certifies that it is capable of strong cryptography.
Server gated cryptography only works for SSL 3.0. If SSL 2.0 is all that can be
negotiated or the server does not have the correct kind of certificate, this
option will act in the same way as <C>TLS_ExportCryptoOnly</C>. In non-export configurations,
the default setting for this option is <C>TLS_AllCrypto</C>.In export/international
configurations, the default setting is <C>TLS_ExportCryptoOnly</C>.
<C>TLS_StrongCryptoOnly</C> is not available in export/international configurations of
SSL Plus for Embedded Systems. 

@param ctx      [Input] Pointer to the TLS context.

@param strength [Input] Cryptographic strength (see above).

@return TLSBadParameterErr -- The <C>context</C> parameter contains a NULL pointer or the <C>strength</C>
                              setting is invalid.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetCryptographicStrength(
    TLSContext *ctx, 
    TLSCryptoStrength strength
    );


/*----------------------------- TLSGenerateKeyAgreementParams() ---------------------------*/
/**Pre-generates the key agreement parameters which are normally generated during the
handshake. This speeds up the handshake process. Call this function before TLSHandshake().

@param ctx [Input] Pointer to the TLS context.

@return TLSMemoryErr      -- Memory allocation failure.
@return TLSNegotiationErr -- A bad curve is provided in the certificate.
@return TLSCryptoErr      -- A computational error occurred at
                             the cryptographic layer.
@return TLSNoErr          -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSGenerateKeyAgreementParams(
    TLSContext *ctx
    );


/*------------------------------ TLSAddECDSACertificate() ----------------------------------*/
/**Adds a DER-encoded ECDSA X.509 certificate to the list of certificates. The certificate
can be either a server or CA certificate. A certificate added with this function will not be
considered trusted; it will still undergo ECDSA verifies when used.

This function includes a <C>noCopy</C> parameter for you to indicate whether the library
should allocate memory for the certificate or re-use the existing certificate pointer.

@param ctx         [Input] Pointer to the TLS context.
@param certificate [Input] The certificate.
@param parent      [Input] Flag to indicate if this certificate
                           is a parent to certificate previously added.
                           Non-zero to indicate it is a parent.
@param noCopy      [Input] Flag to indicate whether the library should
                           allocate memory for the certificate.
                           Set to 0 if memory should be allocated.
                           Set to 1 if the certificate pointer should be re-used.

@return TLSNullContext       -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr   -- A NULL certificate is provided.
@return TLSMemoryErr         -- Memory allocation failure.
@return TLSBadCertificateErr -- The certificate is invalid.
@return TLSNoErr             -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSAddECDSACertificate(
    TLSContext *ctx, 
    TLSBuffer *certificate,
    uint16 parent,
    uint16 noCopy
    );

/* For backward compatability define macro TLSAddCertificate() */
#define TLSAddCertificate(ctx, certificate, parent) TLSAddECDSACertificate(ctx, certificate, parent, 0) 

/*----------------------------- TLSAddRSACertificate() ----------------------------------*/
/**Adds a DER-encoded X.509 RSA certificate to the list of certificates.
The certificate can be either a server or CA certificate. A certificate
added with this function will not be considered trusted; it will still
undergo RSA verifies when used.

This function includes a <C>noCopy</C> parameter for you to indicate whether the library
should allocate memory for the certificate or re-use the existing certificate pointer.

@param ctx         [Input] Pointer to the TLS context.
@param certificate [Input] The certificate.
@param parent      [Input] Flag to indicate if this certificate is a parent
                           to the previously added certificate. Set to a
                           non-zero value to indicate that this is a parent.
@param noCopy      [Input] Flag to indicate whether the library should
                           allocate memory for the certificate. Set to
                           0 if memory should be allocated. Set to 1 if
                           the certificate pointer should be re-used.

@return TLSNullContext       -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr   -- Certificate was a NULL pointer or
                                points to zero-length data.
@return TLSMemoryErr         -- Memory allocation failure.
@return TLSBadCertificateErr -- The certificate is invalid.
@return TLSNoErr             -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSAddRSACertificate(
    TLSContext *ctx, 
    TLSBuffer *certificate,
    uint16 parent,
    uint16 noCopy
    );


/*----------------------------- TLSAddTrustedCertificate() ------------------------------*/
/**Adds a DER-encoded X.509 certificate to the list of trusted certificates. A copy of the 
certificate is made, and the caller retains ownership of the certificate data. The 
certificate can be either a server or a CA certificate. Calling this with a server certificate
prevents the signature from being verified. Calling this with a CA certificate prevents one or
more ECDSA verifications from occurring. 

@param ctx         [Input] Pointer to the TLS context.
@param certificate [Input] The trusted certificate.

@return TLSNullContext       -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr   -- The certificate parameter contains a NULL pointer.
@return TLSMemoryErr         -- Memory allocation failure.
@return TLSBadCertificateErr -- The certificate is invalid.
@return TLSNoErr             -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSAddTrustedCertificate(
    TLSContext *ctx, 
    TLSBuffer *certificate
    );
    

/*------------------------ TLSAddTrustedCertificateNoCopy() ---------------------------*/
/**Adds a DER-encoded X.509 certificate to the list of trusted certificates.
The certificate can either be a server or CA certificate. Calling this with
a server certificate will prevent any ECDSA verifies from occurring if, during
a handshake, the trusted certificate is presented; calling it with a CA
certificate will prevent one or more ECDSA verifies from occurring.
In contrast, untrusted certificates are always verified.

This function works in the same way as TLSAddTrustedCertificate() except
that it does not make a copy of the certificate data. This is useful when you
have a number of certificates and you do not want the memory duplicated in both
the application and the context. The caller retains ownership of the certificate
data (pointer).

@param ctx         [Input] Pointer to the TLS context.
@param certificate [Input] The trusted certificate.

@return TLSNullContext       -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr   -- A NULL certificate was provided.
@return TLSMemoryErr         -- Memory allocation failure.
@return TLSBadCertificateErr -- The certificate is invalid.
@return TLSNoErr             -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSAddTrustedCertificateNoCopy(
    TLSContext *ctx, 
    TLSBuffer *certificate
    );


/*------------------------------- TLSSetECDSAPrivateKey() ------------------------------------*/
/**Copies the private key (ECDSA) for the local identity.
The private key must match the public key in the certificate
for the local identity set with TLSAddECDSACertificate().
This function should be called for clients who require client authentication.

<B>Note</B>: This function is not available for the anonymous client.
      For private keys which are password-protected,
      use TLSSetPwdECDSAPrivateKey().

@param ctx        [Input] Pointer to the TLS context.
@param privateKey [Input] Points to the local private key.

@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr -- The parameter is NULL, has 0 length, or contains NULL data.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetECDSAPrivateKey(
    TLSContext *ctx, 
	TLSBuffer *privKey
    );

/* For backward compatability */
#define TLSSetPrivateKey(ctx, key)          TLSSetECDSAPrivateKey(ctx, key)

/*---------------------------- TLSSetRSAPrivateKey() ---------------------------------*/
/**Copies the private key (RSA) for the local identity.
The private key must match the public key in the certificate
for the local identity set with TLSAddRSACertificate().
This function should be called for clients who require client authentication.

<B>Note</B>: It is not necessary to specify all the components of the RSA key.
      It is sufficient to specify either
      
      1. 'n' and 'd', or

      2. 'p','q' and 'd'.
      
      In the first case the performance of private key operations could
      be up to four times slower.
      
<B>Note</B>: This function is not available for the anonymous client.
      For private keys which are password-protected, use
      TLSSetPwdRSAPrivateKey().
      
@param n    [Input] Modulus.
@param e    [Input] Public exponent.
@param d    [Input] Private exponent.
@param p    [Input] Private exponent basis 'p'.
@param q    [Input] Private exponent basis 'q'.
@param dp   [Input] Private exponent mod p-1.
@param dq   [Input] Private exponent mod q-1.
@param qinv [Input] q inverse mod p.

@return TLSNullContext  -- The context parameter contains a NULL pointer.
@return TLSBadParameter -- A parameter is NULL, has zero length, or contains NULL data.
@return TLSNoErr        -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetRSAPrivateKey(
    TLSContext *ctx, 
	TLSBuffer *n,
	TLSBuffer *e,
	TLSBuffer *d,
	TLSBuffer *p,
	TLSBuffer *q,
	TLSBuffer *dp,
	TLSBuffer *dq,
	TLSBuffer *qinv
    );


/*-------------------------- TLSSetSessionExpiryTime() ----------------------------*/
/**Sets the length of time (in seconds) before a session expires in the session database. The
default expiry period is one week.

@param ctx               [Input] Pointer to the TLS context.

@param sessionExpiryTime [Input] The expiry time (in seconds).

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoErr       -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetSessionExpiryTime( 
    TLSContext *ctx, 
    uint32 sessionExpiryTime
    );


/*------------------------------- TLSSetPeerID() ---------------------------------*/
/**Sets the identity of a TLS server. The library uses the <C>peerID</C> to look up
previous sessions with this server in the session database. If it finds an entry
for this server in the database, it attempts to resume the session using the 
information contained within it. You can set a unique identity for the server
by concatenating the its IP address and port number.

The library uses your callback functions to add, remove and retrieve information
from the session database. If no previous session with this server exists in the 
database, the library uses your callback function to add a new entry.

<B>Notes</B>:
Only TLS client applications need to call this function. If you are developing a 
client application and you do not call this function, the library will not
attempt to resume sessions with servers.

@param ctx    [Input] Pointer to the TLS context.
   
@param peerID [Input] Identifier for a TLS server. This should be a 
                      representation of the server's IP address and port number
					  or some other unique value. The <C>peerID.length</C> must be less
					  than or equal to 32 bytes. 
					  The library makes a copy of this buffer, so the caller is
					  responsible for freeing any memory that was allocated.

@return TLSBadParameterErr -- The <C>peerID</C> parameter is NULL or <C>peerID.length</C> is
                              greater than 32 bytes or <C>peerID.data</C> is invalid.
@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSNoError         -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetPeerID(
    TLSContext *ctx, 
    TLSBuffer peerID
    );


/*
@section Private Key Storage Functions
@desc The functions listed below may be used to securely store an
      elliptic curve private key created with Certicom's
      Security Builder SDK.
      
      <B>Note</B>: These functions are not available in the anonymous library:
      
*/ 
 
/*------------------------------- TLSDeriveARC4Key() ---------------------------------*/
/**Generates ARC4 key material from a passphrase.
The key derivation algorithm is as follows:

1.Pad the passphrase out to 128 bytes with 0xaa.

2.Compute the SHA-1 message digest of the padded passphrase from Step 1.

3.Use the SHA-1 message digest from Step 2 as the first 20 bytes of key material.

4.Pad the passphrase out to 128 bytes with 0x55.

5.Compute the SHA-1 message digest of the padded passphrase from Step 4.

6.Use the SHA-1 message digest from Step 5 as the next 20 bytes of key material.

This function can generate at most 40 bytes of key material.

@param ctx    [Input] Pointer to the TLS context.
@param passphrase [Input] Points to the password used to decrypt the private key.
@param derivedKey [Input/Output] Points to the buffer for the derived key.
                                 On input <C>derivedKey.length</C> specifies
                                 the number of bytes of key material to
                                 generate (MAX = 2 * 20). On output
                                 <C>derivedKey.length</C> will contain the
                                 number of bytes generated and
                                 <C>derivedKey.data</C> will contain the derived key.

@return TLSCryptoErr       -- A computational error occurred at
                              the cryptographic layer.
@return TLSBadParameterErr -- A parameter is invalid (NULL, invalid length or data).
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSDeriveARC4Key(
    TLSContext *ctx,
    const TLSBuffer *passphrase,
    TLSBuffer *derivedKey
    );


/*-------------------------------- TLSSetPwdECDSAPrivateKey() --------------------------------*/
/**Copies the private key for the local identity.
The private key is password protected using ARC4 encryption.
The password protected private key is decrypted and a copy is stored
in the context. The private key must match the public key in the
certificate for the local identity which was set with
TLSAddECDSACertificate().

This function is similar to TLSSetECDSAPrivateKey(), with the
exception that the private key is encrypted using the ARC4 encryption scheme.

@param ctx                 [Input] Points to the TLS context.
                                   
@param protectedPrivateKey [Input] Points to the local private key.
@param password            [Input] Points to the password used to
                                   decrypt the private key.

@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr -- The parameter is a NULL pointer,
                              has zero length, or contains NULL data.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetPwdECDSAPrivateKey(
    TLSContext *ctx, 
    TLSBuffer *protectedPrivateKey,
    TLSBuffer *password
    );

/* For backward compatability define macro TLSSetPwdPrivateKey() which calls TLSSetLocalPrivateKey() */
#define TLSSetPwdPrivateKey(ctx, key, pwd)  TLSSetPwdECDSAPrivateKey( ctx, key, pwd )

/*------------------------------- TLSSetPwdRSAPrivateKey() ---------------------------------*/
/**Copies the RSA private key for the local identity. The private key is pasword protected
using ARC4 encryption. The password protected private key is decrypted and a copy is
stored in the context. The private key must match the public key in the certificate for the
local identity which was set with TLSAddRSACertificate().

Note: It is not necessary to specify all components of the RSA key.
      It is sufficient to specify either
       
      1. 'n' (the modulus) and 'd' (the private exponent), or

      2. 'p' (private exponent basis 'p'), 'q' (private exponent basis 'q')
         and 'd' (private exponent).
         
      In the first case the performance of private key operations could
      be up to four times slower.
      
@param ctx                 [Input] Pointer to the TLS context.
@param protectedPrivateKey [Input] Pointer to the local private key.
@param password            [Input] Pointer to the password used to
                                   decrypt the private key.

@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr -- The parameter is a NULL pointer,
                              is zero length or contains NULL data.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetPwdRSAPrivateKey(
    TLSContext *ctx, 
    TLSBuffer *protectedPrivateKey,
    TLSBuffer *password
    );


/*
@section Certificate Functions
@desc The functions in this section allow you to extract information
      from a certificate.
      
*/

/*--------------------------- TLSExtractCertificateNameItem() ----------------------------*/
/**Extracts a subject RDN from a DER-encoded certificate (usually provided
by the certificate callback).

@param certificate [Input] The certificate to be parsed.
@param which       [Input] A subject RDN such as <C>TLSCommonName</C>. Please see the header file
                           tlstype.h for a complete list of RDN values.
@param result      [Output] A buffer containing the requested value.

@return TLSBadParameterErr   -- A NULL certificate or result is provided.
@return TLSBadCertificateErr -- The certificate is invalid.
@return TLSOverflowErr       -- Insufficient space is provided for the result.
@return TLSNoErr             -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSExtractCertificateNameItem(
    TLSBuffer *certificate, 
    TLSCertificateNameItem which, 
    TLSBuffer *result
    );


/*
@section Data Exchange
@desc Once the network connection has been made and the TLS context has been configured, your
      application can begin to exchange data with the peer. 

	  The functions described in this section perform the following tasks:

	  1. Perform a SSL handshake with the peer.

	  2. Write data to the network connection.

	  3. Read data from the network connection.

	  4. Close the SSL session with the peer.
      
*/
 
/*---------------------------------- TLSHandshake() ------------------------------------------*/
/**Initiates a TLS handshake with a peer. When the handshake is complete, you can use TLSRead()
and TLSWrite() to exchange data with the peer.

If you are using blocking I/O, TLSHandshake() does not return until the handshake is complete.
If you are using non-blocking I/O, TLSHandshake() could return <C>TLSWouldBlockErr</C>. If this is the
case, you should keep calling TLSHandshake() until it returns <C>TLSNoErr</C>.

TLSHandshake() calls your read() and write() callback functions to exchange handshaking data
with the peer. Any error codes that these functions generate are passed back to your application.

@param ctx [Input] Pointer to the TLS context.

@return TLSWouldBlockError    -- The read() or write() callback cannot complete
                                 the request (non-blocking I/O). 
								  						            
@return TLSNullContext        -- The context parameter contains a NULL pointer.
@return TLSUnknownState       -- ctx contains an unrecognized state.
@return TLSOverflowErr        -- The read buffer in the <C>ctx</C> is too small
                                 for the next record.
@return TLSNoErr              -- Success.
@return TLSStateErr           -- Internal error.
@return TLSVersionErr         -- Unsupported TLS version.
@return TLSNegotiationErr     -- An error occurred during the negotiation.
@return TLSCryptoErr          -- A computational error occurred at
                                 the cryptographic layer.
@return TLSBadFinishedMessage -- The finish message is corrupted.

@version TLS 1.0 
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSHandshake(
    TLSContext *ctx
    );


/*-------------------------------- TLSGetNegotiatedCipher() -------------------------------*/
/**Gets the cipher suite that was negotiated during the handshake. The cipher suite is identified
by a two-byte constant.

@param ctx         [Input] Pointer to the TLS context.

@param cipherSuite [Output] Pointer to the negotiated cipher suite.

@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr -- The <C>cipherSuite</C> parameter is NULL or the 
                              negotiated cipher is NULL.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSGetNegotiatedCipher(
    TLSContext *ctx,
    uint16 *cipherSuite
    );


/*------------------------------- TLSGetProtocolVersion() ------------------------------------*/
/**Gets the version of the SSL/TLS protocol that was negotiated during the handshake.

@param ctx     [Input] Pointer to the TLS context.

@param version [Output] The version of the SSL/TLS protocol that was negotiated during
                        the handshake.

@return TLSNullContext     -- The context parameter contained a NULL pointer.
@return TLSBadParameterErr -- The <C>version</C> parameter contained a NULL pointer.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSGetProtocolVersion(
    TLSContext *ctx,
    TLSProtocolVersion *version
    );


/*------------------------------- TLSGetMasterSecret() ------------------------------------*/
/**Gets the Master Secret used in key generation process.

@param ctx [Input] Pointer to the TLS context.

@param buf [Output] Pointer to a TLSBuffer that will contain the Master_Secret in buf->data.
		    The buf is pre-allocated by the caller who is responsible
                    for freeing the memory.

@return TLSStateErr          -- Handshake not finished 
@return TLSBadParameterErr   -- A NULL buffer is provided
@return TLSNullContext       -- A NULL Context.
@return TLSNoErr             -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSGetMasterSecret(
    TLSContext *ctx,
    TLSBuffer *buf
    );

/*-------------------------------------- TLSClose() ----------------------------------------*/
/**Closes the TLS session with the peer by sending a "good-bye kiss" message. 
If the session is not properly closed, it cannot be resumed.

This function causes a "close_notify" alert to be sent to the peer, which indicates that it
should not expect any further communications. It should be called when no errors have 
occurred on the connection. If the peer closes the connection first, TLSConnectionClosedGraceful
is returned from TLSRead(). In this case, calling TLSClose() is usually not necessary because
the peer closes its connection after sending the "goodbye kiss", without waiting to receive 
one from your end. TLSClose() has no effect on the underlying network connection: it must still
be closed manually with its native API. If the network connection is closed without first
calling TLSClose(), the peer may treat this session as unreliable and refuse to cache the 
information necessary to resume it.


@param ctx [Input] Pointer to the TLS context.

@return TLSNullContext  -- The context parameter contains a NULL pointer.
@return TLSNullCallback -- TLSSetWriteFunc() not previously called.
@return TLSNoErr        -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSClose(
    TLSContext *ctx
    );
    

/*--------------------------------- TLSWrite() ---------------------------------*/
/**Writes data to a TLS connection.


@param data   [Input] Pointer to the block of data to be written. Your application is
                      responsible for freeing this buffer.

@param length [Input/Output] The number of bytes to be written. Replaced with the
                             number of bytes actually written.

@param ctx    [Input] Pointer to the TLS context.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSIOErr -- I/O error from the callback function.
@return TLSNoErr -- Success.
            
@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSWrite(
    void *data, 
    uint32 *length, 
    TLSContext *ctx
    );
    

/*--------------------------------- TLSWriteNoCopy() ------------------------------------*/
/**Writes data to a TLS connection, but re-uses the output buffer for encrypting the data
rather than allocating additional space. This can result in better performance on some older
Palm devices, where memory allocation is time consuming.

The output buffer must be at least <I>n</I> bytes longer than the data being written. To get the 
value of <I>n</I>, call TLSNoCopyBufferSize().


@param data        [Input] Pointer to the block of data to be written. Your application is
                           is responsible for freeing this buffer.
          
@param length      [Input/Output] Pointer to the number of bytes to
                                  be written. Replaced with
                                  the number of bytes actually written.

@param totalLength [Input] The size of the <C>data</C> buffer. The size of the buffer
                           must be at least <I>n</I> bytes larger than length. To get 
						   the value of <I>n</I>, call TLSNoCopyBufferSize().

@param ctx         [Input] Pointer to the TLS context.
                           
@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSOverflowErr -- The <C>totalLength</C> parameter is too small.
@return TLSIOErr -- I/O error from the callback function.
@return TLSNoErr -- Success.


@version TLS 1.0 
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSWriteNoCopy(
    void *data, 
    uint32 *length, 
    uint32 totalLength, 
    TLSContext *ctx
    );
    
/*------------------------------------- TLSRead() ------------------------------------------*/
/**Reads data from a TLS connection.

If the I/O callback function returns <C>TLSWouldBlockErr<C>, you should keep calling TLSRead() to 
read the remaining data. You can call TLSPeekNextReadLength() to determine how much data
is left to be read.

@param data   [Output] Pointer to the input buffer. 
@param length [Input/Output] The size of the <C>data</C> buffer.
                             Replaced with the number of bytes
                             actually read.

@param ctx    [Input] Pointer to the TLS context.
                      

@return TLSWouldBlockError          -- The read callback could not fully satisfy the request.
                                                                            
@return TLSConnectionClosedGraceful -- The peer ended the TLS session.
                                       
@return TLSOverFlowErr              -- The data buffer is not big enough for the new data.
                                       Allocate more memory for the buffer and call TLSRead()
									   again. You can find the size of the new data by 
									   calling TLSPeekNextReadLength().

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSIOErr -- I/O error from the callback function.
@return TLSNoErr -- Success. 
 

@version TLS 1.0						  
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSRead(
    void *data, 
    uint32 *length, 
    TLSContext *ctx
    );
    
/*--------------------------------- TLSReadNoCopy() ------------------------------------------*/
/**Reads data from a TLS connection, but re-uses the input buffer for encrypting the data
rather than allocating additional space. This can result in better performance on some older
Palm devices, where memory allocation is time consuming.

If the I/O callback function returns TLSWouldBlockErr, you should keep calling TLSRead() to
read the remaining data. You can call TLSPeekNextReadLength() to determine how much data is
left to be read.

@param data        [Output] Pointer to the input buffer.

@param length      [Input/Output] The size of the <C>data</C> buffer. Replaced with the 
                                  number of bytes actually read.
                                  
@param totalLength [Input] The size of the <C>data</C> buffer. This should be at least 
                           <I>n</I> bytes long, where <I>n</I> is obtained from
						   TLSNoCopyBufferSize().
                                                     
@param ctx         [Input] Pointer to the TLS context.
                           

@return TLSWouldBlockError          -- The read callback could not fully satisfy the request. 
                                       
@return TLSConnectionClosedGraceful -- The peer ended the TLS session.
                                       
@return TLSOverFlowErr              -- The data buffer is not big enough for the new data.
                                       Allocate more memory for the buffer and call TLSRead()
									   again. You can find the size of the new data by
									   calling TLSPeekNextReadLength().

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSIOErr -- I/O error from the callback function.
@return TLSNoErr -- Success.
                                       
                                       

@version TLS 1.0						  
*/
 
extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSReadNoCopy(
    void *data, 
    uint32 *length, 
    uint32 totalLength, 
    TLSContext *ctx
    );
    

/*------------------------------ TLSNoCopyBufferSize() ----------------------------------*/
/**Gets the number of additional bytes required to use the TLSReadNoCopy() and TLSWriteNoCopy() 
functions.

You should call this function to determine how much extra memory to allocate in using
these functions.

<B>Note</B>: If you are developing your application on the Palm platform and calling the shared
      library version of this function, please note the differences in the parameters
      and return values listed below. See the User's Guide for more information.

@param None (for the static library version).

For the Palm shared library version:

@param refNum     [Input] The library reference number.
@param noCopySize [Output] The number of additional bytes required.

@returndesc The number of additional bytes required (static library version only).
@returndesc The Palm shared library version of this function has a return type of
            TLSErr. Here are the possible values:
@return TLSNoErr               -- Success.
@return TLSSharedLibNotOpenErr -- The shared library is not open.
@return TLSBadParameterErr     -- The noCopySize parameter is NULL.

@version TLS 1.0
*/

extern
SSL_EXPORT
uint32 
SSL_CALLCONV
TLSNoCopyBufferSize(
    void
    );


/*---------------------------- TLSPeekNextReadLength() -------------------------------*/
/**Gets the size of the next record available for reading. The size of the record is given
by <C>length</C>. 

To read this record, call TLSRead(), or call TLSReadNoCopy() with a buffer of size <C>length</C>
plus an additional <I>n</I> bytes where <I>n</I> is obtained from TLSNoCopyBufferSize(). 


@param ctx    [Input] Pointer to the TLS context.
@param length [Output] The length (in bytes) of the next record available for reading.
                     
  
@return TLSNullContext      -- The context parameter contains a NULL pointer.
@return TLSNoErr            -- Success.
 	

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSPeekNextReadLength(
    TLSContext *ctx, 
    uint32 *length
    );


/*
@section Miscellaneous Functions
@desc 
*/
 
/*------------------------------------ TLSLibClose() -----------------------------------------*/
/**Releases additional resources that are allocated for use of the Palm OS
shared library.

This function is only valid if you are using the Palm OS shared library configuration of
<B>SSL Plus for Embedded Systems</B>. In all other configurations, this function does nothing.

@param None

@returndesc This function returns OS generated error code.
            A value of 0 usually means that there was not error.
            If the function returns a non-zero value, consult your Palm OS documentation.
            
@version TLS 1.0   
*/
 
extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSLibClose(
    void
    );


/*----------------------------------- TLSLibVersion() ----------------------------------------*/
/**Returns the current version of the <B>SSL for Embedded Systems</B> library.  The 
string returned contains the major, minor, and patch level version numbers. For example, 
version 1.0.10 would return the values major = 1, minor = 0, and patch level = 10.

@param bufferLen [Input] On input contains the size of the <C>versionString</C> buffer. 
                         On output contains the number of bytes copied into the <C>versionString</C> buffer. 
       			         On failure due to <C>TLSOverflowErr</C>, the size of the <C>versionString</C> buffer 
                         is returned. 
@param versionString [Output] Points to the buffer for the version string. Restricted to non-NULL values.

@return TLSNoErr                -- Success.
@return TLSBadParameterErr      -- Either <C>major</C> or <C>minor</C> was NULL.
@return TLSOverflowErr          -- The buffer length <C>bufferLen</C> is too small.
@return TLSSharedLibFailOpenErr -- The shared library was not opened correctly.

@version TLS 1.0
*/
extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSLibVersion (
    uint16 *bufferLen,
    char *versionString
    ); 

/*----------------------------------- TLSSetOption() --------------------------------*/
/**This function sets options which affect the internal processing of the library.

A list of the available options is given below:

1. <C>option_tls_enforce_basic_constraints</C>, <C>option_tls_no_enforce_basic_constraints</C>

The PKIX standard requires that basic constraints be marked critical in CA
certificates.
However, some websites have CA certificates which don't have basic constraints
marked as critical. The default behavior of SSL Plus is to abort a handshake
when this situation occurs. 
This option allows developers to set whether SSL Plus ignores this
requirement or enforces this requirement. The default behavior is to enforce
the requirement.
    
<B>Note:</B> This option only applies when the negotiated protocol is TLS.

2. <C>option_enable_expired_ca_cert_replacement</C>, <C>option_disable_expired_ca_cert_replacement</C>

There are many websites that use expired CA certificates even though newer 
certificates have been issued. With this option SSL Plus substitutes an 
expired CA certificate with an identical CA certificate which has not expired
if one exists in the list of trusted certificates. 
With this option disabled, a certificate chain which contains an expired
CA certificate generates the error <C>TLSInvalidCertDatesErr</C> in the 
certificate chain callback, even if the CA certificate is trusted.

3. <C>option_disable_mobiletrust</C>

When the context is initialized, the MobileTrust root certificates
are installed into the list of trusted certificates. 
This default behavior can be overridden by setting this option
which removes the MobileTrust certs from the list of trusted certificates. 

@param ctx     [Input] Pointer to the TLS context.
                 
@param option [Input] The Option to enable.

@return TLSBadParameterErr -- A parameter contained a NULL pointer or invalid data.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetOption(
    TLSContext *ctx, 
    TLSOption option
    );


/*
@section Assigning Application Callbacks
@desc SSL Plus for Embedded Systems allows an application to set up callback
      functions to be used by the library. 

	  These functions perform the following tasks:

      1. Provide a source of random data for the library.

	  2. Write data to the network connection.

	  3. Read data from the network connection.

	  4. Handle alert messages from the library.

	  5. Add a session entry to the database.

	  6. Get a session entry from the database.

	  7. Delete a session entry from the database.

	  8. Handle certificate verification errors.

      
*/


/*---------------------------------- TLSSetRandomFunc() ---------------------------------*/
/**Sets the callback function which the library uses to obtain a random number.


@param ctx    [Input] Pointer to the TLS context structure.

@param random [Input] Pointer to a callback of type TLSRandomFunc.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetRandomFunc(
    TLSContext *ctx, 
    TLSRandomFunc random
    );
    

/*---------------------------------- TLSSetRandomRef() ---------------------------------------*/
/**Sets the reference parameter that the library passes to your random callback function. It is up 
to your callback function to determine how to use this parameter.

@param ctx       [Input] Pointer to the TLS context.
                        
@param randomRef [Input] The reference parameter.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetRandomRef(
    TLSContext *ctx, 
    void* randomRef
    );
    
/*---------------------------------- TLSRandomCallback() ---------------------------------*/
/**This function is an example of random callback you can use to generate random data in
your application. You can use this function as it is, or you can modify it for your own
purposes. This function uses TLSGenerateRandom() to read seed data for the PRNG.

<B>Note</B>: This function is now available in all implementations of the TLS library.

@param data      [Input/Output] Buffer to fill with random data.
                                data.length specifies the number
                                of bytes of random data required.
@param randomRef [Input] Value specified in TLSSetRandomRef()
                         when the context is initialized.
                         This parameter is not used.
                         
@return TLSCryptoErr -- A computational error occurred at
                        the cryptographic layer.
@return TLSNoErr     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSRandomCallback(
   TLSBuffer data,
   void *randomRef
);


/*----------------------------------- TLSGenerateRandom() --------------------------------*/
/**This function takes a buffer of seed data and generates pseudo-random data. This is a
utility function that can be called from within TLSRandomCallback().

@param seed   [Input] Pointer to the seed to be used by the PRNG.
@param random [Input/Output] Pointer to a buffer which will contain
                             the random data. On input, you should
                             set the length field of this buffer to
                             the number of bytes of random data that
                             you require. After the function has
                             finished, this field will contain the
                             actual number of bytes generated.

@return TLSCryptoErr       -- A computational error occurred at
                              the cryptographic layer.
@return TLSBadParameterErr -- A parameter contained a NULL pointer or invalid data.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSGenerateRandom(
    const TLSBuffer *seed,
    TLSBuffer *random,
    void *cbRef
    );

/*---------------------------------- TLSSetIORef() -------------------------------------*/
/**Sets the reference parameter that the library passes to your I/O callback functions.
It is up to the callback functions to determine how <C>ioRef</C> is used.

@param ctx   [Input] Pointer to the TLS context.
  
@param ioRef [Input] The reference parameter.
         

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetIORef(
    TLSContext *ctx, 
    void *ioRef
    );
    

/*--------------------------------- TLSSetReadFunc() -----------------------------------*/
/**Sets the callback function that the library uses to read data from the network connection.
The callback function should be of type TLSIOFunc.

@param ctx  [Input] Pointer to the TLS context.
        
@param read [Input] Pointer to the callback function.
                    

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetReadFunc(
    TLSContext *ctx, 
    TLSIOFunc read
    );

    
/*--------------------------------- TLSSetWriteFunc() ----------------------------------*/
/**Sets the callback function that the library uses to write data to the network connection.
The callback function should be of type TLSIOFunc.

@param ctx   [Input] Pointer to the TLS context.
                     
@param write [Input] Pointer to the callback function.
                     

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetWriteFunc(
    TLSContext *ctx, 
    TLSIOFunc write
    );
    

/*---------------------------- TLSSetAlertFunc() ---------------------------------------*/
/**Sets the callback function that the library uses to send alert messages to your application.
This callback is optional.

@param ctx       [Input] Pointer to the TLS context.
            
@param alertFunc [Input] Pointer to the callback function.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetAlertFunc(
    TLSContext *ctx, 
    TLSAlertFunc alertFunc
    );


/*--------------------------------- TLSSetAlertRef() -----------------------------------*/
/**Sets the reference parameter that the library passes to your alert callback function.

@param ctx      [Input] Pointer to the TLS context.
                        
@param alertRef [Input] The reference parameter.
                        

@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr -- The <C>alertRef</C> parameter is NULL.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetAlertRef(
    TLSContext *ctx,
    void *alertRef
    );


/*---------------------------- TLSSetAddSessionFunc() ----------------------------------*/
/**Sets the callback function that the library uses to add an entry to the session database.
The library stores enough information to be able to resume the session. The callback function
should be of type TLSAddSessionFunc.

<B>Note</B>:
If you do not set this callback, the library will not attempt to resume any sessions.

@param ctx        [Input] Pointer to the TLS context.

@param addSession [Input] Pointer to the callback function.
                          
@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetAddSessionFunc(
    TLSContext *ctx, 
    TLSAddSessionFunc addFunc
    );
    

/*------------------------------ TLSSetSessionRef() ------------------------------------*/
/**Sets the reference parameter that the library passes to your session callback functions.
The reference parameter is shared between the TLSAddSessionFunc(), TLSDeleteSessionFunc()
and TLSGetSessionFunc() callback functions. The reference parameter is not used by the 
library. It is up to the callback function to determine how it should be used.


@param ctx        [Input] Pointer to the TLS context.
                  
@param sessionRef [Input] The reference parameter.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetSessionRef(
    TLSContext *ctx, 
    void *sessRef
    );
    

/*---------------------------- TLSSetGetSessionFunc() ----------------------------------*/
/**Sets the callback function that the library uses to get an entry from the session database.
The callback function should be of type TLSGetSessionFunc.

<B>Note</B>:
If you do not set this callback, the library will not attempt to resume any sessions.

@param ctx        [Input] Pointer to the TLS context.
                       
@param getSession [Input] Pointer to the callback function.

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetGetSessionFunc(
    TLSContext *ctx, 
    TLSGetSessionFunc getFunc
    );
    

/*----------------------------- TLSSetDeleteSessionFunc() ------------------------------*/
/**Sets the callback function that the library uses to delete an entry from the session
database. The callback function should be of type TLSDeleteSessionFunc.

<B>Note</B>:
If you do not set this callback, the library will not attempt to resume any sessions.

@param ctx           [Input] Pointer to the TLS context.
                          
@param deleteSession [Input] Pointer to the callback function.
                             

@return TLSNullContext -- The context parameter contains a NULL pointer.
@return TLSNoError     -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetDeleteSessionFunc(
    TLSContext *ctx, 
    TLSDeleteSessionFunc deleteFunc
    );
    

/*----------------------- TLSSetCheckCertificateChainFunc() ----------------------------*/
/**Sets the callback function that the library calls when it receives a certificate from
the server during the handshake. You can use the callback function to override any 
validation errors that the library found when it examined the certificate. This callback 
is optional. If you do not set this callback, you can still examine the certificate after
the handshake is complete.

@param ctx       [Input] Pointer to the TLS context.

@param chainFunc [Input] Pointer to the callback function.

@return TLSNullContext  -- The context parameter contains a NULL pointer.
@return TLSNullCallback -- The <C>chainFunc</C> parameter contains a NULL pointer.
@return TLSNoErr        -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetCheckCertificateChainFunc(
    TLSContext *ctx, 
    TLSCheckCertificateChainFunc chainFunc
    );


/*------------------------ TLSSetCheckCertificateChainRef() ---------------------------*/
/**Sets the reference parameter that the library passes to your certificate callback
function. It is up to the callback function to determine how to use this parameter.

@param ctx          [Input] Pointer to the TLS context.
          
@param certChainRef [Input] The reference parameter.

@return TLSNullContext     -- The context parameter contains a NULL pointer.
@return TLSBadParameterErr -- The <C>certChainRef</C> parameter is NULL.
@return TLSNoErr           -- Success.

@version TLS 1.0
*/

extern
SSL_EXPORT
TLSErr 
SSL_CALLCONV
TLSSetCheckCertificateChainRef(
    TLSContext *ctx,
    void* certChainRef
     );

#endif  /* SSLPLUS_API_DECLARED */

#ifdef __cplusplus
}
#endif

#endif /* __TLS_H__ */
