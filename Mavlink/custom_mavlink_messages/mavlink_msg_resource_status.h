// MESSAGE RESOURCE_STATUS PACKING

#define MAVLINK_MSG_ID_RESOURCE_STATUS 150

typedef struct __mavlink_resource_status_t
{
 uint8_t resource; ///< Resource US may be abble to provide: 0: GeoLocalisation, ..., defined in MAV_ISAE_RESOURCE ENUM
 uint8_t status; ///< Resource's status: 0: Stopped, 1: Running, 2: Crashed, defined in MAV_ISAE_RESOURCE_STATUS ENUM
} mavlink_resource_status_t;

#define MAVLINK_MSG_ID_RESOURCE_STATUS_LEN 2
#define MAVLINK_MSG_ID_150_LEN 2



#define MAVLINK_MESSAGE_INFO_RESOURCE_STATUS { \
	"RESOURCE_STATUS", \
	2, \
	{  { "resource", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_resource_status_t, resource) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_resource_status_t, status) }, \
         } \
}


/**
 * @brief Pack a resource_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param resource Resource US may be abble to provide: 0: GeoLocalisation, ..., defined in MAV_ISAE_RESOURCE ENUM
 * @param status Resource's status: 0: Stopped, 1: Running, 2: Crashed, defined in MAV_ISAE_RESOURCE_STATUS ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_resource_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t resource, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, resource);
	_mav_put_uint8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_resource_status_t packet;
	packet.resource = resource;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_RESOURCE_STATUS;
	return mavlink_finalize_message(msg, system_id, component_id, 2, 109);
}

/**
 * @brief Pack a resource_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param resource Resource US may be abble to provide: 0: GeoLocalisation, ..., defined in MAV_ISAE_RESOURCE ENUM
 * @param status Resource's status: 0: Stopped, 1: Running, 2: Crashed, defined in MAV_ISAE_RESOURCE_STATUS ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_resource_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t resource,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, resource);
	_mav_put_uint8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_resource_status_t packet;
	packet.resource = resource;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_RESOURCE_STATUS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 109);
}

/**
 * @brief Encode a resource_status struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param resource_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_resource_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_resource_status_t* resource_status)
{
	return mavlink_msg_resource_status_pack(system_id, component_id, msg, resource_status->resource, resource_status->status);
}

/**
 * @brief Send a resource_status message
 * @param chan MAVLink channel to send the message
 *
 * @param resource Resource US may be abble to provide: 0: GeoLocalisation, ..., defined in MAV_ISAE_RESOURCE ENUM
 * @param status Resource's status: 0: Stopped, 1: Running, 2: Crashed, defined in MAV_ISAE_RESOURCE_STATUS ENUM
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_resource_status_send(mavlink_channel_t chan, uint8_t resource, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, resource);
	_mav_put_uint8_t(buf, 1, status);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RESOURCE_STATUS, buf, 2, 109);
#else
	mavlink_resource_status_t packet;
	packet.resource = resource;
	packet.status = status;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RESOURCE_STATUS, (const char *)&packet, 2, 109);
#endif
}

#endif

// MESSAGE RESOURCE_STATUS UNPACKING


/**
 * @brief Get field resource from resource_status message
 *
 * @return Resource US may be abble to provide: 0: GeoLocalisation, ..., defined in MAV_ISAE_RESOURCE ENUM
 */
static inline uint8_t mavlink_msg_resource_status_get_resource(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field status from resource_status message
 *
 * @return Resource's status: 0: Stopped, 1: Running, 2: Crashed, defined in MAV_ISAE_RESOURCE_STATUS ENUM
 */
static inline uint8_t mavlink_msg_resource_status_get_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a resource_status message into a struct
 *
 * @param msg The message to decode
 * @param resource_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_resource_status_decode(const mavlink_message_t* msg, mavlink_resource_status_t* resource_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	resource_status->resource = mavlink_msg_resource_status_get_resource(msg);
	resource_status->status = mavlink_msg_resource_status_get_status(msg);
#else
	memcpy(resource_status, _MAV_PAYLOAD(msg), 2);
#endif
}
