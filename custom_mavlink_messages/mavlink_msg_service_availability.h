// MESSAGE SERVICE_AVAILABILITY PACKING

#define MAVLINK_MSG_ID_SERVICE_AVAILABILITY 152

typedef struct __mavlink_service_availability_t
{
 uint8_t service; ///< Service the US may be able to perform - 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 uint8_t availablility; ///< Service's availability - 0: Not available, 1: Available. Defined in MAV_ISAE_SERVICE_STATUS ENUM
} mavlink_service_availability_t;

#define MAVLINK_MSG_ID_SERVICE_AVAILABILITY_LEN 2
#define MAVLINK_MSG_ID_152_LEN 2



#define MAVLINK_MESSAGE_INFO_SERVICE_AVAILABILITY { \
	"SERVICE_AVAILABILITY", \
	2, \
	{  { "service", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_service_availability_t, service) }, \
         { "availablility", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_service_availability_t, availablility) }, \
         } \
}


/**
 * @brief Pack a service_availability message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param service Service the US may be able to perform - 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 * @param availablility Service's availability - 0: Not available, 1: Available. Defined in MAV_ISAE_SERVICE_STATUS ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_service_availability_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t service, uint8_t availablility)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, service);
	_mav_put_uint8_t(buf, 1, availablility);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_service_availability_t packet;
	packet.service = service;
	packet.availablility = availablility;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_SERVICE_AVAILABILITY;
	return mavlink_finalize_message(msg, system_id, component_id, 2, 53);
}

/**
 * @brief Pack a service_availability message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param service Service the US may be able to perform - 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 * @param availablility Service's availability - 0: Not available, 1: Available. Defined in MAV_ISAE_SERVICE_STATUS ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_service_availability_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t service,uint8_t availablility)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, service);
	_mav_put_uint8_t(buf, 1, availablility);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_service_availability_t packet;
	packet.service = service;
	packet.availablility = availablility;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_SERVICE_AVAILABILITY;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 53);
}

/**
 * @brief Encode a service_availability struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param service_availability C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_service_availability_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_service_availability_t* service_availability)
{
	return mavlink_msg_service_availability_pack(system_id, component_id, msg, service_availability->service, service_availability->availablility);
}

/**
 * @brief Send a service_availability message
 * @param chan MAVLink channel to send the message
 *
 * @param service Service the US may be able to perform - 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 * @param availablility Service's availability - 0: Not available, 1: Available. Defined in MAV_ISAE_SERVICE_STATUS ENUM
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_service_availability_send(mavlink_channel_t chan, uint8_t service, uint8_t availablility)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, service);
	_mav_put_uint8_t(buf, 1, availablility);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVICE_AVAILABILITY, buf, 2, 53);
#else
	mavlink_service_availability_t packet;
	packet.service = service;
	packet.availablility = availablility;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVICE_AVAILABILITY, (const char *)&packet, 2, 53);
#endif
}

#endif

// MESSAGE SERVICE_AVAILABILITY UNPACKING


/**
 * @brief Get field service from service_availability message
 *
 * @return Service the US may be able to perform - 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 */
static inline uint8_t mavlink_msg_service_availability_get_service(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field availablility from service_availability message
 *
 * @return Service's availability - 0: Not available, 1: Available. Defined in MAV_ISAE_SERVICE_STATUS ENUM
 */
static inline uint8_t mavlink_msg_service_availability_get_availablility(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a service_availability message into a struct
 *
 * @param msg The message to decode
 * @param service_availability C-struct to decode the message contents into
 */
static inline void mavlink_msg_service_availability_decode(const mavlink_message_t* msg, mavlink_service_availability_t* service_availability)
{
#if MAVLINK_NEED_BYTE_SWAP
	service_availability->service = mavlink_msg_service_availability_get_service(msg);
	service_availability->availablility = mavlink_msg_service_availability_get_availablility(msg);
#else
	memcpy(service_availability, _MAV_PAYLOAD(msg), 2);
#endif
}
