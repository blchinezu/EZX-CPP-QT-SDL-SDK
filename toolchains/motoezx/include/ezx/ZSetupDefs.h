
//-------------------------------------------------------------------------------------------------
//                                                                        
//   Module Name: ZSetupDefs.h
//
//   General Description: Setup definitions
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef ZSETUP_DEFS_H
#define ZSETUP_DEFS_H

#define SETUP_GRP_THEME_STR                 "SYS_THEME_SET"
#define SETUP_GRP_SYS_STR                   "SYS_SYSTEM_SET"
#define SETUP_GRP_FLEX_TABLE_STR            "SYS_FLEX_TABLE"

#define THEME_GRP_CONFIG_STR                "THEME_CONFIG_TABLE"
#define THEME_GRP_COLOR_PALETTE_STR         "THEME_COLOR_PALETTE_TABLE"
#define THEME_GRP_MULTI_LANG_NAME_STR       "THEME_MULTI_LANG_NAME"

#define SETUP_KEY_TOUCH_SCREEN_VOLUME_STR   "TouchScreenVolume"
#define SETUP_KEY_TOUCH_SCREEN_TYPE_STR     "TouchScreenType"

#define SETUP_KEY_LANGUAGE_STR              "LanguageType"
#define SETUP_KEY_USER_DEFINED_LANGUAGE_STR "UserDefinedLanguageType"
#define SETUP_KEY_PRIMARY_INPUT_STR         "PrimaryInputMethod"

#define SETUP_KEY_WRITING_HAND_STR          "WritingHand"
#define SETUP_KEY_WRITING_RECOG_STR         "Handwriting Recog"
#define SETUP_KEY_WRITING_SPEED_STR         "WritingSpeed"
#define SETUP_KEY_WORD_COMPLETION_STR       "WordCompletion"
#define SETUP_KEY_USER_DICT_STR             "UserDict"
#define SETUP_KEY_WATER_MARK_STR            "WaterMark"
#define SETUP_KEY_DATE_FORMAT_STR           "DateFormat"
#define SETUP_KEY_TIME_FORMAT_STR           "TimeFormat"
#define SETUP_KEY_LARGE_FONT_SIZE_STR       "LargeFontSize"
#define SETUP_KEY_MEDIUM_FONT_SIZE_STR      "MediumFontSize"
#define SETUP_KEY_SMALL_FONT_SIZE_STR       "SmallFontSize"

#define SETUP_KEY_WALLPAPER_FILE_NAME_STR   "WallpaperFileName"
#define SETUP_KEY_POWER_UP_IMAGE_STR        "PowerUpImage"
#define SETUP_KEY_POWER_DOWN_IMAGE_STR      "PowerDownImage"

//for theme
#define THEME_KEY_WALLPAPER_STR             "ThemeWallpaperFile"
#define THEME_KEY_COLOR_PALETTE_INDEX_STR   "ThemeColorPaletteIndex"
#define THEME_KEY_COLOR_PALETTE_NAME_STR    "ThemeColorPaletteName"
#define THEME_KEY_TEXT_SIZE_STR             "ThemeTextSize"
#define THEME_KEY_SOUND_FILE_LINE1_STR      "ThemeSoundFileLine1"
#define THEME_KEY_SOUND_FILE_LINE2_STR      "ThemeSoundFileLine2"
#define THEME_KEY_ALERT_FILE_MSG_STR        "ThemeMsgAlertFile"
#define THEME_KEY_ALERT_FILE_GENERAL_STR    "ThemeGeneralAlertFile"
#define THEME_KEY_POWER_UP_IMAGE_STR        "ThemePowerUpImage"
#define THEME_KEY_POWER_DOWN_IMAGE_STR      "ThemePowerDownImage"
#define THEME_KEY_ICON_DIR_STR              "ThemeIconDir"
#define THEME_KEY_NAME_STR                  "ThemeName"
#define THEME_KEY_CURRENT_USE_STR           "ThemeCurrentUse"

//Theme color Pallette
#define THEME_FOREGROUND_STR                "ThemeForeground"
#define THEME_BACKGROUND_STR                "ThemeBackground"
#define THEME_BUTTON_STR                    "ThemeButton"
#define THEME_BUTTON_TEXT_STR               "ThemeButtonText"
#define THEME_HIGHLIGHT_STR                 "ThemeHighlight"
#define THEME_HIGHLIGHT_TEXT_STR            "ThemeHighlightedText"
#define THEME_BRIGHT_TEXT_STR               "ThemeBrightText"

//public definitions
#define DEFAULT_LANGUAGE_CODE               "en-us"
#define LANGUAGE_DES_CONFIG_FILE            "readme.cfg"

#define SETUP_DATETIME_FORMAT_CHANNEL       "EZX/Setup/DateTimeFormatChanged"
#define SETUP_DATE_FORMAT_CHANGED           "Setup/DateFormatChanged"
#define SETUP_TIME_FORMAT_CHANGED           "Setup/TimeFormatChanged"

#define SETUP_CFG_FILE                      "ezx_system.cfg"
#define THEME_CFG_FILE                      "ezx_theme.cfg"
#define COLOR_CFG_FILE                      "colorpalette.cfg"

#define SETUP_TIMESTAMP_FILE                "ezx_timestamp.cfg"
#define THEME_TIMESTAMP_FILE                "language_timestamp.cfg"

#define TMP_SETUP_FILE                      "/tmp/ezx_system.cfg"        
#define TMP_THEME_FILE                      "/tmp/ezx_theme.cfg" 
#define TMP_FIXED_DIAL_FILE                 "/tmp/ezx_fixeddial.cfg"
#define TMP_COLOR_PAL_FILE                  "/tmp/colorpalette.cfg" 

#define TMP_SETUP_DIR                       "/tmp/"

#endif //ZSETUP_DEFS_H
