/*+
Release: SSL Plus 1.1.2b

Certicom, the Certicom logo, SSL Plus, and Security Builder are trademarks of
Certicom Corp.  Copyright (c) 1997-2002 Certicom Corp.  All rights reserved.
Protected by U.S. patents 5,787,028; 4,745,568;
5,761,305.  Patents pending.
-*/

#ifndef _CDGLOBAL_H_
#define _CDGLOBAL_H_ 1

/*
 * cdglobal.h : 
 *
 *
 * Description: 
 *
 *---------------------------------------------------------------------
 * Conditional compilations:
 *      None.
 *
 *
 *---------------------------------------------------------------------
 * Notes:
 *      None.
 *
 * 
 * 
 * (C) Certicom Corp., 1996-1999  All rights reserved.
 * Certicom, the Certicom logo, and Security Builder are trademarks of Certicom Corp.  
*/
/* $Id: cdglobal.h,v 2.5 2001/05/31 17:15:16 rdugal Exp $ */

#ifdef __cplusplus
extern "C" {
#endif

/* gcc on solaris defines unix, but not UNIX */
#if defined(unix)
#define UNIX 1
#endif

#ifndef PALM
    #if defined( __MWERKS__ ) && defined( __MC68K__ ) /* Palm O/S with Metrowerks Codewarrior */ 
	    #define  PALM 1
    #else
    	#define  PALM 0
    #endif
#endif

#if !defined(MAC) && !defined(WIN32) && !defined(UNIX) && !defined(_WIN16) && !defined(VXWORKS) && !defined(MCORE) && !defined(NUCLEUS_PLUS) && !PALM
#define MAC 1
#endif

#ifdef _WIN16
	#ifndef WIN16_FAR
		#ifdef FAR
			#define WIN16_FAR FAR
		#else
			#define WIN16_FAR __far
		#endif
	#endif
#else
	#define WIN16_FAR
#endif

#ifndef UNUSED_PARAM
#define UNUSED_PARAM(v)	(void)(v);
#endif

#ifndef SIMPLE_TYPES
    #define SIMPLE_TYPES 1
    #ifdef VMS
        # include <ints.h>
    #else
        #if !PALM
            #include <stddef.h>
        #endif
        typedef unsigned short  uint16;
        typedef unsigned long   uint32;
    #endif
    typedef unsigned char	uint8;
    typedef signed long		sint32;

    typedef struct
    {	uint32  length;
	    uint8	*data;
	    uint8	allocated;		/* This should be non-zero if the memory was allocated specifically for this Buffer */
    } Buffer;
#endif  /* #ifndef SIMPLE_TYPES */

#if defined( UNDER_CE )
    #ifndef SSL_CALLCONV
        #define SSL_CALLCONV    __cdecl
    #endif
#endif

#ifndef SSL_CALLCONV
    #define SSL_CALLCONV    
#endif

#ifndef SSL_EXPORT
    #define SSL_EXPORT    
#endif


/*
@section System Callbacks
@desc You must provide the following platform-dependent callback functions in your application.
      Sample implementations of these callback functions are provided in samples\shared\callback.c.
*/

/*----------------------------------- CD_malloc() ------------------------------------*/
/**Allocates size bytes of memory.
	
@param size [Input] The amount of memory to allocate (in bytes).
@param ref [Input] Optional user reference parameter.

@returndesc None.

@version TLS 1.0
*/

extern 
SSL_EXPORT 
void*     
SSL_CALLCONV 
CD_malloc( 
    uint32 size, 
    void *ref 
    );

/*------------------------------------ CD_free() ------------------------------------*/
/**Frees a block of memory that was allocated with CD_malloc() or
CD_realloc(). 
	
@param block [Input] Pointer to the block of memory.
@param ref [Input] Optional user reference parameter.

@returndesc None.

@version TLS 1.0
*/

extern 
SSL_EXPORT 
void      
SSL_CALLCONV 
CD_free( 
    void *block, 
    void *ref 
    );

/*------------------------------------- CD_realloc() -----------------------------------*/
/**Re-allocates a block of memory.
	
@param block   [Input] Pointer to the old memory block.
@param newSize [Input] The size of the new memory block (in bytes).
@param ref [Input] Optional user reference parameter.

@returndesc A pointer to the new memory block.

@version TLS 1.0
*/

extern 
SSL_EXPORT 
void*     
SSL_CALLCONV 
CD_realloc( 
    void *block, 
    uint32 newSize, 
    void *ref 
    );

/*------------------------------------ CD_memset() -----------------------------------*/
/**Initializes a block of memory.
	
@param block  [Input] Pointer to the memory block.
@param value  [Input] The value to write to the block.
@param length [Input] The number of bytes to be set.

@returndesc None.

@version TLS 1.0
*/

extern 
SSL_EXPORT 
void      
SSL_CALLCONV 
CD_memset( 
    void *block, 
    uint8 value, 
    uint32 length 
    );

/*------------------------------------ CD_memcpy() -------------------------------------*/
/**Copies a block of memory from src to dest.
	
@param dest   [Input] Pointer to the destination of the copy operation.
@param src    [Input] Pointer to the source of the copy operation.
@param length [Input] The number of bytes to copy.

@returndesc None.

@version TLS 1.0
*/

extern 
SSL_EXPORT 
void      
SSL_CALLCONV 
CD_memcpy( 
    void *dest, 
    const void *src, 
    uint32 length 
    );

/*---------------------------------- CD_memcmp() -----------------------------------*/
/**Compares two blocks of memory.

@param a      [Input] Pointer to the source of the comparison operation.
@param b      [Input] Pointer to the destination of the comparison operation.
@param length [Input] The number of bytes to compare.

@returndesc Zero if the buffers are equal. Positive value if <C>a</C> is larger then <C>b</C>.
            Negative value if <C>b</C> is larger than <C>a</C>.
            
@version TLS 1.0
*/

extern 
SSL_EXPORT 
int       
SSL_CALLCONV 
CD_memcmp( 
    const void *a, 
    const void *b, 
    uint32 length 
    );

/*-------------------------------------- CD_time() ------------------------------------*/
/**Return the number of seconds that have elapsed since Jan 1, 1970.

@param None.

@returndesc The number of seconds that have elapsed since January 1,1970.

@version TLS 1.0
*/

extern 
SSL_EXPORT 
uint32    
SSL_CALLCONV 
CD_time( 
    void 
    );

extern SSL_EXPORT void      SSL_CALLCONV CD_yield( void );

/* Prototypes for User provided function pointers */
typedef SSL_EXPORT void*    (SSL_CALLCONV *CD_mallocFunc)( uint32 size, void *ref );
typedef SSL_EXPORT void     (SSL_CALLCONV *CD_freeFunc)( void *block, void *ref );
typedef SSL_EXPORT void*    (SSL_CALLCONV *CD_reallocFunc)( void *block, uint32 newSize, void *ref );
typedef SSL_EXPORT void     (SSL_CALLCONV *CD_memsetFunc)( void *block, uint8 value, uint32 length );
typedef SSL_EXPORT void     (SSL_CALLCONV *CD_memcpyFunc)( void *dest, const void *src, uint32 length );
typedef SSL_EXPORT int      (SSL_CALLCONV *CD_memcmpFunc)( const void *a, const void *b, uint32 length );
typedef SSL_EXPORT uint32   (SSL_CALLCONV *CD_timeFunc)( void );
typedef SSL_EXPORT void     (SSL_CALLCONV *CD_yieldFunc)( void );

typedef struct CallbacksContext
{
    void            *cbRef;         /* Reference parameter for memory allocation callbacks */
    CD_mallocFunc   malloc;
    CD_freeFunc     free;
    CD_reallocFunc  realloc;
    CD_memsetFunc   memset;
    CD_memcpyFunc   memcpy;
    CD_memcmpFunc   memcmp;
    CD_timeFunc     time;
    CD_yieldFunc    yield;
}CallbacksContext;

#ifdef __cplusplus
}
#endif


#endif /* _CDGLOBAL_H_ */
