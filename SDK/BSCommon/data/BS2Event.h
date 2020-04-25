/**
 *  Event Log Definitions
 *
 *  @author jylee@suprema.co.kr
 *  @see
 */

/*
 *  Copyright (c) 2014 Suprema Co., Ltd. All Rights Reserved.
 *
 *  This software is the confidential and proprietary information of
 *  Suprema Co., Ltd. ("Confidential Information").  You shall not
 *  disclose such Confidential Information and shall use it only in
 *  accordance with the terms of the license agreement you entered into
 *  with Suprema.
 */

#ifndef __BS2_EVENT_H__
#define __BS2_EVENT_H__

#include "../BS2Types.h"
#include "BS2Door.h"
#include "BS2Lift.h"
#include "../BS_Deprecated.h"

enum {
    BS2_INVALID_EVENT_ID = 0,

    /**
     *  main event code
     */
    BS2_EVENT_MASK							= 0xFF00,

    // Auth
    BS2_EVENT_VERIFY_SUCCESS				= 0x1000,
    BS2_EVENT_VERIFY_FAIL					= 0x1100,	//	Alert
    BS2_EVENT_VERIFY_DURESS					= 0x1200,	//	Alarm
    BS2_EVENT_IDENTIFY_SUCCESS				= 0x1300,
    BS2_EVENT_IDENTIFY_FAIL					= 0x1400,	//	Alert
    BS2_EVENT_IDENTIFY_DURESS				= 0x1500,	//	Alarm
    BS2_EVENT_DUAL_AUTH_SUCCESS				= 0x1600,
    BS2_EVENT_DUAL_AUTH_FAIL				= 0x1700,
    BS2_EVENT_AUTH_FAILED					= 0x1800,
    BS2_EVENT_ACCESS_DENIED					= 0x1900,	//	Alert
    BS2_EVENT_ACCESS_EXCUSED				= 0x1900,	//	for soft (timed) APB only - TODO: confirm me
    BS2_EVENT_FAKE_FINGER_DETECTED			= 0x1A00,	//LFD

    // User
    BS2_EVENT_USER_ENROLL_SUCCESS			= 0x2000,
    BS2_EVENT_USER_ENROLL_FAIL				= 0x2100,
    BS2_EVENT_USER_UPDATE_SUCCESS			= 0x2200,
    BS2_EVENT_USER_UPDATE_FAIL				= 0x2300,
    BS2_EVENT_USER_DELETE_SUCCESS			= 0x2400,
    BS2_EVENT_USER_DELETE_FAIL				= 0x2500,
    BS2_EVENT_USER_DELETE_ALL_SUCCESS		= 0x2600,
    BS2_EVENT_USER_ISSUE_AOC_SUCCESS		= 0x2700,
    BS2_EVENT_USER_DUPLICATE_CREDENTIAL		= 0x2800,

    // Device
    BS2_EVENT_DEVICE_SYSTEM_RESET			= 0x3000,	// Alert
    BS2_EVENT_DEVICE_SYSTEM_STARTED			= 0x3100,
    BS2_EVENT_DEVICE_TIME_SET				= 0x3200,
    BS2_EVENT_DEVICE_TIMEZONE_SET			= 0x3201,
    BS2_EVENT_DEVICE_DST_SET				= 0x3202,
    BS2_EVENT_DEVICE_LINK_CONNECTED			= 0x3300,
    BS2_EVENT_DEVICE_LINK_DISCONNETED		= 0x3400,	// Alert
    BS2_EVENT_DEVICE_DHCP_SUCCESS			= 0x3500,
    BS2_EVENT_DEVICE_ADMIN_MENU				= 0x3600,
    BS2_EVENT_DEVICE_UI_LOCKED				= 0x3700,
    BS2_EVENT_DEVICE_UI_UNLOCKED			= 0x3800,
    BS2_EVENT_DEVICE_COMM_LOCKED			= 0x3900,
    BS2_EVENT_DEVICE_COMM_UNLOCKED			= 0x3A00,
    BS2_EVENT_DEVICE_TCP_CONNECTED			= 0x3B00,
    BS2_EVENT_DEVICE_TCP_DISCONNECTED		= 0x3C00,	// Alert
    BS2_EVENT_DEVICE_RS485_CONNECTED		= 0x3D00,
    BS2_EVENT_DEVICE_RS485_DISCONNCTED		= 0x3E00,	// Alarm
    BS2_EVENT_DEVICE_INPUT_DETECTED			= 0x3F00,
    BS2_EVENT_DEVICE_TAMPER_ON				= 0x4000,	// Alarm
    BS2_EVENT_DEVICE_TAMPER_OFF				= 0x4100,
    BS2_EVENT_DEVICE_EVENT_LOG_CLEARED		= 0x4200,
    BS2_EVENT_DEVICE_FIRMWARE_UPGRADED 		= 0x4300,
    BS2_EVENT_DEVICE_RESOURCE_UPGRADED 		= 0x4400,
    BS2_EVENT_DEVICE_CONFIG_RESET 			= 0x4500,	// response to BS2_CMD_RESET_CONFIG
    BS2_EVENT_DEVICE_DATABASE_RESET 		= 0x4501,
    BS2_EVENT_DEVICE_FACTORY_RESET 			= 0x4502,

    //BS2_EVENT_DEVICE_AC_FAIL		 		= 0x4503,	// Redefinition 2.6.0
    //BS2_EVENT_DEVICE_AC_SUCCESS 			= 0x4504,	// Redefinition 2.6.0
    BS2_EVENT_DEVICE_CONFIG_RESET_EX 		= 0x4503,	// response to BS2_CMD_RESET_CONFIG_EX

    // Supervised Input
    BS2_EVENT_SUPERVISED_INPUT_SHORT		= 0x4600,	//	Alert
    BS2_EVENT_SUPERVISED_INPUT_OPEN			= 0x4700,	//	Alert

    // Device - Ex
    BS2_EVENT_DEVICE_AC_FAIL		 		= 0x4800,
    BS2_EVENT_DEVICE_AC_SUCCESS 			= 0x4900,

    // Door
    BS2_EVENT_DOOR_UNLOCKED					= 0x5000,
    BS2_EVENT_DOOR_LOCKED					= 0x5100,
    BS2_EVENT_DOOR_OPENED					= 0x5200,
    BS2_EVENT_DOOR_CLOSED					= 0x5300,
    BS2_EVENT_DOOR_FORCED_OPEN				= 0x5400,
    BS2_EVENT_DOOR_HELD_OPEN				= 0x5500,
    BS2_EVENT_DOOR_FORCED_OPEN_ALARM		= 0x5600,	//	Alarm
    BS2_EVENT_DOOR_FORCED_OPEN_ALARM_CLEAR	= 0x5700,
    BS2_EVENT_DOOR_HELD_OPEN_ALARM			= 0x5800,	//	Alarm
    BS2_EVENT_DOOR_HELD_OPEN_ALARM_CLEAR	= 0x5900,
    BS2_EVENT_DOOR_APB_ALARM				= 0x5A00,	//	Alarm - currently, not used.
    BS2_EVENT_DOOR_APB_ALARM_CLEAR			= 0x5B00,
    BS2_EVENT_DOOR_RELEASE					= 0x5C00,
    BS2_EVENT_DOOR_LOCK						= 0x5D00,
    BS2_EVENT_DOOR_UNLOCK					= 0x5E00,

    // Zone
    BS2_EVENT_ZONE_APB_VIOLATION			= 0x6000,
    BS2_EVENT_ZONE_APB_ALARM				= 0x6100,	//	Alarm
    BS2_EVENT_ZONE_APB_ALARM_CLEAR			= 0x6200,
    BS2_EVENT_ZONE_TIMED_APB_VIOLATION		= 0x6300,
    BS2_EVENT_ZONE_TIMED_APB_ALARM			= 0x6400,
    BS2_EVENT_ZONE_TIMED_APB_ALARM_CLEAR	= 0x6500,
    BS2_EVENT_ZONE_FIRE_ALARM_INPUT			= 0x6600,
    BS2_EVENT_ZONE_FIRE_ALARM				= 0x6700,	//	Alarm
    BS2_EVENT_ZONE_FIRE_ALARM_CLEAR			= 0x6800,
    BS2_EVENT_ZONE_SCHEDULED_LOCK_VIOLATION	= 0x6900,
    BS2_EVENT_ZONE_SCHEDULED_LOCK_START		= 0x6A00,
    BS2_EVENT_ZONE_SCHEDULED_LOCK_END		= 0x6B00,
    BS2_EVENT_ZONE_SCHEDULED_UNLOCK_START	= 0x6C00,
    BS2_EVENT_ZONE_SCHEDULED_UNLOCK_END		= 0x6D00,
    BS2_EVENT_ZONE_SCHEDULED_LOCK_ALARM		= 0x6E00,	//	Alarm
    BS2_EVENT_ZONE_SCHEDULED_LOCK_ALARM_CLEAR = 0x6F00,
    BS2_EVENT_ZONE_FORCED_LOCK_VIOLATION	= 0x6900,
    BS2_EVENT_ZONE_FORCED_LOCK_START		= 0x6A00,
    BS2_EVENT_ZONE_FORCED_LOCK_END			= 0x6B00,
    BS2_EVENT_ZONE_FORCED_UNLOCK_START		= 0x6C00,
    BS2_EVENT_ZONE_FORCED_UNLOCK_END		= 0x6D00,
    BS2_EVENT_ZONE_FORCED_LOCK_ALARM		= 0x6E00,	//	Alarm
    BS2_EVENT_ZONE_FORCED_LOCK_ALARM_CLEAR	= 0x6F00,

    // Lift
    BS2_EVENT_FLOOR_ACTIVATED				= 0x7000,
    BS2_EVENT_FLOOR_DEACTIVATED				= 0x7100,
    BS2_EVENT_FLOOR_RELEASE					= 0x7200,
    BS2_EVENT_FLOOR_ACTIVATE				= 0x7300,
    BS2_EVENT_FLOOR_DEACTIVATE				= 0x7400,
    BS2_EVENT_LIFT_ALARM_INPUT				= 0x7500,
    BS2_EVENT_LIFT_ALARM					= 0x7600,
    BS2_EVENT_LIFT_ALARM_CLEAR				= 0x7700,
    BS2_EVENT_ALL_FLOOR_ACTIVATED			= 0x7800,
    BS2_EVENT_ALL_FLOOR_DEACTIVATED			= 0x7900,

    // BioStar
    BS2_EVENT_GLOBAL_APB_EXCUSED			= 0x8000,
    // TBD
    BS2_EVENT_DEVICE_ZONE_ENTRANCE_LIMIT_VIOLATION	= 0x8100,
    BS2_EVENT_DEVICE_ZONE_ENTRANCE_LIMIT_ALARM		= 0x8200,
    BS2_EVENT_DEVICE_ZONE_ENTRANCE_LIMIT_ALARM_CLEAR= 0x8300,

    BS2_EVENT_ZONE_INTRUSION_ALARM_VIOLATION		= 0x9000,
    BS2_EVENT_ZONE_INTRUSION_ALARM_ARM_GRANTED 		= 0x9100,
    BS2_EVENT_ZONE_INTRUSION_ALARM_ARM_SUCCESS 		= 0x9200,
    BS2_EVENT_ZONE_INTRUSION_ALARM_ARM_FAIL			= 0x9300,
    BS2_EVENT_ZONE_INTRUSION_ALARM_DISARM_GRANTED	= 0x9400,
    BS2_EVENT_ZONE_INTRUSION_ALARM_DISARM_SUCCESS	= 0x9500,
    BS2_EVENT_ZONE_INTRUSION_ALARM_DISARM_FAIL		= 0x9600,

    BS2_EVENT_ZONE_INTRUSION_ALARM_INPUT 			= 0x9700,	// Deprecated 2.4.0

    BS2_EVENT_ZONE_INTRUSION_ALARM 					= 0x9800,
    BS2_EVENT_ZONE_INTRUSION_ALARM_CLEAR 			= 0x9900,
    BS2_EVENT_ZONE_INTRUSION_ALARM_ARM_DENIED 		= 0x9A00,
    BS2_EVENT_ZONE_INTRUSION_ALARM_DISARM_DENIED 	= 0x9B00,

    BS2_EVENT_ZONE_INTERLOCK_VIOLATION				= 0xA000,
    BS2_EVENT_ZONE_INTERLOCK_ALARM 					= 0xA100,
    BS2_EVENT_ZONE_INTERLOCK_ALARM_DOOR_OPEN_DENIED = 0xA200,
    BS2_EVENT_ZONE_INTERLOCK_ALARM_INDOOR_DENIED 	= 0xA300,
    BS2_EVENT_ZONE_INTERLOCK_ALARM_CLEAR 			= 0xA400,

    BS2_EVENT_ZONE_AUTH_LIMIT_VIOLATION				= 0xA500,
    BS2_EVENT_GLOBAL_AUTH_LIMIT_EXCUSED				= 0xA600,

    BS2_EVENT_ZONE_MUSTER_VIOLATION 				= 0xB000,
    BS2_EVENT_ZONE_MUSTER_ALARM 					= 0xB100,
    BS2_EVENT_ZONE_MUSTER_ALARM_CLEAR 				= 0xB200,

    BS2_EVENT_DEVICE_USER_SYNC_TO_SERVER_FAIL 		= 0xC000,
    BS2_EVENT_BREAK_GLASS 							= 0xC100, // ~ 0xC1FF;
    BS2_EVENT_MEMORY_FULL_MIGRATION 				= 0xC200,        // Memory full and swap partition

    /**
     *  sub event code
     */
    BS2_SUB_EVENT_MASK							= 0x00FF,

    // Verified authenticaion mode
    BS2_SUB_EVENT_VERIFY_ID_PIN					= 0x01,
    BS2_SUB_EVENT_VERIFY_ID_FINGER				= 0x02,
    BS2_SUB_EVENT_VERIFY_ID_FINGER_PIN			= 0x03,
    BS2_SUB_EVENT_VERIFY_ID_FACE				= 0x04,
    BS2_SUB_EVENT_VERIFY_ID_FACE_PIN			= 0x05,
    BS2_SUB_EVENT_VERIFY_CARD					= 0x06,
    BS2_SUB_EVENT_VERIFY_CARD_PIN				= 0x07,
    BS2_SUB_EVENT_VERIFY_CARD_FINGER			= 0x08,
    BS2_SUB_EVENT_VERIFY_CARD_FINGER_PIN		= 0x09,
    BS2_SUB_EVENT_VERIFY_CARD_FACE				= 0x0A,
    BS2_SUB_EVENT_VERIFY_CARD_FACE_PIN			= 0x0B,
    BS2_SUB_EVENT_VERIFY_AOC					= 0x0C,
    BS2_SUB_EVENT_VERIFY_AOC_PIN				= 0x0D,
    BS2_SUB_EVENT_VERIFY_AOC_FINGER				= 0x0E,
    BS2_SUB_EVENT_VERIFY_AOC_FINGER_PIN			= 0x0F,

    // Identified authentication mode
    BS2_SUB_EVENT_IDENTIFY_FINGER				= 0x01,
    BS2_SUB_EVENT_IDENTIFY_FINGER_PIN			= 0x02,
    BS2_SUB_EVENT_IDENTIFY_FACE					= 0x03,
    BS2_SUB_EVENT_IDENTIFY_FACE_PIN				= 0x04,

    // Reason to be failed
    BS2_SUB_EVENT_DUAL_AUTH_FAIL_TIMEOUT		= 0x01,
    BS2_SUB_EVENT_DUAL_AUTH_FAIL_ACCESS_GROUP	= 0x02,

    // Failed credential
    BS2_SUB_EVENT_CREDENTIAL_ID					= 0x01,
    BS2_SUB_EVENT_CREDENTIAL_CARD				= 0x02,
    BS2_SUB_EVENT_CREDENTIAL_PIN				= 0x03,
    BS2_SUB_EVENT_CREDENTIAL_FINGER				= 0x04,
    BS2_SUB_EVENT_CREDENTIAL_FACE				= 0x05,
    BS2_SUB_EVENT_CREDENTIAL_AOC_PIN			= 0x06,
    BS2_SUB_EVENT_CREDENTIAL_AOC_FINGER			= 0x07,

    // Reason to be failed
    BS2_SUB_EVENT_AUTH_FAIL_INVALID_AUTH_MODE	= 0x01,
    BS2_SUB_EVENT_AUTH_FAIL_INVALID_CREDENTIAL	= 0x02,
    BS2_SUB_EVENT_AUTH_FAIL_TIMEOUT				= 0x03,
    BS2_SUB_EVENT_AUTH_FAIL_MATCHING_REFUSAL 	= 0x04,

    // Reason to be denied
    BS2_SUB_EVENT_ACCESS_DENIED_ACCESS_GROUP	= 0x01,
    BS2_SUB_EVENT_ACCESS_DENIED_DISABLED		= 0x02,
    BS2_SUB_EVENT_ACCESS_DENIED_EXPIRED			= 0x03,
    BS2_SUB_EVENT_ACCESS_DENIED_ON_BLACKLIST	= 0x04,
    BS2_SUB_EVENT_ACCESS_DENIED_APB				= 0x05,
    BS2_SUB_EVENT_ACCESS_DENIED_TIMED_APB		= 0x06,
    BS2_SUB_EVENT_ACCESS_DENIED_SCHEDULED_LOCK	= 0x07,
    BS2_SUB_EVENT_ACCESS_DENIED_FORCED_LOCK		= 0x07,
    BS2_SUB_EVENT_ACCESS_EXCUSED_APB			= 0x08,
    BS2_SUB_EVENT_ACCESS_EXCUSED_TIMED_APB		= 0x09,
    BS2_SUB_EVENT_ACCESS_DENIED_FACE_DETECTION	= 0x0A,
    BS2_SUB_EVENT_ACCESS_DENIED_CAMERA_CAPTURE	= 0x0B,
    BS2_SUB_EVENT_ACCESS_DENIED_FAKE_FINGER		= 0x0C,
    BS2_SUB_EVENT_ACCESS_DENIED_DEVICE_ZONE_ENTRANCE_LIMIT = 0x0D,
    BS2_SUB_EVENT_ACCESS_DENIED_INTRUSION_ALARM	= 0x0E,
    BS2_SUB_EVENT_ACCESS_DENIED_INTERLOCK		= 0x0F,
    BS2_SUB_EVENT_ACCESS_EXCUSED_AUTH_LIMIT		= 0x10,
    BS2_SUB_EVENT_ACCESS_DENIED_AUTH_LIMIT		= 0x11,
    BS2_SUB_EVENT_ACCESS_DENIED_ANTI_TAILGATE	= 0x12,

    // Door flag type
    BS2_SUB_EVENT_DOOR_FLAG_SCHEDULE = BS2_DOOR_FLAG_SCHEDULE,
    BS2_SUB_EVENT_DOOR_FLAG_OPERATOR = BS2_DOOR_FLAG_OPERATOR,
    BS2_SUB_EVENT_DOOR_FLAG_EMERGENCY = BS2_DOOR_FLAG_EMERGENCY,

    // Floor flag type
    BS2_SUB_EVENT_FLOOR_FLAG_SCHEDULE = BS2_FLOOR_FLAG_SCHEDULE,
    BS2_SUB_EVENT_FLOOR_FLAG_OPERATOR = BS2_FLOOR_FLAG_OPERATOR,
    BS2_SUB_EVENT_FLOOR_FLAG_ACTION = BS2_FLOOR_FLAG_ACTION,		// TIIDFI-2050
    BS2_SUB_EVENT_FLOOR_FLAG_EMERGENCY = BS2_FLOOR_FLAG_EMERGENCY,

    // Antipassback violation type
    BS2_SUB_EVENT_ZONE_HARD_APB					= 0x01,
    BS2_SUB_EVENT_ZONE_SOFT_APB					= 0x02,

    // Device Zone Entrance limit violation type
    BS2_SUB_EVENT_DEVICE_ZONE_HARD_ENTRANCE_LIMIT_COUNT	= 0x01,
    BS2_SUB_EVENT_DEVICE_ZONE_SOFT_ENTRANCE_LIMIT_COUNT	= 0x02,
    BS2_SUB_EVENT_DEVICE_ZONE_HARD_ENTRANCE_LIMIT_TIME	= 0x03,
    BS2_SUB_EVENT_DEVICE_ZONE_SOFT_ENTRANCE_LIMIT_TIME	= 0x04,

    // InterlockZone violation type
    BS2_SUB_EVENT_INTERLOCKZONE_DOOR_OPEN 				= 0x01,
    BS2_SUB_EVENT_INTERLOCK_INPUT_DETECT 				= 0x02,

    // Authentication Limit violation type
    BS2_SUB_EVENT_ZONE_HARD_AUTH_LIMIT				= 0x01,
    BS2_SUB_EVENT_ZONE_SOFT_AUTH_LIMIT 				= 0x02,
    BS2_SUB_EVENT_ZONE_SCHEDULE_AUTH_LIMIT 			= 0x03,
    BS2_SUB_EVENT_ZONE_COUNT_AUTH_LIMIT 			= 0x04,
    BS2_SUB_EVENT_ZONE_USER_AUTH_LIMIT 				= 0x05
};

// Deprecated in V2.4.0.
#define BS2_EVENT_ZONE_FORCED_LOCK_VIOLATION		(DEPRECATED_ENUM)BS2_EVENT_ZONE_FORCED_LOCK_VIOLATION
#define BS2_EVENT_ZONE_FORCED_LOCK_START			(DEPRECATED_ENUM)BS2_EVENT_ZONE_FORCED_LOCK_START
#define BS2_EVENT_ZONE_FORCED_LOCK_END				(DEPRECATED_ENUM)BS2_EVENT_ZONE_FORCED_LOCK_END
#define BS2_EVENT_ZONE_FORCED_UNLOCK_START			(DEPRECATED_ENUM)BS2_EVENT_ZONE_FORCED_UNLOCK_START
#define BS2_EVENT_ZONE_FORCED_UNLOCK_END			(DEPRECATED_ENUM)BS2_EVENT_ZONE_FORCED_UNLOCK_END
#define BS2_EVENT_ZONE_FORCED_LOCK_ALARM			(DEPRECATED_ENUM)BS2_EVENT_ZONE_FORCED_LOCK_ALARM
#define BS2_EVENT_ZONE_FORCED_LOCK_ALARM_CLEAR		(DEPRECATED_ENUM)BS2_EVENT_ZONE_FORCED_LOCK_ALARM_CLEAR
#define BS2_EVENT_ZONE_INTRUSION_ALARM_INPUT		(DEPRECATED_ENUM)BS2_EVENT_ZONE_INTRUSION_ALARM_INPUT

typedef uint16_t BS2_EVENT_CODE;

typedef struct {
    BS2_USER_ID userID;		// set "" to get logs for every user
    BS2_TIMESTAMP start;		// set 0 to get the oldest log
    BS2_TIMESTAMP end;		// set 0 to get the recent log
    BS2_EVENT_CODE event;		// set 0 to get the logs for every event code
    uint8_t tnaKey;		// set 0 to get the logs for every tnaKey
    uint8_t reserved[1];
} BS2EventFilter;

typedef struct {
    BS2_EVENT_ID	id;					///< 4 bytes
    BS2_TIMESTAMP	dateTime;			///< 4 bytes
    BS2_DEVICE_ID deviceID;
    union {
        BS2_USER_ID		userID;			///< 32 bytes
        BS2_UID uid;
        BS2_DOOR_ID doorID;
        BS2_LIFT_ID liftID;
        BS2_ZONE_ID zoneID;
        struct {
            BS2_DEVICE_ID 	ioDeviceID;
            BS2_PORT		port;
            BS2_PORT_VALUE value;
            uint8_t reserved[25];
        };
        //Remark for SWIG
        struct {
            BS2_ZONE_ID zoneID;
            BS2_DOOR_ID doorID;
            BS2_DEVICE_ID ioDeviceID;
            BS2_PORT port;
            uint8_t reserved[18];
        } alarm;
        struct {
            BS2_ZONE_ID zoneID;
            BS2_DOOR_ID doorID[4];
            uint8_t reserved[12];
        } interlock;
    };
    union {								///< 2 bytes
        BS2_EVENT_CODE code;
        struct {
            uint8_t	subCode;
            uint8_t	mainCode;
        };
    };
    uint8_t			param;				///< 1 byte : tnaKey, floorIndex, alarmFlags
#ifdef LESS_THAN_SDK_2_6_0
    BS2_BOOL image;						///< 1 byte : Deprecated in V2.6.0
#else
    uint8_t image: 1;					///< Image and DST support devided by bit
    uint8_t isDST: 1;
    uint8_t half: 1;
    uint8_t hour: 4;
    uint8_t negative: 1;
#endif
} BS2Event;

#endif	// __BS2_EVENT_H__
