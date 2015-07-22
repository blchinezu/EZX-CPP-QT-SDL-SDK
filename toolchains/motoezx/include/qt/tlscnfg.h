/*+
Release: SSL Plus 1.1.2b

Certicom, the Certicom logo, SSL Plus, and Security Builder are trademarks of
Certicom Corp.  Copyright (c) 1997-2002 Certicom Corp.  All rights reserved.
Protected by U.S. patents 5,787,028; 4,745,568;
5,761,305.  Patents pending.
-*/

/*+
 * tlscnfg.h - TLS configuration.
 *
 * Description: This module holds the defaults for all preprocessor
 *  options.
 *
 *
 *-------------------------------------------------------------
 * Conditional compilations:
 *
 *  PALM
 *      Indicates if compilation for Palm O/S
 *      = 1 if Palm O/S
 *      = 0 otherwise
 *      Default:
 *          = 0
 *
 *  TLS_CONFIG_PALM_SDK_VERSION
 *      Indicates if the Palm O/S SDK version
 *      = 350 if version 3.5 or later of the Palm O/S SDK
 *      = 300 if version 3.0
 *      Default:
 *          = 350
 *  
 *  TLS_CONFIG_ECC
 *      Used to indicate whether to support ECC.
 *      = 1 if ECC is supported
 *      = 0 otherwise
 *      Default:
 *          = 1
 *  
 *  TLS_CONFIG_PALM_SHARED_TLSLIB
 *      Used to indicate whether to compile TLS library as a 
 *      shared library for Palm O/S.
 *      = 1 if Palm O/S Shared TLS library
 *      = 0 otherwise
 *      Default:
 *          = 0
 *  
 *  TLS_CONFIG_CLIENT_AUTH 
 *      Used to enable code specific to client authentication. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 0, disabled 
 *
 *  TLS_CONFIG_ECDH 
 *      Used to enable code specific to ECDH. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 1, enabled 
 *
 *  TLS_CONFIG_ECDHE 
 *      Used to enable code specific to ECDHE. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 0, disabled 
 *
 *  TLS_CONFIG_ECDSA 
 *      Used to enable code specific to ECDSA. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 1, enabled 
 *
 *  TLS_CONFIG_RC4_40 
 *      Used to enable code specific to 40-bit ARC4. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 1, enabled 
 *
 *  TLS_CONFIG_RC4_56 
 *      Used to enable code specific to 56-bit ARC4. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 1, enabled 
 *
 *  TLS_CONFIG_RC4_128 
 *      Used to enable code specific to 128-bit ARC4. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 1, enabled 
 *
 *  TLS_CONFIG_DES 
 *      Used to enable code specific to DES. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 0, disabled 
 *
 *  TLS_CONFIG_3DES 
 *      Used to enable code specific to 3DES. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 0, disabled 
 *
 *  TLS_CONFIG_AES 
 *      Used to enable code specific to AES. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 0, disabled 
 *
 *  TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS 
 *      Used to enable code/ciphers specific to non-exportable ciphers. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 1, enabled 
 *
 *  TLS_CONFIG_ENABLE_EXPORT_CIPHERS 
 *      Used to enable code/ciphers specific to exportable ciphers. 
 *      = 1 to enable 
 *      = 0 to disable.
 *      Default:
 *          = 1, enabled 
 *
 *  TLS_MAX_CERTIFICATE_PATH_LEN
 *      Indicates the maximum # of certificates supported in the
 *      server certificate message.
 *      Default:
 *          = 4
 *
 *  TLS_CONFIG_SSL2
 *      Indicates support for SSL version 2.0
 *      = 1 to support.
 *      = 0 otherwise.
 *      Default:
 *          = 0
 *
 *  TLS_CONFIG_SSL3
 *      Indicates support for SSL version 3.0
 *      = 1 to support.
 *      = 0 otherwise.
 *      Default:
 *          = 0
 *
 *  TLS_CONFIG_TLS1
 *      Indicates support for TLS version 1.0
 *      = 1 to support.
 *      = 0 otherwise.
 *      Default:
 *          = 1
 *
 *  TLS_CONFIG_RSA
 *      Indicates support for RSA.
 *      = 1 to support.
 *      = 0 otherwise.
 *      Default:
 *          = 1
 *
 *  TLS_CONFIG_ECDH_ECDSA_NULL_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDH_ECDSA_NULL_SHA
 *          Included if ECDSA, ECDH and Export ciphers enabled
 * 
 *  TLS_CONFIG_ECDH_ECDSA_WITH_RC4_128_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDH_ECDSA_WITH_RC4_128_SHA
 *      Default:        
 *          Included if ECDSA, ECDH, RC4_128, and Non-Export ciphers enabled
 * 
 * 
 *  TLS_CONFIG_AES
 *      Indicates support for Cipher suite:     
 *          TLS_RSA_WITH_AES_128_CBC_SHA 
 *      Default:        
 *          Included if RSA, ciphers enabled
 *  TLS_CONFIG_ECDH_ECDSA_WITH_DES_CBC_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDH_ECDSA_WITH_RC4_128_SHA
 *      Default:        
 *          Included if ECDSA, ECDH, DES, and Non-Export ciphers enabled
 * 
 *  TLS_CONFIG_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
 *      Default:        
 *          Included if ECDSA, ECDH, 3DES, and Non-Export ciphers enabled
 * 
 *  TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA
 *      Default:        
 *          Excluded
 * 
 *  TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA
 *      Default:        
 *          Included if ECDSA, ECDH, RC4_56, and Export ciphers enabled
 * 
 *  TLS_CONFIG_ECDHE_ECDSA_WITH_RC4_128_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDHE_ECDSA_WITH_RC4_128_SHA
 *      Default:        
 *          Included if ECDSA, ECDHE, RC4_128, and Non-Export ciphers enabled
 * 
 *  TLS_CONFIG_ECDHE_ECDSA_WITH_DES_CBC_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDHE_ECDSA_WITH_DES_CBC_SHA
 *      Default:        
 *          Included if ECDSA, ECDHE, DES, and Non-Export ciphers enabled
 * 
 *  TLS_CONFIG_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
 *      Default:        
 *          Included if ECDSA, ECDHE, 3DES, and Non-Export ciphers enabled
 * 
 *  TLS_CONFIG_RSA_WITH_3DES_EDE_CBC_SHA
 *      Indicates support for Cipher suite:     
 *          TLS_RSA_WITH_3DES_EDE_CBC_SHA
 *      Default:        
 *          Included if RSA, 3DES, and Non-Export ciphers enabled
 * 
 *  TLS_CONFIG_RSA_WITH_RC4_128_MD5
 *      Indicates support for Cipher suite:     
 *          TLS_RSA_WITH_RC4_128_MD5
 *      Default:        
 *          Included if RSA, RC4_128, and Non-Export ciphers enabled
 * 
 *  TLS_CONFIG_RSA_EXPORT_WITH_RC4_40_MD5
 *      Indicates support for Cipher suite:     
 *          TLS_RSA_EXPORT_WITH_RC4_40_MD5
 *      Default:        
 *          Included if RSA, RC4_40, and Export ciphers enabled
 *
 *  TLS_CONFIG_RSA_WITH_NULL_MD5
 *      Indicates support for Cipher suite:     
 *          TLS_RSA_WITH_NULL_MD5
 *      Default:        
 *          Included if RSA, and Export ciphers enabled
 *
 *  TLS_CONFIG_SGC
 *      Indicates support for Server Gated Crypto.
 *      = 1 to support.
 *      = 0 otherwise.
 *      Default: 
 *          1
 *
 *  TLS_CONFIG_INTERNATIONAL
 *      Indicates support for International configuration.
 *      = 1 to support.
 *      = 0 otherwise.
 *      Default: 
 *          0.
 *
 *-------------------------------------------------------------
 * Notes:
 *
 *-------------------------------------------------------------
 * This software contains trade secrets and confidential information of Certicom Corp.
 * (c) Copyright Certicom Corp. 1997-1999
-*/

/* $Id: tlscnfg.h,v 2.11.8.1 2002/07/03 20:58:38 amartin Exp $ */

#ifndef __TLSCNFG_H__
#define __TLSCNFG_H__ 1

/*
 * Palm O/S option.
 * Used to indicate whether to compiling for Palm O/S.
 *
 * Default: 
 *      0
*/
#ifndef PALM
#   define PALM         0
#endif

/* 
 * TLS_CONFIG_PALM_SDK_VERSION is used to identify that we wish to compile
 * with the Palm OS SDK prior to 3.5 which have different include files.
 * Default to using the new 3.5 includes.
*/
#if !defined(TLS_CONFIG_PALM_SDK_VERSION)
#   define TLS_CONFIG_PALM_SDK_VERSION             350       /* default to 3.5 SDK or later */
#endif

/*
 * ECC support option.
 * Used to indicate whether to support ECC.
 *
 * Default: 
 *      1
*/
#ifndef TLS_CONFIG_ECC
#   define TLS_CONFIG_ECC    1
#endif


/*
 * Palm O/S Shared TLS library option.
 * Used to indicate whether to compile TLS library as a 
 * shared library for Palm O/S.
 *
 * Default: 
 *      0
*/
#ifndef TLS_CONFIG_PALM_SHARED_TLSLIB
#   define TLS_CONFIG_PALM_SHARED_TLSLIB    0
#endif

/*
 * Sanity check: If TLS_CONFIG_PALM_SHARED_TLSLIB enabled, PALM must be enabled
*/
#if !PALM && TLS_CONFIG_PALM_SHARED_TLSLIB
#   error "Incompatible configuration options! (TLS_CONFIG_PALM_SHARED_TLSLIB and PALM)"
#endif

/* 
 * Client authentication support option.
 * Default: 
 *      No client authentication support.
*/
#ifndef TLS_CONFIG_CLIENT_AUTH
#   define TLS_CONFIG_CLIENT_AUTH               1
#endif


/* 
 * ECDH support option.
 * Default: 
 *      ECDH supported.
*/
#ifndef TLS_CONFIG_ECDH
#   if TLS_CONFIG_ECC
#       define TLS_CONFIG_ECDH                  1
#   else
#       define TLS_CONFIG_ECDH                  0
#   endif
#endif


/* 
 * ECDHE support option.
 * Default: 
 *      ECDHE supported.
*/
#ifndef TLS_CONFIG_ECDHE
#   define TLS_CONFIG_ECDHE                     0
#endif


/* 
 * ECDSA support option.
 * Default: 
 *      ECDSA supported.
*/
#ifndef TLS_CONFIG_ECDSA
#   if TLS_CONFIG_ECC
#       define TLS_CONFIG_ECDSA                 1
#   else
#       define TLS_CONFIG_ECDSA                 0
#   endif
#endif



/* 
 * 40-bit ARC4 support option.
 * Default: 
 *      40-bit ARC4 supported.
*/
#ifndef TLS_CONFIG_RC4_40
#   define TLS_CONFIG_RC4_40                    1
#endif


/* 
 * 56-bit ARC4 support option.
 * Default: 
 *      56-bit ARC4 supported.
*/
#ifndef TLS_CONFIG_RC4_56
#   define TLS_CONFIG_RC4_56                    1
#endif


/* 
 * 128-bit ARC4 support option.
 * Default: 
 *      128-bit ARC4 supported.
*/
#ifndef TLS_CONFIG_RC4_128
#   define TLS_CONFIG_RC4_128                   1
#endif

/* 
 * AES support option.
 * Default: 
 *      AES not supported.
*/
#ifndef TLS_CONFIG_AES
#   define TLS_CONFIG_AES                       0
#endif


/* 
 * DES support option.
 * Default: 
 *      DES supported.
*/
#ifndef TLS_CONFIG_DES
#   define TLS_CONFIG_DES                       0
#endif



/* 
 * 3DES support option.
 * Default: 
 *      3DES supported.
*/
#ifndef TLS_CONFIG_3DES
#   define TLS_CONFIG_3DES                      0
#endif

/* 
 * RSA support option.
 * Default: 
 *      RSA not supported
*/
#ifndef TLS_CONFIG_RSA
#   define TLS_CONFIG_RSA                       1
#endif

/* 
 * Non-export ciphers enabled option.
 * Default: 
 *      non-export ciphers enabled.
*/
#ifndef TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#   define TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS  1
#endif

/* 
 * Export ciphers enabled option.
 * Default: 
 *      export ciphers enabled.
*/
#ifndef TLS_CONFIG_ENABLE_EXPORT_CIPHERS
#   define TLS_CONFIG_ENABLE_EXPORT_CIPHERS     1
#endif


#ifndef TLS_MAX_CERTIFICATE_PATH_LEN
    #define TLS_MAX_CERTIFICATE_PATH_LEN        4
#endif

/*
 * SSL Protocol Version 2 support
 * Default: 
 *      No SSLv2 support
*/
#ifndef TLS_CONFIG_SSL2
#   define TLS_CONFIG_SSL2                      0
#endif

/*
 * SSL Protocol Version 3 support
 * Default: 
 *      No SSLv3 support
*/
#ifndef TLS_CONFIG_SSL3
#   define TLS_CONFIG_SSL3                      0
#endif

/*
 * TLS Protocol Version 1 support
 * Default: 
 *      TLSv1 support enabled
*/
#ifndef TLS_CONFIG_TLS1
#   define TLS_CONFIG_TLS1                      1
#endif


/*
 * Below are the preprocessor defines to explicitly include or exclude all
 * cipher suites coded.
 *
*/

/*  TLS_CONFIG_ECDH_ECDSA_NULL_SHA
 *  Cipher suite:   TLS_ECDH_ECDSA_NULL_SHA
 *  Default:        Included if ECDSA, ECDH and Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDH_ECDSA_NULL_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDH && TLS_CONFIG_ENABLE_EXPORT_CIPHERS
#       define TLS_CONFIG_ECDH_ECDSA_NULL_SHA               1
#   else
#       define TLS_CONFIG_ECDH_ECDSA_NULL_SHA               0
#   endif
#elif TLS_CONFIG_ECDH_ECDSA_NULL_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDH || !TLS_CONFIG_ENABLE_EXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif

/*  TLS_CONFIG_ECDH_ECDSA_WITH_RC4_128_SHA
 *  Cipher suite:   TLS_ECDH_ECDSA_WITH_RC4_128_SHA
 *  Default:        Included if ECDSA, ECDH, RC4_128, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDH_ECDSA_WITH_RC4_128_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDH && TLS_CONFIG_RC4_128 && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_ECDH_ECDSA_WITH_RC4_128_SHA               1
#   else
#       define TLS_CONFIG_ECDH_ECDSA_WITH_RC4_128_SHA               0
#   endif
#elif TLS_CONFIG_ECDH_ECDSA_WITH_RC4_128_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDH || !TLS_CONFIG_RC4_128 || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_RSA_WITH_AES_128_CBC_SHA
 *  Cipher suite:   TLS_RSA_WITH_AES_128_CBC_SHA
 *  Default:        Included if RSA, ciphers enabled
 */
#ifndef TLS_CONFIG_RSA_WITH_AES_128_CBC_SHA 
#   if TLS_CONFIG_RSA && TLS_CONFIG_AES
#       define TLS_CONFIG_RSA_WITH_AES_128_CBC_SHA                         1
#   else
#       define TLS_CONFIG_RSA_WITH_AES_128_CBC_SHA                         0
#   endif
#elif TLS_CONFIG_AES && (!TLS_CONFIG_RSA )
#   error "Incompatible configuration options!"
#endif



/*  TLS_CONFIG_ECDH_ECDSA_WITH_DES_CBC_SHA
 *  Cipher suite:   TLS_ECDH_ECDSA_WITH_RC4_128_SHA
 *  Default:        Included if ECDSA, ECDH, DES, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDH_ECDSA_WITH_DES_CBC_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDH && TLS_CONFIG_DES && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_ECDH_ECDSA_WITH_DES_CBC_SHA               1
#   else
#       define TLS_CONFIG_ECDH_ECDSA_WITH_DES_CBC_SHA               0
#   endif
#elif TLS_CONFIG_ECDH_ECDSA_WITH_DES_CBC_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDH || !TLS_CONFIG_DES || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
 *  Cipher suite:   TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
 *  Default:        Included if ECDSA, ECDH, 3DES, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDH && TLS_CONFIG_3DES && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA          1
#   else
#       define TLS_CONFIG_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA          0
#   endif
#elif TLS_CONFIG_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDH || !TLS_CONFIG_3DES || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA
 *  Cipher suite:   TLS_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA
 *  Default:        Excluded
 */
#ifndef TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA
#   define TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA             0
#elif TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDH || !TLS_CONFIG_RC4_40 || !TLS_CONFIG_ENABLE_EXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA
 *  Cipher suite:   TLS_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA
 *  Default:        Included if ECDSA, ECDH, RC4_56, and Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDH && TLS_CONFIG_RC4_56 && TLS_CONFIG_ENABLE_EXPORT_CIPHERS
#       define TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA         1
#   else
#       define TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA         0
#   endif
#elif TLS_CONFIG_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDH || !TLS_CONFIG_RC4_56 || !TLS_CONFIG_ENABLE_EXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_ECDHE_ECDSA_WITH_RC4_128_SHA
 *  Cipher suite:   TLS_ECDHE_ECDSA_WITH_RC4_128_SHA
 *  Default:        Included if ECDSA, ECDHE, RC4_128, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDHE_ECDSA_WITH_RC4_128_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDHE && TLS_CONFIG_RC4_128 && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_ECDHE_ECDSA_WITH_RC4_128_SHA              1
#   else
#       define TLS_CONFIG_ECDHE_ECDSA_WITH_RC4_128_SHA              0
#   endif
#elif TLS_CONFIG_ECDHE_ECDSA_WITH_RC4_128_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDHE || !TLS_CONFIG_RC4_128 || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_ECDHE_ECDSA_WITH_DES_CBC_SHA
 *  Cipher suite:   TLS_ECDHE_ECDSA_WITH_DES_CBC_SHA
 *  Default:        Included if ECDSA, ECDHE, DES, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDHE_ECDSA_WITH_DES_CBC_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDHE && TLS_CONFIG_DES && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_ECDHE_ECDSA_WITH_DES_CBC_SHA              1
#   else
#       define TLS_CONFIG_ECDHE_ECDSA_WITH_DES_CBC_SHA              0
#   endif
#elif TLS_CONFIG_ECDHE_ECDSA_WITH_DES_CBC_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDHE || !TLS_CONFIG_DES || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
 *  Cipher suite:   TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
 *  Default:        Included if ECDSA, ECDHE, 3DES, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
#   if TLS_CONFIG_ECDSA && TLS_CONFIG_ECDHE && TLS_CONFIG_3DES && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA         1
#   else
#       define TLS_CONFIG_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA         0
#   endif
#elif TLS_CONFIG_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA && (!TLS_CONFIG_ECDSA || !TLS_CONFIG_ECDHE || !TLS_CONFIG_3DES || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif



/*  TLS_CONFIG_RSA_WITH_3DES_EDE_CBC_SHA
 *  Cipher suite:   TLS_RSA_WITH_3DES_EDE_CBC_SHA
 *  Default:        Included if RSA, 3DES, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_RSA_WITH_3DES_EDE_CBC_SHA
#   if TLS_CONFIG_RSA && TLS_CONFIG_3DES && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_RSA_WITH_3DES_EDE_CBC_SHA                 1
#   else
#       define TLS_CONFIG_RSA_WITH_3DES_EDE_CBC_SHA                 0
#   endif
#elif TLS_CONFIG_RSA_WITH_3DES_EDE_CBC_SHA && (!TLS_CONFIG_RSA || !TLS_CONFIG_3DES || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_RSA_WITH_RC4_128_MD5
 *  Cipher suite:   TLS_RSA_WITH_RC4_128_MD5
 *  Default:        Included if RSA, RC4_128, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_RSA_WITH_RC4_128_MD5
#   if TLS_CONFIG_RSA && TLS_CONFIG_RC4_128 && TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS
#       define TLS_CONFIG_RSA_WITH_RC4_128_MD5                      1
#   else
#       define TLS_CONFIG_RSA_WITH_RC4_128_MD5                      0
#   endif
#elif TLS_CONFIG_RSA_WITH_RC4_128_MD5 && (!TLS_CONFIG_RSA || !TLS_CONFIG_RC4_128 || !TLS_CONFIG_ENABLE_NONEXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif

/*  TLS_CONFIG_RSA_WITH_NULL_MD5
 *  Cipher suite:   TLS_RSA_WITH_NULL_MD5
 *  Default:        Included if RSA, and Non-Export ciphers enabled
 */
#ifndef TLS_CONFIG_RSA_WITH_NULL_MD5
#   if TLS_CONFIG_RSA && TLS_CONFIG_ENABLE_EXPORT_CIPHERS
#       define TLS_CONFIG_RSA_WITH_NULL_MD5                      1
#   else
#       define TLS_CONFIG_RSA_WITH_NULL_MD5                      0
#   endif
#elif TLS_CONFIG_RSA_WITH_NULL_MD5 && (!TLS_CONFIG_RSA || !TLS_CONFIG_ENABLE_EXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*  TLS_CONFIG_RSA_EXPORT_WITH_RC4_40_MD5
 *  Cipher suite:   TLS_RSA_EXPORT_WITH_RC4_40_MD5
 *  Default:        Included if RSA, RC4_40, and Export ciphers enabled
 */
#ifndef TLS_CONFIG_RSA_EXPORT_WITH_RC4_40_MD5
#   if TLS_CONFIG_RSA && TLS_CONFIG_RC4_40 && TLS_CONFIG_ENABLE_EXPORT_CIPHERS
#       define TLS_CONFIG_RSA_EXPORT_WITH_RC4_40_MD5                1
#   else
#       define TLS_CONFIG_RSA_EXPORT_WITH_RC4_40_MD5                0
#   endif
#elif TLS_CONFIG_RSA_EXPORT_WITH_RC4_40_MD5 && (!TLS_CONFIG_RSA || !TLS_CONFIG_RC4_40 || !TLS_CONFIG_ENABLE_EXPORT_CIPHERS)
#   error "Incompatible configuration options!"
#endif


/*
 * Sanity check: If SSLv2 is enabled, so must RSA and at least one RSA cipher
*/
#if TLS_CONFIG_SSL2 && (!TLS_CONFIG_RSA || (!TLS_CONFIG_RSA_WITH_RC4_128_MD5 && !TLS_CONFIG_RSA_EXPORT_WITH_RC4_40_MD5))
#   error "Incompatible configuration options!"
#endif

/*
 * Sanity check: If SSLv2 and TLSv1 are both enabled, SSLv3 _should_ be enabled
*/
#if (TLS_CONFIG_SSL2 && TLS_CONFIG_TLS1) && !TLS_CONFIG_SSL3
#   error "Incompatible configuration options!"
#endif


/* 
 * SGC support option.
 * Default: 
 *      SGC supported if RSA supported.
*/
#ifndef TLS_CONFIG_SGC
#   define TLS_CONFIG_SGC                      1
#endif

/* 
 * International support option.
 * Default: 
 *      Not supported.
*/
#ifndef TLS_CONFIG_INTERNATIONAL
#   define TLS_CONFIG_INTERNATIONAL             0
#endif

#endif /* __TLSCNFG_H__ */
