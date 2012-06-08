// MESSAGE REQUEST_SERVICE_AVAILABILITY_LIST PACKING

#define MAVLINK_MSG_ID_REQUEST_SERVICE_AVAILABILITY_LIST 153

typedef struct __mavlink_request_service_availability_list_t
{
 uint8_t target_system; ///< System the GCS requests ressource list for
} mavlink_request_service_availability_list_t;

#define MAVLINK_MSG_ID_REQUEST_SERVICE_AVAILABILITY_LIST_LEN 1
#define MAVLINK_MSG_ID_153_LEN 1



#define MAVLINK_MESSAGE_INFO_REQUEST_SERVICE_AVAILABILITY_LIST { \
	"REQUEST_SERVICE_AVAILABILITY_LIST", \
	1, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_service_availability_list_t, target_system) }, \
         } \
}


/**
 * @brief Pack a request_service_availability_list message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System the GCS requests ressource list for
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_service_availability_list_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_request_service_availability_list_t packet;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_SERVICE_AVAILABILITY_LIST;
	return mavlink_finalize_message(msg, system_id, component_id, 1, 214);
}

/**
 * @brief Pack a request_service_availability_list message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System the GCS requests ressource list for
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_service_availability_list_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_request_service_availability_list_t packet;
	packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_SERVICE_AVAILABILITY_LIST;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 1, 214);
}

/**
 * @brief Encode a request_service_availability_list struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param request_service_availability_list C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_service_availability_list_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_request_service_availability_list_t* request_service_availability_list)
{
	return mavlink_msg_request_service_availability_list_pack(system_id, component_id, msg, request_service_availability_list->target_system);
}

/**
 * @brief Send a request_service_availability_list message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System the GCS requests ressource list for
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_request_service_availability_list_send(mavlink_channel_t chan, uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, target_system);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_SERVICE_AVAILABILITY_LIST, buf, 1, 214);
#else
	mavlink_request_service_availability_list_t packet;
	packet.target_system = target_system;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_SERVICE_AVAILABILITY_LIST, (const char *)&packet, 1, 214);
#endif
}

#endif

// MESSAGE REQUEST_SERVICE_AVAILABILITY_LIST UNPACKING


/**
 * @brief Get field target_system from request_service_availability_list message
 *
 * @return System the GCS requests ressource list for
 */
static inline uint8_t mavlink_msg_request_service_availability_list_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a request_service_availability_list message into a struct
 *
 * @param msg The message to decode
 * @param request_service_availability_list C-struct to decode the message contents into
 */
static inline void mavlink_msg_request_service_availability_list_decode(const mavlink_message_t* msg, mavlink_request_service_availability_list_t* request_service_availability_list)
{
#if MAVLINK_NEED_BYTE_SWAP
	request_service_availability_list->target_system = mavlink_msg_request_service_availability_list_get_target_system(msg);
#else
	memcpy(request_service_availability_list, _MAV_PAYLOAD(msg), 1);
#endif
}
