
//-------------------------------------------------------------------------------------------------
//
//  Header Name: ZLRS.h
//
//  General Description: Layout Requirement Specification declarations
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------
//modifid for E6 by wangbin 2010-04-17
#ifndef Z760_LRS_H
#define Z760_LRS_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qrect.h>

/**
 * This file defines Motorola's layout requirements.
 *
 * This header is model dependent. 
 *
 * As different LRS are involved in new product, for example, A780, model 
 * dependent headers must be created and symbolically linked to ZLRS.h
 *
 * @see ZLayout.h for the function naming rules
 * @see ZGlobal.h
 */

namespace ZGlobal
{
    /**
     * GNB button areas
     * @note Useless for LRS0.9.3 - compatible interfaces
     //remove for E6
    QRect getGnb_1R();
    QRect getGnb_2R();
    QRect getGnb_3R();
    QRect getGnb_4R();
    QRect getGnb_5R();
  */
    /**
     * GNB-StatusBar 5 button areas
     * @note Useless for LRS0.9.3 - compatible interfaces
     //remove for E6
    QRect getStatusBar_1R();
    QRect getStatusBar_2R();
    QRect getStatusBar_3R();
    QRect getStatusBar_4R();
    QRect getStatusBar_5R();
    //CST 1 button areas
    
  */
  	QRect getCst1_1R();
    /**
     * CST 2 button areas
     * @note compatible and same as Cst2a
     */
    //QRect getCst2_1R();//remove for E6
    //QRect getCst2_2R();//remove for E6
  
    /**
     * CST 2 button(a) areas
     *  |__________|__________|
     */
    QRect getCst2a_1R();
    QRect getCst2a_2R();
  
    /**
     * CST 2 button(b) areas
     *  |___|_________________|
     */
    QRect getCst2b_1R();
    QRect getCst2b_2R();
  
    /**
     * CST 2 button(c) areas
     *  |_________________|___|
     */
    QRect getCst2c_1R();
    QRect getCst2c_2R();
  
    /**
     * CST 3 button areas
     *  |___|_____________|___|
     */
    QRect getCst3_1R();
    QRect getCst3_3R();
    QRect getCst3_2R();
  
    /**
     * CST 3 button(a) areas
     *  |___|________|________|
     * @note LRS0.9.4 3(b)
     */
    QRect getCst3a_1R();
    QRect getCst3a_2R();
    QRect getCst3a_3R();
  
    /**
     * CST 3 button(b) areas
     *   |___|________|________|
     * @note LRS0.9.4 3(c)
     */
    QRect getCst3b_1R();
    QRect getCst3b_2R();
    QRect getCst3b_3R();
  
    /**
     * CST 3 button(c) areas
     *  |___|________|________|
     * @note LRS0.9.4 3(d)
     */
    QRect getCst3c_1R();
    QRect getCst3c_2R();
    QRect getCst3c_3R();
  
    /**
     * CST 4 button(a) areas
     *  |___|_______________|___|___|
     */
    QRect getCst4a_1R();
    QRect getCst4a_4R();
    QRect getCst4a_3R();
    QRect getCst4a_2R();
  
    /**
     * CST 4 button(b) areas
     *  |___|________|________|___|
     */
    QRect getCst4b_1R();
    QRect getCst4b_4R();
    QRect getCst4b_2R();
    QRect getCst4b_3R();
  
    /**
     * CST 4 button(c) areas
     * |___|____|_____|___________|
     */
    QRect getCst4c_1R();
    QRect getCst4c_2R();
    QRect getCst4c_3R();
    QRect getCst4c_4R();
   
    /**
     * CST 5 button areas
     *  |___|_____|_____|___|___|
     *///remove for E6
    /*QRect getCst5_1R();
    QRect getCst5_2R();
    QRect getCst5_4R();
    QRect getCst5_5R();
    QRect getCst5_3R();
  */
    /**
     * CST 6 button areas:
     * only when InputWidget trigger button appears with 5 CST buttons
     * @note Useless for LRS0.9.3 - compatible interfaces
     *///remove for E6
    /*QRect getCst6_1R();
    QRect getCst6_2R();
    QRect getCst6_5R();
    QRect getCst6_6R();
    QRect getCst6_3R();
    QRect getCst6_4R();
  */
    /**
     * Dialog A location
     */
    ///QRect getDlgAR();//remove for E6
    
    /**
     * Dialog A CST area
     */
    //QRect getDlgACstR();//remove for E6
  
    /**
     * Dialog A Content area (DlgA - DlgACst)
     */
    //QRect getDlgAContentR();//remove for E6
  
    /**
     * Dialog A Title area
     */
    //QRect getDlgATitleR();//remove for E6
  
    /**
     * Dialog A (content-title) area
     */
    //QRect getDlgASubContentR();//remove for E6
    
    /**
     * Dialog A 1 button area
     * |______________________|
     * @note LRS0.9.3
     */
    QRect getDlgA1_1R();
    
    /**
     * Dialog A 2 button(a) area
     * |__________|___________|
     * @note LRS0.9.3
     */
    QRect getDlgA2a_1R();
    QRect getDlgA2a_2R();
  
    /**
     * Dialog A 2 button(b) area
     * |_______________|____|
     * @note LRS0.9.3
     */
    QRect getDlgA2b_1R();
    QRect getDlgA2b_2R();
   
    /**
     * Dialog A 3 button(a) area
     * |___|________________|___|
     * @note LRS0.9.3 3(b)
     */
    QRect getDlgA3a_1R();
    QRect getDlgA3a_3R();
    QRect getDlgA3a_2R();
    
    /**
     * Dialog A 3 button(b) area
     * |______|______|______|
     * @note LRS0.9.3 3(a)
     */
    QRect getDlgA3b_1R();
    QRect getDlgA3b_3R();
    QRect getDlgA3b_2R();
  
    /**
     * Dialog A 3 button(c) area
     * |___|__________|___________|
     * @note LRS0.9.3
     */
    QRect getDlgA3c_1R();
    QRect getDlgA3c_3R();
    QRect getDlgA3c_2R();
  
    /**
     * Dialog M
     */
    QRect getDlgMR();
  
    /**
     * Dialog MA title area
     */
    //QRect getDlgMTitleR();//remove for E6
  
    /**
     * Dialog MA CST area
     */
    //QRect getDlgMCstR();//remove for E6
  
    /**
     * Dialog MA content area
     */
    //QRect getDlgMContentR();//remove for E6
  
    /**
     * Dialog B/C location
     */
   // QRect getDlgBCR();//remove for E6
    
    /**
     * Dialog B CST area
     */
    //QRect getDlgBCstR();//remove for E6
  
    /**
     * Dialog B Content area (DlgB - DlgBCst)
     */
    //QRect getDlgBContentR();//remove for E6
    
    /**
     * Dialog B 1 button area
     * @note Useless for LRS0.9.3 - compatible interface
     */
    QRect getDlgB1_1R();
    
    /**
     * Dialog B 2 button areas
     * @note Useless for LRS0.9.3 - compatible interface
     */
    QRect getDlgB2_1R();
   	QRect getDlgB2_2R();
  
    /**
     * Dialog C Title area
     */
   //QRect getDlgCTitleR();//remove for E6
  
    /**
     * Middle information Dialog area
     */
    //QRect getDlgInfoMR();//remove for E6
   
    /**
     * Middle information Dialog CST area
     */
    //QRect getDlgInfoMCstR();//remove for E6
   
    /**
     * Middle information Dialog Content area (DlgInfoM - DlgInfoMCst)
     */
    //QRect getDlgInfoMContentR();//remove for E6
   
    /**
     * Small information Dialog area
     */
    //QRect getDlgInfoSR();//remove for E6
   
    /**
     * Small information Dialog CST area
     */
    //QRect getDlgInfoSCstR();//remove for E6
   
    /**
     * Small information Dialog Content area (DlgInfoS - DlgInfoSCst)
     */
    //QRect getDlgInfoSContentR();//remove for E6
   
    /**
     * Selection Dialog areas
     * Large selection Dialog area
     */
    //QRect getDlgSelLR();//remove for E6
   
    /**
     * Large selection Dialog CST area
     */
    //QRect getDlgSelLCstR();//remove for E6
   
    /**
     * Large selection Dialog Content area (DlgSelL - DlgSelLCst)
     */
   // QRect getDlgSelLContentR();//remove for E6
   
    /**
     * Large selection Dialog Title area
     */
   // QRect getDlgSelLTitleR();//remove for E6
   
    /**
     * Large selection Dialog  (content-title) area
     */
   // QRect getDlgSelLSubContentR();//remove for E6
   
    /**
     * Middle selection Dialog area
     */
    //QRect getDlgSelMR();//remove for E6
  
    /**
     * Middle selection Dialog CST area
     */
   // QRect getDlgSelMCstR();//remove for E6
  
    /**
     * Middle selection Dialog Content area (DlgSelM - DlgSelMCst)
     */
    //QRect getDlgSelMContentR();//remove for E6
  
    /**
     * Middle selection Dialog Title area
     */
    //QRect getDlgSelMTitleR();//remove for E6
  
    /**
     * Middle selection Dialog  (content-title) area
     */
    //QRect getDlgSelMSubContentR();//remove for E6
  
    /**
     * Small selection Dialog area
     */
    //QRect getDlgSelSR();//remove for E6
  
    /**
     * Small selection Dialog CST area
     */
    //QRect getDlgSelSCstR();//remove for E6
  
    /**
     * Small selection Dialog Content area (DlgSelM - DlgSelMCst)
     */
    //QRect getDlgSelSContentR();//remove for E6
  
    /**
     * Small selection Dialog Title area
     */
    //QRect getDlgSelSTitleR();//remove for E6
  
    /**
     * Small selection Dialog  (content-title) area
     */
    //QRect getDlgSelSSubContentR();//remove for E6
  
    /**
     *Transient Dialog areas
     */
    /*@{*/
    /**
     * Middle transient Dialog area
     */
   // QRect getDlgTranMR();//remove for E6
   
    /**
     * Middle transient Dialog CST area
     */
    //QRect getDlgTranMCstR();//remove for E6
   
    /**
     * Middle transient Dialog Content area (DlgTranM - DlgTranMCst)
     */
   // QRect getDlgTranMContentR();//remove for E6
   
    /**
     * Small transient Dialog area
     */
    //QRect getDlgTranSR();//remove for E6
  
    /**
     * Small transient Dialog CST area
     */
    //QRect getDlgTranSCstR();//remove for E6
  
    /**
     * Small transient Dialog Content area (DlgTranS - DlgTranSCst)
     */
    //QRect getDlgTranSContentR();//remove for E6
    
    //Dialog Cst Large, Middle, Small
    QRect getDlgCstLR(); 
	QRect getDlgCstMR();
	QRect getDlgCstSR();
    QRect getDlgLargeConR();
	QRect getDlgLargeR();
	QRect getDlgMiddleConR();
	QRect getDlgMiddleR();
	QRect getDlgSmallConR();
	QRect getDlgSmallR();
	QRect getDlgTitleLR();
	QRect getDlgTitleMR();
	QRect getDlgTitleSR();
    /*@}*/};

#endif //Z760_LRS_H
