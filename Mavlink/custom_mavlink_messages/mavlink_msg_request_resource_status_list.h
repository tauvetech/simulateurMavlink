// MESSAGE REQUEST_RESOURCE_STATUS_LIST PACKING

#define MAVLINK_MSG_ID_REQUEST_RESOURCE_STATUS_LIST 151

typedef struct __mavlink_request_resource_status_list_t
{
 uint8_t target_system; ///< System the GCS requests resource list for
} mavlink_request_resource_status_list_t;

#define MAVLINK_MSG_ID_REQUEST_RESOURCE_STATUS_LIST_LEN 1
#define MAVLINK_MSG_ID_151_LEN 1



#define MAVLINK_MESSAGE_INFO_REQUEST_RESOURCE_STATUS_LIST { \
	"REQUEST_RESOURCE_STATUS_LIST", \
	1, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_resource_status_list_t, target_system) }, \
         } \
}


/**
 * @brief Pack a request_resource_status_list message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System the GCS requests resource list for
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_resource_status_list_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_request_resource_status_list_t packet;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_RESOURCE_STATUS_LIST;
	return mavlink_finalize_message(msg, system_id, component_id, 1, 135);
}

/**
 * @brief Pack a request_resource_status_list message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System the GCS requests resource list for
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_resource_status_list_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_request_resource_status_list_t packet;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_RESOURCE_STATUS_LIST;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 1, 135);
}

/**
 * @brief Encode a request_resource_status_list struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param request_resource_status_list C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_resource_status_list_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_request_resource_status_list_t* request_resource_status_list)
{
	return mavlink_msg_request_resource_status_list_pack(system_id, component_id, msg, request_resource_status_list->target_system);
}

/**
 * @brief Send a request_resource_status_list message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System the GCS requests resource list for
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_request_resource_status_list_send(mavlink_channel_t chan, uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, target_system);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_RESOURCE_STATUS_LIST, buf, 1, 135);
#else
	mavlink_request_resource_status_list_t packet;
	packet.target_system = target_system;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_RESOURCE_STATUS_LIST, (const char *)&packet, 1, 135);
#endif
}

#endif

// MESSAGE REQUEST_RESOURCE_STATUS_LIST UNPACKING


/**
 * @brief Get field target_system from request_resource_status_list message
 *
 * @return System the GCS requests resource list for
 */
static inline uint8_t mavlink_msg_request_resource_status_list_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a request_resource_status_list message into a struct
 *
 * @param msg The message to decode
 * @param request_resource_status_list C-struct to decode the message contents into
 */
static inline void mavlink_msg_request_resource_status_list_decode(const mavlink_message_t* msg, mavlink_request_resource_status_list_t* request_resource_status_list)
{
#if MAVLINK_NEED_BYTE_SWAP
	request_resource_status_list->target_system = mavlink_msg_request_resource_status_list_get_target_system(msg);
#else
	memcpy(request_resource_status_list, _MAV_PAYLOAD(msg), 1);
#endif
}
