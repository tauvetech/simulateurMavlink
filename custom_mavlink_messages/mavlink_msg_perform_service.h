// MESSAGE PERFORM_SERVICE PACKING

#define MAVLINK_MSG_ID_PERFORM_SERVICE 154

typedef struct __mavlink_perform_service_t
{
 float param_1; ///< Service's parameter 1. X position for GOTO action.
 float param_2; ///< Service's parameter 2. Y position for GOTO action.
 float param_3; ///< Service's parameter 3. Z position for GOTO action.
 uint8_t target_system; ///< System the GCS requests service.
 uint8_t action; ///< Service to perform: 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
} mavlink_perform_service_t;

#define MAVLINK_MSG_ID_PERFORM_SERVICE_LEN 14
#define MAVLINK_MSG_ID_154_LEN 14



#define MAVLINK_MESSAGE_INFO_PERFORM_SERVICE { \
	"PERFORM_SERVICE", \
	5, \
	{  { "param_1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_perform_service_t, param_1) }, \
         { "param_2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_perform_service_t, param_2) }, \
         { "param_3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_perform_service_t, param_3) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_perform_service_t, target_system) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_perform_service_t, action) }, \
         } \
}


/**
 * @brief Pack a perform_service message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System the GCS requests service.
 * @param action Service to perform: 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 * @param param_1 Service's parameter 1. X position for GOTO action.
 * @param param_2 Service's parameter 2. Y position for GOTO action.
 * @param param_3 Service's parameter 3. Z position for GOTO action.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_perform_service_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t action, float param_1, float param_2, float param_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[14];
	_mav_put_float(buf, 0, param_1);
	_mav_put_float(buf, 4, param_2);
	_mav_put_float(buf, 8, param_3);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, action);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 14);
#else
	mavlink_perform_service_t packet;
	packet.param_1 = param_1;
	packet.param_2 = param_2;
	packet.param_3 = param_3;
	packet.target_system = target_system;
	packet.action = action;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 14);
#endif

	msg->msgid = MAVLINK_MSG_ID_PERFORM_SERVICE;
	return mavlink_finalize_message(msg, system_id, component_id, 14, 150);
}

/**
 * @brief Pack a perform_service message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System the GCS requests service.
 * @param action Service to perform: 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 * @param param_1 Service's parameter 1. X position for GOTO action.
 * @param param_2 Service's parameter 2. Y position for GOTO action.
 * @param param_3 Service's parameter 3. Z position for GOTO action.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_perform_service_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t action,float param_1,float param_2,float param_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[14];
	_mav_put_float(buf, 0, param_1);
	_mav_put_float(buf, 4, param_2);
	_mav_put_float(buf, 8, param_3);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, action);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 14);
#else
	mavlink_perform_service_t packet;
	packet.param_1 = param_1;
	packet.param_2 = param_2;
	packet.param_3 = param_3;
	packet.target_system = target_system;
	packet.action = action;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 14);
#endif

	msg->msgid = MAVLINK_MSG_ID_PERFORM_SERVICE;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 14, 150);
}

/**
 * @brief Encode a perform_service struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param perform_service C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_perform_service_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_perform_service_t* perform_service)
{
	return mavlink_msg_perform_service_pack(system_id, component_id, msg, perform_service->target_system, perform_service->action, perform_service->param_1, perform_service->param_2, perform_service->param_3);
}

/**
 * @brief Send a perform_service message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System the GCS requests service.
 * @param action Service to perform: 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 * @param param_1 Service's parameter 1. X position for GOTO action.
 * @param param_2 Service's parameter 2. Y position for GOTO action.
 * @param param_3 Service's parameter 3. Z position for GOTO action.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_perform_service_send(mavlink_channel_t chan, uint8_t target_system, uint8_t action, float param_1, float param_2, float param_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[14];
	_mav_put_float(buf, 0, param_1);
	_mav_put_float(buf, 4, param_2);
	_mav_put_float(buf, 8, param_3);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, action);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PERFORM_SERVICE, buf, 14, 150);
#else
	mavlink_perform_service_t packet;
	packet.param_1 = param_1;
	packet.param_2 = param_2;
	packet.param_3 = param_3;
	packet.target_system = target_system;
	packet.action = action;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PERFORM_SERVICE, (const char *)&packet, 14, 150);
#endif
}

#endif

// MESSAGE PERFORM_SERVICE UNPACKING


/**
 * @brief Get field target_system from perform_service message
 *
 * @return System the GCS requests service.
 */
static inline uint8_t mavlink_msg_perform_service_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field action from perform_service message
 *
 * @return Service to perform: 0: GOTO, ..., defined in MAV_ISAE_SERVICE ENUM
 */
static inline uint8_t mavlink_msg_perform_service_get_action(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field param_1 from perform_service message
 *
 * @return Service's parameter 1. X position for GOTO action.
 */
static inline float mavlink_msg_perform_service_get_param_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param_2 from perform_service message
 *
 * @return Service's parameter 2. Y position for GOTO action.
 */
static inline float mavlink_msg_perform_service_get_param_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param_3 from perform_service message
 *
 * @return Service's parameter 3. Z position for GOTO action.
 */
static inline float mavlink_msg_perform_service_get_param_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a perform_service message into a struct
 *
 * @param msg The message to decode
 * @param perform_service C-struct to decode the message contents into
 */
static inline void mavlink_msg_perform_service_decode(const mavlink_message_t* msg, mavlink_perform_service_t* perform_service)
{
#if MAVLINK_NEED_BYTE_SWAP
	perform_service->param_1 = mavlink_msg_perform_service_get_param_1(msg);
	perform_service->param_2 = mavlink_msg_perform_service_get_param_2(msg);
	perform_service->param_3 = mavlink_msg_perform_service_get_param_3(msg);
	perform_service->target_system = mavlink_msg_perform_service_get_target_system(msg);
	perform_service->action = mavlink_msg_perform_service_get_action(msg);
#else
	memcpy(perform_service, _MAV_PAYLOAD(msg), 14);
#endif
}
